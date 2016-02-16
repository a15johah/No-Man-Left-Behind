#pragma once

#include <map>

#include "ItemStack.h"

class Inventory{
public:
	Inventory();
	~Inventory();

	void clear();
	void setLimit(unsigned char limit);
	unsigned char getLimit();

	unsigned char put(ItemStack is, unsigned char slot);
	unsigned char put(ItemStack is);

	bool take(ItemStack is);
	ItemStack take(unsigned char slot);

	bool has(ItemStack is);
private:
	unsigned char inventoryLimit;

	std::map<unsigned char, ItemStack> slots;
};