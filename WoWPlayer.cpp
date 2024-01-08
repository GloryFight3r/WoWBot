#include "WoWPlayer.h"

std::string WoWPlayer::getName()
{
	intptr_t namePtr = MemoryManager::ReadAddress(NAME_BASE_OFFSET);

	while (true) {
		unsigned long long nextGuid = MemoryManager::ReadUnsignedLongLong(namePtr + NEXT_NAME_OFFSET);

		if (nextGuid != getGuid()) {
			namePtr = MemoryManager::ReadAddress(namePtr);
		}
		else {
			break;
		}
	}
	return MemoryManager::ReadString(namePtr + PLAYER_NAME_OFFSET);
}
