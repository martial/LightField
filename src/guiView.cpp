/*
 *  guiView.cpp
 *  LightField
 *
 *  Created by Martial Geoffre on 04/05/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "guiView.h"

#include "ofxSimpleGuiToo.h"

void guiView::setup(ofxSoundManager * sound, ofxTubeManager * tubesManager) {
	
	
	this->sound = sound;
	this->tubesManager = tubesManager;
	
	
	nodeGrid.setSound(sound, tubesManager);
	
		
    
    setSize( nodeGrid.width + 20,  nodeGrid.height+ 20);	
	fbo.allocate(nodeGrid.height+ 20, nodeGrid.width + 20, GL_RGBA, 1);		
	
	
	//gui.addSlider("Blur amnt", blurAmount, 0, 10);
	
	gui.addContent("Shapes", fbo);
	
}

void guiView::update() {
	
	//printf("update \n");
	
	nodeGrid.update();
	
}

void guiView::draw(int x, int y) {
	
	//ofSetColor(0, 0, 0);
	
	
	fbo.clear();
	fbo.begin();
	//cam.begin();
	
	//nodeGrid.drawGrid();
	//cam.end();
	
	ofPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(20, 20, 0);
	glRotated(180, 1, 1, 0);
	
	ofEnableAlphaBlending();
	nodeGrid.drawDots();
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255);
	ofPopMatrix();
	fbo.end();
	
	
	/*
	ofPushMatrix();
	fbo.draw(0, 0);
	ofPopMatrix();
   */
	
}

void guiView::setSize(int w, int h) {
    width = w;
    height = h;
    
}

void guiView::onWindowsResized( int w, int h) {
    
    setSize( ofGetWidth() - 320,  ofGetHeight() - 135);
    fbo.allocate(width, height, GL_RGBA, 1);
    
}
