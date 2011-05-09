/*
 *  ofxTubePixel.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 05/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxTubePixel.h"
#include "mainSettings.h"

ofxTubePixel::ofxTubePixel () {
	
	numOfPixels = mainSettings::getNumOfTubePixels();
	
	alphaPct = 1.0;
	pos.x = 0;
	pos.y = 0;
	
	tweenPosY.setParameters(0, quint, ofxTween::easeOut, 0, pos.y, 1, 0);
	tweenAlpha.setParameters(0, quint, ofxTween::easeOut, 0,1.0, 1, 0);
}

void ofxTubePixel::init () {
	//this->parentPct = parentPct;
}

void ofxTubePixel::update() {
	pos.y = tweenPosY.update();
	alphaPct =  tweenAlpha.update();
}

void ofxTubePixel::reset () {
	
}

void ofxTubePixel::setPosition(float x, float y, float duration) {
	tweenPosY.setParameters(0, quint, ofxTween::easeOut, pos.y, y, duration, 0);
}

void ofxTubePixel::setAlphaPct(float pct, float duration) {
	
	tweenAlpha.setParameters(0, quint, ofxTween::easeOut, alphaPct, pct, duration, 0);
	
}





void ofxTubePixel::drawFor3DView(float x, float y, float z, float alpha) {
	
	
	
	ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * alpha * 255);
	
	float pixelSize = 10.0 / 36.0;
   
	glPushMatrix();
	glTranslatef(x + pos.x,  pos.y*pixelSize, z+pos.z);
	glScalef(1, pixelSize, 1);
	ofBox(0, 0, 1);
    //ofRect(0,0,1,1);
	glPopMatrix();
}

void ofxTubePixel::drawForDisplay(float x, float y, float alpha) {
	
    if ( alphaPct <= 0.0 ) return;
	
   // ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * 255);
	//glBegin(GL_POINTS);
	//glVertex2f(x, y+ pos.y);
	//glEnd();
	
	ofEnableAlphaBlending();
	ofPushMatrix();
	
	glTranslated((int)x, (int)y, 0);
		
	ofSetColor((int)color.r, (int)color.g,(int)color.b, alphaPct * alpha * 255);
	
	
	glBegin(GL_POINTS);
	glVertex2d(0,(int)pos.y);
	glEnd();
	
	//ofSetColor(255,255,255);
	//glPushMatrix();
	//glTranslated(0, (int)pos.y, 0);
	//glScalef(1, 1, 1);
	
	
	 
	
    //ofLine(0, (int)pos.y,0, (int)pos.y);
    //ofRect(0, (int)pos.y + 40, 1, 1);
	//glPopMatrix();
		
	ofPopMatrix();
	ofDisableAlphaBlending();

}