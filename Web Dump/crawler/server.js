const express = require('express');
const app = express();
const util = require('util');
const aranhaM = require('./aranhaDasMaterias.js');
const aranhaC = require('./aranhaDosCursos.js');
const port = 8080;
const router = express.Router();

app.set('trust proxy', true);
function logRequest (request, response, next) {
	console.log(request.ip + " - " + request.url);
	next();
}

app.use(logRequest);
app.use('/css', express.static('css'));
app.use(express.static('view'));
app.use('/js', express.static('js'));

const requestHandler = (request, response) => {
	response.sendFile('index.html');
}
app.get('/', requestHandler);

router.get('/:id', function (request, response){
	var json = {};
	var link = request.params.id;
	aranhaM.getJSON(link).then((val)=>{
		json = val;
		response.json(json);
	}).catch(errorJSON);
})

app.use('/curso', router);


const coursesList = (request, response) => {
	var resultado;
	aranhaC.getCourses().then((val)=>{
		resultado = val;
		response.json(resultado);
	}).catch(errorJSON);
}
app.get('/cursos', coursesList);

app.listen(port, () => {
	  console.log('Server open on ' + port);
});

const errorJSON = function () {}
