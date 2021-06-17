var windowWidth = window.innerWidth;
var windowHeight = window.innerHeight;

var lineMaterial = new THREE.LineBasicMaterial( { color: 0xcccccc, linewidth: 1 } );
var pointMaterial = new THREE.PointsMaterial( { color: 0x000000, size: 8 } );
var pointMaterials = [
    new THREE.PointsMaterial( { color: 0xff0000, size: 8 } ),
    new THREE.PointsMaterial( { color: 0x0000ff, size: 8 } ),
    new THREE.PointsMaterial( { color: 0x00ff00, size: 8 } )
];

var scene = new THREE.Scene();
var camera = new THREE.OrthographicCamera( windowWidth / -2, windowWidth / 2,  windowHeight / 2,  windowHeight / -2 );
camera.position.set( 0, 0, 1 );
camera.lookAt( 0, 0, 0 );

var renderer = new THREE.WebGLRenderer({ antialias: true});
renderer.setSize( window.windowWidth, window.windowHeight );
renderer.setClearColor( 0xffffff , 1 );
document.body.appendChild( renderer.domElement );


function generateAxis(x, y, z, material) {
    var geometry = new THREE.Geometry();
    geometry.vertices.push(new THREE.Vector3( -x, -y, -z) );
    geometry.vertices.push(new THREE.Vector3( x, y, z) );

    return new THREE.Line( geometry, material );
}

scene.add( generateAxis(windowWidth, 0, 0, lineMaterial) );
scene.add( generateAxis(0, windowHeight, 0, lineMaterial) );

var render = function () {
    requestAnimationFrame( render );
    renderer.render(scene, camera);
};

render();

