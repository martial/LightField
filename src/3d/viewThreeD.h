/*
 *  viewThreeD.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VIEWTHREED	
#define VIEWTHREED

#include "ofMain.h"
#include "Grid.h"
#include "ofxSoundManager.h"
#include "ofxTubeManager.h"
#include "ofxFBOTexture.h"

class viewThreeD {
		
public:
	
	void setup(ofxSoundManager * sound, ofxTubeManager * tubesManager);
	void update();
	void draw(int x, int y);
    
    void setSize(int w, int h);
    void onWindowsResized( int w, int h);
    
	
	Grid					nodeGrid;
	
	float					zDiff;
	
private:
	
	ofEasyCam				cam;
	ofRectangle				viewMain;
	
	ofPoint					centerPoint;
	
	ofxSoundManager		*	sound;
	ofxTubeManager		*	tubesManager;
	
	float						blurAmount;
	ofxFBOTexture				fbo;
	ofxFBOTexture				gridFbo;
	ofShader					blurShaderH, blurShaderV;
	
	float						camDistance, width, height;
	
	
	
};

#endif