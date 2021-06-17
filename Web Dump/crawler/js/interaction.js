const largura = function ( escolhido, tipo ) {
  var arvoreRequisitos = {};
  if(grafoRequisitos[escolhido.id]) {
    var camada = 0;
    var fila = [];
    var vistos = {};
    fila[0] = grafoRequisitos[escolhido.id][tipo];
    while(fila[camada]){
      var pai = 0;
      while(fila[camada].length>0){
        if(vistos[fila[camada][0]]){
          fila[camada].shift();
          continue;
        }else{
          vistos[fila[camada][0]] = '';
        }

        if(!arvoreRequisitos[camada])
          arvoreRequisitos[camada] = Array.of([fila[camada][0], pai]);
        else
          arvoreRequisitos[camada].push([fila[camada][0], pai]);

        if(grafoRequisitos[fila[camada][0]] && grafoRequisitos[fila[camada][0]][tipo].length>0){
          if(fila[camada+1])
            fila[camada+1] = fila[camada+1].concat(grafoRequisitos[fila[camada][0]][tipo]);
          else
            fila[camada+1] = (grafoRequisitos[fila[camada][0]][tipo]);
        }
        fila[camada].shift();
        pai++;
      }
      pai = 0;
      camada++;
    }
    arvoreRequisitos['tamanho'] = camada;
  }
  return arvoreRequisitos;
}

const desenhaArvore = function ( arvore, tipo ) {
  for(var i=0; i<arvore.tamanho; i++){
    if(arvore[i])
      for(var j=0; j<arvore[i].length; j++){
        var atual = document.getElementById(arvore[i][j][0]);
        var transX = (j+1)*fluxoWidth/(arvore[i].length+1) 
                          - boxWidth/2 - lastdx - Number(atual.firstChild.attributes.x.value);
        var transY = (i+1)*(fluxoHeight/2)/(arvore.tamanho+1)
                          - boxHeight/2 - Number(atual.firstChild.attributes.y.value);
        if(tipo === 'libera')
          transY += fluxoHeight/2;
        atual.setAttribute("transform", `translate(${transX}, ${transY})`);
        atual.setAttribute("style", "opacity: 1;");
      }
  }
}

const desenhaGrafoRequisitos = function ( escolhido ) {
  var groups = document.getElementsByTagName('g');
  for(var i=1; i<groups.length; i++){
    groups[i].setAttribute("style", "opacity: 0;");
  }
  var transX = fluxoWidth/2 - boxWidth/2 - lastdx - Number(escolhido.firstChild.attributes.x.value);
  var transY = fluxoHeight/2 - boxHeight/2 - Number(escolhido.firstChild.attributes.y.value);
  escolhido.setAttribute("transform", `translate(${transX}, ${transY})`);
  escolhido.setAttribute("style", "opacity: 1;");
  
  var arvoreLibera = largura(escolhido, 'libera');
  var arvoreRequer = largura(escolhido, 'requer');

  console.log("libera", arvoreLibera);
  console.log("requer", arvoreRequer);

  desenhaArvore(arvoreLibera, 'libera');
  desenhaArvore(arvoreRequer, 'requer');
  /*
  for(var i=0; i<arvoreLibera.tamanho; i++){
    if(arvoreLibera[i])
      for(var j=0; j<arvoreLibera[i].length; j++){
        var atual = document.getElementById(arvoreLibera[i][j][0]);
        var transX = (j+1)*fluxoWidth/(arvoreLibera[i].length+1) - boxWidth/2 - lastdx - Number(atual.firstChild.attributes.x.value);
        var transY = fluxoHeight/2 + (i+1)*(fluxoHeight/2)/(arvoreLibera.tamanho+1)
                          - boxHeight/2 - Number(atual.firstChild.attributes.y.value);
        atual.setAttribute("transform", `translate(${transX}, ${transY})`);
        atual.setAttribute("style", "opacity: 1;");
      }
  }

  for(var i=0; i<arvoreRequer.tamanho; i++){
    if(arvoreRequer[i])
      for(var j=0; j<arvoreRequer[i].length; j++){
        var atual = document.getElementById(arvoreRequer[i][j][0]);
        var transX = (j+1)*fluxoWidth/(arvoreRequer[i].length+1) - boxWidth/2 - lastdx - Number(atual.firstChild.attributes.x.value);
        var transY = (i+1)*(fluxoHeight/2)/(arvoreRequer.tamanho+1)
                          - boxHeight/2 - Number(atual.firstChild.attributes.y.value);
        atual.setAttribute("transform", `translate(${transX}, ${transY})`);
        atual.setAttribute("style", "opacity: 1;");
      }
  }*/
}

var drag = false;
var click = false;
var startx;
var dx;
var lastdx = 0;
var group;

const clickEvent = function (e) {
  click = true;
  startx = e.clientX;
}

const touchEvent = function (e) {
  click = true;
  startx = e.touches[0].clientX;
}

const moveMouseEvent = function (e) {
  if(click){
    drag = true;
    dx = e.clientX - startx + lastdx;
    if(!isNaN(dx))
      group.setAttribute("transform", "translate("+dx+")");
  }
}

const moveTouchEvent = function (e) {
  if(click){
    drag = true;
    dx = e.touches[0].clientX - startx + lastdx;
    if(!isNaN(dx))
      group.setAttribute("transform", "translate("+dx+")");

  }
}

const releaseEvent = function (e) {
  if(drag){
    lastdx = dx;
  } else {
    if(e.target.tagName !== 'svg'){
      desenhaGrafoRequisitos(e.target.parentNode);
    }
  }

  click = false;
  drag = false;
}

const setListeners = function ( fluxograma ) {
    fluxograma.addEventListener('mousedown', clickEvent);
    fluxograma.addEventListener('touchstart', touchEvent);

    fluxograma.addEventListener('mousemove', moveMouseEvent);
    fluxograma.addEventListener('touchmove', moveTouchEvent);

    fluxograma.addEventListener('mouseup', releaseEvent);
    fluxograma.addEventListener('mouseleave', releaseEvent);
    fluxograma.addEventListener('touchend', releaseEvent);
}