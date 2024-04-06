#include "stdafx.h"
#include "Protections.h"
#include "All Players.h"

void AP::UpdateLoop() {

	INFIN1T ? Infinite(true) : NULL;

	nesp ? NESP(true) : NULL;

	Regesp ? regesp(true) : NULL;

	Regessp ? regessp(true) : NULL;

}

/*
MPPLY_TOTAL_CUSTOM_RACES_WON
MPPLY_ARMWRESTLING_TOTAL_MATCH
MPPLY_ARMWRESTLING_TOTAL_WINS
MPPLY_CREW_LOCAL_XP_0
MPPLY_DARTS_TOTAL_WINS
MPPLY_INGAMESTORE_MONEYSPENT
MPPLY_CASINO_CHIPS_WON_GD
*/

bool AP::INFIN1T = false;
void AP::Infinite(bool toggle) {

	 Foxy_Engine::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_LUCKY_WHEEL_USAGE"), 0, true);
}

void AP::Crash()
{
	Blockweather = true; //Weather protection
	WAIT(1);
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
	{
		
		notifyMap("Spam it for a few seconds");
	}
	else
	{
		notifyMap("Go into online to prevent crashing yourself.");
	}
}

bool AP::nesp = false;
void AP::NESP(bool toggle) 
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
		for (int i = 0; i < 32; i++)
		{
			Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
			Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
			char* Name = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));
			if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
			{
				float x1;
				float y1;
				BOOL screenCoords = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);
				std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));
				std::string nameSetupRed = "~HUD_COLOUR_RED~" + playerName;
				std::string nameSetupGreen = "~HUD_COLOUR_BLUE~" + playerName;
				char* playerInfoRed = new char[nameSetupRed.length() + 1];
				char* playerInfoGreen = new char[nameSetupGreen.length() + 1];
				std::strcpy(playerInfoRed, nameSetupRed.c_str());
				std::strcpy(playerInfoGreen, nameSetupGreen.c_str());
				UI::SET_TEXT_FONT(7);
				UI::SET_TEXT_SCALE(0.0, 0.40);
				UI::SET_TEXT_COLOUR(0, 255, 0, 255);
				UI::SET_TEXT_CENTRE(0);
				UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
				UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
				UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
				if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17))
				{
					UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoGreen);
				}
				else
				{
					UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoRed);
				}
				UI::END_TEXT_COMMAND_DISPLAY_TEXT(x1, y1);
				UI::SET_TEXT_OUTLINE();
				UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
			}
		}
}

bool AP::Regesp = false;
void AP::regesp(bool toggle) {

	for (int i = 0; i < 32; i++)
	{
		if (i != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
		{
			Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
			Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
			Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
			Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 0, 200, 255);
			GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
			Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
			Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
			GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 0, 200, 255);
		}
	}
}
bool AP::Regessp = false;
void AP::regessp(bool toggle) {

	/*Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
	Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
	Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
	Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
	Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
	Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
	Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
	Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
	Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
	GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 0, 200, 255);
	GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 0, 200, 255);
	Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
	Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(latestObj, 1);
	GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 0, 200, 255);
	*/


}