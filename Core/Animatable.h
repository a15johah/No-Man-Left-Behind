#pragma once

#include "Manager.h"
#include "Drawable.h"

enum AnimatableType{
	DIRECTIONAL,
	STATES
};

class Animatable : public drawable::Drawable{
public:
	Animatable();
	~Animatable();

	void apply(Manager* m, const std::string& a);

	void setNextState(const unsigned int& state);

	virtual void move(const float& dt);

	AnimatableType animatableType;
	unsigned char numStates;
};