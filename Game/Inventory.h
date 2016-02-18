#pragma once

#include <map>
#include <vector>

#include "ItemStack.h"

class Inventory {
public:
	Inventory(const unsigned char limit);
	~Inventory();

	void clear();
	std::vector<ItemStack>& setLimit(unsigned char limit);
	unsigned char getLimit();

	ItemStack& put(ItemStack& is, unsigned char slot);
	ItemStack& put(ItemStack& is);

	bool take(ItemStack& is);
	ItemStack& take(unsigned char slot);

	bool has(ItemStack& is);
private:
	unsigned char inventoryLimit;

	std::map<unsigned char, ItemStack> slots;
};