function onMousePress(e) {
    if(controller.state !== KMEANS.START)
        return;

    //datgui
    if(e.clientX>gui.domElement.offsetLeft-10 && e.clientY < 100)
        return;

    let point = new THREE.Vector3();
    point.set(
        (e.clientX / window.innerWidth) * 2 - 1,
        - (e.clientY / window.innerHeight) * 2 + 1,
        0
    );
    point.unproject(camera);
    point.z = 0;

    points.push(point);

    var geometry = new THREE.Geometry();
    geometry.vertices.push(point);
    scene.add( new THREE.Points( geometry, pointMaterial) );
}

function reset() {
    while(scene.children.length > 0){
        scene.remove(scene.children[0]);
    }
    scene.add( generateAxis(windowWidth, 0, 0, lineMaterial) );
    scene.add( generateAxis(0, windowHeight, 0, lineMaterial) );
}

function cleanAndDrawNewScene() {
    reset();
    points.forEach((item) => {
        var geometry = new THREE.Geometry();
        geometry.vertices.push(item);
        scene.add(new THREE.Points( geometry, pointMaterial));
    });

    centers.forEach((item, index) => {
        var geometry = new THREE.Geometry();
        geometry.vertices.push(item);
        scene.add(new THREE.Points( geometry, pointMaterials[index%3]));
    });
}

function cleanAndDrawDividedScene() {
    reset();
    pointClusters.forEach((pts, index)=> {
        pts.forEach((item) => {
            var geometry = new THREE.Geometry();
            geometry.vertices.push(item);
            scene.add(new THREE.Points(geometry, pointMaterials[index]));
        });
    });

    centers.forEach((item, index) => {
        var geometry = new THREE.Geometry();
        geometry.vertices.push(item);
        scene.add(new THREE.Points( geometry, pointMaterials[index%3]));
    });
}

function cleanAndDrawDividedWithLineScene() {
    reset();
    pointClusters.forEach((pts, index)=> {
        pts.forEach((item) => {
            var geometry = new THREE.Geometry();
            geometry.vertices.push(item);
            scene.add(new THREE.Points(geometry, pointMaterials[index]));
        });
    });



    centers.forEach((item, index) => {
        var geometry = new THREE.Geometry();
        geometry.vertices.push(item);
        scene.add(new THREE.Points( geometry, pointMaterials[index%3]));
    });
}

window.addEventListener( 'contextmenu', reset, false );
window.addEventListener( 'mousedown', onMousePress, false );