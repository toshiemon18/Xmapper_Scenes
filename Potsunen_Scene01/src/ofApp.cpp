#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetCircleResolution(64);
	ofBackground(0, 109, 0);
	ofEnableAlphaBlending();
	
	world.init();
	world.setGravity(0, 1);
	world.createBounds(0, -100, ofGetWidth(), ofGetHeight() - 100);
	world.setFPS(30);
	world.registerGrabbing();
	
	snow.load("snow.png");
	snow.setAnchorPercent(0.5, 0.5);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofRandom(0, 100) < 5) {
		float r = ofRandom(25, 40);
		ofVec2f v = generatePositionParameters();
		
		snows.push_back(ofPtr<Xmapper::XmapperSnow>(new Xmapper::XmapperSnow));
		snows.back().get() -> setPhysics(1.0, 0.5, 0.1);
		snows.back().get() -> setVelocity(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
		snows.back().get() -> setup(world.getWorld(), v, r);
	}
	world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	for (int i = 0; i < snows.size(); i++) {
//		snows[i].get() -> draw();
		ofPoint p = snows[i].get() -> getPosition();
		float size = snows[i].get() -> getRadius() * 5.0;
		snow.draw(p, size, size);
	}
	world.draw();
}

//--------------------------------------------------------------
ofVec2f ofApp::generatePositionParameters() {
	float x;
	x = ofRandom(250, 550);
	ofVec2f v(x, -70);
	return v;
}

//--------------------------------------------------------------
void ofApp::drawTreeShadow() {
	
}