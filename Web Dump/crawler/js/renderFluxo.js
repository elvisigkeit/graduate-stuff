/****************Criando cores pasteis**********************
//https://kentor.me/posts/generating-pastel-colors-for-css/
var hue = Math.floor(Math.random() * 360);
var pastel = 'hsl(' + hue + ', 100%, 87.5%)';
*/

const glueNames = function ( names ) {
  var result = [];
  var accum = "";
  for (var i=0; i<names.length-1; i++){
    if(accum.length === 0){
      if((names[i+1].length + names[i].length + 1)<9){
        accum = names[i] + " " + names[i+1];
      }else{
        result.push(names[i]);
      }
    }else{
      if((accum.length + names[i+1].length + 1)<9){
        accum = accum + " " + names[i+1];
      }else{
        result.push(accum);
        accum = "";
      }
    }
  }
  if(accum.length === 0){
    result.push(names[names.length-1]);
  }else{
    result.push(accum);
  }
  return result;
}

var boxWidth = 128;
var boxHeight = 70;

const createMateria = function ( materia, fluxograma, semestre, nrMateria) {
  var group = document.createElementNS("http://www.w3.org/2000/svg", "g");
  group.id = materia.codigo;
  var posX = (semestre-1)*boxWidth;
  var posY = (nrMateria)*boxHeight;
  var node = document.createElementNS("http://www.w3.org/2000/svg", "rect");
  node.setAttribute("x", (posX)+10);
  node.setAttribute("y", (posY)+3);
  node.setAttribute("width", "120");
  node.setAttribute("height", "63");
  node.setAttribute("fill", materia.cor);
  node.setAttribute("rx", "10");
  node.setAttribute("ry", "10");
  group.append(node);
  var nomes = materia.nome.split(" ");
  nomes = glueNames(nomes);
  for (var i=0; i<nomes.length; i++){
    var text = document.createElementNS("http://www.w3.org/2000/svg", "text");
    text.innerHTML = nomes[i];
    text.setAttribute("x", (posX) + boxWidth/2 + 5);
    text.setAttribute("y", (posY) + (i+1)*(boxHeight/(nomes.length+1)) + 5);
    text.setAttribute("style", "user-select: none; text-anchor: middle");
    group.append(text);
  }
  fluxograma.append(group);
}

var grafoRequisitos = {};

const geraGrafoRequisitos = function () {
  grafoRequisitos = {};
  var i=1;
  while (curso.semesters[i].titulo.match(/.*Período$/)) {
    for(var j=0; j<curso.semesters[i].materias.length; j++){
      tracaRequisitosComEquivalencias(curso.semesters[i].materias[j].codigo, 
                                        curso.semesters[i].materias[j].requisitos);
    }
    i++;
  }
}

const criaLink =  function ( materia, requerimento ) {
  if(grafoRequisitos[materia]){
    grafoRequisitos[materia].requer.push(requerimento);
  } else {
    grafoRequisitos[materia] = {requer: [requerimento], libera: []};
  }
  if(grafoRequisitos[requerimento]){
    grafoRequisitos[requerimento].libera.push(materia);
  } else {
    grafoRequisitos[requerimento] = {requer: [], libera: [materia]};
  }
}

const tracaRequisitosComEquivalencias = function ( codigo, requisitos ) {
  if(requisitos[0][0].length === 0)
    return;

  for(var i=0; i<requisitos.length; i++) {
    if(requisitos[i].length === 1)
      criaLink(codigo, requisitos[i][0]);
    else{
      var reqEquivalente = requisitos[i].filter((val)=>{
        var a = 1;
        while (curso.semesters[a].titulo.match(/.*Período$/)) {
          for(var b=0; b<curso.semesters[a].materias.length; b++){
            if(curso.semesters[a].materias[b].codigo === val)
              return true;
          }
          a++;
        }
        return false;
      });
      criaLink(codigo, reqEquivalente[0]);
    }
  
  }
}

const generateFlowchart = function ( curso ) {
  var i=1;
  var fluxograma = document.getElementsByTagName('svg')[0];
  fluxograma.append(document.createElementNS("http://www.w3.org/2000/svg", "g"));
  group = document.getElementsByTagName('g')[0];

  setListeners(fluxograma);
  geraGrafoRequisitos();

  while (curso.semesters[i].titulo.match(/.*Período$/)) {
    for(var j=0; j<curso.semesters[i].materias.length; j++){
      createMateria (curso.semesters[i].materias[j], group, i, j);
    }
    i++;
  }
}