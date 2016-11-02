#pragma once
#include <string>

class Button
{
public:
	Button(std::string aName, std::string aPath, int aX, int aY, int aW, int aH);
	~Button();

	void Display(SDL_Surface* aSurface);
private:
	std::string name;
	SDL_Surface* image;
	SDL_Rect* imageArea = new SDL_Rect();
};

