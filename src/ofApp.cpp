#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    ofNode root = ofNode();
    root.setPosition(450, 700, 0);
    auto branch = Branch();
    branch.setParent(root);
    
    string _instruction = "F+F+F";
    
    for (int i = 0; i < _instruction.length(); i++) {
        char c = _instruction[i];
        if (c == 'F') {
            if(mesh.getNumVertices() == 0){
                //add the first branch to the root
                branch.preTranslate(ofVec3f(0, -100, 0));
                mesh.addVertex(branch.getGlobalPosition());
                mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
            }else{
                //add a new branch
                auto newBranch = Branch();
                newBranch.setParent(branch);
                newBranch.move(ofVec3f(0, -100,0));
                mesh.addVertex(newBranch.getGlobalPosition());
                mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
                
                branch.preTranslate(ofVec3f(0, -100, 0));
            };
        }else if( c == 'G') {
            branch.move(ofVec3f(0, -100, 0));
        }else if (c == '+') {
            branch.roll(25.00);
        }
        else if (c == '-') {
            branch.roll(-25.00);
        }
        else if (c == '[') {
            bookmarks.push_back(branch);
        }
        else if (c == ']') {
            branch = bookmarks.back();
            bookmarks.pop_back();
        }
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
