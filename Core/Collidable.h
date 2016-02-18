#pragma once

#include "Entity.h"

class Collidable : public Entity{
public:
	Collidable();
	~Collidable();

	bool collideWith(const Collidable* c);

	Vector offsett;
	Vector size;
};