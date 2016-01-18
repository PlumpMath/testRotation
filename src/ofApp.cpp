#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    auto joinBranch = ofNode();
    auto oldBranch = ofNode();
    auto newBranch = ofNode();
    
    oldBranch.setPosition(150, 700, 0);
    oldBranch.move(ofVec3f(0, -100, 0));
    mesh.addVertex(oldBranch.getGlobalPosition());
    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
    
    for(int i = 0; i < 4; i++){
        joinBranch = ofNode();
        joinBranch.setParent(oldBranch);
        joinBranch.roll(25.0);
        
        newBranch = ofNode();
        newBranch.setParent(joinBranch);
        newBranch.move(0, -100.0, 0);
        
        mesh.addVertex(newBranch.getGlobalPosition());
        mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
        
        //reassign oldBranch value
        oldBranch = newBranch;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    mesh.draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
