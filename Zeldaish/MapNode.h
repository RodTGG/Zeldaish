#pragma once
#include "ZeldaishObject.h"
#include "ItemContainer.h"
#include "CharacterContainer.h"

class MapNode :
	public ZeldaishObject
{
public:
	MapNode(std::string aName, std::string aPath);
	~MapNode();

	void Display(SDL_Renderer* aRender) override;
	void AddMapNode(std::string aDirection, MapNode* aNode);
	bool HasNeighbor(std::string aDirection);

	std::map<std::string, MapNode*> gNeighbor;

	ItemContainer* gItems;
	CharacterContainer* gCharacters;
private:
};

