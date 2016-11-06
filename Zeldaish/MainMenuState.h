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
	States HandleEvent() override;
private:
	Button* btnPlay;
	Button* btnAbout;
	Button* btnExit;
};

