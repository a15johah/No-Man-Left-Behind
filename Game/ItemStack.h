#pragma once

#include "Drawable.h"
#include "Item.h"

class ItemStack : public drawable::Drawable{
public:
	ItemStack();
	~ItemStack();

	Item item;

	unsigned char count;
};