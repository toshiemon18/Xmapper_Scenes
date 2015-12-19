#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

namespace Xmapper {
	class XmapperSnow : public ofxBox2dCircle {
		public:
			ofColor snowColor = (255, 255, 255);
			void draw() {
				float radius = getRadius();
				glPushMatrix();
				glTranslatef(getPosition().x, getPosition().y, 0);
				ofFill();
				ofSetColor(snowColor);
				ofCircle(0, 0, radius);
				glPopMatrix();
			};
	};
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
		ofVec2f generatePositionParameters();
		void drawTreeShadow();
	
		ofxBox2d world;
		vector <ofPtr<Xmapper::XmapperSnow>> snows;
};
