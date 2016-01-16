#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    
//    ofNode first = ofNode();
//    first.setPosition(150, 700, 0);
//    first.move(ofVec3f(0, -100, 0));
//    mesh.addVertex(first.getGlobalPosition());
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
//    
//    auto b = Branch();
//    b.setParent(first);
//    b.roll(25.0);
//    b.move(ofVec3f(0, -100, 0));
//    mesh.addVertex(b.getGlobalPosition());
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
//
//    auto c = Branch();
//    c.setParent(b);
//    c.roll(25.0);
//    c.move(ofVec3f(0, -100, 0));
//    mesh.addVertex(c.getGlobalPosition());
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
//
//    auto d = Branch();
//    d.setParent(c);
//    d.roll(25.0);
//    d.move(ofVec3f(0, -100, 0));
//    mesh.addVertex(d.getGlobalPosition());
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
//
//    auto e = Branch();
//    e.setParent(d);
//    e.roll(25.0);
//    e.move(ofVec3f(0, -100, 0));
//    mesh.addVertex(e.getGlobalPosition());
//    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));

    
    ofNode root = ofNode();
    root.setPosition(450, 700, 0);
    auto branch = Branch();
    branch.setParent(root);

    bool branching = false;
    
    string _instruction = "F+F+F";
    mesh.clear();
    
    for (int i = 0; i < _instruction.length(); i++) {
        char c = _instruction[i];
        if (c == 'F') {
            branching = true;
        }else if (c == '+') {
            auto jointBranch = Branch();
            jointBranch.setParent(branch);
            jointBranch.roll(45);
            auto branch = Branch();
            branch.setParent(jointBranch);
        }
        
        if(branching){
            if(mesh.getNumVertices() == 0){
                //add the first branch to the root
                branch.move(ofVec3f(0, -100, 0));
                mesh.addVertex(branch.getGlobalPosition());
                mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
                branching = false;
            }else{
                //add a new branch
                auto oldBranch = Branch(branch);
                auto branch = Branch();
                branch.setParent(oldBranch);
                branch.move(ofVec3f(0, -100,0));
                mesh.addVertex(branch.getGlobalPosition());
                mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
                branching = false;
            };
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
