#pragma once

#include "ofMain.h"
#include "Walls.h"

#include "ofxCv.h"

using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"




// define VARS

#define NWALLS 100


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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    //Walls
    
    Walls wallSet[NWALLS];
    
    
    
    
    //Box 2d
    
    ofxBox2d box2d;
    
    vector <ofPtr<ofxBox2dRect> > boxes;
    
    
    //Face Tracker
    
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    
    ofVec2f position;
    float scale;
    ofVec3f orientation;
    ofMatrix4x4 rotationMatrix;
    float mouthWidth;
    
    
    
    Mat translation, rotation;
    ofMatrix4x4 pose;
	
    ofEasyCam easyCam;
    
    
    
		
};



