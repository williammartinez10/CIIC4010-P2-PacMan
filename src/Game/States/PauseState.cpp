#include "PauseState.h"

PauseState::PauseState() {
	resumeButton = new Button(ofGetWidth()/2,315,150,150, "Start");
    quitButton = new Button(ofGetWidth()/10, 315,150,150,"Quit");
}
void PauseState::tick() {
	resumeButton->tick();
	if(resumeButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}else if(quitButton->wasPressed()){
        setNextState("Menu");
		setFinished(true);
    }
}
void PauseState::render() {
	
	ofDrawBitmapStringHighlight("PRESS HERE TO RESUME",ofGetWidth()/2, 330);
    ofDrawBitmapStringHighlight("PRESS HERE TO RETURN TO MENU",ofGetWidth()/10, 330);

	ofSetBackgroundColor(230, 230, 250);
	//startButton->render();
	
}

void PauseState::keyPressed(int key){
	
}

void PauseState::mousePressed(int x, int y, int button){
	resumeButton->mousePressed(x, y);
    quitButton->mousePressed(x,y);
}

void PauseState::reset(){
	setFinished(false);
	setNextState("");
	resumeButton->reset();
    quitButton->reset();
}