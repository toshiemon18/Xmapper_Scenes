#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// General settring
	ofEnableSmoothing();
	ofSetCircleResolution(64);
	ofBackground(0, 109, 0);
	
	// Set sphere colors
	spheresColor[0].set(0, 0, 0); // 青
	spheresColor[1].set(0, 0, 0); // 緑
	spheresColor[2].set(0, 0, 0); // 赤
	
	// Set sphere position
	configureSpheres();
}

//--------------------------------------------------------------
// isSphereUpdateがtrue返してきたらconfigureSpheresを呼び出す
// そうじゃなかったら直径を更新する
// i番目の玉飾りの直径が45を超えたらi+1番目の玉飾りの描画フラグを立てる
void ofApp::update(){
//	if (isSphereUpdate()) {
//		configureSpheres();
//	}
//	else {
		for (int i = 0; i < SPHERE_NUM; i++) {
			if (sphere[i].sphereDrawingFlag) {
				if (sphere[i].radius <= MaxRadius) { sphere[i].update(); }
				if (sphere[i].radius >= 20 && i != SPHERE_NUM - 1) {
					sphere[i + 1].sphereDrawingFlag = true;
				}
			}
		}
//	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < SPHERE_NUM; i++) {
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2.0, 0);
		if (sphere[i].sphereDrawingFlag) {
			ofNoFill();
			sphere[i].draw();
		}
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
// 玉飾りの個数分設定をする
// 配列の要素1番目のsphereDrawingFlagをtrueにする
void ofApp::configureSpheres() {
	// Generate sphere positions
	float width = ofGetWidth() / 2.0;
	ofPoint p(ofRandom(-1/4*width, 0), ofRandom(1/6*ofGetHeight(), 1/3*ofGetHeight()));
	sphere[0].set(spheresColor[(int)ofRandomf()%3], p);
	sphere[0].sphereDrawingFlag = true;
	
	p.set(ofRandom(0, 1/4*width), ofRandom(1/6*ofGetHeight(), 1/3*ofGetHeight()));
	sphere[1].set(spheresColor[(int)ofRandomf()%3], p);
	
	p.set(ofRandom(-1/2*width, 0), ofRandom(1/2*ofGetHeight(), 2/3*ofGetHeight()));
	sphere[2].set(spheresColor[(int)ofRandomf()%3], p);
	
	p.set(ofRandom(0, 1/2*width), ofRandom(1/2*ofGetHeight(), 2/3*ofGetHeight()));
	sphere[3].set(spheresColor[(int)ofRandomf()%3], p);
	
	p.set(ofRandom(-3/4*width, 0), ofRandom(5/6*ofGetHeight(), ofGetHeight() - 100));
	sphere[4].set(spheresColor[(int)ofRandomf()%3], p);
	
	p.set(ofRandom(0, 3/4*width), ofRandom(5/6*ofGetHeight(), ofGetHeight() - 100));
	sphere[5].set(spheresColor[(int)ofRandomf()%3], p);
	
	// Shuffle ofVec2f array elements
//	for (int i = 0; i < SPHERE_NUM; i++) {
//		int j = ofRandom(6);
//		Xmapper::Sphere tmp = sphere[i];
//		sphere[i] = sphere[j];
//		sphere[j] = tmp;
//	}
}

//--------------------------------------------------------------
// すべての玉飾りが描画されたならリセットフラグをtrueにして返す
bool ofApp::isSphereUpdate() {
	bool reset_frag = false;
	for (int i = 0; i < SPHERE_NUM; i++) {
		if (sphere[i].radius >= MaxRadius && sphere[i].sphereDrawingFlag) {
			reset_frag = true;
		}
		else {
			reset_frag = false;
		}
	}
	
	return reset_frag;
}