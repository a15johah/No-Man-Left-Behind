#include "Inventory.h"

Inventory::Inventory(){
	inventoryLimit = 255;
}

Inventory::~Inventory(){

}

void Inventory::clear(){
	slots.clear();
}

void Inventory::setLimit(const unsigned char limit){
	inventoryLimit = limit;
}

unsigned char Inventory::getLimit(){
	return inventoryLimit;
}

bool Inventory::put(ItemStack is, unsigned char slot){
	if (slots.count(slot) == 0){

		slots[slot] = is;
		return true;
	}

	if (slots[slot].item.type == is.item.type){

		unsigned char value = slots[slot].count + is.count;

		if (value < 0){

			logger::warning("Don't have that many items in the stack");
			return false;
		}

		slots[slot].count = value;
		return true;
	}
	logger::warning("Item could not be placed, slot " + std::to_string(slot) + " already occupied");
	return false;
}

bool Inventory::put(ItemStack is){
	for (unsigned char i = 0; i < inventoryLimit; i++){

		if (slots.count(i) == 0){

			slots[i] = is;
			return true;
		}

		if (slots[i].item.type == is.item.type){

			unsigned char value = slots[i].count + is.count;

			if (value < 0){

				logger::warning("Don't have that many items in the stack");
				return false;
			}

			slots[i].count = value;
			return true;
		}
	}
	logger::warning("Item could not be placed, inventory is full");
	return false;
}

bool Inventory::take(ItemStack is){
	for (auto &itemStack : slots){
		if (is.item.type == itemStack.second.item.type){

			slots.erase(itemStack.first);
			return true;
		}
	}
	return false;
}

ItemStack Inventory::take(unsigned char slot){
	return slots[slot];
}

bool Inventory::has(ItemStack is){
	for (auto &itemStack : slots){

		if (is.item.type == itemStack.second.item.type){
			return true;
		}
	}
	return false;
}