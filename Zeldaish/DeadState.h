#pragma once
#include "ZeldaishState.h"
class DeadState :
	public ZeldaishState
{
public:
	DeadState();
	~DeadState();

	void Setup() override;

	/// <summary>
	/// Displays the about screen
	/// </summary>
	/// <param name="aRenderer">renderer.</param>
	void Display(SDL_Renderer* aRenderer) override;

	/// <summary>
	/// Handles the event.
	/// </summary>
	/// <returns>next state</returns>
	States HandleEvent(SDL_Renderer* aRenderer) override;
private:
	Button* btnMenu;
};

