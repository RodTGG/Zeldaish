#include "stdafx.h"
#include "MapNode.h"


MapNode::MapNode(std::string aName, std::string aPath) : ZeldaishObject(aName, aPath)
{
	gItems = new ItemContainer();
	gCharacters = new CharacterContainer();
	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 800;
	gImageArea->h = 600;
}


MapNode::~MapNode()
{
}

void MapNode::AddMapNode(MapNode* aNode) 
{
	gNeighbor.push_back(aNode);
}

void MapNode::Display(SDL_Renderer* aRender)
{
	gTexture = ZeldaishFunctions::loadTexture(*aRender, gImagePath);
	SDL_RenderCopy(aRender, gTexture, gClip, gImageArea);
	SDL_DestroyTexture(gTexture);

	for (unsigned int i = 0; i < gCharacters->CharacterList().size(); i++) 
	{
		if (gCharacters->CharacterList()[i] != NULL)
		{
			gCharacters->CharacterList()[i]->Display(aRender);
		}
	}
	for (unsigned int i = 0; i < gItems->ItemList().size(); i++)
	{
		if (gItems->ItemList()[i] != NULL)
		{
			gItems->ItemList()[i]->Display(aRender);
		}
	}
}