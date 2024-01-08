#pragma once
#include "WoWUnit.h"
#include "WoWPlayer.h"

class LocalPlayer : public WoWPlayer {
public:
	LocalPlayer(unsigned long long guid, intptr_t ptr, Objects::ObjectType objectType) : WoWPlayer(guid, ptr, objectType) {

	}
	LocalPlayer() {

	}
};