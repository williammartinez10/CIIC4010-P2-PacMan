#pragma once

#include "State.h"
#include "Button.h"

class PauseState : public State {
private:
	Button *resumeButton;
    Button *quitButton;

public:
	PauseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
