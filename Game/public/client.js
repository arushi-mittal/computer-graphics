import * as THREE from '/build/three.module.js';
import {OrbitControls} from '/jsm/controls/OrbitControls.js';
import Stats from '/jsm/libs/stats.module.js';
import { GLTFLoader } from '/jsm/loaders/GLTFLoader.js';

var model;
var enemy1;
var enemy2;
var bullet1;
var bullet2;
const scene = new THREE.Scene();
// scene.background = new THREE.Color(0x000000)

const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 100);
camera.position.y = 10;
camera.position.z = 3;

const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

renderer.setClearColor( 0xff0000, 0);

var light = new THREE.AmbientLight(0xffffff, 0.7);
var dlight = new THREE.DirectionalLight(0xf00000, 0.7);
dlight.castShadow = true;
scene.add(light)
scene.add(dlight)

const controls = new OrbitControls(camera, renderer.domElement);

// const geometry = new THREE.BoxGeometry();
// const material = new THREE.MeshBasicMaterial({
//     color: 0x00ff00,
//     wireframe: true
// });
// const cube = new THREE.Mesh(geometry, material);
// scene.add(cube);

var loader = new GLTFLoader();
var newLoader = new GLTFLoader();
var enemy2Loader = new GLTFLoader();
var bulletLoader1 = new GLTFLoader();
var bulletLoader2 = new GLTFLoader();
loader.load(
	'./plane.glb',
	( gltf ) => {
		// called when the resource is loaded
        model = gltf.scene;
        model.scale.set(0.1, 0.1, 0.1)
        model.rotation.y = Math.PI/2;
        model.position.y = -0.1;
        model.position.z = 4;
		scene.add(model);
	},
	( xhr ) => {
		// called while loading is progressing
		console.log( `${( xhr.loaded / xhr.total * 100 )}% loaded` );
	},
	( error ) => {
		// called when loading has errors
		console.error( 'An error happened', error );
	},

    newLoader.load(
        './enemy.glb',
        ( gltf ) => {
            // called when the resource is loaded
            enemy1 = gltf.scene;
            enemy1.scale.set(0.1, 0.1, 0.1)
            enemy1.rotation.y = Math.PI/2;
            enemy1.position.y = -0.1;
            enemy1.position.z = -5;
            enemy1.position.x = 5;
            scene.add(enemy1);
        },
        ( xhr ) => {
            // called while loading is progressing
            console.log( `${( xhr.loaded / xhr.total * 100 )}% loaded` );
        },
        ( error ) => {
            // called when loading has errors
            console.error( 'An error happened', error );
        },
    ),
    enemy2Loader.load(
        './enemy.glb',
        ( gltf ) => {
            // called when the resource is loaded
            enemy2 = gltf.scene;
            enemy2.scale.set(0.1, 0.1, 0.1)
            enemy2.rotation.y = Math.PI/2;
            enemy2.position.y = -0.1;
            enemy2.position.z = -5;
            enemy2.position.x = -5;
            scene.add(enemy2);
        },
        ( xhr ) => {
            // called while loading is progressing
            console.log( `${( xhr.loaded / xhr.total * 100 )}% loaded` );
        },
        ( error ) => {
            // called when loading has errors
            console.error( 'An error happened', error );
        },
    ),

    bulletLoader1.load(
        './missile.glb',
        ( gltf ) => {
            // called when the resource is loaded
            bullet1 = gltf.scene;
            bullet1.scale.set(0.1, 0.1, 0.1)
            bullet1.rotation.z = Math.PI/2;
            bullet1.position.y = -0.1;
            bullet1.position.z = -5;
            bullet1.position.x = 5;
            scene.add(bullet1);
        },
        ( xhr ) => {
            // called while loading is progressing
            console.log( `${( xhr.loaded / xhr.total * 100 )}% loaded` );
        },
        ( error ) => {
            // called when loading has errors
            console.error( 'An error happened', error );
        },
    ),
    bulletLoader2.load(
        './missile.glb',
        ( gltf ) => {
            // called when the resource is loaded
            bullet2 = gltf.scene;
            bullet2.scale.set(0.1, 0.1, 0.1)
            bullet2.rotation.z = Math.PI/2;
            bullet2.position.y = -0.1;
            bullet2.position.z = -5;
            bullet2.position.x = -5;
            scene.add(bullet2);
        },
        ( xhr ) => {
            // called while loading is progressing
            console.log( `${( xhr.loaded / xhr.total * 100 )}% loaded` );
        },
        ( error ) => {
            // called when loading has errors
            console.error( 'An error happened', error );
        },
    ),
);


window.addEventListener("keydown", onDocumentKeyDown, false);
function onDocumentKeyDown(event) {
    var keyCode = event.which;
    if (keyCode == 87) {
        // console.log(model.position.z);
        if (model.position.z >= -10) {
            model.position.z -= 1;
        }
    } else if (keyCode == 83) {
        // console.log(model.position.z);
        if (model.position.z <= 6) {
            model.position.z += 1;
        }
        
    } else if (keyCode == 65) {
        if (model.position.x >= -5) {
            model.position.x -= 1;
        }
    } else if (keyCode == 68) {
        if (model.position.x <= 5) {
            model.position.x += 1;
        }
        // console.log(model.position.x);
        // console.log(model.position.y);
        // console.log(model.position.z);
        
    } 
    // else if (keyCode == 32) {
    //     model.position.set(0, 0, 0);
    // }
};

window.addEventListener('resize', () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
    render();
}, false);

const stats = Stats();
document.body.appendChild(stats.dom);

var animate = function () {
    requestAnimationFrame(animate);
    // model.rotation.x += 0.01;
    // model.rotation.y += 0.01;
    controls.update();
    render();
    stats.update();
};

var moveBullet = function () {
    requestAnimationFrame(moveBullet);
    bullet1.position.z += 0.04;
    bullet2.position.z += 0.04;
    if (bullet1.position.z >= 6) {
        bullet1.position.z = -5;
    }
    if (bullet2.position.z >= 6) {
        bullet2.position.z = -5;
    }
    controls.update();
    render();
    stats.update();
}

var checkCollision = function () {
    requestAnimationFrame(checkCollision);
    if (bullet1.position.x <= model.position.x - 3 && bullet1.position.x >= model.position.x + 3) {
        console.log("Hello")

    }
    controls.update();
    render();
    stats.update();
}

function render() {
    renderer.render(scene, camera);
}

animate();
moveBullet();
checkCollision();