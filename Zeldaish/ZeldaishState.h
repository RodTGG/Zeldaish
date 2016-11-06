#pragma once
class ZeldaishState
{
public:
	ZeldaishState();
	ZeldaishState(States aId);
	~ZeldaishState();

	virtual void Display(SDL_Surface* aSurface) = 0;
	virtual States HandleEvent() = 0;

	States getID();
private:

protected:
	SDL_Event* e;
	ZeldaishFunctions* gFunctions;
	States gId;
};

