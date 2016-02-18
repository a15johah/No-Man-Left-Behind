#include "Collidable.h"

Collidable::Collidable(){

}

Collidable::~Collidable(){

}

bool Collidable::collideWith(const Collidable* c) {
	sf::FloatRect local;

	local.top = position.x + offsett.x;
	local.left = position.x + offsett.x;
	local.height = size.y;
	local.width = size.x;

	sf::FloatRect given;

	given.top = c->position.x + c->offsett.x;
	given.left = c->position.x + c->offsett.x;
	given.height = c->size.y;
	given.width = c->size.x;

	return local.intersects(given);
}