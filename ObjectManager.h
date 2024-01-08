#pragma once
#include "Functions.h"
#include "MemoryManager.h"
#include "WoWObject.h"
#include <vector>
#include "WoWUnit.h"
#include "ranges"
#include "LocalPlayer.h"
#include "WoWPlayer.h"

static class ObjectManager {
public:
	static const int OBJECT_TYPE_OFFSET = 0x14;

	static intptr_t callbackPtr;

	ObjectManager();

	//static std::vector<WoWObject*> object;

	static bool isLoggedIn();

	static void EnumerateObjects();

	static int __fastcall cc(int filter, unsigned long long guid);

	static std::vector <WoWUnit> getUnits();

	static LocalPlayer localPlayer;

	static std::vector<WoWObject> object;
};

//extern int __fastcall cc(int filter, unsigned long long guid);