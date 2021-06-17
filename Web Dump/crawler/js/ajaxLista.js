
ajax = new XMLHttpRequest();

const inicializacoesRL = function(){
  var select = document.getElementsByTagName('select');
  select[0].disabled = true;

  ajax.open('GET', '/cursos');
  ajax.send();
  lista.disabled = true;
}

document.addEventListener('DOMContentLoaded', inicializacoesRL, false);

var cursos = [];

const ajaxListaEstados = function() {
    if(ajax.readyState === 1){
      desenhaLoading();
    }else if(ajax.readyState === 4){
      apagaLoading();
      var select = document.getElementsByTagName('select');
      if (ajax.status === 200) {
        cursos = JSON.parse(ajax.responseText);
        geraListaCursos(cursos);
      } else {
        alert("Deu merda ao encontrar o fluxograma!! Erro: " + fluxogramaAjax.status);
      }
      select[0].disabled = false;
    }
}

const geraListaCursos = function (cursos) {
  for(var i=0; i<cursos.length; i++) {
    var atual = document.createElement("OPTION");
    atual.setAttribute("value", cursos[i].link);
    var texto = document.createTextNode(cursos[i].name);
    atual.appendChild(texto);
    document.getElementById("lista").appendChild(atual);
  }
}

ajax.onreadystatechange = ajaxListaEstados;
