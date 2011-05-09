/*
 *  guiView.h
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUIVIEW	
#define GUIVIEW

#include "ofMain.h"
#include "Grid.h"
#include "ofxSoundManager.h"
#include "ofxTubeManager.h"
#include "ofxFBOTexture.h"

class guiView {
	
public:
	
	void setup(ofxSoundManager * sound, ofxTubeManager * tubesManager);
	void update();
	void draw(int x, int y);
    
    void setSize(int w, int h);
    void onWindowsResized( int w, int h);
    
	
	Grid					nodeGrid;
	
private:
	
	ofRectangle				viewMain;
	
	
	ofxSoundManager		*	sound;
	ofxTubeManager		*	tubesManager;
	
	
	ofxFBOTexture				fbo;
	
	float					width, height;
	
	
};

#endif