/*
 *  Grid.cpp
 *  advanced3dExample
 *
 *  Created by Elliot Woods on 19/01/2011.
 *  Copyright 2011 Kimchi and Chips. All rights reserved.
 *
 */

#include "Grid.h"

#include "mainSettings.h"

Grid::Grid () {
	
	coords.x = mainSettings::getGridSize().x;
	coords.y =  mainSettings::getGridSize().y;
	
	padding.x =  mainSettings::getGridPadding().x;
	padding.y =  mainSettings::getGridPadding().y;
	
	showNumbers = false;
	
	width = coords.x * padding.x;
	height = coords.y * padding.y;
	
	centerPoint.x = ( coords.x * padding.x) * .5 - ( padding.x * .5 );
	centerPoint.y = ( coords.y * padding.y) * .5 - ( padding.y * .5 );
	
	rot.x = 0.0;
	rot.y = 0.0;
	rot.z = 0.0;
	
	rotToGo.x = 0.0;
	rotToGo.y = 0.0;
	rotToGo.z = 0.0;
	
	
	
		
	//ofRegisterMouseEvents(this);
	
}

void Grid::setSound(ofxSoundManager * sound, ofxTubeManager * tubesManager) {
		
	this->sound = sound;
	this->tubesManager = tubesManager;
}

void Grid::update () {
	
	
}

void Grid::updateMouse (ofRectangle rect) {
	
	ofVec2f mousePosScreen = ofVec3f(ofGetMouseX() - rect.width/2 - rect.x, rect.height/2 - (ofGetMouseY() - rect.y), 0);
	
	if( ofGetMousePressed(0) && mousePosScreen.x > 0  ) {
				
		ofVec2f mouseDiffScreen = (mousePosScreen - mousePosScreenPrev);
		ofVec2f mouseVelScreen = mouseDiffScreen.lengthSquared();
		
		rotToGo.y -= mousePosScreen.x - mousePosScreenPrev.x;
		rotToGo.x += mousePosScreen.y - mousePosScreenPrev.y;	
				
	}
	
	rot.x = .75 * rot.x + (1 - .75) * rotToGo.x;
	rot.y = .75 * rot.y + (1 - .75) * rotToGo.y;


	
	mousePosScreenPrev = mousePosScreen;
	
}



void Grid::drawGrid () {
	
	
	ofPushMatrix();
	
	glTranslatef(getGlobalPosition().x, getGlobalPosition().y, getGlobalPosition().z);
	
	ofPoint pos;
	
	//fbo.begin();
	ofPushMatrix();
	
	
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);
	
	glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	ofSetColor(40, 40, 40);
	ofSetLineWidth(1);
	
	for ( int i = 0; i < coords.x; i++) {		
		pos.x = (i * padding.x);
		ofLine(pos.x, 0, 0, pos.x, 0,   (coords.y * padding.y - padding.y) );
	}
	
	for ( int j = 0; j < coords.y; j++) {
		pos.y =  (j * padding.y);
		ofLine(0, 0,  pos.y, coords.x * padding.x - padding.x, 0,  pos.y);
	}
	
	ofPopMatrix();
	
	ofPopMatrix();	
	ofSetColor(255,255,255);
}

void Grid::drawTubes() {
	
	ofPushMatrix();
	
	glTranslatef(getGlobalPosition().x, getGlobalPosition().y, getGlobalPosition().z);
	
	ofPushMatrix();
	
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);
	glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	//glTranslatef(0, 20, 0);
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
	
	ofPoint pos;

	
	for ( int i = 0; i < coords.x; i++) {
		
		for ( int j = 0; j < coords.y ; j++) {
			
			pos.x = (i * padding.x);
			pos.y = (j * padding.y);
			
			int index = (int)(i * coords.y + j);
			
			tubesManager->tubes[index]->drawFor3DView(pos.x, pos.y);
			
			if ( showNumbers ) {
				ofPushStyle();
				ofSetColor(255, 255, 255);
				ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
				ofDrawBitmapString(ofToString(i * coords.y + j, 0), pos.x, 0, pos.y);
				ofPopStyle();
				
			}
			
		}
		
	}
	
	ofDisableAlphaBlending();
	
	
	
	ofPopMatrix();
	
	
	ofPopMatrix();
	ofSetColor(255,255,255);
	
}

void Grid::drawDots () {
	
	ofPushMatrix();
	
	glTranslatef(getGlobalPosition().x, getGlobalPosition().y, getGlobalPosition().z);
	
	ofPushMatrix();
	
	//glRotatef(rot.x, 1, 0, 0);
	//glRotatef(rot.y, 0, 1, 0);
	//glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	//glTranslatef(0, 20, 0);
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
	
	ofPoint pos;
	
	
	for ( int i = 0; i < coords.x; i++) {
		
		for ( int j = 0; j < coords.y; j++) {
			
			pos.x = (i * padding.x);
			pos.y = (j * padding.y);
			
			int index = (int)(i * coords.y + j);
			
			tubesManager->tubes[index]->drawFor2DView(pos.x, pos.y);

			
		}
		
	}
	
	ofDisableAlphaBlending();
	
	
	
	ofPopMatrix();
	
	
	ofPopMatrix();
	ofSetColor(255,255,255);	
	
}

void Grid::customDraw()
{
	
	
	
	//ofPushStyle();
		
	ofPoint centerPoint;
	centerPoint.x = ( coords.x * padding.x) * .5 - ( padding.x * .5 );
	centerPoint.y = ( coords.y * padding.y) * .5 - ( padding.y * .5 );
	ofPoint pos;
	
	//fbo.begin();
	ofPushMatrix();
	//glRotated(90, 0, 1, 0);
	glTranslatef(-centerPoint.x, 0, -centerPoint.y);
	
	glTranslatef(0, 20, 0);
	ofSetColor(125, 125, 125);
	ofSetLineWidth(1);
	
	for ( int i = 0; i < coords.x; i++) {		
		pos.x = (i * padding.x);
		ofLine(pos.x, 0, 0, pos.x, 0,   (coords.y * padding.y - padding.y) );
	}
	
	for ( int j = 0; j < coords.y; j++) {
		pos.y =  (j * padding.y);
		ofLine(0, 0,  pos.y, coords.x * padding.x - padding.x, 0,  pos.y);
	}
	
	
	ofSetLineWidth(4);
	ofSetHexColor(0xffffff);
	
	
	ofEnableAlphaBlending();
	
	
	
	
	for ( int i = 0; i < coords.x; i++) {
		
		for ( int j = 0; j < coords.y; j++) {
			
			pos.x = (i * padding.x);
			pos.y = (j * padding.y);
			
			int index = (int)(i * coords.y + j);
			
			tubesManager->tubes[index]->drawFor3DView(pos.x, pos.y);
			
			if ( showNumbers ) {
			ofPushStyle();
			ofSetColor(255, 255, 255);
			//ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
			ofDrawBitmapString(ofToString(i * coords.y + j, 0), pos.x, 0, pos.y);
			ofPopStyle();
			
			}
			
		}
		
	}
	
	ofDisableAlphaBlending();
	
	
	
	
	ofPopMatrix();	
	
	
	ofPopMatrix();
	
	
	//ofPopStyle();
	
	//fbo.end();
	
	/*
	ofPushMatrix();
	ofSetLineWidth(1);
	ofDrawAxis(100);
	ofPopMatrix();
	*/
	 
}