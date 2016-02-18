#pragma once

#include "Drawable.h"

class Collidable : public drawable::Drawable{
public:
	Collidable();
	~Collidable();

	bool collideWith(Collidable* c, const sf::Time& time);

	Vector offsett;
	Vector size;
};