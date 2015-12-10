#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofBackground(0, 109, 0);
	
	// set sphere colors
	xmasSpheresColor[0].set(0, 0, 0); // 青
	xmasSpheresColor[1].set(0, 0, 0); // 緑
	xmasSpheresColor[2].set(0, 0, 0); // 赤
	
	// set sphere position
	configureSpherePositions();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::configureSpherePositions() {
	// generate sphere positions
	for (int i = 0; i < 6; i++) {
		int n = i / 2;
		float x = ofRandom(-(1 + n) / 4 * ofGetWidth(), (1 + n) / 4 * ofGetWidth());
		float y = ofRandom((1 + n) / 6 * ofGetHeight(), (1 + n) / 3 * ofGetHeight());
		spherePositionVec[i].set(x, y);
	}
	
	// shuffle ofVec2f array elements
	int n = sizeof(spherePositionVec) / sizeof(spherePositionVec[0]);
	for (int i = 0; i < n; i++) {
		int j = ofRandom(6);
		ofVec2f tmp = spherePositionVec[i];
		spherePositionVec[i] = spherePositionVec[j];
		spherePositionVec[j] = tmp;
	}
}

