#pragma once
#include "State.h"
class MainMenuState :
	public State
{
public:
	MainMenuState();
	~MainMenuState();

	void display() override;
	int handleEvent() override;
};

