/*
 *  LayerAnim.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 07/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "LayerAnim.h"



LayerAnim::LayerAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void LayerAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
}

void LayerAnim::launch(vector<ofxTube*> * tubes) {
	
	layerPos = 1;
	sens = 1;
	
	for ( int i = 0; i < (int)tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
			tube->setPixelAlpha(j, ( j < 1 ) ? 1.0 : 0.0, 0.0);
		}
	}

	
}


void LayerAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	
	tube->bFlickering = true;
	
	//tube->pixels[ofClamp(layerPos, 0, 35)]->setAlphaPct(1.0, 0.0);
	
	for ( int j=0; j< layerPos; j++ ) {
		tube->pixels[j]->setAlphaPct(1.0, 0.0);
	}
		
	
}

void LayerAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	tube->bFlickering = false;
	for ( int j=0; j< AbstractTubeAnimation::numOfTubePixels; j++ ) {
		tube->pixels[j]->setAlphaPct(0.0, 2000.0);
	}
	//tube->changeSizePct(0, 2000);
}

void LayerAnim::onAnimationLoopEvent(int & a) {
		
}

void LayerAnim::update () {
    AbstractTubeAnimation::update();	
	if ( layerPos > AbstractTubeAnimation::numOfTubePixels-1 ) sens = -1;
	if ( layerPos < 0 ) sens = 1;
	layerPos+= sens;
    
}