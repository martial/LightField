/*
 *  ofxAnimPlayer.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 28/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef OFXANIPLAYER
#define OFXANIPLAYER

#include "ofMain.h"
#include "animationData.h"
#include "frameData.h"

class ofxAnimPlayer {

	public : 
	
	ofxAnimPlayer();
	void setup();
	frameData * update();
	
	frameData * getCurrentFrameData ();
	
	
	void pushAnimation();
	void popAnimation();
	
	
	
	void setAnimation (animationData * animation);
	void setSpeed(float speed);
	
	ofEvent<int>				animationLoopEvent;
	
	private:
	
	animationData		*		currentAnimationData;
	
	
	int							timeStep;
	int							currentFrame;
	int							sens;
	
	
	
	float						speed;
	float						speedAlpha;
	
};

#endif
