#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofHideCursor();
    ofSetFrameRate(60);
   
    
    
    //box2D Init
    
   //box2d.init();
   // box2d.setGravity(0, 30);
    //box2d.createGround();
    //box2d.setFPS(60.0);
    
    
    // Load Placeholder Screen (Doesn't seem to work - Displays White Screen)
    
    ofBackground(0, 0, 255);
    
    
    //Set up Open Face Tracker
    
    ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
    
    
	cam.initGrabber(320, 240);
	
	tracker.setup();
    
    for (int i = 0; i<NWALLS; i++){
        
        
        wallSet[i].setup();
        wallSet[i].setWallColor(i);
    
        
    
    }
  
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Camera Update AND
    // Update Open Face Tracker
    
    cam.update();
    
	if(cam.isFrameNew()) {                  //Get Camera Info
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
        mouthWidth = tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);
	}
    
    
    // Update Box2d
    
    box2d.update();

    
    
    // Update Walls
    
    for (int i = 0; i<NWALLS; i++){
    
        
        wallSet[i].update();
       
        //Get and Set Values;
        
        wallSet[i].setOrientation(orientation);
        wallSet[i].getMouthWidth(mouthWidth);
    }
    
    // Test if both eyes are closed
    
  
    
    //Debug Eye Values
    
   // cout << "Right Eye_" << tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS) << endl;
// cout << "Left Eye_" << tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS) << endl;
        
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
    
    //Draw BG

    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofBackgroundGradient(ofColor::blueSteel,ofColor::blue, OF_GRADIENT_LINEAR);
    
    //Draw Walls
    //ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
   for (int i = 0; i<NWALLS; i++){
       
       
       wallSet[i].draw();
     
   
   }
    
    //Tracker Draw
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
    tracker.draw();
    //cam.draw(320, 240);
    
    //Check For Eyes Closed Value (Really Rough Value, should probably check for this at first synchronisation.)
    
    
    if (tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS) <= 2.5 && tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS) <= 2.5){
        
        //cout << "Both Eyes are closed" << endl;
        //ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofColor::seaShell;
        ofDrawBitmapString("Open Your Eyes", (ofGetWidth()/2), (ofGetWindowHeight()/2));
        
        
    }
    
    

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
