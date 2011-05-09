/*
 *  Grid.h
 *  advanced3dExample
 *
 *  Created by Elliot Woods on 19/01/2011.
 *  Copyright 2011 Kimchi and Chips. All rights reserved.
 *
 */

// Grid is a custom 3D
// object that we've
// created in this
// example.
//
// We inherit from ofNode

#ifndef GRD
#define GRD

#include "ofMain.h"
#include "ofxSoundManager.h"
#include "ofxTubeManager.h"


class Grid : public ofNode
{
public:
	Grid();
	void		setSound(ofxSoundManager * sound, ofxTubeManager * tubesManager);
	
	void		update();
	void		updateMouse (ofRectangle rect);
	
	void		drawGrid();
	void		drawDots();
	void		drawTubes();
	void		customDraw();
	
	ofPoint		coords;
	ofPoint		padding;
	float		width, height;
	
	bool						showNumbers;
	
	//ofFbo						fbo;
	
private:
	ofxSoundManager		*		sound;
	ofxTubeManager		*		tubesManager;
	
	ofPoint						centerPoint;
	
	ofVec3f						rotToGo, rot;
	ofVec2f						mousePosScreenPrev;
	int							lastMouseY;
	
	
};

#endif