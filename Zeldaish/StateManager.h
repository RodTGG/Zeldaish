#pragma once
#include "ZeldaishState.h"

/// <summary>
/// Manages states for Zeldaish engine
/// </summary>
class StateManager
{
public:
	StateManager();
	~StateManager();
	
	/// <summary>
	/// Sets the next state.
	/// </summary>
	/// <param name="aState">a state.</param>
	void setNextState(States aState);
	
	/// <summary>
	/// Changes the current state to the the next
	/// </summary>
	void changeState();
	
	/// <summary>
	/// Gets the current sate.
	/// </summary>
	/// <returns>a State class</returns>
	ZeldaishState* getCurrentSate();
	ZeldaishState* getNextState();
private:
	ZeldaishState* gCurrentSate;	//current state
	ZeldaishState* gNextState;		//next state
};

