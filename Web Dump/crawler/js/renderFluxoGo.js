
const linkaRequisitos = function (materia) {
    if (materia.requisitos[0] == "")
      return;
    return ({codigo: materia.codigo, requisitos: materia.requisitos});
  }
  
const dadoCodigoRetornaNome = function (codigo, curso) {
  var i=1;
  while (curso.semesters[i].titulo.match(/.*Período$/)) {
    for(var j=0; j<curso.semesters[i].materias.length; j++){
      if(curso.semesters[i].materias[j] && curso.semesters[i].materias[j].codigo == codigo)
        return curso.semesters[i].materias[j].nome;
    }
    i++;
  }
  return "";
}

const formataRequisitosEmLinks = function (requisitos, curso) {
  var links = [];
  for(var i=0; i<requisitos.length; i++)
    for(var j=0; j<requisitos[i].requisitos.length; j++){
      if(requisitos[i].requisitos[j].length === 1)
        links = links.concat({from: requisitos[i].requisitos[j][0], to: requisitos[i].codigo});
      else{
        var reqEquivalente = requisitos[i].requisitos[j].filter((val)=>{
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
        links = links.concat({from: reqEquivalente[0], to: requisitos[i].codigo});
      }
    }
      
  return links;
}
  
const formataMaterias = function (materias, periodo) {
  var resultado = [];
  for (var i=0; i<materias.length; i++)
    resultado = resultado.concat({key: materias[i].codigo, nome: materias[i].nome, color: materias[i].cor, group: periodo});
  return resultado;
}


const generateFlowchartGo = function ( curso ) {
  var $ = go.GraphObject.make;
  var diagram = $(go.Diagram, "fluxograma",
    {layout: $(go.GridLayout, {wrappingWidth: 2000})});
  diagram.nodeTemplate = 
    $(go.Node, "Auto",
      new go.Binding("location", "loc", go.Point.parse).makeTwoWay(go.Point.stringify),
      $(go.Shape, "RoundedRectangle", { strokeWidth: 2, stroke: null, name: "SHAPE" },
        new go.Binding("fill","color")),
      $(go.TextBlock, "", {margin: 5, height:40, width:110, stroke: "white", font: "bold 11px sans-serif"},
        new go.Binding("text", "nome"))
    );
  diagram.linkTemplate = 
    $(go.Link,
      { curve: go.Link.Bezier },
      $(go.Shape),
      $(go.Shape, { toArrow: "Standard" })
    );
  diagram.groupTemplate = 
    $(go.Group, "Vertical",
      {
        layout: $(go.GridLayout,  // automatically lay out the lane's subgraph
        {
          wrappingColumn: 1,
          cellSize: new go.Size(1, 1),
          spacing: new go.Size(5, 5),
          alignment: go.GridLayout.Position,
          comparer: function(a, b) {  // can re-order within a lane
            var ay = a.location.y;
            var by = b.location.y;
            if (isNaN(ay) || isNaN(by)) return 0;
            if (ay < by) return -1;
            if (ay > by) return 1;
            return 0;
          }
        })
      },
      $(go.Panel, "Auto",
        $(go.Shape, "RoundedRectangle",  // surrounds the Placeholder
          { parameter1: 14,
            fill: "rgba(128,128,200,0.1)" }),
        $(go.Placeholder,    // represents the area of all member parts,
          { padding: 2})  // with some extra padding around them
        ),
      $(go.TextBlock,         // group title
        { alignment: go.Spot.Right, font: "Bold 12pt Sans-Serif" },
        new go.Binding("text", "key"))
    );
  var model = $(go.Model);
  var i = 1;
  var data = [];
  var requisitos = [];
  while (curso.semesters[i].titulo.match(/.*Período$/)) {
    var materias = curso.semesters[i].materias;
    data = data.concat({key: i, isGroup: true, loc: `${(i-1)*150+10}, 10`});
    data = data.concat(formataMaterias(materias, i));
    requisitos = requisitos.concat((materias.map(linkaRequisitos)).filter((e)=>e!=null));
    i++;
  }
  var links = formataRequisitosEmLinks(requisitos, curso);
  var model = $(go.GraphLinksModel);
  model.nodeDataArray = data;
  model.linkDataArray = links;
  diagram.isReadOnly = true;
  diagram.model = model;
}