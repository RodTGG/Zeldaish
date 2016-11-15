#pragma once
#include "ZeldaishState.h"
#include "ZeldaishHUD.h"
#include "Enemy.h"
#include "Player.h"

class GamePlayState :
	public ZeldaishState
{
public:
	GamePlayState();
	~GamePlayState();
	
	void Setup() override;
	void UpdateEnemies();
	void CheckCollision();

	States HandleInput();
	/// <summary>
	/// Updates this instance.
	/// </summary>
	void Update() override;

	/// <summary>
	/// Displays the interface
	/// </summary>
	/// <param name="aRenderer">renderer.</param>
	void Display(SDL_Renderer* aRenderer) override;

	/// <summary>
	/// Handles the event.
	/// </summary>
	/// <returns>next state</returns>
	States HandleEvent(SDL_Renderer* aRenderer) override;
private:
	Player* gPlayer;
	ZeldaishHUD* gHud;
};

