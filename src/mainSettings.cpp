/*
 *  mainSettings.cpp
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "mainSettings.h"

ofPoint mainSettings::getGridSize () {
	ofPoint size;
	size.x = 8;
	size.y = 11;
	return size;
}

ofPoint mainSettings::getGridPadding () {
	
	ofPoint padding;
	padding.x = 12.0;
	padding.y = 47.3;
	return padding;
	
}

ofPoint mainSettings::getPanelSize () {
	
	ofPoint size;
	size.x = 1440.0;
	size.y = 900.3;
	return size;
	
}

int mainSettings::getNumOfTubePixels () {
	return 36;
	
}