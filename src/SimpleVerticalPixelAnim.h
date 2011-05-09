/*
 *  SimpleVerticalPixelAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SMPLVERTICALPXANIM
#define SMPLVERTICALPXANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class SimpleVerticalPixelAnim : public  AbstractTubeAnimation {
    
public:
	
    SimpleVerticalPixelAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);

	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
	
	
	private :
	
	
	int						pixelIndex, numOfTubePixels;
	ofxTween				pixelTween;
	ofxEasingQuint			easingquint;
    
    
};

#endif