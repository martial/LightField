/*
 *  RainAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 05/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "RainAnim.h"

RainAnim::RainAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
	
}

void RainAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
	
	//printf("init %d\n", AbstractTubeAnimation::numOfTubePixels);
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
		tube->setPixelAlpha(j, 0.0, 1.0);
		}
	}
	
	
}

void RainAnim::launch(vector<ofxTube*> * tubes) {
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, 0.0, 1.0);
		}
	}
	
	
}

void RainAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	
	ofxTube * tube = tubes->at(args->id);
	
	for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j+=2 ) {
	float rdm = 2000 + ofRandom(1000);
	float rdmPos = ofRandom(AbstractTubeAnimation::numOfTubePixels);
		
	
	
	tube->pixels[j]->setPosition(0,rdmPos, rdm);
	
		
			int tubeRdm = (int)ofRandom(AbstractTubeAnimation::numOfTubePixels);
			if ( tubeRdm >= AbstractTubeAnimation::numOfTubePixels/2 ) {
				if ( tube->pixels[j]->alphaPct == 0.0 ) tube->pixels[j]->setAlphaPct(1.0, rdm);
			} else {
				if ( tube->pixels[j]->alphaPct == 1.0 ) tube->pixels[j]->setAlphaPct(0.0, rdm);
			}
			
		
	
		
	}
	
	
}

void RainAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	//tube->pixels[0]->setPosition(0,0, 200);
}

void RainAnim::onAnimationLoopEvent(int & a) {
	
}

void RainAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i = 0; i < tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		//tube->pixels[0]->pos.y ;
	}
    
}