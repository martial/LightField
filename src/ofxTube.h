/*
 *  ofxTube.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef OFXTUBE
#define OFXTUBE

#include "ofMain.h"
#include "ofxTubeEvent.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"
#include "ofxTubePixel.h"

class ofxTube {
	
public:

	ofxTube();
	
	
	void setup(int size, int numOfPixels);
	void update();
	void drawFor2DView(float x, float y);
	void drawFor3DView(float x, float y);
	void drawForDisplay(float x, float y);
	void setActive(bool bActive);
	
	
	/* */
	
	void reset();
	void setMainAlphaPct (float pct);
	void changeSizePct(float sizePct, float time );
	void setAllPixelAlpha( float alpha);
	void setPixelAlpha(int pixelIndex, float alpha, float duration);
	
	int						id;
	
	float					alphaPct;
	float					sizePct;
	float					dumbPct;
	bool					bActive;
	bool					bFlickering;
	
	ofColor					color1;
	ofColor					color2;
	vector<ofxTubePixel*>	pixels;

	
	ofEvent<ofxTubeEvent>	activeEvent;
	
	ofxTween				sizePctTween;
	ofxTween				dumbPctTween;
	ofxEasingQuint			easingquint;
	
private:
		
	int						size;
	int						numOfPixels;
	float					mainAlphaPct;
	
	
	
	
};

#endif