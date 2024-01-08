#pragma once
#include "ObjectType.h"
#include "MemoryManager.h"

class WoWObject {
private:
	unsigned long long guid;
	intptr_t pointer;
	Objects::ObjectType objectType;

public:
	static const int DESCRIPTOR_OFFSET = 0x8;
	WoWObject(unsigned long long guid, intptr_t pointer, Objects::ObjectType objectType) {
		this->guid = guid;
		this->pointer = pointer;
		this->objectType = objectType;
	}

	WoWObject() {

	}

	unsigned long long getGuid();
	intptr_t getPointer();
	Objects::ObjectType getObjectType();
	intptr_t getDescriptorPointer();
};