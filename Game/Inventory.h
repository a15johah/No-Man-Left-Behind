#pragma once

#include <map>
#include <vector>

#include "ItemStack.h"

class Inventory {
public:
	Inventory(const unsigned char size);
	~Inventory();

	std::vector<ItemStack> setSize(unsigned char size);
	unsigned char getSize() const;

	ItemStack& put(ItemStack& is, unsigned char slot);
	ItemStack& put(ItemStack& is);

	ItemStack& swap(ItemStack& is, unsigned char slot);
	ItemStack& take(unsigned char slot);

	bool take(ItemStack is);

	bool has(ItemStack is) const;

	void clear();
private:
	unsigned char size;

	ItemStack* content;
};