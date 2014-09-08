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
    
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
   // isGlistening = true;
   //isCrystalline = true;
    
    speedY = ofRandom(-1,1);
    //speedX = ofGetElapsedTimef();
   // ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
    ofSetCircleResolution(6);
   // box.set(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
   
    
}


void Walls::setup(){
    
    //ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
    //ofSetCircleResolution(6);
    box.set(20,20,200);
    box.enableNormals();
    box.drawWireframe();
    

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
    
    
   // ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(128,255));
    
    //ofRect(x, y, -camtrackerOrientation.y, 200);
    //ofCircle(x+20, y, -camtrackerOrientation.y);
    //ofCircle(x, y, -camtrackerOrientation.y);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    box.setPosition(x, y, camtrackerOrientation.x);
    
    wallImage.draw(x, y, 100, camtrackerOrientation.y);
    
    box.draw();
    
    
}

void Walls::setOrientation(ofVec3f o){
    
    camtrackerOrientation = 500 * o;
    
}

void Walls::getMouthWidth(float w){
    
    camTrackerMouthWidth = 200 * sin(w);
    
   // cout << camTrackerMouthWidth << endl;
    
}

void Walls::setWallColor(int i){
    

    //ofSetColor(ofRandom(i,255), ofRandom(i,255), ofRandom(i,255));
  
}




