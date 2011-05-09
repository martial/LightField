/*
 *  BeatCatcher.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 02/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "BeatCatcher.h"

BeatCatcher::BeatCatcher () {

	
	ofRegisterMouseEvents(this);
	
	drawTime = 10;
	delay = 600;
	lastTime = 0.0;
	drawCount = 0.0;
	
	
	timer.setup(delay, true);
	ofAddListener(timer.TIMER_REACHED, this, &BeatCatcher::drawBeats);
}


void BeatCatcher::update() {

}

void BeatCatcher::drawBeats(ofEventArgs & args) {
	printf("ahou \n");
	ofSetColor(255, 0, 0);
	ofRect(0, 0, 500, 500);
	drawCount = 0;
}

void BeatCatcher::debugDraw () {
	
	if( drawCount<drawTime ) {
		
		ofSetColor(255, 0, 0);
		ofRect(0, 0, 500, 500);
		
	} else {
		
	}
	
	drawCount ++;
	
	
}

void BeatCatcher::setBeat () {
	
	delay = ofGetElapsedTimeMillis() - lastTime;
	timer.reset();
	timer.setup(delay, true);
	lastTime = ofGetElapsedTimeMillis();
	
}

void BeatCatcher::mouseMoved(ofMouseEventArgs& mouse) {}
void BeatCatcher::mouseDragged(ofMouseEventArgs& mouse) {}
void BeatCatcher::mouseReleased(ofMouseEventArgs& mouse) {}


void BeatCatcher::mousePressed(ofMouseEventArgs& mouse) {

	delay = ofGetElapsedTimeMillis() - lastTime;
	timer.reset();
	timer.setup(delay, true);
	lastTime = ofGetElapsedTimeMillis();
	
	
}