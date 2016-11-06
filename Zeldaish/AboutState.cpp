#include "stdafx.h"
#include "AboutState.h"


AboutState::AboutState()
{
	gId = States::STATE_ABOUT;
	btnBack = new Button("Button Play", "btn_back.png", 5, 500, 150, 100);
}


AboutState::~AboutState()
{
}

void AboutState::Display(SDL_Renderer* aRenderer)
{
	
	gBackground = gFunctions->loadTexture(*aRenderer, "about.png");
	SDL_RenderCopy(aRenderer, gBackground,NULL,NULL);
	btnBack->Display(aRenderer);

	SDL_DestroyTexture(gBackground);
}

States AboutState::HandleEvent() 
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
				if (gFunctions->leftMouseButtonClicked(*e) && gFunctions->isOver(btnBack->getRectangle()))
				{
					result = STATE_MAINMENU;
					selected = true;
				}
			}
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	} while (!selected);

	return result;
}
