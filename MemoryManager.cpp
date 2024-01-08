#include "MemoryManager.h"

short MemoryManager::ReadByte(intptr_t pointer) {
	return (*(short*)pointer);
}

int MemoryManager::ReadInt(intptr_t ptr)
{
	return *(int *)ptr;
}

unsigned long long MemoryManager::ReadUnsignedLongLong(intptr_t ptr)
{
	return *(unsigned long long*)ptr;
}

intptr_t MemoryManager::ReadAddress(intptr_t ptr)
{
	return *(unsigned int*)ptr;
}

std::string MemoryManager::ReadString(intptr_t ptr) {
	char* ret = MemoryManager::ReadBytes(ptr, 512);
	
	std::string answer = "";

	for (int i = 0; i < 512; i++) {
		answer += ret[i];
		if (ret[i] == '\0') break;
	}

	return answer;
}

char* MemoryManager::ReadBytes(intptr_t ptr, int cnt) {
	char* ret = new char[cnt];
	char* addr = (char*)ptr;

	for (int i = 0; i < cnt; i++) {
		//ret[i] = *(addr+i);
		ret[i] = addr[i];
	}
	return ret;
}
