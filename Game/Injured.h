#pragma once

#include <vector>
#include <map>

#include "Collidable.h"
#include "Drawable.h"
#include "Item.h"

static enum Injure{
	DEAD = 0,
	GRAVE = 1,
	SEVERE = 2,
	LIGHT = 3,
	HEALED = 4
};

class Injured : public drawable::Drawable{	// Should be Collidable
public:
	Injured();
	~Injured();

	const Injure nextStage(const Injure& current);
	const Injure previusStage(const Injure& current);

	const Injure parseInjure(const std::string& s);
	const std::string injureToString(const Injure& Injure);

	std::vector<Resource>* getRequirements(const Injure inj);
	void setRequirements(Injure inj, std::vector<Resource>* req);

	void clear();
private:
	std::map<Injure, std::vector<Resource>*> requirements;
};