/*
 *  guiPanel.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "guiPanel.h"
#include "ofxSimpleGuiToo.h"



guiPanel::guiPanel () {

}

void guiPanel::setup () {
	
	logo.loadImage("logo.png");
	fps.setup(256, 40, 60);
	
	xmlSettings.loadFile("colors.xml");	
	parseXML();
	
	
	gui.show();
	gui.addFboContent("fps", fps.fbo);
	
	//memset(colors, 0, sizeof(int) * sizeof(colors));
	globalColor.set(255,255,255);
	//gui.addColorPicker("color", &color.r);

}

void guiPanel::parseXML() {
	
	xmlSettings.pushTag("colors");
	
	numOfPanels = xmlSettings.getNumTags("panel");
	colors.reserve(numOfPanels);
	
	for ( int i = 0; i < numOfPanels; i++ ) {
		
		xmlSettings.pushTag("panel", i);
		
		ofColor color;
		color.set(255, 255, 255);
		colors.push_back(color);
		
		string name = ( i != numOfPanels-1 ) ? "Gradient " + ofToString(i) : "All Colors";
		ofColor * targetColor = ( i != numOfPanels-1 ) ? &colors[i] : &globalColor;
		
		ofxPalettePicker * palette = &gui.addPalettePicker(name, targetColor);
		ofAddListener(palette->onClickEvent, this, &guiPanel::onClickHandler);
		pickers.push_back(palette);
		
		int numOfColors = xmlSettings.getNumTags("color");
		
		for ( int j=0; j<numOfColors;j++) {
			
			ofColor colorPalette;
			int r = xmlSettings.getAttribute("color", "r", 0, j);
			int g = xmlSettings.getAttribute("color", "g", 0, j);
			int b = xmlSettings.getAttribute("color", "b", 0, j);
			colorPalette.set(r, g, b);
			palette->addColor(colorPalette);
			
		}
		xmlSettings.popTag();
	}
	
}

void guiPanel::onClickHandler(string & name) {
	
	if ( name=="All Colors" ) {
		allColorsEnabled = true;
	} else {
		allColorsEnabled = false;
	}
	
}

void guiPanel::update () {
	fps.update();
}

void guiPanel::draw () {
	
	ofEnableAlphaBlending();
	ofSetHexColor(0xffffff);
	logo.draw(0, 0);
	ofDisableAlphaBlending();
	fps.draw(0, 0, 256, 40, true);
	gui.draw();
}