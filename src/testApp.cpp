#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	//ofSetVerticalSync(true);
	
	ofSoundStreamSetup(0,2,this, 44100, 128, 4);	
	
	//ofEnableSmoothing();
	
	soundManager.setup();
	soundManager.addGui();
	
	animData.setup();
	
	tubesManager.setup(&soundManager, &animData, &panel);
	
	panel.setup();
	
	view2D.setup(&soundManager, &tubesManager);
	view3D.setup(&soundManager, &tubesManager);
    
   		
}

//--------------------------------------------------------------
void testApp::update(){
	
	tubesManager.update();
	view2D.update();
	view3D.update();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(10,10,10);
	ofSetColor(255, 255, 255);
	
	soundManager.debugDraw();
	view3D.draw(300, 115);
	
	view2D.draw(0,0);
	
	panel.draw();
	
    
    ofEnableAlphaBlending();
	ofSetColor(255, 255, 255,255);
	ofFbo * display = tubesManager.drawForDisplay(1440, 0);
	ofDisableAlphaBlending();

	
	vector<ofColor> * newColors = colorUtils.getGradient(&panel.colors);
	float size = 1680 / 128;
	for ( int i=0; i< newColors->size(); i++) {
		ofColor current = newColors->at(i);
		ofSetColor(current.r, current.g, current.b);
		ofRect(i*size, 80, size, .5);
	}
	
	
}

//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){	
	soundManager.audioReceived(input, bufferSize);
    
    //test.analyze(input);

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	printf("key : %d\n", key);
	
	switch(key) {
			
		case 'q':
			view3D.zDiff +=10;
			break;
			
		case 'w':
			view3D.zDiff -=10;
			break;
			
		case 'b':
			break;
			
		case 356:
			tubesManager.pushAnimation();
			break;

			
		case 358:
			tubesManager.popAnimation();
			break;
			
			
		case 'R':
		case 'r':
			soundManager.setup();
			break;
			
		case 'N':
		case 'n':
			view3D.nodeGrid.showNumbers = !view3D.nodeGrid.showNumbers;
			break;
			
		
		case 'F':
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    printf("key %d\n", button);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
    view3D.onWindowsResized(w,h);

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
