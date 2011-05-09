/*
 *  RainAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 05/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RNANIM
#define RNANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class RainAnim : public  AbstractTubeAnimation {
    
public:
	
    RainAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
	void launch(vector<ofxTube*> * tubes);
    
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
    void onAnimationLoopEvent(int & a);
	
    void update();
    
    void setEstimatedAnimationTime(float time);
    
	int	numOfTubePixels;
    
};

#endif