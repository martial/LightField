/*
 *  ofxTubeManager.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTubeManager.h"
#include "mainSettings.h"
#include "ofxSimpleGuiToo.h"

ofxTubeManager::ofxTubeManager () {

}

void ofxTubeManager::setup (ofxSoundManager * sndManager, mainAnimData * animData, guiPanel * panel) {
	
	this->sndManager = sndManager;
	this->animData = animData;
	this->panel = panel;
	
	currentAnimation = 2;
	
	sizeSoundEnabled = false;
	reverseFilled = false;
	
	player.setup();
	player.setAnimation(animData->animationsData[currentAnimation]);
	
	
	
	

	gui.addToggle("Size + sound" , sizeSoundEnabled);
	gui.addToggle("Reverse Filled" , reverseFilled);
	
	
	
	
	total = (int)(mainSettings::getGridSize().x * mainSettings::getGridSize().y);
	
	for( int i = 0; i<total; i++ ) {
		ofxTube * tube = new ofxTube();
		tube->setup(10, 8);
		tube->id = i;
		tubes.push_back(tube);
	}
	
	vAnimationManager.setup(&tubes, &player);
	soundManager.setup(sndManager, &tubes);
	colorManager.setup(&tubes,panel);
	
	//displayFbo.setup(total, 36*2 + 4, GL_RGBA, 1);
	
	//gui.addFboContent("output", displayFbo);
}

void ofxTubeManager::update () {
	
	vAnimationManager.update();
	
	colorManager.setColors();
	soundManager.update();
	
	frameData * frame = player.update();
	if (frame) setActivePoints(frame);
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->update();
	}	
}

void ofxTubeManager::setActivePoints (frameData * frame) {
	
	if(!frame ) return;
	
	int pointSize = frame->points.size();
	for( int i = 0; i<total; i++ ) {
		tubes[i]->update();
		bool bActive = (reverseFilled) ? true : false;
		tubes[i]->setActive(bActive);
		for ( int j=0; j< pointSize; j++ ) {
			if ( frame->points[j] == i ) {
				bool bActive = (reverseFilled) ? false : true;
				tubes[i]->setActive(bActive);
				break;
			}
			
		}
		
	}
		
}


void ofxTubeManager::pushAnimation () {
	
		
	currentAnimation++;
	if ( currentAnimation > animData->animationsData.size() -1 ) currentAnimation = 0;
	player.setAnimation(animData->animationsData[currentAnimation]);
	
}

void ofxTubeManager::popAnimation () {
	
	currentAnimation--;
	if ( currentAnimation < 0 ) currentAnimation = animData->animationsData.size() -1;
	player.setAnimation(animData->animationsData[currentAnimation]);
	
}

void ofxTubeManager::resetTubesState () {
	
	for( int i = 0; i<total; i++ ) {
		tubes[i]->reset();
	}
	
}

ofFbo * ofxTubeManager::drawForDisplay (int x, int y) {
	
	
	//displayFbo.clean();
	//displayFbo.begin();
	ofEnableAlphaBlending();
	
	//ofSetColor(0, 0, 0);
	//ofRect(0, 0, total, 36*2+4);
	glPushMatrix();
	glTranslated(0, 0, 0);
	ofSetColor(255,255,255,255);
	glShadeModel(GL_FLAT);
	for( int i = 0; i<total; i++ ) {
		tubes[i]->drawForDisplay(x+i,y);
	}
	
	glPopMatrix();
	ofDisableAlphaBlending();
	//displayFbo.end();
	
	/*
	ofEnableAlphaBlending();
	ofSetColor(255,255,255,255);
	//displayFbo.draw(x,y);
	ofDisableAlphaBlending();
	*/
	
	return &displayFbo;
}

