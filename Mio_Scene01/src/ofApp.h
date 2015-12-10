#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofColor xmasSpheresColor[3];
		ofVec2f spherePositionVec[6];
};