#pragma once
#include "ZeldaishObject.h"

class Character :
	public ZeldaishObject
{
public:
	Character(std::string aName, std::string aImgName);
	Character(std::string aName, std::string aImgName, int aX,int aY,int aW,int aH);
	~Character();
private:
protected:

};

