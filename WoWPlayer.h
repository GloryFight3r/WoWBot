#pragma once
#include "WoWUnit.h"

class WoWPlayer : public WoWUnit {
public:
	static const int NAME_BASE_OFFSET = 0xC0E230;
	static const int NEXT_NAME_OFFSET = 0xC;
	static const int PLAYER_NAME_OFFSET = 0x14;

	WoWPlayer(unsigned long long guid, intptr_t ptr, Objects::ObjectType objectType) : WoWUnit(guid, ptr, objectType) {

	}

	WoWPlayer() {

	}

	std::string getName();
};