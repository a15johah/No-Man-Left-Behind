#include "Inventory.h"

Inventory::Inventory(){
	inventoryLimit = 255;	// TODO: Centralize?
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

unsigned char Inventory::put(ItemStack is, unsigned char slot){
	if (slots.count(slot) == 0){

		slots[slot] = is;
		return 0;
	}

	if (compareItemStackType(slots[slot], is)){

		is.amount = combineItemStacks(slots[slot], is);

		return is.amount;
	}
	logger::warning("Item could not be placed, slot " + std::to_string(slot) + " already occupied");
	return is.amount;
}

unsigned char Inventory::put(ItemStack is){
	for (unsigned char i = 0; i < inventoryLimit; i++){

		if (slots.count(i) == 0 ){

			slots[i] = is;
			return 0;
		}

		if (compareItemStackType(slots[i], is)){

			is.amount = combineItemStacks(slots[i], is);

			return is.amount;
		}
	}
	logger::warning("Item could not be placed, inventory is full");
	return is.amount;
}

bool Inventory::take(ItemStack is){
	for (auto &itemStack : slots){
		if (compareItemStacks(is, itemStack.second)){

			slots.erase(itemStack.first);
			return true;
		}
	}
	logger::warning("Stack not found");
	return false;
}

ItemStack Inventory::take(unsigned char slot){
	return slots[slot];
}

bool Inventory::has(ItemStack is){
	bool haveIs = false;

	for (auto &itemStack : slots){

		if (compareItemStacks(is, itemStack.second)){
			haveIs = true;
		}
	}
	return haveIs;
}
// Help functions
static bool compareItemStacks(const ItemStack& is1, const ItemStack is2){
	return (is1.item.type == is2.item.type && is1.amount == is2.amount);
}

static bool compareItemStackType(const ItemStack& is1, const ItemStack is2){
	return (is1.item.type == is2.item.type);
}

static unsigned char combineItemStacks(ItemStack& local, ItemStack& given){
	unsigned char value = local.amount + given.amount;
	// check if value is greater than the local stack limit
	if (value > local.stackLimit){
		local.amount = local.stackLimit;
		return value - local.stackLimit;
	}
	else{
		local.amount = value;
		return 0;
	}
}