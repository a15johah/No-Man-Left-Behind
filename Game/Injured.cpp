#include "Injured.h"

Injured::Injured() {

}

Injured::~Injured() {

}

const Injure Injured::nextStage(const Injure& current) {
	switch (current) {
	case DEAD:
		return DEAD;
		break;
	case CRITICAL:
		return SERIOUS;
		break;
	case SERIOUS:
		return FAIR;
		break;
	case FAIR:
		return HEALED;
		break;
	case HEALED:
		return HEALED;
		break;
	}
	return DEAD;
}

const Injure Injured::previusStage(const Injure& current) {
	switch (current) {
	case DEAD:
		return DEAD;
		break;
	case CRITICAL:
		return DEAD;
		break;
	case SERIOUS:
		return CRITICAL;
		break;
	case FAIR:
		return SERIOUS;
		break;
	case HEALED:
		return HEALED;
		break;
	}
	return DEAD;
}

const Injure Injured::parseInjure(const std::string& s) {
	if (s == "DEAD") {
		return DEAD;
	}
	else if (s == "CRITICAL") {
		return CRITICAL;
	}
	else if (s == "SERIOUS") {
		return SERIOUS;
	}
	else if (s == "FAIR") {
		return FAIR;
	}
	else if (s == "HEALED") {
		return HEALED;
	}
	return DEAD;
}

const std::string Injured::injureToString(const Injure& Injure) {
	if (Injure == DEAD) {
		return "DEAD";
	}
	else if (Injure == CRITICAL) {
		return "CRITICAL";
	}
	else if (Injure == SERIOUS) {
		return "SERIOUS";
	}
	else if (Injure == FAIR) {
		return "FAIR";
	}
	else if (Injure == HEALED) {
		return "HEALED";
	}
	return "DEAD";
}

std::vector<Resource>* Injured::getRequirements(const Injure inj) {
	return requirements[inj];
}

void Injured::setRequirements(Injure inj, std::vector<Resource>* req) {
	requirements[inj] = req;
}

void Injured::clear() {
	requirements.clear();
}
