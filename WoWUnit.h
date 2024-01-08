#pragma once
#include "WoWObject.h"

class WoWUnit : public WoWObject {
private:

public:
	static const int HEALTH_OFFSET = 0x58;
	static const int NAME_OFFSET = 0xB30;
	WoWUnit(unsigned long long guid, intptr_t ptr, Objects::ObjectType objectType) : WoWObject(guid, ptr, objectType) {

	}

	WoWUnit() {

	}

	int getHealth();
	std::string getName();
};