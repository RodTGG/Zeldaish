#include "stdafx.h"
#include "ZeldaishEngine.h"

int main(int argc, char *argv[])
{
	ZeldaishEngine* myGame = new ZeldaishEngine();
	myGame->setup();
	myGame->run();

	return 0;
}