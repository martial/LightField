/*
 *  ofxTubeManager.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXTUBEMNGR
#define OFXTUBEMNGR

#include "ofMain.h"
#include "ofxTube.h"
#include "ofxSoundManager.h"
#include "mainAnimData.h"
#include "frameData.h"

#include "ofxAnimPlayer.h"
#include "TubeAnimationManager.h"
#include "guiPanel.h"
#include "ofxColorTubeManager.h"
#include "ofxSoundTubeManager.h"
#include "ofxColorUtils.h"

class ofxTubeManager {
	
public:
	
	ofxTubeManager();
	void setup(ofxSoundManager * sndManager, mainAnimData * animData, guiPanel * panel);
	void update();
	ofFbo *  drawForDisplay(int x, int y);
	
	void pushAnimation();
	void popAnimation();
	
	
	void setActivePoints (frameData * frame);
	
	void resetTubesState();
	
	ofxAnimPlayer					player;
	TubeAnimationManager			vAnimationManager;
	ofxColorTubeManager				colorManager;
	ofxSoundTubeManager				soundManager;
	
	vector<ofxTube*>				tubes;
	
	
	private	:
	
	ofxSoundManager			*		sndManager;
	mainAnimData			*		animData;
	guiPanel				*		panel;
	frameData			*			currentFrame;
	
	ofxColorUtils					colorUtils;
	
	int								total;
	int								currentAnimation;
	
	ofFbo							displayFbo;
	
	/* Interaction modes */ 
	
	bool							sizeSoundEnabled, reverseFilled;
	
};

#endif