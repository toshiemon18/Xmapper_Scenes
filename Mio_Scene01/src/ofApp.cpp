#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// General settring
	ofEnableSmoothing();
	ofBackground(0, 109, 0);
	
	// Set sphere colors
	spheresColor[0].set(0, 0, 0); // 青
	spheresColor[1].set(0, 0, 0); // 緑
	spheresColor[2].set(0, 0, 0); // 赤
	
	// Set sphere position
	configureSpheres();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (isSphereUpdate()) {
		configureSpheres();
	}
	else {
		for (int i = 0; i < SPHERE_NUM; i++) {
			if (sphere[i].sphereDrawingFlag) {
				sphere[i].update();
				if (sphere[i].radius >= 45) {
					
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}

void ofApp::configureSpheres() {
	// Generate sphere positions
	for (int i = 0; i < SPHERE_NUM; i++) {
		int n = i / 2;
		float x = ofRandom(-(1 + n) / 4 * ofGetWidth(), (1 + n) / 4 * ofGetWidth());
		float y = ofRandom((1 + n) / 6 * ofGetHeight(), (1 + n) / 3 * ofGetHeight());
		ofVec2f v(x, y);
		sphere[i].set(spheresColor[(int)ofRandomf()%3], v);
		if (i == 0) { sphere[i].sphereDrawingFlag = true; }
	}
	
	// Shuffle ofVec2f array elements
	for (int i = 0; i < SPHERE_NUM; i++) {
		int j = ofRandom(6);
		Xmapper::Sphere tmp = sphere[i];
		sphere[i] = sphere[j];
		sphere[j] = tmp;
	}
}

bool ofApp::isSphereUpdate() {
	bool reset_frag = true;
	for (int i = 0; i < SPHERE_NUM; i++) {
		reset_frag = reset_frag & sphere[i].sphereDrawingFlag;
	}
	
	return reset_frag;
}