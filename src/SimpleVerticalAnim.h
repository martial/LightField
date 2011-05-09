//
//  SimpleVerticalAnim.h
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SMPLVERTICALANIM
#define SMPLVERTICALAMIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class SimpleVerticalAnim : public  AbstractTubeAnimation {
    
public:
	
    SimpleVerticalAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);

	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
    
    
};

#endif