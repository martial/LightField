//
//  TubeAnimationManager.cpp
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TubeAnimationManager.h"
#include "SimpleVerticalAnim.h"
#include "SimpleVerticalPixelAnim.h"
#include "RainAnim.h"
#include "LayerAnim.h"

#include "ofxSimpleGuiToo.h"



TubeAnimationManager::TubeAnimationManager () {
    
    
}

void TubeAnimationManager::setup (vector<ofxTube*> * tubes, ofxAnimPlayer * player) {
    
	this->tubes = tubes;
	
	for ( int i=0; i<tubes->size(); i++ ) {
		ofxTube * tube = tubes->at(i);
		ofAddListener(tube->activeEvent,this,&TubeAnimationManager::onActiveEvent);
	}
	
	
	
	this->player = player;
	ofAddListener(this->player->animationLoopEvent, this, &TubeAnimationManager::onAnimationLoopEvent);
	
	setAnimations();
	setCurrentAnimationById(2);
	
	gui.addSlider("Vertical", mode, 0, animations.size()-1);
	
}

void TubeAnimationManager::setAnimations() {
	
	SimpleVerticalAnim * simpleVertical = new SimpleVerticalAnim();
	SimpleVerticalPixelAnim * simplePixelVertical = new SimpleVerticalPixelAnim();
	RainAnim * rain = new RainAnim() ;
	LayerAnim * layerAnim = new LayerAnim();
    
	simpleVertical->init("simple vertical", tubes);
	simplePixelVertical->init("simple pixel vertical", tubes);
	rain->init("rain", tubes);
	layerAnim->init("rain", tubes);
		
	animations.push_back(simpleVertical);
	animations.push_back(simplePixelVertical);
	animations.push_back(rain);
	animations.push_back(layerAnim);
    
}

void TubeAnimationManager::update() {
    
    if (!currentAnimation ) return;
	
	if ( mode != oldMode ) {
		for ( int i=0; i<tubes->size(); i++ ) {
			ofxTube * tube = tubes->at(i);
			tube->reset();
		}
		setCurrentAnimationById(mode);
	}
	currentAnimation->update();
	
	oldMode = mode;
}

void TubeAnimationManager::setCurrentAnimationById(int num) {
    
	//if ( num > animations.size() -1 ) return;
	mode = num;
	currentAnimation = animations[num];
    currentAnimation->launch(tubes);
}

void TubeAnimationManager::onAnimationLoopEvent(int & a) {
	if (!currentAnimation ) return;
	currentAnimation->onAnimationLoopEvent(a);
}

void TubeAnimationManager::onActiveEvent(ofxTubeEvent & args) {
	
	ofxTube * tube = tubes->at(args.id);
	bool bActive = args.bActive;	
	
	if (!currentAnimation ) return;
	
	if ( bActive ) {
	
		currentAnimation->onAnimationStart(&args);
	} else {
		currentAnimation->onAnimationEnd(&args);
	}

}