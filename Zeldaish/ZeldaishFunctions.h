#pragma once
class ZeldaishFunctions
{
public:
	ZeldaishFunctions();
	~ZeldaishFunctions();

	bool isOver(int& x, int& y, SDL_Rect& aArea);
	bool leftMouseButtonClicked(SDL_Event* aEvent);
};

