#pragma once

#include "ofMain.h"

namespace Xmapper {
	class Sphere {
		public:
			double radius = 3;
			bool sphereDrawingFlag = false;
			ofColor sphereColor;
			ofVec2f spherePosition;
		
			void set(ofColor c, ofVec2f v) {
				sphereColor = c;
				spherePosition = v;
			};
			void update(float update_val=0.3) {
				radius += update_val;
			};
			void draw() {
				ofSetColor(sphereColor);
				ofCircle(spherePosition.x, spherePosition.y, radius);
			};
			void reset() {
				spherePosition.set(0, 0);
			};
	};
}

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
	private:
		void configureSpheres();
		bool isSphereUpdate();
		void drawBaseTree();
	
		const int SPHERE_NUM = 6;
		const int DefaultValueRadius = 3;
		const int MaxRadius = 30;
		ofColor spheresColor[4];
		Xmapper::Sphere sphere[6];
};