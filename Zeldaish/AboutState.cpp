#include "stdafx.h"
#include "AboutState.h"


AboutState::AboutState()
{
	gName = "About";
	gId = States::STATE_ABOUT;
	btnBack = new Button("Button Play", "btn_back.png", 0, 500, 150, 100);
}


AboutState::~AboutState()
{
}

void AboutState::Display(SDL_Renderer* aRenderer)
{
	
	gBackground = ZeldaishFunctions::loadTexture(*aRenderer, "about.png");
	SDL_RenderCopy(aRenderer, gBackground,NULL,NULL);
	btnBack->Display(aRenderer);

	SDL_DestroyTexture(gBackground);
}

States AboutState::HandleEvent(SDL_Renderer* aRenderer)
{
	States result = STATE_NULL;
	bool selected = false;

	do {
		while (SDL_PollEvent(e) != 0)
		{
			if (e->type == SDL_QUIT)
			{
				result = STATE_EXIT;
				selected = true;
			}
			else
			{
				if (ZeldaishFunctions::leftMouseButtonClicked(*e) && ZeldaishFunctions::isOver(*btnBack->getRectangle()))
				{
					result = STATE_MAINMENU;
					selected = true;
				}
			}
		}
	} while (!selected);

	return result;
}
