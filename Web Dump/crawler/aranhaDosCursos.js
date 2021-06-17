var request = require('request');
var cheerio = require('cheerio');

const PAGE_COURSES = "https://www.siga.ufrj.br/sira/repositorio-curriculo/80167CF7-3880-478C-8293-8E7D80CEDEBE.html";

function parseCoursePages() {
	var courses = [];

	return new Promise(function(resolve, reject) {
	request({ url: PAGE_COURSES, encoding: 'binary'}, function(error, response, body) {
		// Check status code (200 is HTTP OK)
		if(response.statusCode !== 200) {
			console.log("ERRO ENTRANDO NA PAGINA " + url + "!");
			reject(error);
			return;
		}

		// Searches for the link where the course is
		var $ = cheerio.load(body);
    $('.identacao1').find('b').map((i, el) => {
      var name;
      var distr = el.parent.parent.children[2].children;
      var link = distr[distr.length-1].attribs.href;
      link = link.split("'")[1].split("=");
			link = link[1].split("/")[2];
      if(el.children[0].data == '\n'){
        name = el.children[0].next.children[0].data;
      }
      else
        name = el.children[0].data;

      courses.push({name: name, link: link});
    });
    resolve(courses);
  });
  });
}

async function getCourses(){
	var courses = await parseCoursePages();
	return courses;
}

//getCourses().then((resultado)=>console.log(resultado)).catch(()=>console.log("Error"));

module.exports =
{
	parseCoursePages: parseCoursePages,
	getCourses: getCourses
};
