#include "Collidable.h"

Collidable::Collidable(){

}

Collidable::~Collidable(){

}

bool Collidable::collideWith(Collidable* c, const sf::Time& time) {
	sf::FloatRect local;
	sf::Sprite* localSpr = getSprite(time);

	local.top = localSpr->getOrigin().x + (localSpr->getScale().x * offsett.x);
	local.left = localSpr->getOrigin().y + (localSpr->getScale().y * offsett.y);
	local.height = localSpr->getScale().x * size.x;
	local.width = localSpr->getScale().y * size.y;

	sf::FloatRect given;
	sf::Sprite* givenSpr = c->getSprite(time);

	given.top = givenSpr->getOrigin().x + (givenSpr->getScale().x * c->offsett.x);
	given.left = givenSpr->getOrigin().y + (givenSpr->getScale().y * c->offsett.y);
	given.height = givenSpr->getScale().x * c->size.x;
	given.width = givenSpr->getScale().y * c->size.y;

	return local.intersects(given);
}