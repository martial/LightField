/*
 *  guiPanel.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GUIPNL
#define GUIPNL

#include "ofMain.h"
#include "fpsViewer.h"
#include "ofxXmlSettings.h"
#include "ofxPalettePicker.h"

class guiPanel  {
	
	public:
	
	guiPanel();
	
	void	setup();
	void	parseXML();
	void	update();
	void	draw();
	
	void	onClickHandler(string & name);
	
	ofColor				globalColor;
	vector<ofColor>		colors;
	
	private:
	
	ofImage			logo;
	fpsViewer		fps;
	ofColor			color;
	
	
	ofxXmlSettings	xmlSettings;
	ofxPalettePicker	*	globalPicker;
	vector<ofxPalettePicker*>	pickers;
	
	int					numOfPanels;
	bool				allColorsEnabled;

};

#endif