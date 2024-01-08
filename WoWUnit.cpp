#include "WoWUnit.h"

int WoWUnit::getHealth() {
	return MemoryManager::ReadInt(getDescriptorPointer() + HEALTH_OFFSET);
}

std::string WoWUnit::getName() {
	intptr_t ptr1 = MemoryManager::ReadAddress(getPointer() + NAME_OFFSET);
	intptr_t ptr2 = MemoryManager::ReadAddress(ptr1);
	return MemoryManager::ReadString(ptr2);
}
