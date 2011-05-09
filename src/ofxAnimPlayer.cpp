/*
 *  ofxAnimPlayer.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 28/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxAnimPlayer.h"
#include "ofxSimpleGuiToo.h"

ofxAnimPlayer::ofxAnimPlayer () {
	
}

void ofxAnimPlayer::setup () {
	
	timeStep		= 0;
	currentFrame	= 0;
	sens			= 1;

	speed			= 50.0;
	speedAlpha		= 1.0;
	
	gui.addSlider("Speed", speed, -100, 100);

}

frameData * ofxAnimPlayer::update () {
	
	if (!currentAnimationData ) return;
	
	sens = ( speed <= 0.0 ) ? -1 : 1;
	float _sp = abs(speed);
	if ( speed == 500 ) timeStep = ofGetElapsedTimeMillis();
		
	if ( ofGetElapsedTimeMillis() - timeStep > _sp ) {
		timeStep = ofGetElapsedTimeMillis();
		currentFrame += 1*sens;
				
		if ( currentFrame > currentAnimationData->frames.size() -1  && currentFrame != -1) {
			currentFrame = 0;
			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		if ( currentFrame < 0  ) {
			currentFrame = currentAnimationData->frames.size() -1 ;
			ofNotifyEvent(animationLoopEvent, currentFrame, this);
		}
		
		
		
	}
	
	return getCurrentFrameData();
	
}

frameData * ofxAnimPlayer::getCurrentFrameData () {
	
	if(!currentAnimationData) return NULL;
	return currentAnimationData->frames[currentFrame];
	
}


void ofxAnimPlayer::setAnimation (animationData * animation) {
	currentFrame = 0;
	currentAnimationData = animation;
	
}



void ofxAnimPlayer::setSpeed(float speed) {

}