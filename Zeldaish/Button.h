#pragma once
#include "ZeldaishObject.h"

/// <summary>
/// Button class
/// A button that can be added to a SDL surface
/// Scales to parameter values using SDL rectangle and SDL_BlitScaled
/// </summary>
class Button : public ZeldaishObject
{
public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Button"/> class.
	/// </summary>
	/// <param name="aName">button name.</param>
	/// <param name="aPath">image path.</param>
	/// <param name="aX">x.</param>
	/// <param name="aY">y.</param>
	/// <param name="aW">width.</param>
	/// <param name="aH">height.</param>
	Button(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);

	/// <summary>
	/// Finalizes an instance of the <see cref="Button"/> class.
	/// </summary>
	~Button();
	
	/// <summary>
	/// Displays the button to the specified surface.
	/// </summary>
	/// <param name="aSurface">a surface.</param>
	void Display(SDL_Surface* aSurface);
private:
};

