//
//  Sprite.hpp
//  Midterm The-Jumper
//
//  Created by Alexander Jiang on 3/26/19.
//
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Sprite {
public:
    void draw();
    void update();
    void startAnim();
    void stopAnim();
    void advanceFrame();
    
    glm::vec3 pos;
    float width, height, voff;
    ofImage image;
    
    int ntiles_x, ntiles_y;
    int nframes;
    int frame = 0;
    int row = 0;
    int col = 0;
    bool bAnimRunning = false;
    float lastTimeRec;
    
};
