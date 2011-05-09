#pragma once

#include "ofMain.h"
#include "ofxSoundManager.h"
#include "guiPanel.h"
#include "viewThreeD.h"
#include "ofxTubeManager.h"

#include "mainAnimData.h"
#include "ofxColorUtils.h"
#include "guiView.h"


class testApp : public ofBaseApp {
	public:
	
		void setup();
		void update();
		void draw();
		
		void audioReceived (float * input, int bufferSize, int nChannels);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

		ofxSoundManager			soundManager;
	
		guiPanel				panel;
		
		ofxTubeManager			tubesManager;
	
		guiView					view2D;
		viewThreeD				view3D;
	
		mainAnimData			animData;
	ofxColorUtils				colorUtils;
		
		static bool				keyShiftPressed;
        
        //BeatTrackTest               test;
	
		
};
