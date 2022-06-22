#include "WinState.h"

WinState::WinState() {
	restartButton = new Button(0,0,10000,10000, "Start");
}
void WinState::tick() {
	restartButton->tick();
	if(restartButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void WinState::render() {
	
	ofDrawBitmapStringHighlight("YOU WIN",ofGetWidth()/10, 300);
	ofDrawBitmapStringHighlight("PRESS ANYWHERE TO RESTART",ofGetWidth()/10, 315);
	ofSetBackgroundColor(230, 230, 250);
	//startButton->render();
	
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	restartButton->reset();
}