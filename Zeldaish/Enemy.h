#pragma once
#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(std::string aName, std::string aImgName);
	~Enemy();

	void Update(Directions aDir, Character* aCharacter) override;
	void Move(Directions) override;
};

