#include "stdafx.h"
#include "CharacterContainer.h"


CharacterContainer::CharacterContainer()
{
}


CharacterContainer::~CharacterContainer()
{
}

bool CharacterContainer::HasCharacter(std::string aCharacter)
{
	bool result = false;

	for (unsigned int i = 0; i < gCharacters.size(); i++)
	{
		if (gCharacters[i]->getName() == aCharacter)
		{
			result = true;
			break;
		}
		else
		{
			result = false;
		}
	}

	return result;
}

void CharacterContainer::AddCharacter(Character* aCharacter)
{
	gCharacters.push_back(aCharacter);
	gCharacters.resize(gCharacters.size());
}

void CharacterContainer::RemoveCharacter(Character* aCharacter)
{
	for (unsigned int i = 0; i < gCharacters.size(); i++)
	{
		if (gCharacters[i] == aCharacter)
		{
			gCharacters.erase(gCharacters.begin() + i);
			break;
		}
	}
}

std::vector<Character*> CharacterContainer::CharacterList()
{
	return gCharacters;
}