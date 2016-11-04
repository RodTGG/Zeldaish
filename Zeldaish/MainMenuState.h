#pragma once
#include "ZeldaishState.h"
#include "Button.h"

class MainMenuState :
	public ZeldaishState
{
public:
	MainMenuState();
	~MainMenuState();

	void Display(SDL_Surface* aSurface) override;
	int HandleEvent(SDL_Event* aEvent) override;
private:
	Button* myButton;
};

