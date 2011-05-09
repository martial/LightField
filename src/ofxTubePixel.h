/*
 *  ofxTubePixel.h
 *  LightField
 *
 *  Created by Martial Geoffre on 05/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXTBPIX
#define OFXTBPIX

#include "ofxTween.h"
#include "ofxEasingQuint.h"

class ofxTubePixel {
		
	public :
	
	
	ofxTubePixel();
	
	void init () ;
	void update();
	void drawFor3DView(float x, float y, float z, float alpha );
	void drawForDisplay(float x, float y, float alpha);
	
	void reset();
	void setAlphaPct(float pct, float duration);
	void setPosition(float x, float y, float duration = 0.0);
	
	
	ofColor			color;
	ofPoint			pos;
	
	float			alphaPct,tempAlphaPct;
	
	ofxTween		tweenPosY;
	ofxTween		tweenAlpha;
	ofxEasingQuint	quint;
	
	int				numOfPixels;
	
	
	private :
	
	float		*		parentPct;
	
	
	
};

#endif