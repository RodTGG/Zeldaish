#pragma once
class ZeldaishState
{
public:
	ZeldaishState();
	ZeldaishState(States aId);
	~ZeldaishState();

	virtual void Display(SDL_Surface* aSurface) = 0;
	virtual int HandleEvent(SDL_Event* aEvent) = 0;

	States getID();
private:

protected:
	ZeldaishFunctions* zFunctions;
	States id;
};

