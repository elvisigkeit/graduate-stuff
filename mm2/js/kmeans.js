var clustersElement;
var pointClusters = [];
var gui;
var centers;
var points = [];


var KMEANS = {
    START: 1,
    DIVIDE: 2,
    NEW_CENTERS: 4,
    ITERATE: 5
};

var controller = {
    state: KMEANS.START,
    Clusters: 2,
    Iteration: function () {
        if(this.state === KMEANS.START) {
            centers = generateRandomPoints(this.Clusters);
            gui.remove(clustersElement);
        }

        pointClusters = [];
        for(var i=0; i<this.Clusters; i++)
            pointClusters.push([]);

        cleanAndDrawNewScene();
        this.state = KMEANS.DIVIDE;
    },
    Next: function () {
        switch (this.state) {
            case KMEANS.DIVIDE:
                points.forEach((point)=> {
                    var greaterDistance = Infinity;
                    var greaterIndex = 0;
                    centers.forEach((center, index)=> {
                        var distance = point.distanceTo(center);
                        if(distance < greaterDistance) {
                            greaterDistance = distance;
                            greaterIndex = index;
                        }
                    });
                    pointClusters[greaterIndex].push(point);
                });
                cleanAndDrawDividedScene();
                this.state = KMEANS.NEW_CENTERS;
                break;
            case KMEANS.NEW_CENTERS:
                for(var i=0; i<this.Clusters; i++) {
                    var media = pointClusters[i].reduce((result, item)=>{
                            result.x+=item.x;
                            result.y+=item.y;
                            result.nr++;
                            return result;
                        },
                        {x: 0, y: 0, nr: 0}
                    );
                    centers[i].set(
                        media.x/media.nr,
                        media.y/media.nr,
                        0
                    );
                }
                cleanAndDrawDividedScene();
                this.state = KMEANS.ITERATE;
                break;
        }
    }
};

window.onload = function() {
    gui = new dat.GUI();

    clustersElement = gui.add(controller, 'Clusters');
    gui.add(controller, 'Iteration');
    gui.add(controller, 'Next');
};

function generateRandomPoints(nrClusters) {
    let centers = [];
    for (let i = 0; i < nrClusters; i++) {
        let center = new THREE.Vector3();
        center.set(
            THREE.Math.randFloat(windowWidth / -2, windowWidth / 2),
            THREE.Math.randFloat(windowHeight / -2, windowHeight / 2),
            0
        );
        centers.push(center);
    }
    return centers;
}