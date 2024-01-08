#include "TestCommands.h"

void TestCommands::Test() {
	
	ImGui::Begin("Scanned units");
	//ImGui::Text("%llu", a.callbackPtr);
		
	if (!ObjectManager::isLoggedIn()) {
		ObjectManager::object.clear();
	}
	else {
		ObjectManager::EnumerateObjects();
		ImGui::Text("Name: %s", ObjectManager::localPlayer.getName().c_str());
	}

	/*for (WoWObject x : ObjectManager::object) {
		if (x.getObjectType() != Objects::ObjectType::Player) {
			continue;
		}
		ImGui::Text("Guid: %llu", x.getGuid());
		ImGui::Text("Pointer: %u", x.getPointer());
		ImGui::Text("Name: %s", (static_cast<LocalPlayer&>(x)).getName().c_str());
		//ImGui::Text("Health: %u", x.getHealth());
		ImGui::Text("Type: %s", Object::reverse[(int)x.getObjectType()].c_str());
	}*/
	ImGui::End();

}