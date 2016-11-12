#pragma once
#include "ZeldaishFunctions.h"

/// <summary>
/// ZeldaishObject
/// parent class of objects in game
/// the most basic of objects
/// </summary>
class ZeldaishObject
{
public:		
	/// <summary>
	/// Initializes a new instance of the <see cref="ZeldaishObject"/> class.
	/// rectangle values default to 0
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aImgName">Name of a img.</param>
	ZeldaishObject(std::string aName, std::string aImgName);

	/// <summary>
	/// Initializes a new instance of the <see cref="ZeldaishObject"/> class.
	/// </summary>
	/// <param name="aName">a name.</param>
	/// <param name="aImgName">Name of a img.</param>
	/// <param name="aX">a x.</param>
	/// <param name="aY">a y.</param>
	/// <param name="aW">a w.</param>
	/// <param name="aH">a h.</param>
	ZeldaishObject(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH);
	~ZeldaishObject();
		
	/// <summary>
	/// Gets the name.
	/// </summary>
	/// <returns></returns>
	std::string getName();

	/// <summary>
	/// Gets the sdl rectangle.
	/// </summary>
	/// <returns>SDL Rectangle</returns>
	SDL_Rect getRectangle();

	/// <summary>
	/// Gets the x.
	/// </summary>
	/// <returns>position x</returns>
	int getX();
		
	/// <summary>
	/// Gets the y.
	/// </summary>
	/// <returns>position y</returns>
	int getY();
	
	/// <summary>
	/// Gets the w.
	/// </summary>
	/// <returns>width</returns>
	int getW();	

	/// <summary>
	/// Gets the h.
	/// </summary>
	/// <returns>heihgt</returns>
	int getH();
	
	/// <summary>
	/// Sets the x.
	/// </summary>
	/// <param name="aLocation">a location.</param>
	void setX(int aLocation);	

	/// <summary>
	/// Sets the y.
	/// </summary>
	/// <param name="aLocation">a location.</param>
	void setY(int aLocation);
	
	/// <summary>
	/// Sets the h.
	/// </summary>
	/// <param name="aSize">a size.</param>
	void setH(int aSize);
	
	/// <summary>
	/// Sets the w.
	/// </summary>
	/// <param name="aSize">a size.</param>
	void setW(int aSize);
private:

protected:
	// object name
	std::string gName;

	// name of image
	std::string gImagePath;

	// texture to display
	SDL_Texture* gTexture;

	// area of texture
	SDL_Rect* gImageArea;
};

