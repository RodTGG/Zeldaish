#pragma once
class ZeldaishState
{
public:
	ZeldaishState();
	ZeldaishState(States aId);
	~ZeldaishState();

	virtual void Display(SDL_Renderer* aRenderer) = 0;
	virtual States HandleEvent() = 0;

	States getID();
private:

protected:
	SDL_Event* e;
	SDL_Texture* gBackground;

	ZeldaishFunctions* gFunctions;
	States gId;
};

