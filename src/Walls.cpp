//
//  Walls.cpp
//  lieutenantButterfly_oFx_Drawing3
//
//  Created by Phil James on 3/09/14.
//
//

#include "Walls.h"

#define DBG


Walls::Walls(){
    
   
   wallImage.loadImage("paint1B.png");
   
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
    
    isGlistening = true;
    isCrystalline = true;
    
    speedY = ofRandom(-1,1);
    //speedX = ofGetElapsedTimef();
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
    ofSetCircleResolution(6);
    
   
    
}






void Walls::update(){
    
    
    // Basic Wrapping
    
    
    if(x<0){
        x = ofGetWidth();
    }
    
    if(y<0){
        y = ofGetHeight();
    }
    
    if(y > ofGetHeight()){
        y = 0;
    }
    
    if(x > ofGetWidth()){
        x = 0;
    }
    
    y+=speedY;
    
    x = x + 0.01*-camtrackerOrientation.z;
    
    
    
    
#ifdef DBG
    cout << speedX <<endl;
#endif
    
}



void Walls::draw(){
    
    
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(128,255));
    
    //ofRect(x, y, -camtrackerOrientation.y, 200);
    ofCircle(x+20, y, -camtrackerOrientation.y);
    ofCircle(x, y, -camtrackerOrientation.y);
    
    
    //wallImage.draw(x, y, 100, camtrackerOrientation.y);
    
   
    
    
}

void Walls::setOrientation(ofVec3f o){
    
    camtrackerOrientation = 500 * o;
    
    
    
}

void Walls::getMouthWidth(float w){
    
    camTrackerMouthWidth = 200 * sin(w);
    
   // cout << camTrackerMouthWidth << endl;
    
}




