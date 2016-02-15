#pragma once

#include <map>

#include "ItemStack.h"

class Inventory{
public:
	Inventory();
	~Inventory();

	void clear();

	bool put(ItemStack* is, unsigned char slot);
	bool put(ItemStack* is);

	bool take(ItemStack* is);
	ItemStack* take(unsigned char slot);

	bool has(ItemStack* is);
private:
	std::map<unsigned char, ItemStack*> slots;
};