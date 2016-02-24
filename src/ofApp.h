#pragma once

#include "ofMain.h"
#include "ofxRay.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

#define PROJ 4

struct proj {
		ofProjector projector;
		vector<ofRay> rays;
		vector<ofVec2f> pixels;

		ofxVec3Slider position;
		ofxVec3Slider rotation;

		ofVec2f resolution;
		float throwRatio;
		ofVec2f lensOffset;
		

};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void updateProjector(proj p);
		//vector<proj>projector;

		proj projector[PROJ];
		ofxFloatSlider thrownRatio;
		ofxPanel gui1;


		ofxAssimpModelLoader model;
		ofMesh modelMesh;

		ofEasyCam cam;

		ofLight light;
		 

	//	ofxVec3Slider test;

};
