#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// General settring
	ofEnableSmoothing();
	ofSetCircleResolution(64);
	ofBackground(0);
	
	// Set sphere colors
	spheresColor[0].setHex(0x05E3E3); // 青
	spheresColor[1].setHex(0x0AD100); // 緑
	spheresColor[2].setHex(0xFF3D84); // 赤
	spheresColor[3].setHex(0xDAF23A); // 黄色
	
	// Set sphere position
	configureSpheres();
}

//--------------------------------------------------------------
// isSphereUpdateがtrue返してきたらconfigureSpheresを呼び出す
// そうじゃなかったら直径を更新する
// i番目の玉飾りの直径が45を超えたらi+1番目の玉飾りの描画フラグを立てる
void ofApp::update(){
	if (isSphereUpdate()) {
//		for (int i = 0; i < SPHERE_NUM; i++) {
//			if (sphere[i].spherePosition.y < ofGetHeight()) {
//				sphere[i].fall();
//			}
//		}
		configureSpheres();
	}
	else {
		for (int i = 0; i < SPHERE_NUM; i++) {
			if (sphere[i].sphereDrawingFlag) {
				if (sphere[i].radius < MaxRadius) {
					sphere[i].update();
				}
				if (sphere[i].radius >= 15) {
					sphere[i + 1].sphereDrawingFlag = true;
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	drawBaseTree();
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2.0, 0);
	for (int i = 0; i < SPHERE_NUM; i++) {
		if (sphere[i].sphereDrawingFlag) {
			sphere[i].draw();
		}
	}
	ofPopMatrix();
}

//--------------------------------------------------------------
// 玉飾りの個数分設定をする
// 配列の要素1番目のsphereDrawingFlagをtrueにする
void ofApp::configureSpheres() {
	// Generate sphere positions
	for (int i = 0; i < SPHERE_NUM; i++) {
		int n = i / 2;
		float width = ofGetWidth() / 2;
		float height = ofGetHeight() - 50;
		float x; // = ofRandom(-float(1 + n) / 4.0 * width, float(1 + n) / 4.0 * width);
		float y = ofRandom(float(1 + n) / 6.0 * height, float(1 + n) / 3.0 * height);
		
		if (i % 2 == 0) { x = ofRandom(i * 35, float(1 + n) / 4.0 * width - 50); }
		else { x = ofRandom(-float(1 + n) / 4.0 * width + 50, (i/2.0) * 30); }
		ofPoint v(x, y);
		sphere[i].set(spheresColor[(int)ofRandom(100)%4], v);
		sphere[i].radius = DefaultValueRadius;
		sphere[i].sphereDrawingFlag = false;
		if (i == 0) { sphere[i].sphereDrawingFlag = true; }
	}
	
	// Shuffle ofVec2f array elements
	for (int i = 0; i < SPHERE_NUM; i++) {
		int j = ofRandom(6);
		Xmapper::Sphere tmp = sphere[i];
		sphere[i] = sphere[j];
		sphere[j] = tmp;
	}
}

//--------------------------------------------------------------
// すべての玉飾りが描画されたならリセットフラグをtrueにして返す
bool ofApp::isSphereUpdate() {
	bool reset_flag = false;
	for (int i = 0; i < SPHERE_NUM; i++) {
		if (sphere[i].radius > MaxRadius) {
			reset_flag = true;
		}
		else {
			reset_flag = false;
			break;
		}
	}
	
	return reset_flag;
}

//--------------------------------------------------------------
// クリスマスツリー表示
void ofApp::drawBaseTree() {
	ofSetColor(0, 109, 0);
	float h_width = ofGetWidth() / 2.0;
	float height = ofGetHeight() - 100;
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2.0, 0);
		ofBeginShape();
			ofVertex(0, 0);
			ofVertex(-(1 / 3.0) * h_width, 1 / 3.0 * height);
			ofVertex(-(1 / 6.0) * h_width, 1 / 3.0 * height);
	
			ofVertex(-(2 / 3.0) * h_width, 2 / 3.0 * height);
			ofVertex(-(1 / 3.0) * h_width, 2 / 3.0 * height);
	
			ofVertex(-h_width, height);
			ofVertex(h_width, height);
	
			ofVertex(1 / 3.0 * h_width, 2 / 3.0 * height);
			ofVertex(2 / 3.0 * h_width, 2 / 3.0 * height);
	
			ofVertex(1 / 6.0 * h_width, 1 / 3.0 * height);
			ofVertex(1 / 3.0 * h_width, 1 / 3.0 * height);
			ofVertex(0, 0);
		ofEndShape();
	ofPopMatrix();
}
