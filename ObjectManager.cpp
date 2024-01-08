#include "ObjectManager.h"

intptr_t ObjectManager::callbackPtr;
std::vector<WoWObject> ObjectManager::object;
LocalPlayer ObjectManager::localPlayer;

ObjectManager::ObjectManager() {
	int (__fastcall * fncPtr)(int, unsigned long long) = &ObjectManager::cc;
	callbackPtr = (intptr_t&)fncPtr;
}

bool ObjectManager::isLoggedIn() {
	return Functions::GetPlayerGuid() > 0;
}

void ObjectManager::EnumerateObjects() {
	if (isLoggedIn()) {
		object.clear();

		int(__fastcall * fncPtr)(int, unsigned long long) = &ObjectManager::cc;
		callbackPtr = (intptr_t&)fncPtr;

		Functions::EnumerateObjects(callbackPtr, 0);
	}
}

int __fastcall ObjectManager::cc(int filter, unsigned long long guid) {
	intptr_t ptr = Functions::GetObjectPtr(guid);
	Objects::ObjectType currentObject = (Objects::ObjectType)MemoryManager::ReadByte(ptr + ObjectManager::OBJECT_TYPE_OFFSET);

	switch (currentObject) {
		case Objects::ObjectType::Unit: {
			object.push_back(WoWUnit(guid, ptr, currentObject));
			break;
		}
		case Objects::ObjectType::Player: {
			// checks if the found player is us
			if (guid == Functions::GetPlayerGuid()) {
				localPlayer = LocalPlayer(guid, ptr, currentObject);
				object.push_back(localPlayer);
			}
			else {
				// it's another player
				object.push_back(WoWPlayer(guid, ptr, currentObject));
			}
			break;
		}
		default: {
			// still not implemented for other types 
			object.push_back(WoWObject(guid, ptr, currentObject));
		}
	}
	return 1;
}

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return static_cast<const Base*>(ptr) != nullptr;
}

std::vector<WoWUnit> ObjectManager::getUnits() {
	std::vector <WoWUnit> ans;
	for (WoWObject x : object) {
		if (x.getObjectType() == Objects::ObjectType::Unit) {
			WoWUnit a = static_cast<WoWUnit&>(x);
			ans.push_back(a);
		}
	}
	return ans;
}
