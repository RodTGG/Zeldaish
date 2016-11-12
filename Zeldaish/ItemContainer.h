#pragma once
#include "Item.h"
#include <vector>

class ItemContainer
{
public:
	ItemContainer();
	~ItemContainer();

	bool HasItem(std::string aItem);
	void AddItem(Item* aItem);
	Item* DropItem(Item* aItem);
	void RemoveItem(Item* aItem);

	std::vector<Item*> ItemList();
private:
	std::vector<Item*> gItems;
};

