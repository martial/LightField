//
//  SimpleVerticalAnim.cpp
//  LightField
//
//  Created by Martial Geoffre on 03/05/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SimpleVerticalAnim.h"


SimpleVerticalAnim::SimpleVerticalAnim () {
    AbstractTubeAnimation::AbstractTubeAnimation();	
}

void SimpleVerticalAnim::init(string name, vector<ofxTube*> * tubes) {
	AbstractTubeAnimation::init(name, tubes);
}

void SimpleVerticalAnim::launch(vector<ofxTube*> * tubes) {
}


void SimpleVerticalAnim::onAnimationStart(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationStart(args); 
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(1, 1);
	
		printf("yes \n");
	
	
}

void SimpleVerticalAnim::onAnimationEnd(ofxTubeEvent * args) {
    AbstractTubeAnimation::onAnimationEnd(args);
	ofxTube * tube = tubes->at(args->id);
	tube->changeSizePct(0, 2000);
}

void SimpleVerticalAnim::onAnimationLoopEvent(int & a) {
	
}

void SimpleVerticalAnim::update () {
    AbstractTubeAnimation::update();
    
}