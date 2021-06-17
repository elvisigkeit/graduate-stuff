var request = require('request');
var cheerio = require('cheerio');
const rc = require('./js/randomColor.js');

var PAG_BASE = "https://www.siga.ufrj.br/sira/temas/zire/frameConsultas.jsp?mainPage=/repositorio-curriculo/";
var PAG_TEST = "FA9F18A7-92A4-F79B-1A98-293E97D8939B.html";
//var PAG_TEST = "C4A0EE64-92A4-F716-0097-168A2FDAFF82.html";

function parseCourse(url) {
	var jsonCourse = {
		"name": "",
		"semesters": []
	};

	return new Promise(function(resolve, reject) {
	request(url, function(error, response, body) {
		// Check status code (200 is HTTP OK)
		if(response.statusCode !== 200) {
			console.log("ERRO ENTRANDO NA PAGINA " + url + "!");
			reject(error);
			return;
		}

		// Searches for the link where the course is
		var $ = cheerio.load(body);
		var course = $('#main').attr('src');
		var nextLink = url.split('\/sira\/');
		nextLink = nextLink[0] + course;

		//Then enters in it
		request(nextLink, function(error, response, body) {
			// Check status code (200 is HTTP OK)
			if(response.statusCode !== 200) {
				console.log("ERRO ENTRANDO NA PAGINA " + nextLink + "!");
				reject(error);
				return;
			}

			// Searches for the link where the course is
			var $ = cheerio.load(body);
			nextLink = "https://www.siga.ufrj.br/sira/repositorio-curriculo/" + ($('#frameDynamic').attr('src'));

			//Enters in the final jump
			request({ url: nextLink, encoding: 'binary'}, function(error, response, body) {
				// Check status code (200 is HTTP OK)
				if(response.statusCode !== 200) {
					console.log("ERRO ENTRANDO NA PAGINA " + nextLink + "!");
					reject(error);
					return;
				}

				// Searches for the link where the course is
				var $ = cheerio.load(body);
				var course = (($('.tableTitle').text()).split("Curriculo"))[0];
				jsonCourse.name = course;

				var semesters = $('table[class="cellspacingTable"]');
				var titles = $('tr[class="tableTitleBlue"]');
				//titles.map((i, el)=>{console.log(el.children[0].children[0].children[0]);console.log("\n\n----\n\n");});
				var possuiExtensao = /Teórica\/Prática\/Extensão/.test(semesters.text());
				jsonCourse.semesters.push(
				semesters.map(function(i, el){
					var semester = {};
					var titulo = el.children[0];
					while(titulo.children)
						titulo = titulo.children[0];
					semester.titulo = titulo.data;
					semester.materias = getCourses($(this).text().split('\n'), possuiExtensao);
					semester.optativas = false;
					//Para fazer jus...
					//Equacoes de Equivalencia
					//Equivalencias por Cod Anterior
					return semester;
				}));
				jsonCourse.semesters = jsonCourse.semesters[0];
				delete jsonCourse.semesters.options;
				delete jsonCourse.semesters._root;
				delete jsonCourse.semesters.prevObject;
				resolve(jsonCourse);
			});
		});
	});
	});
}

function getRequisitos(line) {
	var requisitos = [];
	line.split(',').map(function(val){
		requisitos.push(Array.of(val.substr(1,6)));
		//console.log(val.substr(-3, 3)); Getting the type of requirement, if (C) it wouldnt appear
		if(val.length>11){//this means it is an equation
			var incomplete = true;
			var equation = val.slice(11, val.length);
			while(incomplete){
				incomplete = false;
				if(equation[15] == " "){//sum
					var left = equation.substr(0,6);
					var right = equation.substr(9,15);
					for(var i=0; i<requisitos.length; i++){
						if(requisitos[i][0] === left){
							requisitos[i].push(right);
							break;
						}
					}
					equation = equation.slice(24, equation.length);
					incomplete = true;
				}else if(equation[15]){//theres more after one equality equation
					var left = equation.substr(0,6);
					var right = equation.substr(9,6);
					for(var i=0; i<requisitos.length; i++){
						if(requisitos[i][0] === left){
							requisitos[i].push(right);
							break;
						}
					}
					equation = equation.slice(15, val.length);
					incomplete = true;
				}else if(equation.length>1){//last equation of equality
					var left = equation.substr(0,6);
					var right = equation.substr(9,6);
					for(var i=0; i<requisitos.length; i++){
						if(requisitos[i][0] === left){
							requisitos[i].push(right);
							break;
						}
					}
				}
			}
		}
	});
	return requisitos;
}

function getCourses(text, extensao) {
	var state = 7;
	var courses = [];
	var course = {};

	for(var i=1; i<text.length; i++){
		if(state==7)
			if(text[i].length>2){
				if(course.hasOwnProperty("codigo") && !/^([0-9])+/.test(course.nome))
					courses.push(course);
				course = {};
				state = 0;
			}
		switch(state){
			case 0:
				course.codigo = text[i].substr(1);
				state++;
				break;
			case 1:
				course.nome = text[i].substr(1);
				state++;
				break;
			case 2:
				course.creditos = text[i].substr(1);
				state++;
				break;
			case 3:
				course.CHTeorica = text[i].substr(1);
				state++;
				break;
			case 4:
				course.CHPratica = text[i].substr(1);
				state++;
				break;
			case 5:
				if(extensao){
					course.CHExtensao = text[i].substr(1);
				}else{
					course.requisitos = getRequisitos(text[i]);
				}
				state++;
				break;
			case 6:
				if(extensao){
					course.requisitos = getRequisitos(text[i]);
				}
				course.cor = rc.randomColor();
				state++;
				break;
		}
	}
	return courses;
}

async function getJSON(curso){
	const link = PAG_BASE + curso;
	var jsonCourse = await parseCourse(link);
	return jsonCourse;
}

//getJSON(PAG_TEST).then((resultado)=>console.log(resultado)).catch(()=>console.log("Error"));

module.exports =
{
	parseCourse: parseCourse,
	getJSON: getJSON
};
