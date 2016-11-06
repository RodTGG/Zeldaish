#pragma once
class ZeldaishFunctions
{
public:
	ZeldaishFunctions();
	~ZeldaishFunctions();

	bool isOver(SDL_Rect& aArea);
	bool leftMouseButtonClicked(SDL_Event& aEvent);
	SDL_Texture* loadTexture(SDL_Renderer& aRenderer, std::string aPath);
};

