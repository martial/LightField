/*
 *  BeatCatcher.h
 *  LightField
 *
 *  Created by Martial Geoffre on 02/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */



#ifndef BTCATCHER
#define BTCATCHER

#include "ofMain.h"
#include "ofxTimer.h"


class BeatCatcher {
	
public:
	BeatCatcher();
	
	void update();
	void drawBeats(ofEventArgs & args);
	void debugDraw();
	
	void setBeat();
	
	void mouseDragged(ofMouseEventArgs& mouse);
	void mouseMoved(ofMouseEventArgs& mouse);
	void mousePressed(ofMouseEventArgs& mouse);
	void mouseReleased(ofMouseEventArgs& mouse);
	
	
	ofxTimer	timer;
	float		delay;
	float		lastTime;
	
	float		drawCount;
	float		drawTime;
		
};


#endif

