#pragma once
#include "ZeldaishState.h"
#include "Button.h"

class AboutState :
	public ZeldaishState
{
public:
	AboutState();
	~AboutState();

	void Display(SDL_Renderer* aRenderer) override;
	States HandleEvent() override;
private:
	Button* btnBack;
};