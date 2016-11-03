#pragma once
#include "State.h"
class MainMenuState :
	public State
{
public:
	MainMenuState();
	~MainMenuState();

	void Display() override;
	int HandleEvent() override;
};

