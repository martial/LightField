/*
 *  ofxTube.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTube.h"
#include "mainSettings.h"

ofxTube::ofxTube() {
	
	mainAlphaPct = 1.0;
	alphaPct = 1.0;
	sizePct = 0.0;
	bActive = true;
	bFlickering = false;
	
	numOfPixels = mainSettings::getNumOfTubePixels();
	
	pixels.reserve(numOfPixels);
	for ( int i=0; i<numOfPixels; i++ ) {
		ofxTubePixel * pixel = new ofxTubePixel();
		pixel->init();
		ofColor white;
		white.set(255,255,255);
		
		pixel->setPosition(0, i);
		pixel->color = white;
		pixel->alphaPct = 1.0;
		
		//pixelsAlphaPct[i] = 1.0;
		pixels[i] = pixel;
		
		
	}
	
	sizePctTween.setParameters(0, easingquint, ofxTween::easeOut, 0, 1, 1000, 0);
	sizePctTween.start();
	
	dumbPctTween.setParameters(0, easingquint, ofxTween::easeOut, 0, 0, 1, 0);
	dumbPctTween.start();
	
	
}

void ofxTube::setup(int size, int numOfPixels) {
	
	this->size = size;
	//this->numOfPixels = numOfPixels;
	
}
void ofxTube::update() {
	
	sizePct = sizePctTween.update();
	dumbPct = dumbPctTween.update();
	
	
	for ( int i = 0; i<numOfPixels; i++ ) {
		pixels[i]->update();
	}
	
	

	
	//sizePct = 1.0;
}

void ofxTube::setActive(bool bActive) {
	
	if (bActive == this->bActive ) return;
	
	this->bActive = bActive;
	static ofxTubeEvent args;
	args.id = this->id;
	args.bActive = bActive;
	
	ofNotifyEvent(activeEvent, args, this); 
}



/*
 
 Useful actions
 
 
 */

void ofxTube::reset() {
	
	bFlickering = false;
	mainAlphaPct = 1.0;
	changeSizePct(1.0, 10);
	for ( int i = 0; i<numOfPixels; i++ ) {
		pixels[i]->setAlphaPct(1.0, 10.0);
		pixels[i]->setPosition(50, i);
		//pixels[i]->alphaPct = 1.0;
	}
	
}

void ofxTube::changeSizePct(float sizePct, float time ) {
	
	sizePctTween.setParameters(0, easingquint, ofxTween::easeOut, this->sizePct, sizePct, time, 0);
	sizePctTween.start();
}

void ofxTube::setPixelAlpha(int pixelIndex, float alpha, float duration) {
	
	//ofColor * pixelAlpha = pixelsAlphaPct[pixelIndex];
	if ( pixelIndex > numOfPixels-1 ) return;
	pixels[pixelIndex]->setAlphaPct(alpha, duration);
	
}

void ofxTube::setAllPixelAlpha( float alpha) {
	
	//ofColor * pixelAlpha = pixelsAlphaPct[pixelIndex];
	for ( int i=0; i<numOfPixels; i++) {
	pixels[i]->setAlphaPct(alpha, 1);
	}
	
}

void ofxTube::setMainAlphaPct (float pct) {
	mainAlphaPct = pct;
}



void ofxTube::drawFor2DView(float x, float y) {
	if ( bActive ) {
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, 255);	
		
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(1, 1, 1);
	ofCircle(0, 0, 2);
	glPopMatrix();
	
	ofDisableAlphaBlending();
	}

	
	
}

void ofxTube::drawFor3DView(float x, float y) {
	
	if ( bFlickering && ofGetFrameNum() % 2 == 0 ) return;
		
		
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	ofSetColor(255, 255, 255, 255);	
	
	
	
	glScalef(1, sizePct, 1);
	
	//printf("size : %f\n", sizePct);
			
	for ( int i = 0; i<numOfPixels; i++ ) {
		ofxTubePixel * pixel = pixels[i];
		pixel->drawFor3DView(x, 0, y,mainAlphaPct);
		
	}
	
	ofPopMatrix();
	ofDisableAlphaBlending();
		
	
}

void ofxTube::drawForDisplay(float x, float y) {
	
	if ( bFlickering && ofGetFrameNum() % 2 == 0 ) return;
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	ofSetColor(255, 255, 255, 255*mainAlphaPct);	
	
	glTranslatef(x, y, 0);
	
	glScalef(1, sizePct, 1);
		
	for ( int i = 0; i<numOfPixels; i++ ) {
		
		ofxTubePixel * pixel = pixels[i];
		pixel->drawForDisplay(0, 0,mainAlphaPct);
		
			
	}
	

	ofPopMatrix();
	ofDisableAlphaBlending();
}

