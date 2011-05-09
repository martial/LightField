/*
 *  viewThreeD.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "viewThreeD.h"

#include "ofxSimpleGuiToo.h"

#include "mainSettings.h"

void viewThreeD::setup(ofxSoundManager * sound, ofxTubeManager * tubesManager) {
	
	
	this->sound = sound;
	this->tubesManager = tubesManager;
	
	
	nodeGrid.setSound(sound, tubesManager);
	
	camDistance =	400.0;
	blurAmount =	0.8;
	zDiff =			0.0;
    
	
	
    setSize( mainSettings::getPanelSize().x - 320,  ofGetHeight() - 135);
    
	ofNode center;
    center.setPosition( width * .5 , height * .5, 0);
	
	cam.setDistance(camDistance);
	cam.enableMouseInput();

	
	fbo.allocate(width, height, GL_RGBA, 1);		
	
	blurShaderH.setup("", "shaders/blur_frag.glsl");
	
	gui.addSlider("Blur amnt", blurAmount, 0, 10);
	
	//gui.addFboContent("Equalizer", fbo);

}

void viewThreeD::update() {
	
	//printf("update \n");
	
	nodeGrid.update();
	
	
	
	if ( ofGetKeyPressed(122) && ofGetMousePressed(0)) {
		
		cam.disableMouseInput();
		camDistance = 0 + ofGetMouseY() * 650 / ofGetHeight();
		cam.setDistance(camDistance);

	} else 
	cam.enableMouseInput();
}

void viewThreeD::draw(int x, int y) {
	
	//ofSetColor(0, 0, 0);
	
	
	ofRectangle viewport;
	viewport.set(0,0,width,height);
	
	ofVec3f pos;
	pos.x = width *.5;
	pos.y = height *.45;
	pos.z = 250 + zDiff;
	
	nodeGrid.setPosition(pos);
	
	nodeGrid.updateMouse(viewport);
	
	fbo.clear();
	fbo.begin();
	//cam.begin();
		
	nodeGrid.drawGrid();
	//cam.end();
	fbo.end();

	fbo.draw(x, y, width,height);
	
	
	
	fbo.clear();
	fbo.begin();

	
	glColor3f(1, 1, 1);
	
	ofEnableAlphaBlending();
	
	
	//cam.begin(viewport);
	glEnable (GL_DEPTH_TEST);
    //glShadeModel (GL_SMOOTH);
	nodeGrid.drawTubes();
	glDisable(GL_DEPTH_TEST);
	//cam.end();
	
	ofDisableAlphaBlending();
	ofSetColor(255, 255, 255);
	fbo.end();
	
	
		
	if (blurAmount == 0.0 ) {
	ofEnableAlphaBlending();
	glColor3f(1,1,1);
	fbo.draw(x, y);
	ofDisableAlphaBlending();
		
	} else {
	
	ofEnableAlphaBlending();
	glColor3f(1,1,1);
	
	blurShaderH.begin();
	blurShaderH.setUniform1i("tex0", 0);
	blurShaderH.setUniform1f("sampleOffset", blurAmount);
	fbo.bind();
	fbo.draw(x, y);
	fbo.unbind();
	blurShaderH.end();
	ofDisableAlphaBlending();
		
	}
	 
    
	
}

void viewThreeD::setSize(int w, int h) {
    width = w;
    height = h;
    
}

void viewThreeD::onWindowsResized( int w, int h) {
    
    setSize( mainSettings::getPanelSize().x - 320,  ofGetHeight() - 135);
    fbo.allocate(width, height, GL_RGBA, 1);
    ofNode center;
    center.setPosition( width * .5 , height * .5, 0);
}
