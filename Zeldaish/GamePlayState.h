#pragma once
#include "ZeldaishState.h"
class GamePlayState :
	public ZeldaishState
{
public:
	GamePlayState();
	~GamePlayState();
private:
	ZeldaishFunctions* gFunctions = new ZeldaishFunctions();
};

