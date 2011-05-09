/*
 *  ofxColorTubeManager.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxColorTubeManager.h"
#include "mainSettings.h"
#include "ofxSimpleGuiToo.h"


void ofxColorTubeManager::setup(vector<ofxTube*> * tubes, guiPanel * panel) {
	
	this->tubes = tubes;
	this->panel = panel;
	total = tubes->size();
	numOfTubePixels = mainSettings::getNumOfTubePixels();
	mode = 1;
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	gui.addSlider("Color mode", mode, 0, 1);
	
}

void ofxColorTubeManager::setMode(int index) {
	mode = index;
}

void ofxColorTubeManager::setColors () {
	
	switch (mode) {
		case 0:
			doNormalGradient();
			break;
		
		case 1:
			doHorizontalGradient();
			break;
		
		default:
			doNormalGradient();
			break;
	}
	
	
	
}


void ofxColorTubeManager::doNormalGradient () {
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colors, total);
	
	for( int i = 0; i<total; i++ ) {
		
		ofColor current = newColors->at(i);
		for( int j = 0; j<numOfTubePixels; j++ ) {
			tubes->at(i)->pixels[j]->color.r = current.r;
			tubes->at(i)->pixels[j]->color.g = current.g;
			tubes->at(i)->pixels[j]->color.b = current.b;
		}
		
	}
}


void ofxColorTubeManager::doHorizontalGradient () {
	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel->colors, coords.y);
	
	for ( int i = 0; i < coords.y; i++) {
		
		ofColor current = newColors->at(i);
		
		
		
		for ( int j = 0; j < coords.x; j++) {
			
			int index = j * coords.y + i;
			vector<ofColor> * newColorsTube = colorUtilsTube.getGradient(&panel->colors, numOfTubePixels);
			
			for( int k = 0; k<36; k++ ) {
			
			ofColor currentTubeColor = newColorsTube->at(k);

				
			tubes->at(index)->pixels[k]->color.r = currentTubeColor.r;
			tubes->at(index)->pixels[k]->color.g = currentTubeColor.g;
			tubes->at(index)->pixels[k]->color.b = currentTubeColor.b;
			}
			
			
		}
		
	}
	
}

