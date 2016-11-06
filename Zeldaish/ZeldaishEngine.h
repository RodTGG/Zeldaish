#pragma once
#include "StateManager.h"
#include "Button.h"

/// <summary>
/// Zeldaish engine class
/// Initializes SDL and external dependencies
/// handles state manager
/// runs event loop and display thread
/// </summary>
class ZeldaishEngine
{
public:
	ZeldaishEngine();
	~ZeldaishEngine();
	
	/// <summary>
	/// Initializes SDL and other dependencies
	/// throws error if not able to
	/// </summary>
	void init();
	
	/// <summary>
	/// Sets up the game by calling init, setting render size and calling load.
	/// </summary>
	void setup();
	
	/// <summary>
	/// Closes this instance.
	/// closes SDL and dependencies
	/// </summary>
	void close();	

	/// <summary>
	/// Shows splashscreen
	/// </summary>
	void load();
	
	/// <summary>
	/// Handles state event and sets next state.
	/// </summary>
	void handleEvent();
	
	/// <summary>
	/// Updates this instance.
	/// calls for change state
	/// </summary>
	void update();
	
	/// <summary>
	/// Displays the state interface.
	/// clears texture
	/// updates screen
	/// puts display thread to sleep to lower CPU usage
	/// </summary>
	void display();
	
	/// <summary>
	/// Runs this instance.
	/// starts display thread
	/// game loop
	/// </summary>
	void run();
	
	/// <summary>
	/// Determines whether this instance is exiting.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is exiting; otherwise, <c>false</c>.
	/// </returns>
	bool isExiting();
private:
	//exit state bool
	bool exiting;

	//display thread
	std::thread* gDisplayThread;

	//event thread
	std::thread* gEventThread;

	//renderer
	SDL_Renderer* gRenderer;

	//state manager
	StateManager* gStateManager;

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The image we will load and show on the screen
	SDL_Texture* SplashScreen;
};

