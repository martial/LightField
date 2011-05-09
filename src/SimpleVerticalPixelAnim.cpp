/*
 *  SimpleVerticalPixelAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimpleVerticalPixelAnim.h"

SimpleVerticalPixelAnim::SimpleVerticalPixelAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void SimpleVerticalPixelAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
}

void SimpleVerticalPixelAnim::launch(vector<ofxTube*> * tubes) {
}

void SimpleVerticalPixelAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);	
	//tube->setAllPixelAlpha(1.0);
	tube->dumbPct = 0;
	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, AbstractTubeAnimation::numOfTubePixels-1, 1000, 0);
	tube->dumbPctTween.start();
	
}

void SimpleVerticalPixelAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	
//	tube->dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, tube->dumbPct, 16, 1000, 0);
	//tube->dumbPctTween.start();
}

void SimpleVerticalPixelAnim::onAnimationLoopEvent(int & a) {
	
}

void SimpleVerticalPixelAnim::update () {
    AbstractTubeAnimation::update();
	
	for ( int i=0; i<tubes->size(); i++ ) {
		
		ofxTube * tube = tubes->at(i);
		int index = floor(tube->dumbPct);
		
		
		for ( int j = 0; j<AbstractTubeAnimation::numOfTubePixels; j++ ) {
			if ( index == j ) {
				tube->setPixelAlpha(j, 1.0, 0.0); 
			} else {
				tube->setPixelAlpha(j, 0.0, 0.0); 
			}
		}
		
		
		
	}	
}