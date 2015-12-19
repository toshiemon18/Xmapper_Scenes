#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetCircleResolution(64);
	ofBackground(0, 109, 0);
	
	world.init();
	world.setGravity(0, 0.5);
	world.createBounds(0, -70, ofGetWidth(), ofGetHeight());
	world.setFPS(30);
	world.registerGrabbing();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofRandom(0, 100) < 40) {
		float r = ofRandom(5, 40);
		ofVec2f v = generatePositionParameters();
		
		snows.push_back(ofPtr<Xmapper::XmapperSnow>(new Xmapper::XmapperSnow));
		snows.back().get() -> setPhysics(1.0, 0.8, 0.5);
		snows.back().get() -> setup(world.getWorld(), v, r);
	}
	world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < snows.size(); i++) {
		snows[i].get() -> draw();
	}
	world.draw();
}

//--------------------------------------------------------------
ofVec2f ofApp::generatePositionParameters() {
	float x;
	x = ofRandom(250, 550);
	ofVec2f v(x, -50);
	return v;
}

//--------------------------------------------------------------
void ofApp::drawTreeShadow() {
	
}