#pragma once

#include "ofMain.h"

namespace Xmapper {
	class Sphere {
		public:
			double radius = 10;
			bool sphereDrawingFlag = false;
			ofColor sphereColor;
			ofVec2f spherePosition;
		
			void set(ofColor c, ofVec2f v) {
				sphereColor = c;
				spherePosition = v;
			};
			void update(float update_val=0.1) {
				radius += update_val;
			};
			void draw() {
				ofSetColor(sphereColor);
				ofCircle(spherePosition.x, spherePosition.y, radius);
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
	
		const int SPHERE_NUM = 6;
		const int DefaultValueRadius = 10;
		const int MaxRadius = 30;
		ofColor spheresColor[3];
		Xmapper::Sphere sphere[6];
};