#include "WoWObject.h"
#include <cstdint>

unsigned long long WoWObject::getGuid() {
	return guid;
}
intptr_t WoWObject::getPointer() {
	return pointer;
}
Objects::ObjectType WoWObject::getObjectType() {
	return objectType;
}

intptr_t WoWObject::getDescriptorPointer() {
	intptr_t newPointer = MemoryManager::ReadAddress(getPointer() + DESCRIPTOR_OFFSET);
	return newPointer;
}
