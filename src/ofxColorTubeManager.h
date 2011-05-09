/*
 *  ofxColorTubeManager.h
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CLRTBMNGR
#define CLRTBMNGR

#include "ofMain.h"
#include "ofxColorUtils.h"
#include "ofxTube.h"
#include "guiPanel.h"

class ofxColorTubeManager {
			
public:
	
	void setup(vector<ofxTube*> * tubes, guiPanel * panel);
	void update();
	void setColors();
	
	void setMode(int index);
	void doNormalGradient();
	void doHorizontalGradient();
	
private:
	
	vector<ofxTube*>	*	tubes;
	guiPanel			*	panel;
	int						total;
	ofxColorUtils			colorUtils;
	ofxColorUtils			colorUtilsTube;
	ofPoint					coords;
	int						mode, numOfTubePixels;
	
};

#endif