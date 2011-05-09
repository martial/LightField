//
//  AbstractTubeAnimation.h
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#ifndef ABSTRCTTUBEANIM
#define ABSTRCTTUBEANIM

#include "ofMain.h"
#include "ofxTube.h"
#include "ofxTubeEvent.h"
#include "mainSettings.h"


class AbstractTubeAnimation {
    
public:
    
    AbstractTubeAnimation();
	
    virtual void init(string name, vector<ofxTube*> * tubes);
	virtual void launch(vector<ofxTube*> * tubes);
	virtual void update();
    
	virtual void onAnimationLoopEvent(int & a);
    virtual void onAnimationStart(ofxTubeEvent * args);
    virtual void onAnimationEnd(ofxTubeEvent * args);
        
    void setEstimatedAnimationTime(float time);
    
	vector<ofxTube*> *		tubes;
	
	string					name;
	int						numOfTubePixels;
	
    private:
    
	
    float					animationTime;
    
    
    
};

#endif