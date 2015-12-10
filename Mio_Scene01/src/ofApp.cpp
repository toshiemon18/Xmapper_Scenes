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
	for (int i = 0; i < 6; i++) {
		spherePositionVec[i].set(ofRandom(<#float val0#>, <#float val1#>), 0);
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}