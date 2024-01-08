#include "Functions.h"

const int GET_PLAYER_GUID_FUN_PTR = 0x00468550;

unsigned long long __cdecl Functions::GetPlayerGuid() {
	return ((unsigned long long(*)(void))GET_PLAYER_GUID_FUN_PTR)();
}

// EnumerateVisibleObjects
const int ENUMERATE_VISIBLE_OBJECTS_FUN_PTR = 0x00468380;

void __stdcall Functions::EnumerateObjects(intptr_t callback, int filter) {
	typedef void __fastcall func(intptr_t, int);
	func* function = (func*)ENUMERATE_VISIBLE_OBJECTS_FUN_PTR;
	function(callback, filter);
}

// GetObjectPtr
const int GET_OBJECT_PTR_FUN_PTR = 0x00464870;

intptr_t __stdcall Functions::GetObjectPtr(unsigned long long guid) {
	typedef intptr_t __stdcall func(unsigned long long guid);
	func* function = (func*)GET_OBJECT_PTR_FUN_PTR;
	return function(guid);
}