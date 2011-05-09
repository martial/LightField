#include "ofAppGlutWindow.h"
#include "testApp.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1440, 900, OF_WINDOW);
	ofRunApp(new testApp());
}
