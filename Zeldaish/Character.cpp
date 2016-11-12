#include "stdafx.h"
#include "Character.h"


Character::Character(std::string aName, std::string aImgName) : ZeldaishObject(aName, aImgName)
{
}

Character::Character(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : ZeldaishObject(aName, aImgName, aX, aY, aW, aH)
{
}



Character::~Character()
{
}
