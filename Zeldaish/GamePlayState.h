#pragma once
#include "ZeldaishState.h"
class GamePlayState :
	public ZeldaishState
{
public:
	GamePlayState();
	~GamePlayState();

	void Update() override;
private:
	ZeldaishFunctions* gFunctions = new ZeldaishFunctions();
};

