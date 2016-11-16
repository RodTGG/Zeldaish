#pragma once
#include "ZeldaishObject.h"

/// <summary>
/// ZeldaishFunctions class
/// addtional functions to check for states and add functionality to game
/// </summary>
class ZeldaishFunctions
{
public:	
	/// <summary>
	/// Determines whether the mouse is over a specified area.
	/// </summary>
	/// <param name="aArea">a Rectangle.</param>
	/// <returns>
	///   <c>true</c> if the mouse is over a specified area; otherwise, <c>false</c>.
	/// </returns>
	static bool isOver(const SDL_Rect& aRectangle);
	
	/// <summary>
	/// Checks if the left mouse is clicked
	/// </summary>
	/// <param name="aEvent">a event.</param>
	/// <returns>
	///<c>true</c> if mouse left button is pressed; otherwise, <c>false</c>
	///</returns>
	static bool leftMouseButtonClicked(const SDL_Event& aEvent);
		
	/// <summary>
	/// Buttons down.
	/// </summary>
	/// <param name="aEvent">a event.</param>
	/// <returns></returns>
	static bool buttonDown(const SDL_Event& aEvent, SDL_Keycode aCode);

	/// <summary>
	/// Turns surface to texture so that in can be used by renderer
	/// automatically checks in resources folder
	/// </summary>
	/// <param name="aRenderer">a renderer.</param>
	/// <param name="aPath">a path to file.</param>
	/// <returns>converted texture</returns>
	static SDL_Texture* loadTexture(SDL_Renderer& aRenderer, const std::string aPath);
	
	/// <summary>
	/// Loads the specified music.
	/// If NULL throws Error
	/// </summary>
	/// <param name="aPath">a path.</param>
	/// <returns></returns>
	static Mix_Music* loadMusic(const std::string aPath);

	static Mix_Chunk* loadSFX(const std::string aPath);
	
	/// <summary>
	/// Checks collision with object.
	/// </summary>
	/// <param name="aSource">a source.</param>
	/// <param name="aObject">a object.</param>
	/// <returns>
	///	<c>true</c> if collision detected;otherwise, <c>false</c>
	///</returns>
	static bool CollidedWith(ZeldaishObject& aSource, ZeldaishObject& aObject);

	static Directions MoveTowards(ZeldaishObject& aSource, ZeldaishObject& aObject);
};

