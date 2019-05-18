#pragma once

#include "ofMain.h"
#include "Sprite.hpp"

class ParticleForceField;

class Particle {
public:
	Particle();

	ofVec3f position;
	ofVec3f velocity;
	ofVec3f acceleration;
	ofVec3f forces;
	float	damping;
	float   mass;
	float   lifespan;
	float   width, height;
	float   birthtime;
	void    integrate();
    void    jump();
	void    draw();
	float   age();        // sec
	ofColor color;
    
    bool haveImage;
    Sprite sprite;
};


