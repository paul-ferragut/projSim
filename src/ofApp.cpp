#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	proj tProj;
	for (int i = 0;i < 5;i++) {
		/*
		tProj.projector.setWidth(1920);
		tProj.projector.setHeight(1080);
		tProj.projector.setProjection(0.5,ofVec2f(0.0,0.0));
		
		projector.push_back(tProj);
		*/

		projector[i].projector.setWidth(1920);
		projector[i].projector.setHeight(1080);
		projector[i].projector.setProjection(0.5, ofVec2f(0.0, 0.0));
		
	}

	thrownRatio = 0.5;


	gui1.setup();
	gui1.add(thrownRatio.setup("ratio", 0.5, 0.1, 2.0));
	for (int i = 0; i <PROJ; i++) //projector.size()
	{
	//	cout << "i" << i << endl;
		gui1.add(projector[i].position.setup("position "+ofToString(i), ofVec3f(0,35,0), ofVec3f(40,35,-200), ofVec3f(120,35,-50)));
		gui1.add(projector[i].rotation.setup("rotation " + ofToString(i), ofVec3f(0, 0, 0), ofVec3f(-0, -180, 0), ofVec3f(-80, 180, 0)));

	}
	

		


	gui1.loadFromFile("settings.xml");


	/*
	gui.add(projector[0].position.setup("position " + ofToString(0), ofVec3f(0, 0, 0), ofVec3f(-900, -900, -900), ofVec3f(900, 900, 900)));
	gui.add(projector[0].rotation.setup("rotation " + ofToString(0), ofVec3f(0, 0, 0), ofVec3f(-180, -180, -180), ofVec3f(180, 180, 180)));


	gui.add(projector[1].position.setup("position " + ofToString(1), ofVec3f(0, 0, 0), ofVec3f(-900, -900, -900), ofVec3f(900, 900, 900)));
	gui.add(projector[1].rotation.setup("rotation " + ofToString(1), ofVec3f(0, 0, 0), ofVec3f(-180, -180, -180), ofVec3f(180, 180, 180)));
	//gui.add(test.setup("rotation" , ofVec3f(0, 0, 0), ofVec3f(-180, -180, -180), ofVec3f(180, 180, 180)));
	*/

	

	model.loadModel("jaguarshoes.obj");
	modelMesh = model.getMesh(0);
	
	//

	ofSetVerticalSync(true);
	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int i = 0; i <PROJ; i++) //projector.size()
	{
	
		projector[i].projector.setProjection(thrownRatio, ofVec2f(0.0,0.0));
		projector[i].projector.setPosition(projector[i].position);

		projector[i].projector.setOrientation(projector[i].rotation);

		projector[i].pixels.clear();

		for (int j = 0; j<1920; j += 64)
			for (int k = 0; k<1080; k += 64)
				projector[i].pixels.push_back(ofVec2f(j, k));
		projector[i].projector.castPixels(projector[i].pixels, projector[i].rays);

	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);	
	
	ofSetLineWidth(2.0);
	ofEnableDepthTest();
	ofEnableLighting();
	
	cam.begin();
	//ofDrawGrid(10, 5, true);
	ofSetColor(255,255,255);
	light.enable();	


	ofPushMatrix();
	ofScale(0.1,0.1,0.1);
	modelMesh.draw();
	ofSetColor(0, 0, 0);
	//modelMesh.drawWireframe();
	ofPopMatrix();
	ofEnableAlphaBlending();
	ofSetColor(255, 100);
	
	for (int i = 0;i <PROJ;i++) { //projector.size()
		vector<ofRay>::iterator it;
	for (it = projector[i].rays.begin(); it != projector[i].rays.end(); it++)
		it->draw();
	
	}



	cam.end();

	ofDisableDepthTest();
	light.disable();
	ofDisableLighting();
	ofSetColor(255, 255, 255);
	

	gui1.draw();
	
}
void ofApp::exit() {
	gui1.saveToFile("settings.xml");
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
	//	thrownRatio += 0.01;
	}
	if (key == 'q') {
	//	thrownRatio -= 0.01;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
void ofApp::updateProjector(proj p) {
	//projector.setWidth(this->resolution.x);
	//projector.setHeight(this->resolution.y);
	//projector.setProjection(this->throwRatio, this->lensOffset);
	//projector.setPosition(this->position);
	/*
	pixels.clear();
	for (int i = 0; i<this->resolution.x; i += 32)
		for (int j = 0; j<this->resolution.y; j += 32)
			pixels.push_back(ofVec2f(i, j));
	projector.castPixels(pixels, rays);

	*/
}