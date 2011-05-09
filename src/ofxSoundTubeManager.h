/*
 *  ofxSoundTubeManager.h
 *  LightField
 *
 *  Created by Martial Geoffre on 06/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef OFXSNDTBMNGR
#define OFXSNDTBMNGR

#include "ofMain.h"
#include "ofxSoundManager.h"
#include "ofxTube.h"

class ofxSoundTubeManager {
	
public :

	ofxSoundTubeManager();
	
	void setup(ofxSoundManager * soundManager, vector<ofxTube*> * tubes);
	void update();
	
	void changeMode (int mode);
	
	void doNormalGrid();
	
	void doVerticalStereo();
	void doHorizontalStereo();
	
	void doVerticalCenteredStereo();
	void doHorizontalCenteredStereo();
	
	
private :
	
	ofPoint					coords;
	
	ofxSoundManager		*	soundManager;
	vector<ofxTube*>	*	tubes;
	
	int						mode;
	int						total;
	
	bool					opacitySoundEnabled;
	
};

#endif

