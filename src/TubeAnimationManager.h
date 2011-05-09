//
//  TubeAnimationManager.h
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#ifndef TBANIMMNGR
#define TBANIMMNGR

#include "ofMain.h"
#include "AbstractTubeAnimation.h"
#include "ofxTube.h"
#include "ofxTubeEvent.h"
#include "ofxAnimPlayer.h"

class TubeAnimationManager {
    
  public:
    
    TubeAnimationManager();
    void setup(vector<ofxTube*> * tubes, ofxAnimPlayer * player);
    void setAnimations();
    void update();
    
    void setCurrentAnimationById(int num);
    
	void onAnimationLoopEvent(int & a) ;
	void onActiveEvent(ofxTubeEvent & args);
    
    
    private:
    
	vector<ofxTube*>				*	tubes;
    vector<AbstractTubeAnimation*>      animations;
	AbstractTubeAnimation			*	currentAnimation;
	
	ofxAnimPlayer					*	player;
	
	
	int									mode, oldMode;
};

#endif