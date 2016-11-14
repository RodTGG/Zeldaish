#pragma once

/// <summary>
/// Parent state class
/// contains methods and properties for child classes
/// </summary>
class ZeldaishState
{
public:
	ZeldaishState();
	ZeldaishState(States aId);
	~ZeldaishState();
	
	/// <summary>
	/// Updates this instance.
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// Displays the interface
	/// </summary>
	/// <param name="aRenderer">renderer.</param>
	virtual void Display(SDL_Renderer* aRenderer) = 0;
	
	/// <summary>
	/// Handles the event.
	/// </summary>
	/// <returns>next state</returns>
	virtual States HandleEvent(SDL_Renderer* aRenderer) = 0;
	
	/// <summary>
	/// Gets the identifier.
	/// </summary>
	/// <returns>State</returns>
	States getID();
	std::string getName();
private:

protected:
	std::string gName;
	SDL_Event* e;	//event for polling or waiting
	SDL_Texture* gBackground; //background texture
	States gId; //id
};

