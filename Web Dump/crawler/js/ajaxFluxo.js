
fluxogramaAjax = new XMLHttpRequest();
var curso = {};

var fluxoWidth;
var fluxoHeight = 490;

const desenhaFluxograma = function() {
  document.getElementById('fluxograma').remove();
  var div = document.createElement('div');
  div.id = "fluxograma";
  document.getElementsByClassName("tela")[0].appendChild(div);

  var loader = document.createElement('div');
  loader.setAttribute('class', 'loader');
  div.appendChild(loader);
  var fluxograma = document.createElementNS("http://www.w3.org/2000/svg", "svg");
  fluxoWidth = div.offsetWidth-20;
  fluxograma.setAttribute('width', fluxoWidth);
  fluxograma.setAttribute('height', fluxoHeight);
  div.appendChild(fluxograma);
}

const desenhaLoading = function () {
  document.getElementsByTagName('body')[0].setAttribute('style', 'cursor: progress;')
  var fluxograma = document.getElementById('fluxograma');
  fluxograma.setAttribute('style', 'opacity: 0.3;');
  var loader = document.getElementsByClassName('loader')[0];
  var caixa = document.createElementNS("http://www.w3.org/2000/svg", "svg");
  caixa.setAttribute('class', 'loader');
  caixa.setAttribute('viewBox', '-25 -25 100 100');
  var circFora = document.createElementNS("http://www.w3.org/2000/svg", "circle");
  circFora.setAttribute('r', '20');
  circFora.setAttribute('fill','none');
  circFora.setAttribute('stroke-width','2');
  circFora.setAttribute('class','loader-out');
  circFora.setAttribute('cx','0');
  circFora.setAttribute('cy','0');
  caixa.appendChild(circFora);
  var circDentro = document.createElementNS("http://www.w3.org/2000/svg", "circle");
  circDentro.setAttribute('r', '16');
  circDentro.setAttribute('fill','none');
  circDentro.setAttribute('stroke-width','2');
  circDentro.setAttribute('class','loader-in');
  circDentro.setAttribute('cx','0');
  circDentro.setAttribute('cy','0');
  caixa.appendChild(circDentro);
  loader.appendChild(caixa);
}

const apagaLoading = function () {
  document.getElementsByTagName('body')[0].setAttribute('style', '')
  var loader = document.getElementsByClassName('loader')[0];
  while (loader.firstChild) {
    loader.removeChild(loader.firstChild);
  }
  var fluxograma = document.getElementById('fluxograma');
  fluxograma.setAttribute('style', 'opacity: 1.0;');
}

const ajaxFluxoEstados = function () {
  if(fluxogramaAjax.readyState === 1){
    desenhaFluxograma();
    //Loading image
    desenhaLoading();
  }else if(fluxogramaAjax.readyState === 4){
    apagaLoading();
    var select = document.getElementsByTagName('select');
    select[0].disabled = false;

    if (fluxogramaAjax.status === 200) {
      curso = JSON.parse(fluxogramaAjax.responseText);
      generateFlowchart(curso);
    } else {
      alert("Não pôde encontrar o fluxograma!! Erro: " + fluxogramaAjax.status);
    }

  }
}

fluxogramaAjax.onreadystatechange = ajaxFluxoEstados;

const selectTrigger = function () {
  var select = document.getElementsByTagName('select');
  var escolhido = select[0].value;
  if(escolhido !== ""){
    var link = "/curso/"+escolhido;
    fluxogramaAjax.open('GET', link);
    fluxogramaAjax.send();
    select[0].disabled = true;
  }
}

