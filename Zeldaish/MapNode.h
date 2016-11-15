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

	void AddMapNode(MapNode* aNode);
	std::vector<MapNode*> gNeighbor;
private:
	ItemContainer* gItems;
	CharacterContainer* gCharacters;
};

