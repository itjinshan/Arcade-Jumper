#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //
    //
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    // adding charactor particle
    //
    jumper.width = 50;
    jumper.height= 50;
    
    //
    //
    string spriteFile = "images/running1.png";
    if (!jumper.sprite.image.load(spriteFile)) {
        cout << "Can't load image file: " << spriteFile << endl;
    }
    else{
        jumper.haveImage = true;
        jumper.sprite.width = jumper.sprite.image.getWidth() / 8.0;
        jumper.sprite.height = jumper.sprite.image.getHeight() / 2.0-20;
        jumper.width = jumper.sprite.width ;
        jumper.height = jumper.sprite.height;
        jumper.sprite.ntiles_x = 8;
        jumper.sprite.ntiles_y = 2;
        jumper.sprite.voff = 0;
        jumper.sprite.nframes = 18;
    }
    
    
    level1Ground.color = ofColor::green;
    level1Ground.width = ofGetWindowWidth();
    level1Ground.height = 100;

    level2Ground.color = ofColor::green;
    level2Ground.width = 400;
    level2Ground.height = 200;
    
    jumper.position = ofVec3f(20, (ofGetWindowHeight()-level1Ground.height-jumper.height), 10);
    
    parSys = new ParticleSystem();
    parSys->add(jumper);
    
    // adding ground to the scene (2 pieces of ground)
    //
    ground = new ParticleSystem();
    level1Ground.position = ofVec3f(0,(ofGetWindowHeight()-level1Ground.height),0);
    level2Ground.position = ofVec3f((ofGetWindowWidth()-level2Ground.width), (ofGetWindowHeight()-level2Ground.height-level1Ground.height),0);
    
    ground->add(level1Ground);
    ground->add(level2Ground);
    
    // Physics
    //
    grav.setGravity(ofVec3f(0,10,0));
    parSys->addForce(&grav);
    
    
    // UI Control
    //
    gui.setup();
    gui.add(x.setup("x", 100, 80, 200));
    gui.add(y.setup("y", 300, 280, 500));
    gui.add(gravity.setup("Gravity", 150, 100, 250));
    gui.add(impulse.setup("JumpForce", 3, 1, 10));
    gui.add(sw.setup("Sprite Width", jumper.sprite.width, 1, 800));
    gui.add(sh.setup("Sprite Height", jumper.sprite.height, 1, 800));
    gui.add(voff.setup("Vertical Offset", jumper.sprite.voff, 0, 200));
}

//--------------------------------------------------------------
void ofApp::update(){
    parSys->particles[0].sprite.width = sw;
    parSys->particles[0].sprite.height = sh;
    parSys->particles[0].sprite.voff = voff;
    parSys->particles[0].sprite.pos = parSys->particles[0].position;
    parSys->particles[0].sprite.update();
    
    
    if(readyJump) {
        grav.setGravity(ofVec3f(0,gravity,0));
    }
    else{
        grav.setGravity(ofVec3f(0,0,0));
    }
    jumpDir = ofVec3f(x,-y,0);
    if(parSys->onTallGround(ground)){
        parSys->setVelocity(ofVec3f(0,0,0));
        grav.setGravity(ofVec3f(0,0,0));
        readyJump = false;
        parSys->particles[0].position += ofVec3f(0,-0.1,0);
    }
    if(parSys->onLowGround(ground)){
        parSys->setVelocity(ofVec3f(0,0,0));
        grav.setGravity(ofVec3f(0,0,0));
        readyJump = false;
        parSys->particles[0].position += ofVec3f(0,-0.1,0);
    }
    parSys->update();
    ground->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    parSys->draw();
    ground->draw();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == prevKey) {
        return;
    }
    switch (key) {
        case OF_KEY_LEFT:
            parSys->setVelocity(ofVec3f(-100,0,0));
            voff = 140;
            parSys->particles[0].sprite.startAnim();
            key = prevKey;
            break;
        case OF_KEY_RIGHT:
            parSys->setVelocity(ofVec3f(100,0,0));
            voff = 0;
            parSys->particles[0].sprite.startAnim();
            key = prevKey;
            break;

        case OF_KEY_UP:
            parSys->setVelocity(jumpDir);
            readyJump = true;
            key = prevKey;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case OF_KEY_LEFT:
            parSys->setVelocity(ofVec3f(0,0,0));
            parSys->particles[0].sprite.stopAnim();
            break;
        case OF_KEY_RIGHT:
            parSys->setVelocity(ofVec3f(0,0,0));
            parSys->particles[0].sprite.stopAnim();
            break;
    }
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
