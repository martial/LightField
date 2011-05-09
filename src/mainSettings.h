/*
 *  mainSettings.h
 *  easyCamExample
 *
 *  Created by Martial Geoffre on 26/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MAINSTGS
#define MAINSTGS

#include "ofMain.h"

class mainSettings {

	public :
	
	static ofPoint	getGridSize();
	static ofPoint	getGridPadding();
	static ofPoint	getPanelSize();
	static int		getNumOfTubePixels();
};

#endif