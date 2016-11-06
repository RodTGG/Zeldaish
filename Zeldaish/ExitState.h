#pragma once
#include "ZeldaishState.h"

/// <summary>
/// Exit state
/// Called when program is exiting
/// </summary>
/// <seealso cref="ZeldaishState" />
class ExitState :
	public ZeldaishState
{
public:
	ExitState();
	~ExitState();
	
	/// <summary>
	/// Displays exit window
	/// </summary>
	/// <param name="aRenderer">renderer.</param>
	void Display(SDL_Renderer* aRenderer) override;
	
	/// <summary>
	/// Handles the event.
	/// </summary>
	/// <returns>next state</returns>
	States HandleEvent() override;
private:

};

