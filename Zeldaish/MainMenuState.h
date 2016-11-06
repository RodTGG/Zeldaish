#pragma once
#include "ZeldaishState.h"
#include "Button.h"

class MainMenuState :
	public ZeldaishState
{
public:
	MainMenuState();
	~MainMenuState();

	void Display(SDL_Renderer* aRenderer) override;
	States HandleEvent() override;
private:
	Button* btnPlay;
	Button* btnAbout;
	Button* btnExit;
};

