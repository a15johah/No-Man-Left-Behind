#include "Injured.h"

Injured::Injured(){

}

Injured::~Injured(){

}

const Injure Injured::nextStage(const Injure& current){
	switch (current){
	case DEAD:
		return DEAD;
		break;
	case GRAVE:
		return SEVERE;
		break;
	case SEVERE:
		return LIGHT;
		break;
	case LIGHT:
		return HEALED;
		break;
	case HEALED:
		return HEALED;
		break;
	}
	return DEAD;
}

const Injure Injured::previusStage(const Injure& current){
	switch (current){
	case DEAD:
		return DEAD;
		break;
	case GRAVE:
		return DEAD;
		break;
	case SEVERE:
		return GRAVE;
		break;
	case LIGHT:
		return SEVERE;
		break;
	case HEALED:
		return LIGHT;
		break;
	}
	return DEAD;
}

const Injure Injured::parseInjure(const std::string& s){
	if (s == "DEAD"){
		return DEAD;
	}
	else if (s == "GRAVE"){
		return GRAVE;
	}
	else if (s == "SEVERE"){
		return SEVERE;
	}
	else if (s == "LIGHT"){
		return LIGHT;
	}
	else if (s == "HEALED"){
		return HEALED;
	}
	return DEAD;
}

const std::string Injured::injureToString(const Injure& Injure){
	if (Injure == DEAD){
		return "DEAD";
	}
	else if (Injure == GRAVE){
		return "GRAVE";
	}
	else if (Injure == SEVERE){
		return "SEVERE";
	}
	else if (Injure == LIGHT){
		return "LIGHT";
	}
	else if (Injure == HEALED){
		return "HEALED";
	}
	return "DEAD";
}

std::vector<Resource>* Injured::getRequirements(const Injure inj){
	return requirements[inj];
}

void Injured::setRequirements(Injure inj, std::vector<Resource>* req){
	requirements[inj] = req;
}

void Injured::clear(){
	requirements.clear();
}