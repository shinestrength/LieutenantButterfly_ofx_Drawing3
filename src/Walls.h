//
//  Walls.h
//  lieutenantButterfly_oFx_Drawing3
//
//  Created by Phil James on 3/09/14.
//
//

#ifndef __lieutenantButterfly_oFx_Drawing3__Walls__
#define __lieutenantButterfly_oFx_Drawing3__Walls__

#include <iostream>
#include "ofMain.h"
#include "ofxBox2d.h"

#endif /* defined(__lieutenantButterfly_oFx_Drawing3__Walls__) */


class Walls {
    

public:
    
    void setup();
    void update();
    void draw();
    
    void setOrientation(ofVec3f o);
    void getMouthWidth(float w);
    
    void setWallColor(int i);
    
    
    bool isGlistening;
    bool isCrystalline;
    
    float x;
    float y;
    
    float speedY;
    float speedX;
    
    ofColor c;
    
    ofImage wallImage;
    
    ofVec3f camtrackerOrientation;
    
    float camTrackerMouthWidth;
    
    ofBoxPrimitive box;
   
    
    Walls();
    
private:
    
    
    
    
};