#include "stdafx.h"
#include "ZeldaishEngine.h"

int main(int argc, char *argv[])
{
	ZeldaishEngine* myGame = new ZeldaishEngine();
	myGame->setup();

	while (!myGame->isExiting()) 
	{
		myGame->display();
		myGame->handleEvent();
		myGame->update();
	}

	return 0;
}