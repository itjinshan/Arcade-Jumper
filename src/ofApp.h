#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ParticleSystem.h"
#include "Particle.h"
#include "Sprite.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
        ParticleSystem *parSys;
        Particle jumper;
        ParticleSystem *ground;
        Particle level1Ground;
        Particle level2Ground;
    
    
        int prevKey = -9999;
        ofVec3f jumpDir;
        float jumpForce;
    
        bool readyJump = false;
        bool freez = false;
        bool haveImage = false;
    
    
        GravityForce grav;
    
        //UI Control
        ofxPanel gui;
        ofxFloatSlider gravity;
        ofxFloatSlider impulse;
        ofxFloatSlider x;
        ofxFloatSlider y;
        ofxFloatSlider sw;
        ofxFloatSlider sh;
        ofxFloatSlider voff;
        ofxFloatSlider hoff;
};
