#pragma once
#include "Character.h"

class CharacterContainer
{
public:
	CharacterContainer();
	~CharacterContainer();

	bool HasCharacter(std::string aCharacter);
	void AddCharacter(Character* aCharacter);
	void RemoveCharacter(Character* aCharacter);

	std::vector<Character*> CharacterList();
private:
	std::vector<Character*> gCharacters;
};

