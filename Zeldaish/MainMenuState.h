#pragma once
#include "ZeldaishState.h"
#include "Button.h"

/// <summary>
/// Main menu state
/// games main menu
/// </summary>
/// <seealso cref="ZeldaishState" />
class MainMenuState :
	public ZeldaishState
{
public:
	MainMenuState();
	~MainMenuState();
	
	/// <summary>
	/// Displays the interface
	/// </summary>
	/// <param name="aRenderer">renderer.</param>
	void Display(SDL_Renderer* aRenderer) override;	

	/// <summary>
	/// Handles the event.
	/// </summary>
	/// <returns>next state</returns>
	States HandleEvent() override;
private:
	Button* btnPlay;	//play button
	Button* btnAbout;	//about button
	Button* btnExit;	//exit button
};

