#include <cstdint>

#pragma once
namespace Functions {
	unsigned long long __cdecl GetPlayerGuid();

	void __stdcall EnumerateObjects(intptr_t, int);

	intptr_t __stdcall GetObjectPtr(unsigned long long);
};

