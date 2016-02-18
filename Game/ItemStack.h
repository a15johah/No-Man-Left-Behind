#pragma once

#include "Drawable.h"
#include "Item.h"

class ItemStack : public drawable::Drawable {
public:
	ItemStack();
	~ItemStack();

	Item item;

	unsigned char amount;

	unsigned char stackLimit = 128;	// TODO: Centralize default?

};
