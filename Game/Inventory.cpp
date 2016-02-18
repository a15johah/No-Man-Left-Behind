#include "Inventory.h"

/* HELP FUNCTIONS */
static bool compareItemStacks(const ItemStack& is1, const ItemStack is2) {
	return (is1.item.type == is2.item.type && is1.amount == is2.amount);
}

static bool compareItemStackType(const ItemStack& is1, const ItemStack is2) {
	return (is1.item.type == is2.item.type);
}

bool combineItemStacks(ItemStack& local, ItemStack& given) {
	unsigned char value = local.amount + given.amount;
	// check if value is greater than the local stack limit
	if (value > local.stackLimit) {
		local.amount = local.stackLimit;
		given.amount = value - local.stackLimit;
		return false;	//given is not empty (unsuccessfuly combined)
	}
	else {
		local.amount = value;
		given.amount = 0;
		return true;	// given is empty (successfuly combined)
	}
}
/* INVENTORY */
Inventory::Inventory(const unsigned char limit){
	inventoryLimit = limit;

	for (unsigned char i = 0; i < inventoryLimit; i++) {
		slots[i] = ItemStack();
	}
}

Inventory::~Inventory(){

}

void Inventory::clear(){
	slots.clear();
}

std::vector<ItemStack>& Inventory::setLimit(const unsigned char limit){
		std::map<unsigned char, ItemStack> old = slots;
	
	slots.clear();	// Reset the slots for new size
	for (unsigned char i = 0; i < limit; i++) {
		slots[i] = ItemStack();
	}

	// Transfer the old that's within the range
	for (unsigned char i = 0; i < limit; i++) {
		if (old[i].amount > 0) {
			slots[i] = old[i];
			old[i].amount = 0;
		}
	}
	// Find space for the itemstacks that were out of range if the range shrunk
	if (limit < inventoryLimit) {
		for (unsigned char i = limit; i < inventoryLimit; i++) {
			if (old[i].amount > 0) {
				for (unsigned char j = 0; j < limit; j++) {
					if (slots[j].amount == 0) {
						slots[j] = old[i];
						old[i].amount = 0;
						j = limit; // conitnue? break?
					}
				}
			}
		}
	}
	// Creating a vector for what was left behind
	std::vector<ItemStack> leftovers;
	for (unsigned char i = 0; i < inventoryLimit; i++) {
		if (old[i].amount > 0) {
			leftovers.push_back = old[i];
		}
	}
	// remeber the new inventory limit
	inventoryLimit = limit;

	return leftovers;
}

unsigned char Inventory::getLimit(){
	return inventoryLimit;
}

ItemStack& Inventory::put(ItemStack& is, unsigned char slot){
	if (slots[slot].amount == 0 || compareItemStackType(slots[slot], is)){

		combineItemStacks(slots[slot], is);

		return is;
	}
	logger::warning("Item could not be placed, slot " + std::to_string(slot) + " already occupied");
	return is;
}

ItemStack& Inventory::put(ItemStack& is){
	for (unsigned char i = 0; i < inventoryLimit; i++){
		if (compareItemStackType(slots[i], is) || slots.count(i) == 0){

			if (combineItemStacks(slots[i], is)) {
				return is;
			}
		}
	}
	logger::warning("All items could not be placed, inventory is full");
	return is;
}

bool Inventory::take(ItemStack& is){
	for (auto &itemStack : slots){
		if (compareItemStacks(is, itemStack.second)){

			itemStack.second.amount = 0;	// is this really right?
			return true;
		}
	}
	logger::warning("Stack not found");
	return false;
}

ItemStack& Inventory::take(unsigned char slot){
	ItemStack detached;

	detached.item.type = slots[slot].item.type;
	detached.amount = slots[slot].amount;

	slots[slot].amount = 0;

	return detached;
}

bool Inventory::has(ItemStack& is){
	unsigned char count;

	for (auto &itemStack : slots){

		if (compareItemStackType(is, itemStack.second)){
			count++;
		}
	}
	return count >= is.amount;
}