#include "stdafx.h"
#include "ItemContainer.h"


ItemContainer::ItemContainer()
{
}


ItemContainer::~ItemContainer()
{
}

bool ItemContainer::HasItem(std::string aItem) 
{
	bool result = false;

	for (unsigned int i = 0; i < gItems.size(); i++)
	{
		if (gItems[i]->getName() == aItem)
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

void ItemContainer::AddItem(Item* aItem) 
{
	gItems.push_back(aItem);
	gItems.resize(gItems.size());
}

Item* ItemContainer::DropItem(Item* aItem) 
{
	Item* result = NULL;

	for (unsigned int i = 0; i < gItems.size(); i++)
	{
		if (gItems[i] == aItem)
		{
			result = gItems[i];
			gItems.erase(gItems.begin() + i);
			break;
		}
	}

	return result;
}

void ItemContainer::RemoveItem(Item* aItem) 
{
	for (unsigned int i = 0; i < gItems.size(); i++)
	{
		if (gItems[i] == aItem)
		{
			gItems.erase(gItems.begin() + i);
			break;
		}
	}
}

std::vector<Item*> ItemContainer::ItemList()
{
	return gItems;
}