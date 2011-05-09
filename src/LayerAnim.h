/*
 *  LayerAnim.h
 *  LightField
 *
 *  Created by Martial Geoffre on 07/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef LYRANIM
#define LYRANIM

#include "ofMain.h"
#include "AbstractTubeAnimation.h"

class LayerAnim : public  AbstractTubeAnimation {
    
public:
	
    LayerAnim();
    
    void init(string name, vector<ofxTube*> * tubes);
    void launch(vector<ofxTube*> * tubes);
	
	
    void onAnimationStart(ofxTubeEvent * args);
    void onAnimationEnd(ofxTubeEvent * args);
	void onAnimationLoopEvent(int & a);
    
    void update();
    
    void setEstimatedAnimationTime(float time);
	
	int layerPos, sens;
    
    
};

#endif