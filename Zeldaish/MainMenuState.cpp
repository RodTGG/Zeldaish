#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	gId = States::STATE_MAINMENU;
	btnPlay = new Button("Button Play", "btn_play.png", 350, 20, 150, 100);
	btnAbout = new Button("Button About", "btn_about.png", 350, 140, 150, 100);
	btnExit = new Button("Button Exit", "btn_exit.png", 350, 260, 150, 100);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Display(SDL_Renderer* aRenderer)
{
	gBackground = ZeldaishFunctions::loadTexture(*aRenderer, "menu_background.png");
	SDL_RenderCopy(aRenderer, gBackground, NULL, NULL);
	btnPlay->Display(aRenderer);
	btnAbout->Display(aRenderer);
	btnExit->Display(aRenderer);
	
	//Clear memory
	SDL_DestroyTexture(gBackground);
}

States MainMenuState::HandleEvent()
{
	States result = STATE_MAINMENU;
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
				if (ZeldaishFunctions::leftMouseButtonClicked(*e) && ZeldaishFunctions::isOver(btnPlay->getRectangle()))
				{
					result = STATE_GAMEPLAY;
					selected = true;
				}
				else if (ZeldaishFunctions::leftMouseButtonClicked(*e) && ZeldaishFunctions::isOver(btnAbout->getRectangle()))
				{
					result = STATE_ABOUT;
					selected = true;
				}
				else if (ZeldaishFunctions::leftMouseButtonClicked(*e) && ZeldaishFunctions::isOver(btnExit->getRectangle()))
				{
					result = STATE_EXIT;
					selected = true;
				}
			}
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	} while (!selected);

	return result;
}
