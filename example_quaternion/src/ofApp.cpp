#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ukf.init(0.00001, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
	m.makeIdentityMatrix();
	m.rotate(ofMap(mouseX, 0, ofGetWidth(), -180, 180), 1, 0, 0);
	m.rotate(ofMap(mouseY, 0, ofGetHeight(), -180, 180), 0, 1, 0);
	m.rotate(ofMap(ofGetElapsedTimef(), 0, 1, 0, 180), 0, 1, 1);
	
	ofQuaternion q;
	q = m.getRotate();
	
	ukf.update(q);
	ofQuaternion qPredicted = ukf.getEstimation();
	
	mPredicted.makeIdentityMatrix();
	mPredicted.setRotate(qPredicted);
	//ofLogWarning() << q;
	//ofLogWarning() << qPredicted;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(54);
	
	cam.begin();
	ofPushMatrix();
	ofTranslate(-200, 0, 0);
	glMultMatrixf((GLfloat*)m.getPtr());
	ofDrawAxis(100);
	ofPopMatrix();
	
	ofPushMatrix();
	ofTranslate(200, 0, 0);
	glMultMatrixf((GLfloat*)mPredicted.getPtr());
	ofDrawAxis(100);
	ofPopMatrix();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
