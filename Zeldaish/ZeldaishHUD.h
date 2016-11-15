#pragma once
#include "ZeldaishObject.h"
#include "Player.h"

class ZeldaishHUD :
	public ZeldaishObject
{
public:
	ZeldaishHUD();
	~ZeldaishHUD();

	void Update(Player* aPlayer);

	void Display(SDL_Renderer* aRender, Player* aPlayer);
private:
	ZeldaishObject* gHearts[3];
};

