//
//  Sprite.cpp
//  Midterm The-Jumper
//
//  Created by Alexander Jiang on 3/26/19.
//
#pragma once
#include "Sprite.hpp"
#include "ofMain.h"
#include "ofxGui.h"

void Sprite::startAnim() {
    
    frame = 0;
    bAnimRunning = true;
    lastTimeRec = ofGetSystemTimeMillis();
}

void Sprite::stopAnim() {
    bAnimRunning = false;
}

void Sprite::update() {
    if (!bAnimRunning) return;
    
    float curTime = ofGetSystemTimeMillis();
    if ((curTime - lastTimeRec) > 50) {
        advanceFrame();
        lastTimeRec = curTime;
    }
}


void Sprite::advanceFrame() {
    if (frame == (nframes - 1)) {
        col = 0;
        row = 0;
        frame = 0;  // cycle back to first frame
    }
    else {
        frame++;
        if (col == ntiles_x - 1) col = 0; else col++;
        row = frame / ntiles_x;
    }
}
void Sprite::draw() {
    image.drawSubsection(pos.x, pos.y, width, height,col*width, row*height+voff);
}

