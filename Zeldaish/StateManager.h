#pragma once
#include "ZeldaishState.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	void setNextState(States aState);
	void changeState();
	ZeldaishState* getCurrentSate();
private:
	ZeldaishState* currentSate;
	ZeldaishState* nextState;
};

