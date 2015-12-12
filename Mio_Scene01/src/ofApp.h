#pragma once

#include "ofMain.h"

namespace Xmapper {
	class Sphere {
		public:
			double radius = 5;
			bool sphereDrawingFlag = false;
			ofColor sphereColor;
			ofVec2f spherePositionVec;
		
			void set(ofColor c, ofVec2f v) {
				sphereColor = c;
				spherePositionVec = v;
			};
		
		private:
			void update(float update_val=3) {
				radius += update_val;
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
		const int MaxRadius = 60;
		ofColor spheresColor[3];
		Xmapper::Sphere sphere[6];
};