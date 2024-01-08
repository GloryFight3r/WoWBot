#pragma once
#include <cstdint>
#include <string>

static class MemoryManager {
public:
	static short ReadByte(intptr_t);

	static int ReadInt(intptr_t);

	static unsigned long long ReadUnsignedLongLong(intptr_t);

	static intptr_t ReadAddress(intptr_t);

	static std::string ReadString(intptr_t);

	static char* ReadBytes(intptr_t, int);
};