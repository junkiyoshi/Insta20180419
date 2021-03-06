#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int min_size = 3;
	int max_size = 35;
	int number_of_circle = 512 + 128;
	for (int i = 0; i < number_of_circle; i++) {

		float size = ofRandom(min_size, max_size) + ofMap(ofNoise(ofRandom(512) * 0.005, ofGetFrameNum() * 0.001), 0, 1, -max_size, max_size);
		float x = ofRandom(0, ofGetWidth());
		float y = ofRandom(0, ofGetHeight());
		x += ofMap(ofNoise(ofRandom(number_of_circle) * 0.005, ofGetFrameNum() * 0.005), 0, 1, -size, size);
		y += ofMap(ofNoise(ofRandom(number_of_circle) * 0.005, ofGetFrameNum() * 0.005), 0, 1, -size, size);

		ofColor circle_color;
		circle_color.setHsb(((int)ofPoint(x, y).length() - ofGetFrameNum()) % 255, 255, 255);
		ofSetColor(circle_color, ofMap(size, min_size, max_size, 255, 25));

		ofDrawCircle(x, y, size);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}