#pragma once
#include "ZeldaishState.h"
#include "Button.h"

/// <summary>
/// About state
/// about menu state shows information about program
/// </summary>
/// <seealso cref="ZeldaishState" />
class AboutState :
	public ZeldaishState
{
public:
	AboutState();
	~AboutState();
		
	/// <summary>
	/// Updates this instance.
	/// </summary>
	void Update() override;

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

	/// <summary>
	/// Button to return to main menu
	/// </summary>
	Button* btnBack;
};