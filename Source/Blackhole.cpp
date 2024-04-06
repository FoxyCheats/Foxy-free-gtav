#include "stdafx.h"
#include "Blackhole.h"
#include "stdafx.h"
#include "Something.h"
#include "Map.h"
#include "Other.h"
#include "natives.h"

Vector3 vec3;
float BH_FORCE = 1.0f;

int rww = 255, gww = 0, bww = 0;
void RGBFadeee()
{
	if (rww > 0 && bww == 0) {
		rww--;
		gww++;
	}
	if (gww > 0 && rww == 0) {
		gww--;
		bww++;
	}
	if (bww > 0 && gww == 0) {
		rww++;
		bww--;
	}
}


void BH::UpdateLoop() {

	Blackholetoggle ? blackholetoggle(true) : NULL;
	Blackholetoggle2 ? blackholetoggle2(true) : NULL;



}



void BH::Sub()
{

Menu::Title("Black Hole");
Menu::SubTitle("Black Hole");

auto pos = &vec3;
if (pos->x == 0)
vec3 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
Menu::Toggle("Toggle", BH::Blackholetoggle);
Menu::Float("Force", BH_FORCE, 1.f, 50.f, 1.f);
Menu::Float("X", pos->x, -1999999.f, 1999999.f, 1.f);
Menu::Float("Y", pos->y, -1999999.f, 1999999.f, 1.f);
Menu::Float("Z", pos->z, -1999999.f, 1999999.f, 1.f);
Menu::Addoption("Set to Player Position", [] { vec3 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1); });
//Menu::Break("");
RGBFadeee();
GRAPHICS::DRAW_MARKER(28, pos->x, pos->y, pos->z, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, bww, rww, gww, 255, false, false, 0, false, NULL, NULL, false);

}

std::vector<int32_t> vehiclepush() {
	const int countt = 100;
	int nerby[countt * 2 + 2] = { countt * 2 + 2 };
	auto count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), (int*)& nerby);
	std::vector<int32_t> rtrn;

	for (int i = 0; i < count; i++) {
		auto v = nerby[i * 2 + 2];
		rtrn.push_back(v);
	}

	return rtrn;
}

std::vector<int32_t> pedspush() {
	const int countt = 100;
	int nerby[countt * 2 + 2] = { countt * 2 + 2 };
	auto count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), (int*)& nerby, PLAYER::PLAYER_PED_ID());
	std::vector<int32_t> rtrn;

	for (int i = 0; i < count; i++) {
		auto p = nerby[i * 2 + 2];
		rtrn.push_back(p);
	}

	return rtrn;
}

bool BH::Blackholetoggle = false;
void BH::blackholetoggle(bool toggle)
{
	if (Blackholetoggle)
	{
		RGBFadeee();
		GRAPHICS::DRAW_MARKER(28, vec3.x, vec3.y, vec3.z, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, bww, rww, gww, 255, false, false, 0, false, NULL, NULL, false);

		auto vp = vehiclepush();
		auto pdp = pedspush();
		vp.insert(vp.end(), pdp.begin(), pdp.end());
		for (auto main : vp) {
			if (main && ENTITY::DOES_ENTITY_EXIST(main)) {
				auto pos1 = ENTITY::GET_ENTITY_COORDS(main, 1);
				auto pos2 = vec3;
				pos2.z += 1.5f;
				Vector3 bhpos = { pos2.x - pos1.x, pos2.y - pos1.y, pos2.z - pos1.z };
				if (distanceBetween(pos2, pos1) > 3.f) {
					ENTITY::APPLY_FORCE_TO_ENTITY(main, 1, (bhpos.x / 13)*BH_FORCE, (bhpos.y / 13)* BH_FORCE, bhpos.z / 13, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
				}
				else {
					ENTITY::SET_ENTITY_VELOCITY(main, 0.f, 0.f, 0.f);
					ENTITY::APPLY_FORCE_TO_ENTITY(main, 1, 0.f, 0.f, bhpos.z / 15, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
				}
			}
		}
	}
	else
	{

	}
}








Vector3 vec2;
float BH_FORCE2 = 1.0f;

int red2z = 255, green2z = 0, blue2z = 0;
void RGBFD()
{
	if (red2z > 0 && blue2z == 0) {
		red2z--;
		green2z++;
	}
	if (green2z > 0 && red2z == 0) {
		green2z--;
		blue2z++;
	}
	if (blue2z > 0 && green2z == 0) {
		red2z++;
		blue2z--;
	}
}


void BH::Sub2()
{

	Menu::Title("Black Hole");
	Menu::SubTitle("Black Hole");

	auto pos = &vec2;
	if (pos->x == 0)
		vec2 =  ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
	Menu::Toggle("Toggle", BH::Blackholetoggle2);
	Menu::Float("Force", BH_FORCE2, 1.f, 50.f, 1.f);
	Menu::Float("X", pos->x, -1999999.f, 1999999.f, 1.f);
	Menu::Float("Y", pos->y, -1999999.f, 1999999.f, 1.f);
	Menu::Float("Z", pos->z, -1999999.f, 1999999.f, 1.f);
	Menu::Addoption("Set to Player Position", [] { vec2 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false); });
	if (Menu::Option("~f~[ ~w~Be Close to the Player ~f~]"))
	{
	}
	RGBFD();
	GRAPHICS::DRAW_MARKER(28, pos->x, pos->y, pos->z, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, red2z, blue2z, green2z, 255, false, false, 0, false, NULL, NULL, false);

}

std::vector<int32_t> vehiclepush2() {
	const int countt = 100;
	int nerby[countt * 2 + 2] = { countt * 2 + 2 };
	auto count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), (int*)&nerby);
	std::vector<int32_t> rtrn;

	for (int i = 0; i < count; i++) {
		auto v = nerby[i * 2 + 2];
		rtrn.push_back(v);
	}

	return rtrn;
}

std::vector<int32_t> pedspush2() {
	const int countt = 100;
	int nerby[countt * 2 + 2] = { countt * 2 + 2 };
	auto count = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), (int*)&nerby, (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1));
	std::vector<int32_t> rtrn;

	for (int i = 0; i < count; i++) {
		auto p = nerby[i * 2 + 2];
		rtrn.push_back(p);
	}

	return rtrn;
}

bool BH::Blackholetoggle2 = false;
void BH::blackholetoggle2(bool toggle)
{
	if (Blackholetoggle2)
	{
		RGBFD();
		vec2 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);

		GRAPHICS::DRAW_MARKER(28, vec2.x, vec2.y, vec2.z, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, red2z, blue2z, green2z, 255, false, false, 0, false, NULL, NULL, false);

		auto vp = vehiclepush2();
		auto pdp = pedspush2();
		vp.insert(vp.end(), pdp.begin(), pdp.end());
		for (auto main : vp) {
			if (main && ENTITY::DOES_ENTITY_EXIST(main)) {
				auto pos1 = ENTITY::GET_ENTITY_COORDS(main, 1);
				auto pos2 = vec2;
				pos2.z += 1.5f;
				Vector3 bhpos = { pos2.x - pos1.x, pos2.y - pos1.y, pos2.z - pos1.z };
				if (distanceBetween(pos2, pos1) > 3.f) {
					ENTITY::APPLY_FORCE_TO_ENTITY(main, 1, (bhpos.x / 13) * BH_FORCE2, (bhpos.y / 13) * BH_FORCE2, bhpos.z / 13, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
				}
				else {
					ENTITY::SET_ENTITY_VELOCITY(main, 0.f, 0.f, 0.f);
					ENTITY::APPLY_FORCE_TO_ENTITY(main, 1, 0.f, 0.f, bhpos.z / 15, 0.f, 0.f, 0.f, 0, false, true, true, 0, 0);
				}
			}
		}
	}
	else
	{

	}
}










