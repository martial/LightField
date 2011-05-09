/*
 *  ofxSoundTubeManager.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 06/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSoundTubeManager.h"
#include "ofxSimpleGuiToo.h"
#include "mainSettings.h"

ofxSoundTubeManager::ofxSoundTubeManager () {
	
}

void ofxSoundTubeManager::setup(ofxSoundManager * soundManager, vector<ofxTube*> * tubes) {
	
	this->soundManager = soundManager;
	this->tubes = tubes;
	
	total = tubes->size();
	
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	gui.addSlider("Sound dispatch", mode, 0, 2);
	gui.addToggle("Opacity + sound" , opacitySoundEnabled);
	
}


void ofxSoundTubeManager::update () {
	
	for( int i = 0; i<total; i++ ) {
		ofxTube * tube = tubes->at(i);
		if ( !opacitySoundEnabled )tube->setMainAlphaPct(1.0);
	}
	
	switch ( mode ) {
				
		case 0:
			doNormalGrid();
			break;
			
		case 1:
			doVerticalStereo();
			break;
			
		case 2:
			doHorizontalStereo();
			break;
			
			
	}
	
	//doNormalGrid();
	
}

void ofxSoundTubeManager::doNormalGrid () {
	
	
	for( int i = 0; i<total; i++ ) {
		
		int step = floor(i * 128 / total);
		ofxTube * tube = tubes->at(i);
		if ( opacitySoundEnabled ) tube->setMainAlphaPct(soundManager->leftAverage[step]);
		
	}
	
	
}


void ofxSoundTubeManager::doVerticalStereo(){
	
	for ( int i = 0; i < coords.x; i++) {
		
		
		
		for ( int j = 0; j < coords.y ; j++) {
			
			int step = ( j< coords.y / 2 ) ?  floor(j * 2 * 128 / (coords.y-1)) : floor( (j-coords.y / 2 )  *  2 * 128 / (coords.y-1));
			float val = ( j< coords.y / 2 ) ? soundManager->leftAverage[127-step] : soundManager->leftAverage[step] ;
			
			ofxTube * tube = tubes->at(i * coords.y + j);
			if ( opacitySoundEnabled )tube->setMainAlphaPct(val);			
		}
		
	}
		
}


void ofxSoundTubeManager::doHorizontalStereo(){
	
	for ( int i = 0; i < coords.x; i++) {
		
		int step = ( i< coords.x / 2 ) ?  floor(i * 2 * 128 / (coords.x-1)) : floor( (i-coords.x / 2 )  *  2 * 128 / (coords.x-1));
		float val = ( i< coords.x / 2 ) ? soundManager->leftAverage[127-step] : soundManager->rightAverage[step] ;
				
		for ( int j = 0; j < coords.y ; j++) {
			
			ofxTube * tube = tubes->at(i * coords.y + j);
			if ( opacitySoundEnabled ) tube->setMainAlphaPct(val);			
		}
		
	}
	
	
}

void ofxSoundTubeManager::doVerticalCenteredStereo(){
}
void ofxSoundTubeManager::doHorizontalCenteredStereo(){
}


