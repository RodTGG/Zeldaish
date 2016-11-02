#include "stdafx.h"
#include "GameEngine.h"

int main(int argc, char *argv[])
{
	GameEngine* myGame = new GameEngine();
	myGame->setup();

	return 0;
}