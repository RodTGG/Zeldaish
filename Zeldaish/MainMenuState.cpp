#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	gId = States::STATE_MAINMENU;
	btnPlay = new Button("Button Play", "btn_play.png", 20, 20, 150, 100);
	btnAbout = new Button("Button About", "btn_about.png", 20, 140, 150, 100);
	btnExit = new Button("Button Exit", "btn_exit.png", 20, 260, 150, 100);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Display(SDL_Surface* aSurface)
{
	btnPlay->Display(aSurface);
	btnAbout->Display(aSurface);
	btnExit->Display(aSurface);
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


			gFunctions->isOver(btnPlay->getRectangle());

			if (gFunctions->leftMouseButtonClicked(*e) && gFunctions->isOver(btnPlay->getRectangle()))
			{
				result = STATE_GAMEPLAY;
				selected = true;
			}
			else if (gFunctions->leftMouseButtonClicked(*e) && gFunctions->isOver(btnAbout->getRectangle()))
			{
				result = STATE_ABOUT;
				selected = true;
			}
			else if (gFunctions->leftMouseButtonClicked(*e) && gFunctions->isOver(btnExit->getRectangle()))
			{
				result = STATE_EXIT;
				selected = true;
			}



			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	} while (!selected);


	return result;
}
