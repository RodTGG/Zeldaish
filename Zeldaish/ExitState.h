#pragma once
#include "ZeldaishState.h"
class ExitState :
	public ZeldaishState
{
public:
	ExitState();
	~ExitState();

	void Display(SDL_Renderer* aRenderer) override;
	States HandleEvent() override;
private:

};

