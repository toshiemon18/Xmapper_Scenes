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
	
}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::configureSpheres() {
	// Generate sphere positions
	for (int i = 0; i < 6; i++) {
		int n = i / 2;
		float x = ofRandom(-(1 + n) / 4 * ofGetWidth(), (1 + n) / 4 * ofGetWidth());
		float y = ofRandom((1 + n) / 6 * ofGetHeight(), (1 + n) / 3 * ofGetHeight());
		ofVec2f v(x, y);
		sphere[i].set(spheresColor[(int)ofRandomf()%3], v);
	}
	
	// Shuffle ofVec2f array elements
	int n = sizeof(sphere) / sizeof(sphere[0]);
	for (int i = 0; i < n; i++) {
		int j = ofRandom(6);
		Xmapper::Sphere tmp = sphere[i];
		sphere[i] = sphere[j];
		sphere[j] = tmp;
	}
}