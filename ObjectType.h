#pragma once
#include <cstdint>
#include <string>

static class Objects {
public:
	enum ObjectType {
		None,
		Item,
		Container,
		Unit,
		Player,
		GameObject,
		DynamicObject,
		Corpse
	};
};

namespace Object {
	const std::string reverse[8] = {
		"None",
		"Item",
		"Conmtainer",
		"Unit",
		"Player",
		"GameObject",
		"DynamicObject",
		"Corpse"
	};
}
