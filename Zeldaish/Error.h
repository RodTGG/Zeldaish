#pragma once
#include "stdafx.h"

/// Error class.
/// Displays message and exits program
///	Error returns 1
class Error
{
public:	
	/// <summary>
	/// Displays the specified message and exits.
	/// </summary>
	/// <param name="aMsg">a message.</param>
	static void Display(std::string aMessage)
	{
		system("color 04");
		std::cout << aMessage << std::endl;
		exit(1);
	}
};