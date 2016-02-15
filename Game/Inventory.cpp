#include "Inventory.h"

static unsigned char INVENTORY_LIMIT = 255;	// arbiträr! Bör inte ligga här?

Inventory::Inventory(){

}

Inventory::~Inventory(){

}

void Inventory::clear(){
	slots.clear();
}

bool Inventory::put(ItemStack* is, unsigned char slot){
	if (slots.count(slot) == 0){
		slots[slot] = is;
		return true;
	}
	else{
		logger::warning("Item could not be placed, slot " + std::to_string(slot) + " already occupied");
		return false;
	}
}

bool Inventory::put(ItemStack* is){
	for (unsigned char i = 0; i < INVENTORY_LIMIT; i++){
		if (slots.count(i) == 0){
			slots[i] = is;
			return true;
		}
	}
	logger::warning("Item could not be placed, inventory is full");
	return false;
}

bool Inventory::take(ItemStack* is){
	// Ska is tas ur slots?
	return has(is);
}

ItemStack* Inventory::take(unsigned char slot){
	return slots[slot];
}

bool Inventory::has(ItemStack* is){
	for (auto &itemStack : slots){
		if (is->item.type == itemStack.second->item.type){
			return true;
		}
	}
	return false;
}