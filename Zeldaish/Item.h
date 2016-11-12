#pragma once
#include "ZeldaishObject.h"
class Item :
	public ZeldaishObject
{
public:
	Item(std::string aName, std::string aImgName);
	~Item();
};

