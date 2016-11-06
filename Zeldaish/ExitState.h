#pragma once
#include "ZeldaishState.h"
class ExitState :
	public ZeldaishState
{
public:
	ExitState();
	~ExitState();

	void Display(SDL_Surface* aSurface) override;
	States HandleEvent() override;
private:

};

