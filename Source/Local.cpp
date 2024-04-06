#include "stdafx.h"
#include "math.h"
#include "Local.h"
#include "offsets.h"
#include "Other.h"
#include "Weapons.h"

extern int TimePD;
char *call1o;
char *call2o;
char *nameo;
int flag = 0;
bool Local::OS = false;
bool Local::antiafk = false;
bool BodyguardInvincible  = false;

int Local::TimePD1;
int Local::TimePD2;
int Local::TimePD3;
int Local::TimePD4;
int Local::TimePD5;
int Local::TimePD6;
int Local::TimePD7;
int Local::TimePD8;
int Local::TimePD9;
int Local::TimePD10;
int Local::TimePD11;
int Local::TimePD12;
int Local::TimePD13;
int Local::TimePD14;
float tpx = 0.f;
float tpy = 0.f;
float tpz = 0.f;
class Ini
{
private:
	std::string inifile;
public:
	Ini(std::string file)
	{
		this->inifile = file;
	}
	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	std::string GetString(std::string app, std::string key)
	{
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());
		return (std::string)buf;
	}
	void WriteInt(int value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	int GetInt(std::string app, std::string key)
	{
		return std::stoi(GetString(app, key));
	}
	void WriteFloat(float value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	float GetFloat(std::string app, std::string key)
	{
		return std::stof(GetString(app, key));
	}
};

#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())
#define Vk_c 0x43

bool Local::walkinair = false;
int AnimationFlag_pos = 0;
static char* AnimationFlagsName[] = {
	"Full Body", "Top Only", "Can Move", "Rotate",
};
int Animationflags[] = {
	9, 31, 63, 43
};



Vector3 CombineVector(float x, float y, float z)
{
	Vector3 returnVector;
	returnVector.x = x;
	returnVector.y = y;
	returnVector.z = z;
	return returnVector;
}

Object Create_Obj(char* ObjectName, Vector3 Coordinates)
{
	Object returnObj;
	Hash ObjectHash = GAMEPLAY::GET_HASH_KEY(ObjectName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectHash))
		{
			STREAMING::REQUEST_MODEL(ObjectHash);
			if (STREAMING::HAS_MODEL_LOADED(ObjectHash))
			{
				returnObj = OBJECT::CREATE_OBJECT(ObjectHash, Coordinates.x, Coordinates.y, Coordinates.z, 1, 1, 0);
			}
			else
			{
				returnObj = NULL;
			}
		}
	}
	return returnObj;
}
void allpedscenario(char* senarios) {
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;
	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			AI::TASK_START_SCENARIO_IN_PLACE(peds[OffsetID], senarios, 0, true);
		}
	}
 }
void Local::UpdateLoop()
{

	God ? god(true) : NULL;

	NeverWanted ? neverWanted(true) : NULL;

	OffRadar ? offRadar(true) : NULL;

	MobileRadio ? mobileRadio(true) : NULL;

	Invisible ? invisible(true) : NULL;

	NoRagdoll ? noragdoll(true) : NULL;

	SlowMotion ? slowMotion(true) : NULL;

	Force ? Field(true) : NULL;

	SV ? sv(true) : NULL;

	SV2 ? sv2(true) : NULL;

	SV3 ? sv3(true) : NULL;

	SV4 ? sv4(true) : NULL;

	SV5 ? sv5(true) : NULL;

	SV6 ? sv6(true) : NULL;

	FB ? fb(true) : NULL;

	Swim ? swim(true) : NULL;

	Running ? running(true) : NULL;

	TinyPlayer ? tinyPlayer(true) : NULL;

	Fly ? fly(true) : NULL;

	Superjump ? superjump(true) : NULL;

	Superpunch ? superpunch(true) : NULL;

	Pedscale ? pedscale(true) : NULL;

	Fov ? fov1(true) : NULL;

	Nophone ? nophone(true) : NULL;

	Ultrajump ? ultrajump(true) : NULL;

	SuperRun ? Superun(true) : NULL;

	NoClip ? noClip(true) : NULL;

	FreeCam ? freeCam(true) : NULL;

	SaveOutfit ? save(true) : NULL;

	LoadOutfit ? load(true) : NULL;

	//O = Outfit

	O1 ? o1(true) : NULL;

	O2 ? o2(true) : NULL;

	O3 ? o3(true) : NULL;

	O4 ? o4(true) : NULL;

	O5 ? o5(true) : NULL;

	O6 ? o6(true) : NULL;

	O7 ? o7(true) : NULL;

	O8 ? o8(true) : NULL;

	O9 ? o9(true) : NULL;

	O10 ? o10(true) : NULL;

	O11 ? o11(true) : NULL;

	O12 ? o12(true) : NULL;



	KeyNote ? keyNote(true) : NULL;

	F7 ? f7(true) : NULL;

	F4 ? f4(true) : NULL;

	Particle ? particle(true) : NULL;

	Hulk ? hulk(true) : NULL;

	STRW ? strw(true) : NULL;

	isAutoRegArmour ? AutoRegArmour(true) : NULL;

	isAutoRegHealth ? AutoRegHealth(true) : NULL;

	GODOFRAIN ? godofrain(true) : NULL;

	if (OS)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
		WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
		while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
			WAIT(0);
		int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
		if (UI::DOES_BLIP_EXIST(WaypointHandle)) {
			Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
			WaypointPos.z += 25.0f;
			FIRE::ADD_EXPLOSION(WaypointPos.x, WaypointPos.y, WaypointPos.z, 29, 10000.f, 1, true, 0.0f);


			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(WaypointPos.x, WaypointPos.y, WaypointPos.z + 50.f, WaypointPos.x, WaypointPos.y, WaypointPos.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(WaypointPos.x, WaypointPos.y + 20.f, WaypointPos.z + 50.f, WaypointPos.x, WaypointPos.y, WaypointPos.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(WaypointPos.x + 20.f, WaypointPos.y, WaypointPos.z + 50.f, WaypointPos.x, WaypointPos.y, WaypointPos.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			FIRE::ADD_EXPLOSION(WaypointPos.x + 1, WaypointPos.y + 1, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x + 1, WaypointPos.y + 2, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x + 0, WaypointPos.y + 1, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x + 0, WaypointPos.y + 2, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x - 0, WaypointPos.y - 2, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x - 0, WaypointPos.y - 1, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x - 1, WaypointPos.y - 2, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(WaypointPos.x - 1, WaypointPos.y - 1, WaypointPos.z, 7, 90.0f, false, true, 0.0f);
		}
	}


	if (antiafk)
	{
		globalHandle(0x262145).At(0x56).As<int>() = INT_MAX;
		globalHandle(0x262145).At(0x57).As<int>() = INT_MAX;
		globalHandle(0x262145).At(0x58).As<int>() = INT_MAX;
		globalHandle(0x262145).At(0x59).As<int>() = INT_MAX;

		globalHandle(1654054).At(1173).As<int>() = INT_MAX;
		globalHandle(1654054).At(1172).As<int>() = INT_MAX;
	}
	else
	{
		NULL;
	}



	if (ToggleGlow)
	{
		if (Local::Head == true)
		{
			Local::PTFXCALLBoneless(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x796e);
		}
		else
		{

		}
		if (Local::Arm == true) //Right Arm
		{
			Local::PTFXCALLBoneless(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0xdead);
		}
		else
		{

		}
		if (Local::Arm2 == true)
		{
			Local::PTFXCALLBoneless(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x8cbd);
		}
		else
		{

		}
		if (Local::Foot == true)
		{
			Local::PTFXCALLBoneless(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0xcc4d);
		}
		else
		{

		}
		if (Local::Foot2 == true) //Left
		{
			Local::PTFXCALLBoneless(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x3779);
		}
		else
		{

		}
	}


	if (pToggleGlow)
	{
		if (Local::pHead == true)
		{
			Local::PTFXCALLBoneless2(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x796e);
		}
		else
		{

		}
		if (Local::pArm == true) //Right Arm
		{
			Local::PTFXCALLBoneless2(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0xdead);
		}
		else
		{

		}
		if (Local::pArm2 == true)
		{
			Local::PTFXCALLBoneless2(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x8cbd);
		}
		else
		{

		}
		if (Local::pFoot == true)
		{
			Local::PTFXCALLBoneless2(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0xcc4d);
		}
		else
		{

		}
		if (Local::pFoot2 == true) //Left
		{
			Local::PTFXCALLBoneless2(Local::GlowThing, Local::GlowThing, Local::GlowThing3, 0x3779);
		}
		else
		{

		}
	}



	if (walkinair)
	{

		Ped playerPed = PLAYER::PLAYER_PED_ID();

		char* prop = "p_oil_slick_01";
		Hash ObjHash = GAMEPLAY::GET_HASH_KEY(prop);
		Vector3 PlayerCoord = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Object WalkOnAir = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(PlayerCoord.x, PlayerCoord.y, PlayerCoord.z, 100, ObjHash, 1, 0, 1);
		float zPlane;

		if ((!ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (walkinair))
		{
			Object WalkOnAir = Create_Obj(prop, PlayerCoord);
			ENTITY::FREEZE_ENTITY_POSITION(WalkOnAir, 1);
			ENTITY::SET_ENTITY_VISIBLE2(WalkOnAir, 0);
		}
		else if ((ENTITY::DOES_ENTITY_EXIST(WalkOnAir)) && (walkinair))
		{
			float Normal = 1.0225;
			float Down = 1.60;
			float Up = 0.40;
			float Vehicular = 50.0;

			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))       
			{
				zPlane = PlayerCoord.z - Vehicular;
			}
			else if (GetAsyncKeyState(0x5A) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_LS)))      //Down Z and L3          
			{
				zPlane = PlayerCoord.z - Down;
			}
			else if (GetAsyncKeyState(0x51) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_SCRIPT_RS)))      //Up Q and R3  
			{
				zPlane = PlayerCoord.z - Up;
			}
			else                                             
			{
				zPlane = PlayerCoord.z - Normal;
			}

			Vector3 Coord = CombineVector(PlayerCoord.x, PlayerCoord.y, zPlane);
			ENTITY::SET_ENTITY_COORDS(WalkOnAir, Coord.x, Coord.y, Coord.z, 1, 0, 0, 1);

		}
	}
}

bool Local::SuperRun = false;
void Local::Superun(bool toggle)
{
	if (IsKeyPressed('W'))
	{
		Ped ped = PLAYER::PLAYER_PED_ID();
		Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 1.3, 0, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), 1);
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 1.59);

	}
}

bool Local::Ultrajump = false;
void Local::ultrajump(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(player);
	WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE"));
	if (PED::IS_PED_JUMPING(playerPed))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(playerPed, true, 0, 0, 5, 0, 0, 0, true, true, true, true, false, true);
	}
}

bool Local::Superjump = false;
void Local::superjump(bool toggle)
{
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
}

bool Local::Superpunch = false;
void Local::superpunch(bool toggle)
{
	GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());//SET_EXPLOSIVE_MELEE_THIS_FRAME
}

bool Local::Nophone = false;
void Local::nophone(bool toggle)
{
	//AI::TASK_USE_MOBILE_PHONE_TIMED(playerPedId, 999999);
	MOBILE::_DISABLE_PHONE_THIS_FRAME(true);//_DISABLE_PHONE_THIS_FRAME
}


bool Local::TinyPlayer = false;
void Local::tinyPlayer(bool toggle)
{
	if (toggle == true)
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, true);
	}
	else
	{
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, false);
	}
}

bool Local::NoRagdoll = false;
void Local::noragdoll(bool toggle)
{
	PED::SET_PED_RAGDOLL_ON_COLLISION(playerPedId, !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPedId, !toggle);
	PED::SET_PED_CAN_RAGDOLL(playerPedId, !toggle);
}

bool Local::Force = false;
void Local::Field(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	FIRE::ADD_EXPLOSION(pCoords.x + 2, pCoords.y + 2, pCoords.z, 7, 9.0f, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(pCoords.x + 3, pCoords.y + 3, pCoords.z, 7, 9.0f, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(pCoords.x + 4, pCoords.y + 4, pCoords.z, 7, 9.0f, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(pCoords.x + 5, pCoords.y + 5, pCoords.z, 7, 9.0f, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(pCoords.x + 6, pCoords.y + 6, pCoords.z, 7, 9.0f, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(pCoords.x + 7, pCoords.y + 7, pCoords.z, 7, 9.0f, false, true, 0.0f);
}

bool Local::Running = false;
void Local::running(bool toggle)
{
	if (!Running)
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1);
	else
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.5);
}

bool Local::Swim = false;
void Local::swim(bool toggle)
{
	if (!Swim)
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1);
	else
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.5);
}

bool Local::God = false;
void Local::god(bool toggle)
{
	if (God)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}
}



bool Local::NeverWanted = false;
void Local::neverWanted(bool toggle)
{
	if (NeverWanted)
	{
		Player player = PLAYER::PLAYER_ID();
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
		PLAYER::SET_PLAYER_WANTED_LEVEL(player, 0, true);
		PLAYER::SET_MAX_WANTED_LEVEL(0);
	}
	else
	{
		Player player = PLAYER::PLAYER_ID();
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
		PLAYER::SET_PLAYER_WANTED_LEVEL(player, 0, false);
		PLAYER::SET_MAX_WANTED_LEVEL(5);
	}
}

bool Local::OffRadar = false;
void Local::offRadar(bool toggle)
{
	Memory::set_value<float>({ 0x8, 0x2A0 }, 0.0f);
}


bool Local::MobileRadio = false;
void Local::mobileRadio(bool toggle)
{
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();

	if (MobileRadio)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
	}
}

bool Local::isAutoRegHealth = false;
void Local::AutoRegHealth(bool toggle) {
	if (Local::isAutoRegHealth)
	{
		float fHealth = Memory::get_value<float>({ 0x08 , 0x280 });
		float fHealthMax = Memory::get_value<float>({ 0x08 , 0x2A0 });
		float value = 20.f;

		if ((timeGetTime() - Local::TimePD9) > 400) {
			value += fHealth;
			if (fHealth < fHealthMax) {
				fHealth = value;
				Memory::set_value<float>({ 0x08 , 0x280 }, value);
			}
			if (fHealth == fHealthMax) {
				fHealth = fHealthMax;
			}
			Local::TimePD9 = timeGetTime();
		}
	}
}

bool Local::isAutoRegArmour = false;
void Local::AutoRegArmour(bool toggle) {

	if (Local::isAutoRegArmour)
	{
		if ((timeGetTime() - Local::TimePD10) > 400) {
			if (PED::GET_PED_ARMOUR(PLAYER::PLAYER_PED_ID()) < PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID())) {
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 20);
			}
			Local::TimePD10 = timeGetTime();
		}
	}

}

bool Local::Invisible = false;
void Local::invisible(bool toggle)
{
	if (toggle == true)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 1);
	}
}

static std::int32_t cam;
float fov = 1.0f;

bool Local::SlowMotion = false;
void Local::slowMotion(bool toggle)
{
	


}

float Local::pedsize = 1.0f;
float Local::pedwith = 1.0f;
bool Local::Pedscale = false;
void Local::pedscale(bool toggle)
{
	if (Pedscale == true)
	{
		Memory::set_value<float>({ 0x08, 0x88 }, Local::pedsize);
		Memory::set_value<float>({ 0x08, 0X0064 }, Local::pedwith);
	}
	else
	{
		Memory::set_value<float>({ 0x08, 0x88 }, 1.0f);
		Memory::set_value<float>({ 0x08, 0X0064 }, 1.0f);
	}
}


float Local::fovrender = 1.0f;
bool Local::Fov = false;
void Local::fov1(bool toggle) 
{

	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	int Handle = PLAYER::PLAYER_PED_ID();

	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
		CAM::SET_CAM_FOV(cam, - Local::fovrender);
	}
	if (!toggle)
	{
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
	}
	p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
    CAM::SET_CAM_FOV(cam, - Local::fovrender);
	CAM::SET_CAM_COORD(cam, p_coord.x, p_coord.y, p_coord.z);


}




bool Local::SV = false;
void Local::sv(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("WEAPON_RAILGUN");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}

bool Local::SV2 = false;
void Local::sv2(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("WEAPON_RAYPISTOL");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}

bool Local::SV3 = false;
void Local::sv3(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("VEHICLE_WEAPON_PLAYER_LAZER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}


bool Local::SV4 = false;
void Local::sv4(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("weapon_raycarbine");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 999, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}


bool Local::SV5 = false;
void Local::sv5(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("VEHICLE_WEAPON_TAMPA_MORTAR");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}


bool Local::SV6 = false;
void Local::sv6(bool toggle)
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("VEHICLE_WEAPON_STRIKEFORCE_BARRAGE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}


void Local::super_vision_rudolf()
{

	auto playerPed = PLAYER::PLAYER_PED_ID();
	static bool start_supervis;
	float s = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(playerPed, true)) + 5.25;
	auto h = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(playerPed, PED::GET_PED_BONE_INDEX(playerPed, SKEL_Head));
	float end = std::distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true)) + 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && IsKeyPressed(VK_LBUTTON))
	{
		if (start_supervis) {
			//Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			//ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
			start_supervis = false;
		}
		//WEAPON::SET_CURRENT_PED_WEAPON(playerPed, $("WEAPON_UNARMED"), 1);
		//ENTITY::SET_ENTITY_ROTATION(playerPed, 0, 0, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 1, true);

		auto war = $("WEAPON_RAYMINIGUN");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
		{
			WEAPON::REQUEST_WEAPON_ASSET(war, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(war))
				WAIT(0);
		}
		Vector3 startCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), s));
		Vector3 endCoords = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), end));
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 250, 1, war, playerPed, 1, 0, -1.0);
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, war, 1, 0);
		auto camrot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		auto camdir = rot_to_direction(&camrot);
		auto start = ENTITY::GET_ENTITY_COORDS(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID()), 1);

		auto end = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&camdir, 10.f));
		if (ENTITY::DOES_ENTITY_EXIST(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID())) && CONTROLS::IS_CONTROL_PRESSED(2, INPUT_AIM))
			GRAPHICS::DRAW_LINE(start.x, start.y, start.z, end.x, end.y, end.z, 255, 0, 0, 255);
	}
	else {
		start_supervis = true;
	}


}



bool Local::Fly = false;
void Local::fly(bool toggle)
{

	Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");

	PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
	PED::SET_PED_RAGDOLL_ON_COLLISION(playerPedId, !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPedId, !toggle);
	PED::SET_PED_CAN_RAGDOLL(playerPedId, !toggle);
	if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
	{
		if (GetAsyncKeyState(VK_SHIFT))
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 6, 0);
		}
		if (GetAsyncKeyState(0x53))
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, -6, 0);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 0, 0, 6);
		}
	}
}

int Local::TimePD;
bool Local::FB = false;
void Local::fb(bool toggle)
{
	float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;

	STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
	if ((timeGetTime() - Local::TimePD) > 200)
	{
		int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
			XOff, YOff, ZOff, SKEL_Head, 1, 1, 1, 1);
		Local::TimePD = timeGetTime();
	}
	STREAMING::REMOVE_PTFX_ASSET();
}



//if (IsKeyPressed(VK_MULTIPLY) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {

Vector3 GET_CAMERA_DIRECTIONLocal(float distance)
{
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	float tX = rot.x * 0.0174532924;
	float tZ = rot.z * 0.0174532924;
	float num = abs(cos(tX));
	Vector3 dir = { ((-sin(tZ)) * (num + distance)), (cos(tZ) * (num + distance)), (sin(tX) * 8) };
	return dir;
}
bool Local::NoClip = false;
void Local::noClip(bool toggle) {
	auto playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 rota = CAM::GET_GAMEPLAY_CAM_ROT(0.1);
	Vector3 dira = GET_CAMERA_DIRECTIONLocal(0.1);
	ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
	ENTITY::SET_ENTITY_ROTATION(playerPed, rota.x, rota.y, rota.z, 0.1, 0.1);
	auto pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, true, true, true);
restartpoint:;
	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptRB))
	{
		Vector3 pos = add(&ENTITY::GET_ENTITY_COORDS(playerPed, false), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 10.f));
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, true, true, true);
		if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptRB)) {
			goto restartpoint;
		}
	}
}




bool Local::FreeCam = false;
void Local::freeCam(bool toggle) {

	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	int Handle = PLAYER::PLAYER_PED_ID();

	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
	}
	if (!toggle)
	{
		Vector3 camCoords = CAM::GET_CAM_COORD(cam);
		ENTITY::SET_ENTITY_COORDS(Handle, camCoords.x, camCoords.y, camCoords.z, 0, 0, 0, 1);
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);

	}

	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

	p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
	PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

	auto speed = .5f;
	if (IsKeyPressed(VK_LSHIFT))
	{
		speed += .3f;
	}

	if (IsKeyPressed(VK_KEY_S))
	{
		speed /= -1;
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}

	if (IsKeyPressed(VK_KEY_W))
	{
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}
	else
	{
		CAM::SET_CAM_ACTIVE(cam, false);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::SET_PLAYER_CONTROL(Handle, true, 0);
		CAM::RENDER_SCRIPT_CAMS(false, false, 3000, 1, 0);
	}
	
}

bool Local::O1 = false;
void Local::o1(bool toggle)
{
	//Ghost
	Other::ResetAppearance();
	Other::changeAppearance("TORSO", 17, 0);
	Other::changeAppearance("MASK", 29, 0);
	Other::changeAppearance("HATS", 28, 0);
	Other::changeAppearance("HAIR", 0, 0);
	Other::changeAppearance("GLASSES", 0, 1);
	Other::changeAppearance("LEGS", 31, 0);
	Other::changeAppearance("SHOES", 24, 0);
	Other::changeAppearance("SPECIAL", 30, 2);
	Other::changeAppearance("SPECIAL2", 15, 0);
	Other::changeAppearance("TORSO2", 50, 0);
	Other::changeAppearance("HANDS", 0, 0);
}

bool Local::O2 = false;
void Local::o2(bool toggle)
{
	//Penguin
	Other::ResetAppearance();
	Other::changeAppearance("TORSO", 0, 0);
	Other::changeAppearance("MASK", 31, 0);
	Other::changeAppearance("HATS", 0, 0);
	Other::changeAppearance("HAIR", 0, 0);
	Other::changeAppearance("GLASSES", 0, 0);
	Other::changeAppearance("LEGS", 32, 0);
	Other::changeAppearance("SHOES", 17, 0);
	Other::changeAppearance("SPECIAL1", 0, 0);
	Other::changeAppearance("SPECIAL2", 57, 0); 
	Other::changeAppearance("TEXTURES", 0, 0); 
	Other::changeAppearance("TORSO2", 51, 0);
	Other::changeAppearance("HANDS", 0, 0);
}

bool Local::O3 = false;
void Local::o3(bool toggle)
{
	//Splinter
	Other::ResetAppearance();
	Other::changeAppearance("TORSO", 96, 0);
	Other::changeAppearance("MASK", 57, 0);
	Other::changeAppearance("HATS", 0, 0);
	Other::changeAppearance("HAIR", 23, 0);
	Other::changeAppearance("GLASSES", 0, 1);
	Other::changeAppearance("LEGS", 31, 0);
	Other::changeAppearance("SHOES", 25, 0);
	Other::changeAppearance("SPECIAL1", 0, 0);
	Other::changeAppearance("SPECIAL2", 58, 0);
	Other::changeAppearance("TEXTURES", 3, 0);
	Other::changeAppearance("TORSO2", 50, 0);
	Other::changeAppearance("HANDS", 0, 0);
}

bool Local::O4 = false;
void Local::o4(bool toggle)
{
	//Pilot
	Other::ResetAppearance();
	Other::changeAppearance("HATS", 20, 0);
	Other::changeAppearance("GLASSES", 6, 0);
	Other::changeAppearance("TORSO", 16, 0);
	Other::changeAppearance("LEGS", 30, 0);
	Other::changeAppearance("HANDS", 39, 4);
	Other::changeAppearance("SHOES", 24, 0);
	Other::changeAppearance("SPECIAL2", 15, 0);
	Other::changeAppearance("TORSO2", 48, 0);
}

bool Local::O5 = false;
void Local::o5(bool toggle)
{
	//Bad ass night soldier
	Other::ResetAppearance();
	Other::changeAppearance("TORSO", 96, 0);
	Other::changeAppearance("HATS", 40, 0);
	Other::changeAppearance("MASK", 54, 0);
	Other::changeAppearance("GLASSES", 0, 1);
	Other::changeAppearance("LEGS", 34, 0);
	Other::changeAppearance("SHOES", 25, 0);
	Other::changeAppearance("SPECIAL1", 0, 0);
	Other::changeAppearance("SPECIAL2", 15, 0);
	Other::changeAppearance("TORSO2", 53, 0);
	Other::changeAppearance("HANDS", 51, 0);
}

bool Local::O6 = false;
void Local::o6(bool toggle)
{
	//Favorite 
	Other::ResetAppearance();
	Other::changeAppearance("HATS", 40, 0);
	Other::changeAppearance("MASK", 28, 0);
	Other::changeAppearance("TORSO", 44, 0);
	Other::changeAppearance("LEGS", 34, 0);
	Other::changeAppearance("HANDS", 45, 0);
	Other::changeAppearance("SHOES", 25, 0);
	Other::changeAppearance("SPECIAL2", 56, 1);
	Other::changeAppearance("TORSO2", 53, 0);
}

bool Local::O7 = false;
void Local::o7(bool toggle)
{
	//Balla
	Other::ResetAppearance();
	Other::changeAppearance("HATS", 10, 7);
	Other::changeAppearance("GLASSES", 17, 6);
	Other::changeAppearance("MASK", 51, 6);
	Other::changeAppearance("TORSO", 14, 0);
	Other::changeAppearance("LEGS", 5, 9);
	Other::changeAppearance("SHOES", 9, 5);
	Other::changeAppearance("SPECIAL2", 23, 0);
	Other::changeAppearance("TORSO2", 7, 9);
}

bool Local::O8 = false;
void Local::o8(bool toggle)
{
	//Elf
	Other::ResetAppearance();
	Other::changeAppearance("MASK", 34, 0);
	Other::changeAppearance("TORSO", 4, 0);
	Other::changeAppearance("LEGS", 19, 1);
	Other::changeAppearance("SHOES", 22, 1);
	Other::changeAppearance("SPECIAL1", 18, 0);
	Other::changeAppearance("SPECIAL2", 28, 8);
	Other::changeAppearance("TORSO2", 19, 1);
}

bool Local::O9 = false;
void Local::o9(bool toggle)
{
	//Thug/gae
	Other::ResetAppearance();
	Other::changeAppearance("HATS", 46, 1);
	Other::changeAppearance("GLASSES", 17, 6);
	Other::changeAppearance("MASK", 51, 7);
	Other::changeAppearance("TORSO", 22, 0);
	Other::changeAppearance("LEGS", 7, 0);
	Other::changeAppearance("HANDS", 44, 0);
	Other::changeAppearance("SHOES", 12, 6);
	Other::changeAppearance("SPECIAL2", 15, 0);
	Other::changeAppearance("TORSO2", 14, 7);
}

bool Local::O10 = false;
void Local::o10(bool toggle)
{
	//Santa
	Other::ResetAppearance();
	Other::changeAppearance("MASK", 8, 0);
	Other::changeAppearance("TORSO", 12, 0);
	Other::changeAppearance("LEGS", 19, 0);
	Other::changeAppearance("SHOES", 4, 4);
	Other::changeAppearance("SPECIAL1", 10, 0);
	Other::changeAppearance("SPECIAL2", 21, 2);
	Other::changeAppearance("TORSO2", 19, 0);
}

bool Local::O11 = false;
void Local::o11(bool toggle)
{
	//Snowman 
	Other::ResetAppearance();
	Other::changeAppearance("MASK", 10, 0);
	Other::changeAppearance("TORSO", 12, 0);
	Other::changeAppearance("LEGS", 20, 0);
	Other::changeAppearance("SHOES", 18, 1);
	Other::changeAppearance("SPECIAL1", 24, 2);
	Other::changeAppearance("SPECIAL2", 22, 4);
	Other::changeAppearance("TORSO2", 25, 7);
}


bool Local::O12 = false;
void Local::o12(bool toggle)
{
	//Foxy
	Other::ResetAppearance();
	Other::changeAppearance("MASK", 18, 0);
	Other::changeAppearance("TORSO", 0, 0);
	Other::changeAppearance("LEGS", 27, 15);
	Other::changeAppearance("SHOES", 92, 1);
	Other::changeAppearance("SPECIAL1", 83, 0);
	Other::changeAppearance("SPECIAL2", 85, 3);
	Other::changeAppearance("TORSO2", 65, 3);
	Other::changeAppearance("HANDS", 51, 0); 
}
//	// mask 18| necklace 119,2 |hat 100 |gloves 20 |tshirt 196,2Z |pants 104, |shoes 92,1 |bag 82,7 
/*bool Local::O13 = false;
void Local::o13(bool toggle)
{
	//Foxy
	Other::ResetAppearance();
	Other::changeAppearance("MASK", 18, 0);// done
	Other::changeAppearance("TORSO", 0, 0);
	Other::changeAppearance("LEGS", 104, 0);//done
	Other::changeAppearance("SHOES", 92, 1);//done
	Other::changeAppearance("SPECIAL1", 83, 0);
	Other::changeAppearance("SPECIAL2", 85, 3);
	Other::changeAppearance("TORSO2", 65, 3);
	Other::changeAppearance("HANDS", 51, 0);
}*/



bool Local::F4 = false;
void Local::f4(bool toggle)
{
	if (GetAsyncKeyState(VK_F4))
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPedId, 1))
		{
			Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPedId);
			if (ENTITY::DOES_ENTITY_EXIST(playerVeh) && !ENTITY::IS_ENTITY_DEAD(playerVeh))
				VEHICLE::SET_VEHICLE_FIXED(playerVeh);
		}
		else
		{
			notifyMap("Happy, you didn't die right?");
		}
	}
}


bool Local::F7 = false;
void Local::f7(bool toggle)
{
	if (GetAsyncKeyState(VK_F7)) {


		void teleport_to_marker();
		{
			Vector3 coords = get_blip_marker();

			Entity e = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			{
				e = PED::GET_VEHICLE_PED_IS_USING(e);
			}

			if (coords.x == 0 && coords.y == 0)
			{
				Vector3 Coords;
				Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
				teleport_to_coords(e, Coords);
			}

			// load needed map region and check height levels for ground existence
			bool groundFound = false;
			static float groundCheckHeight[] =
			{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(100);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
				{
					groundFound = true;
					coords.z += 3.0;
					break;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				coords.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
			}
			//do it
			teleport_to_coords(e, coords);
		
		}
	}
}

bool Local::KeyNote = false;
void Local::keyNote(bool toggle) {

	if (GetAsyncKeyState(VK_F3))
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x -= xVec, pos.y -= yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x += xVec, pos.y += yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
		}
		if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
		}
		if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z -= 0.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z += 0.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
	}


}

void BoneFX(char* call1, char* call2, char* name, int bone) {
	float fx = 0.08f;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, PLAYER::PLAYER_PED_ID(), 0.00f, 0.00f, 0.00f,
		0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
	STREAMING::REMOVE_PTFX_ASSET();
}

bool Local::Particle = false;
void Local::particle(bool toggle)
{
	BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x796e);
	BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x8cbd);
	BoneFX("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0xdead);
}


double cDegreeToRadian(double n) {
	return n * 0.017453292519943295;
}

Vector3 cRotationToDirection(Vector3 rot) {
	double num = cDegreeToRadian(rot.z);
	double num2 = cDegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}

Vector3 caddVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}

Vector3 cmultiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

Vector3 crotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}

void Local::gae()
{
	GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
}

bool locked = false;
bool Local::Hulk = false;
void Local::hulk(bool toggle)
{
	if (toggle == true)
	{
		auto Yourself = PLAYER::PLAYER_PED_ID();

		PED::SET_PED_RAGDOLL_ON_COLLISION(playerPedId, !toggle);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPedId, !toggle);
		PED::SET_PED_CAN_RAGDOLL(playerPedId, !toggle);
		
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		
		if (IsKeyPressed('W'))
		{
			Ped ped = PLAYER::PLAYER_PED_ID();
			Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
			ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 1.3, 0, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
			PLAYER::SET_PLAYER_SPRINT(PLAYER::PLAYER_ID(), 1);
			PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(PLAYER::PLAYER_ID(), 4.6f);
			FIRE::START_SCRIPT_FIRE(offset.x, offset.y, offset.z, 1, false);
		}

		WEAPON::SET_CURRENT_PED_WEAPON(Yourself, $("WEAPON_UNARMED"), 1);

		int Me = PLAYER::PLAYER_PED_ID();
		if (GetAsyncKeyState(VK_SPACE))
		{
			Ped ped2 = PLAYER::PLAYER_PED_ID();
			AI::TASK_JUMP(ped2, true);
			AI::TASK_JUMP(Me, true);
			ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0, +3, 0, 0, 0, 1, 1, 1, 1, 0, 1);
		}

		 if (IsKeyPressed(VK_KEY_G))
		 {
			 if (ENTITY::IS_ENTITY_IN_AIR(Me))
			 {
				 Ped ped = PLAYER::PLAYER_PED_ID();
				 Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
				 ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, 0.0f, -50.f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
			 }
			 else {
				 Ped ped = PLAYER::PLAYER_PED_ID();
				 Vector3 spawnPosition = ENTITY::GET_ENTITY_COORDS(ped, 0);
				 char* dict = "rcmbarry";
				 char* anim = "bar_1_attack_alien_wins_aln";
				 STREAMING::REQUEST_ANIM_DICT(dict);
				 AI::TASK_PLAY_ANIM(ped, dict, anim, 1, 1, 16, 0, 0, false, 0, false);
				 FIRE::ADD_EXPLOSION(spawnPosition.x, spawnPosition.y, spawnPosition.z, 70, 1000, false, true, false);
				 FIRE::ADD_EXPLOSION(spawnPosition.x - 0.5, spawnPosition.y, spawnPosition.z, 70, 1000, false, true, false);
				 FIRE::ADD_EXPLOSION(spawnPosition.x, spawnPosition.y - 0.5, spawnPosition.z, 70, 1000, false, true, false);

				 FIRE::ADD_EXPLOSION(spawnPosition.x - 0.5, spawnPosition.y + 0.5, spawnPosition.z, 70, 1000, false, true, false);
				 FIRE::ADD_EXPLOSION(spawnPosition.x - 0.5, spawnPosition.y + 0.5, spawnPosition.z, 70, 1000, false, true, false);

				 FIRE::ADD_EXPLOSION(spawnPosition.x + 0.5, spawnPosition.y + 0.5, spawnPosition.z, 70, 1000, false, true, false);
				 FIRE::ADD_EXPLOSION(spawnPosition.x + 0.5, spawnPosition.y + 0.5, spawnPosition.z, 70, 1000, false, true, false);
			 }
		}

		Entity EntityTarget;
		DWORD equippedWeapon;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = cRotationToDirection(rot);
		Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float spawnDistance = get_distance(&camPosition, &playerPosition);
		spawnDistance += 6;
		Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


		Player tempPed = PLAYER::PLAYER_ID();

		if (locked) 
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{

				GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_01");
				Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestControlOfEnt(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
					ENTITY::SET_ENTITY_HEADING(
						EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_01");
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
						0.0f, 0, 0, 1, 1, 0, 1);
					locked = false;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
		if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			locked = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
	}

}


bool Local::STRW = false;
void Local::strw(bool toggle)
{
	if (toggle == true)
	{
		// Preset before loading inside options 
		auto Yourself = PLAYER::PLAYER_PED_ID(); 
		char* dict = "anim@amb@clubhouse@mini@darts@"; 
		char* anim = "outro";
		PED::SET_PED_RAGDOLL_ON_COLLISION(playerPedId, false);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPedId, false);
		PED::SET_PED_CAN_RAGDOLL(playerPedId, false);
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Yourself, 900);
		Entity EntityTarget;
		DWORD equippedWeapon;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
		Player player = PLAYER::PLAYER_ID();
		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = cRotationToDirection(rot);
		Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float spawnDistance = get_distance(&camPosition, &playerPosition);
		spawnDistance += 6;
		Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));
		Player tempPed = PLAYER::PLAYER_ID();
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);

		auto weapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
		auto weapon2 = WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID());
		Vector3 d1, d2;
		GAMEPLAY::GET_MODEL_DIMENSIONS(weapon2, &d1, &d2);
		auto x = std::sqrt((d1.x - d2.x)); 
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_impexp_jug");
		while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED1("scr_impexp_jug"))
		{
			WAIT(0);
		}
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_impexp_jug");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon,0.f, ((x * x) / 1.f + 0.3f), 0.f, 0.f, 180.f, 0.f, 0.5f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_ie_jug_mask_flame", weapon, 0.f, 0.f, 0.f, 0.f, 180.f, 0.f, 0.1f, 1, 1, 1);

		if (GetAsyncKeyState(Vk_c))
		{
			WEAPON::SET_CURRENT_PED_WEAPON(Yourself, $("WEAPON_POOLCUE"), 1);
		}


		int Me = PLAYER::PLAYER_PED_ID();
		if (GetAsyncKeyState(VK_SPACE))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0, +6, 0, 0, 0, 1, 1, 1, 1, 0, 1);
		}

		if (ENTITY::IS_ENTITY_IN_AIR(Me))
		{
			Ped ped = PLAYER::PLAYER_PED_ID();
			Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0, 0.6, 0);
			ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.0f, - 0.f, -5.f, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);

		}


		if (GetAsyncKeyState(VK_RBUTTON))
		{
			WEAPON::SET_CURRENT_PED_WEAPON(Yourself, $("WEAPON_UNARMED"), 1);
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{
				AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);

				GRAPHICS::SET_TIMECYCLE_MODIFIER("damage");
				Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestControlOfEnt(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
					ENTITY::SET_ENTITY_HEADING(
						EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					GRAPHICS::SET_TIMECYCLE_MODIFIER("damage");
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
						0.0f, 0, 0, 1, 1, 0, 1);
					locked = false;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
	}
	else
	{
		auto Yourself = PLAYER::PLAYER_PED_ID();
		PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Yourself, 1);
	}
}


//Bodyguard Local

#include "stdafx.h"

/*void Local::Outfit()
{
	Menu::Title("Wardrope");
	Menu::SubTitle("Wardrope");


	Menu::Int("Outfit Slot", selectedOutfit, 0, 100);
	Menu::Toggle("Load Ini Outfit", Local::LoadOutfit);
	Menu::Toggle("save Ini Outfit", Local::SaveOutfit);
	if (Menu::Option("ADD Rockstar Logo")) {
		PED::_APPLY_PED_OVERLAY(PLAYER::PLAYER_PED_ID(), -1398869298, -1730534702);

	}
	if (Menu::Option("ADD Rockstar Logo")) {
		PED::_APPLY_PED_OVERLAY(PLAYER::PLAYER_PED_ID(), -1398869298, -1730534702);

	}
	if (Menu::Int("Face", outfit1, 0, 11)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
	}
	if (Menu::Int("Mask", mask1, 0, 132)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
	}
	if (Menu::Int("Hair", mask2, 0, 73)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
	}
	if (Menu::Int("Gloves", shirt1, 0, 164)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
	}
	if (Menu::Int("Top", collars1, 0, 254)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
	}
	if (Menu::Int("Accessories", Accessories1, 0, 131)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
	}
	if (Menu::Int("Pants", pants1, 0, 99)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
	}
	if (Menu::Int("Accessories", hands1, 0, 69)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
	}
	if (Menu::Int("Shoes", shoes1, 0, 79)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
	}
	if (Menu::Int("Mission Stuff", mission1, 0, 29)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
	}
	if (Menu::Int("Decals", decals1, 0, 28)) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
	}

	if (Menu::Settings::currentOption == 1) {

	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Display a Rockstar Icon On Your Shirt");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Edit Your Face");
	}
	if (Menu::Settings::currentOption == 4) {
		Menu::OptionInfo("Edit Your Mask");
	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Edit Your Hair");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Edit Your Gloves");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Edit Your Top");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Edit Your Accessories");
	}
	if (Menu::Settings::currentOption == 9) {
		Menu::OptionInfo("Edit Your Shoes");
	}
	if (Menu::Settings::currentOption == 10) {
		Menu::OptionInfo("Edit Your Mission Stuff");
	}
	if (Menu::Settings::currentOption == 11) {
		Menu::OptionInfo("Edit Your Decals");
	}

}*/

// commom
char * Local::BodyguardModel2 = "";
char* Local::WeaponThing2 = "";
char* Local::BodyguardModel = "csb_ramp_marine";
char* Local::WeaponThing = "WEAPON_ASSAULTRIFLE";
int FormationPed = 0;
int Accu = 100;
int CombatRangehe = 500;
int pedattackers;
bool spawnWithBlipPed = false;
bool hostiletank = false;
bool vehspawncheck = false;
// Functions

void Local::Mainbodyguardss()
{
	Menu::Title("Bodyguards");
	Ped group = PED::GET_PED_GROUP_INDEX(PLAYER::PLAYER_PED_ID());
	Menu::SubTitle("BodyGuards");
	Menu::Toggle("Spawn With Blip", spawnWithBlipPed);
	Menu::Toggle("Invincible", BodyguardInvincible);
	Menu::Int("Formation", FormationPed, 0, 3); { PED::SET_GROUP_FORMATION(group, FormationPed); }
    Menu::Int("Accuracy", Accu, 0, 100, 10);
	Menu::Int("Combat Range", CombatRangehe, 0, 500, 100);
	Menu::MenuOption("Models", modelsub);
	Menu::MenuOption("Weapons", BodyguardWeapons);
	
	if (Menu::Option("Spawn")) 
	{
		{
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			Vector3 position = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			DWORD pedModel = GAMEPLAY::GET_HASH_KEY(BodyguardModel);
			Vector3 fposition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0.0, 5.0, 0.0);

			if (STREAMING::IS_MODEL_IN_CDIMAGE(pedModel) && STREAMING::IS_MODEL_VALID(pedModel))
			{

				STREAMING::REQUEST_MODEL(pedModel);
				while (!STREAMING::HAS_MODEL_LOADED(pedModel)) WAIT(0);
				Ped spawnedPed = PED::CREATE_PED(1, pedModel, fposition.x, fposition.y, fposition.z, ENTITY::GET_ENTITY_HEADING(playerPed), TRUE, TRUE);


				PED::SET_PED_AS_GROUP_MEMBER(spawnedPed, group);
				PED::SET_PED_COMBAT_RANGE(spawnedPed, CombatRangehe);
				PED::SET_PED_ALERTNESS(spawnedPed, 100);
				ENTITY::SET_ENTITY_INVINCIBLE(spawnedPed, BodyguardInvincible);
				PED::SET_PED_ACCURACY(spawnedPed, Accu);
				PED::SET_PED_ACCURACY(spawnedPed, Accu);
				PED::SET_PED_CAN_SWITCH_WEAPON(spawnedPed, 1);
				PED::SET_PED_SHOOT_RATE(spawnedPed, 200);
				PED::SET_PED_KEEP_TASK(spawnedPed, true);
				AI::TASK_COMBAT_HATED_TARGETS_AROUND_PED(spawnedPed, 5000.f, 0);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(spawnedPed, GAMEPLAY::GET_HASH_KEY(WeaponThing), 1, 0);
				PED::SET_PED_KEEP_TASK(spawnedPed, true);
				PED::SET_PED_GENERATES_DEAD_BODY_EVENTS(spawnedPed, true);

				{
				
					if (spawnWithBlipPed)
					{
						int blip;
						blip = UI::ADD_BLIP_FOR_ENTITY(spawnedPed);
						UI::SET_BLIP_SPRITE(blip, 28);
						UI::SET_BLIP_COLOUR(blip, 3);
						int blip2 = UI::ADD_BLIP_FOR_ENTITY(spawnedPed);
						UI::SET_BLIP_SPRITE(blip2, 1); // REMOVE_BLIP
					}
					char buf[255];
					char buf1[255];
					char buf2[255];
					sprintf(buf, "Weapon: %s", WeaponThing2);//
					sprintf(buf1, "Model: %s", BodyguardModel2);
					sprintf(buf2, "Bodyguard spawned!~n~"
						"%s~n~"
						"%s~n~", buf1, buf);
					notifyMap(buf2);
				}
			}
		}
	}
	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Show a Friend Icon On Your Bodyguards");
	}
	if (Menu::Settings::currentOption == 2) {
		Menu::OptionInfo("Set Bodyguards In Godmode");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Edit Your Bodyguard's Formation");
	}
	if (Menu::Settings::currentOption == 4) {
		Menu::OptionInfo("Edit Your Bodyguard's Accuracy");
	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Edit Your Bodyguard's Combat Range");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Models Sub");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Weapons Sub");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Spawn Your Bodyguards");
	}
	
}


void Local::Weaponss()
{
	Menu::Title("");
	Menu::SubTitle("Weapons"); // WeaponThing

	if (Local::WeaponThing == "WEAPON_ASSAULTRIFLE")
	{
		Local::WeaponThing2 = "Assault Rifle";
	}
	if (Local::WeaponThing == "WEAPON_CARBINERIFLE")
	{
		Local::WeaponThing2 = "Carbine Rifle";
	}
	if (Local::WeaponThing == "WEAPON_KNIFE")
	{
		Local::WeaponThing2 = "Knife";
	}
	if (Local::WeaponThing == "WEAPON_ASSAULTSHOTGUN")
	{
		Local::WeaponThing2 = "Assault Shotgun";
	}
	if (Local::WeaponThing == "WEAPON_HEAVYSNIPER")
	{
		Local::WeaponThing2 = "Heavy Sniper";
	}
	if (Local::WeaponThing == "WEAPON_RPG")
	{
		Local::WeaponThing2 = "RPG";
	}
	if (Local::WeaponThing == "WEAPON_RAYPISTOL")
	{
		Local::WeaponThing2 = "Ray Pistol";
	}
	if (Local::WeaponThing == "WEAPON_RAYCARBINE")
	{
		Local::WeaponThing2 = "Ray Carbine";
	}
	if (Local::WeaponThing == "WEAPON_PISTOL")
	{
		Local::WeaponThing2 = "Pistol";
	}
	if (Local::WeaponThing == "WEAPON_MICROSMG")
	{
		Local::WeaponThing2 = "Micro SMG";
	}
	if (Local::WeaponThing == "WEAPON_MARKSMANRIFLE")
	{
		Local::WeaponThing2 = "Marksman Rifle";
	}
	if (Local::WeaponThing == "WEAPON_CARBINERIFLE_MK2")
	{
		Local::WeaponThing2 = "Carbinerifle MKII";
	}
	if (Local::WeaponThing == "WEAPON_VINTAGEPISTOL")
	{
		Local::WeaponThing2 = "Silenced Pistol";
	}
	char buf[255];
	sprintf(buf, "Current Weapon: %s", Local::WeaponThing2);//
	Menu::Option(buf);
	if (Menu::Option("~f~[ ~w~Select Weapons ~f~]"))
	{
	}
	if (Menu::Option("Default")) {
		Local::WeaponThing = "WEAPON_ASSAULTRIFLE";
		notifyMap("Weapon set to:~n~"
			"Assaultrifle~n~");
	}
	if (Menu::Option("Carbine Rifle")) {
		Local::WeaponThing = "WEAPON_CARBINERIFLE";
		notifyMap("Weapon set to:~n~"
			"Carbinerifle~n~");
	}
	if (Menu::Option("Knife")) {
		Local::WeaponThing = "WEAPON_KNIFE";
		notifyMap("Weapon set to:~n~"
			"Knife~n~");
	}
	if (Menu::Option("Assault Shotgun")) {
		Local::WeaponThing = "WEAPON_ASSAULTSHOTGUN";
		notifyMap("Weapon set to:~n~"
			"Assault Shotgun~n~");
	}
	if (Menu::Option("Heavy Sniper")) {
		Local::WeaponThing = "WEAPON_HEAVYSNIPER";
		notifyMap("Weapon set to:~n~"
			"Heavy Sniper~n~");
	}
	if (Menu::Option("RPG")) {
		Local::WeaponThing = "WEAPON_RPG";
		notifyMap("Weapon set to:~n~"
			"RPG~n~");
	}
	if (Menu::Option("Ray Pistol")) {
		Local::WeaponThing = "WEAPON_RAYPISTOL";
		notifyMap("Weapon set to:~n~"
			"Raypistol~n~");
	}
	if (Menu::Option("Ray Carbine")) {
		Local::WeaponThing = "WEAPON_RAYCARBINE";
		notifyMap("Weapon set to:~n~"
			"Raycarbine~n~");
	}
	if (Menu::Option("Pistol")) {
		Local::WeaponThing = "WEAPON_PISTOL";
		notifyMap("Weapon set to:~n~"
			"Pistol~n~");
	}
	if (Menu::Option("Micro SMG")) {
		Local::WeaponThing = "WEAPON_MICROSMG";
		notifyMap("Weapon set to:~n~"
			"Miscro SMG~n~");
	}
	if (Menu::Option("Marksman Rifle")) {
		Local::WeaponThing = "WEAPON_MARKSMANRIFLE";
		notifyMap("Weapon set to:~n~"
			"Marksman Rifle~n~");
	}
	if (Menu::Option("Carbinerifle MKII")) {
		Local::WeaponThing = "WEAPON_CARBINERIFLE_MK2";
		notifyMap("Weapon set to:~n~"
			"Carbinerifle MK2~n~");
	}
}

void Local::Modelss()
{
	Menu::Title("");
	Menu::SubTitle("Models");

	char buf[255];
	sprintf(buf, "Current Model: %s", Local::BodyguardModel2);//

	if (Local::BodyguardModel == "csb_ramp_marine")
	{
		Local::BodyguardModel2 = "Marine";
	}
	if (Local::BodyguardModel == "G_M_Y_Lost_02")
	{
		Local::BodyguardModel2 = "Biker";
	}
	if (Local::BodyguardModel == "S_M_Y_Cop_01")
	{
		Local::BodyguardModel2 = "Cop";
	}
	if (Local::BodyguardModel == "Player_Zero")
	{
		Local::BodyguardModel2 = "Michael";
	}
	if (Local::BodyguardModel == "Player_One")
	{
		Local::BodyguardModel2 = "Franklin";
	}
	if (Local::BodyguardModel == "Player_two")
	{
		Local::BodyguardModel2 = "Trevor";
	}
	if (Local::BodyguardModel == "U_M_Y_ImpoRage")
	{
		Local::BodyguardModel2 = "Impo Rage";
	}
	if (Local::BodyguardModel == "U_M_Y_RSRanger_01")
	{
		Local::BodyguardModel2 = "Space Ranger";
	}
	if (Local::BodyguardModel == "IG_ChrisFormage")//model
	{
		Local::BodyguardModel2 = "Christ Fromage";//name
	}
	if (Local::BodyguardModel == "CS_Floyd")//model
	{
		Local::BodyguardModel2 = "Floyd";//name
	}
	if (Local::BodyguardModel == "S_M_Y_Clown_01")//model
	{
		Local::BodyguardModel2 = "Clown";//name
	}
	if (Local::BodyguardModel == "Player_One")//model
	{
		Local::BodyguardModel2 = "Player One?";//name
	}
	if (Local::BodyguardModel == "S_M_Y_BlackOps_01")//model
	{
		Local::BodyguardModel2 = "Black Ops1";//name
	}
	if (Local::BodyguardModel == "S_M_Y_BlackOps_02")//model
	{
		Local::BodyguardModel2 = "Black Ops2";//name
	}
	if (Local::BodyguardModel == "S_M_Y_BlackOps_03")//model
	{
		Local::BodyguardModel2 = "Black Ops3";//name
	}
	if (Local::BodyguardModel == "A_C_Rhesus")//model
	{
		Local::BodyguardModel2 = "Rhesus";//name
	}

	Menu::Option(buf);
	if (Menu::Option("~f~[ ~w~Set Models ~f~]"))
	{
	}
	if (Menu::Option("Default")) {
		Local::BodyguardModel = "csb_ramp_marine";
		notifyMap("Model set to:~n~"
			"Marine~n~");
	}
	if (Menu::Option("Biker")) {
		Local::BodyguardModel = "G_M_Y_Lost_02";
		notifyMap("Model set to:~n~"
			"Biker~n~");
	}
	if (Menu::Option("Cop")) {
		Local::BodyguardModel = "S_M_Y_Cop_01";
		notifyMap("Model set to:~n~"
			"Cop~n~");
	}
	if (Menu::Option("Michael")) {
		Local::BodyguardModel = "Player_Zero";
		notifyMap("Model set to:~n~"
			"Michael~n~");
	}
	if (Menu::Option("Franklin")) {
		Local::BodyguardModel = "Player_One";
		notifyMap("Model set to:~n~"
			"Franklin~n~");
	}
	if (Menu::Option("Trevor")) {
		Local::BodyguardModel = "Player_two";
		notifyMap("Model set to:~n~"
			"Trevor~n~");
	}
	if (Menu::Option("Impo Rage")) {
		Local::BodyguardModel = "U_M_Y_ImpoRage";
		notifyMap("Model set to:~n~"
			"Impo Rage~n~");
	}
	if (Menu::Option("Space Ranger")) {
		Local::BodyguardModel = "U_M_Y_RSRanger_01";
		notifyMap("Model set to:~n~"
			"Space Ranger~n~");
	}
	if (Menu::Option("Christ Fromage")) {//option name
		Local::BodyguardModel = "IG_ChrisFormage";//Model
		notifyMap("Model set to:~n~"
			"Christ Fromage~n~");//name
	}
	if (Menu::Option("Floyd")) {//option name
		Local::BodyguardModel = "CS_Floyd";//Model
		notifyMap("Model set to:~n~"
			"Floyd~n~");//name
	}
	if (Menu::Option("Clown")) {//option name
		Local::BodyguardModel = "S_M_Y_Clown_01";//Model
		notifyMap("Model set to:~n~"
			"Clown~n~");//name
	}
	if (Menu::Option("Player One?")) {//option name
		Local::BodyguardModel = "Player_One";//Model
		notifyMap("Model set to:~n~"
			"Player 1?~n~");//name
	}
	if (Menu::Option("Black Ops1")) {//option name
		Local::BodyguardModel = "S_M_Y_BlackOps_01";//Model
		notifyMap("Model set to:~n~"
			"Black Ops1~n~");//name
	}
	if (Menu::Option("Black Ops2")) {//option name
		Local::BodyguardModel = "S_M_Y_BlackOps_02";//Model
		notifyMap("Model set to:~n~"
			"Black Ops2~n~");//name
	}
	if (Menu::Option("Black Ops3")) {//option name
		Local::BodyguardModel = "S_M_Y_BlackOps_03";//Model
		notifyMap("Model set to:~n~"
			"Black Ops~n~");//name
	}
	if (Menu::Option("Rhesus")) {//option name
		Local::BodyguardModel = "A_C_Rhesus";//Model
		notifyMap("Model set to:~n~"
			"Rhesus~n~");//name
	}

}













// spawn enemy

bool HostileTank()
{
	if (hostiletank)
	{
		if (vehspawncheck)
		{
			int movdel = GAMEPLAY::GET_HASH_KEY("rhino");
			float speed = ENTITY::GET_ENTITY_SPEED(PLAYER::PLAYER_PED_ID());
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("rhino"));
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("rhino")))
			{
				Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 6.0, 0.0, 0.0);
				int vehattackers = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY("rhino"), coords.x, coords.y + 10, coords.z, 0, 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(vehattackers))
				{
					vehspawncheck = false;
					pedattackers = true;
					if (pedattackers)
					{
						STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"));
						if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01")))
						{
							Vector3 coords_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 6.0, 0.0, 0.0);
							pedattackers = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY("s_m_y_blackops_01"), coords_.x, coords_.y, coords_.z, 1, 1, 0);
							if (ENTITY::DOES_ENTITY_EXIST(pedattackers))
							{
								PED::SET_PED_INTO_VEHICLE(pedattackers, vehattackers, -1);
								VEHICLE::SET_VEHICLE_DOORS_LOCKED(vehattackers, true);
								VEHICLE::SET_VEHICLE_ENGINE_ON(vehattackers, true, true, true);
								VEHICLE::SET_HELI_BLADES_FULL_SPEED(vehattackers);
								AI::TASK_VEHICLE_SHOOT_AT_PED(0, 0, 0);
								AI::TASK_LEAVE_ANY_VEHICLE(pedattackers, true, false);
								int TargetHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
								AI::TASK_COMBAT_PED(pedattackers, TargetHandle, 0, 16);
								AI::TASK_VEHICLE_CHASE(pedattackers, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
								PED::SET_PED_CAN_SWITCH_WEAPON(pedattackers, true);
								pedattackers = false;
								return true;
							}
							return false;
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}
void DeletePed(int pedID)
{
	if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID))
		while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pedID));

	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedID, 1, 1);
	PED::DELETE_PED(&pedID);
}
void makePedHostile(uint Ped, int Target, bool choporswat = false, bool isClone = false)
{
	if (choporswat)
	{
		AI::TASK_COMBAT_PED(Ped, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 16);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
	}
	else
	{
		if (isClone)
		{
			int Hash = ENTITY::GET_ENTITY_MODEL(Ped);
			DeletePed(Ped);

			STREAMING::REQUEST_MODEL(Hash);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target), 1);
			if (STREAMING::HAS_MODEL_LOADED(Hash))
			{
				int newPed = PED::CREATE_PED(21, Hash, coords.x, coords.y, coords.z, 0, 1, 0);
				if (ENTITY::GET_ENTITY_HEALTH(newPed) == ENTITY::GET_ENTITY_MAX_HEALTH(newPed))
				{
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hash);
					RequestControlOfEnt(newPed);
					AI::TASK_COMBAT_PED(newPed, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0, 16);
					PED::SET_PED_CAN_SWITCH_WEAPON(Ped, true);
				}
			}
		}
		else
		{
			int TargetHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Target);
			AI::TASK_COMBAT_PED(Ped, TargetHandle, 0, 16);
		}
	}

}
void GiveWeaponPed(int Ped, int WeaponHash)
{
	WEAPON::GIVE_WEAPON_TO_PED(Ped, WeaponHash, 9999, 1, 1);

}

//Visions
//Animations
//Scenarios
//Outfit Main Menu

bool reee(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}

void PTFXCALL(char *call1, char *call2, char *name)
{

	call1o = call1;
	call2o = call2;
	nameo = name;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

}


void PTFXCALLCORE(char* name)
{
	nameo = name;
	STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
}



void doAnimation(char* anim, char* animid)
{
	int pPlayer = playerPedId;
	reee(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, Animationflags[AnimationFlag_pos], 0, 0, 0, 0);
	}
}


void doAnimation1(char* anim, char* animid)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			STREAMING::REQUEST_ANIM_DICT(anim);
			if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
			{
				AI::TASK_PLAY_ANIM(peds[OffsetID], anim, animid, 8.0f, 0.0f, -1, Animationflags[AnimationFlag_pos], 0, 0, 0, 0);
			}
		}
	}
}


void Local::Visions()
{
	Menu::Title("");
	Menu::SubTitle("Visions");
	if (Menu::Option("Clear Vision"))
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
	}
	if (Menu::Option("Chop"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CHOP");
	}
	if (Menu::Option("Silverlake Water"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("WATER_silverlake");
	}
	if (Menu::Option("Night Lighting"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("whitenightlighting");
	}
	if (Menu::Option("White Out"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("WhiteOut");
	}
	if (Menu::Option("Camera BW"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_BW");
	}
	if (Menu::Option("Camera Security"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity");
	}
	if (Menu::Option("Camera Secuirty Buzz"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity_FUZZ");
	}
	if (Menu::Option("Canyon Mission"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("canyon_mission");
	}
	if (Menu::Option("Cops"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("cops");
	}
	if (Menu::Option("Damage"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("damage");
	}
	if (Menu::Option("Bank HLWD"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Bank_HLWD");
	}
	if (Menu::Option("Death"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("MP_death_grade");
	}
	if (Menu::Option("Drugs 1"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_drive_blend01");
	}
	if (Menu::Option("Drugs 2"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_drive_blend02");
	}
	if (Menu::Option("Drugs 3"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("drug_flying_01");
	}
	if (Menu::Option("Prologue"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("prologue");
	}
	if (Menu::Option("Prologue Reflection"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("prologue_reflection_opt");
	}
	if (Menu::Option("Prolouge Shootout"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("prologue_shootout");
	}
	if (Menu::Option("Prolouge Shootout 2"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Prologue_shootout_opt");
	}
	if (Menu::Option("Cinema"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema");
	}
	if (Menu::Option("Cinema 2"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("cinema_001");
	}
	if (Menu::Option("Pulse"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("pulse");
	}
	if (Menu::Option("Race Turbo Dark"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("RaceTurboDark");
	}
	if (Menu::Option("Race Turbo Flash"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("RaceTurboFlash");
	}
	if (Menu::Option("Race Turbo Light"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("RaceTurboLight");
	}
	if (Menu::Option("Ranch"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("ranch");
	}
	if (Menu::Option("Red Mist"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST");
	}
	if (Menu::Option("Red Mist Blend"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("REDMIST_blend");
	}
	if (Menu::Option("UFO"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("ufo");
	}
	if (Menu::Option("UFO Deathray"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("ufo_deathray");
	}
	if (Menu::Option("Under Water"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("underwater");
	}
	if (Menu::Option("Tunnel"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Tunnel");
	}
	if (Menu::Option("Barry Stoned"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("Barry1_Stoned");
	}
	if (Menu::Option("Barry Fade Out"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BarryFadeOut");
	}
	if (Menu::Option("Bloom Light"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BloomLight");
	}
	if (Menu::Option("Building Top"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("buildingTOP");
	}
	if (Menu::Option("Bullet Time Dark"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BulletTimeDark");
	}
	if (Menu::Option("Building Time Light"))
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER("BulletTimeLight");
	}
}

void Local::Effects()
{
	Menu::Title("");
	Menu::SubTitle("Effects");
	Menu::MenuOption("Core Ptfx", Coreptfx);
	if (Menu::Option("Clown Appears"))PTFXCALL("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears");
	if (Menu::Option("Alien 1"))PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate");
	if (Menu::Option("Alien 2"))PTFXCALL("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport");
	if (Menu::Option("Firework 1"))PTFXCALL("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst");
	if (Menu::Option("Firework 2"))PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_burst_rgw");
	if (Menu::Option("Firework 3"))PTFXCALL("proj_xmas_firework", "proj_xmas_firework", "scr_firework_xmas_spiral_burst_rgw");
	if (Menu::Option("Meth Smoke"))PTFXCALL("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke");
	if (Menu::Option("Electric Box"))PTFXCALL("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box");
	if (Menu::Option("Truck Crash"))PTFXCALL("scr_fbi4", "scr_fbi4", "scr_fbi4_trucks_crash");
	if (Menu::Option("Water Splash"))PTFXCALL("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash");
	//if (Menu::Option("Bubbles"))PTFXCALL("scr_fbi5a", "scr_fbi5a", "water_splash_ped_bubbles");
	//if (Menu::Option("Blood Entry"))PTFXCALL("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry");
	if (Menu::Option("Sniper Impact"))PTFXCALL("scr_martin1", "scr_martin1", "scr_sol1_sniper_impact");
	if (Menu::Option("Dirt Throw"))PTFXCALL("core_snow", "core_snow", "cs_mich1_spade_dirt_throw");
	if (Menu::Option("Banknotes"))PTFXCALL("scr_ornate_heist", "scr_ornate_heist", "scr_heist_ornate_banknotes");
	if (Menu::Option("Blood Stab"))PTFXCALL("scr_michael2", "scr_michael2", "scr_mich2_blood_stab");
	if (Menu::Option("Ped Sliced"))PTFXCALL("scr_michael2", "scr_michael2", "scr_abattoir_ped_sliced");
	if (Menu::Option("Camera"))PTFXCALL("scr_rcpaparazzo1", "scr_rcpaparazzo1", "scr_rcpap1_camera");
	if (Menu::Option("Burial Dirt"))PTFXCALL("scr_reburials", "scr_reburials", "scr_burial_dirt");
	if (Menu::Option("Champagne"))PTFXCALL("scr_ba_club", "scr_ba_club", "scr_ba_club_champagne_spray");
	if (Menu::Option("Arcade Lazer"))PTFXCALL("scr_ch_finale", "scr_ch_finale", "scr_ch_finale_laser");
	if (Menu::Option("Arcade Lazer Spark"))PTFXCALL("scr_ch_finale", "scr_ch_finale", "scr_ch_finale_laser_sparks");
	if (Menu::Option("Arcade Drill Spark"))PTFXCALL("scr_ch_finale", "scr_ch_finale", "scr_ch_finale_drill_sparks");
	if (Menu::Option("Arcade Drill OverHeat"))PTFXCALL("scr_ch_finale", "scr_ch_finale", "scr_ch_finale_drill_overheat");
	if (Menu::Option("Beast Appear"))PTFXCALL("scr_powerplay", "scr_powerplay", "scr_powerplay_beast_appear");
    if (Menu::Option("Splash"))PTFXCALL("scr_mp_creator", "scr_mp_creator", "scr_mp_splash");
	if (Menu::Option("Dust Cloud"))PTFXCALL("scr_mp_creator", "scr_mp_creator", "scr_mp_dust_cloud");
}

void Local::Anim()
{
	Menu::Title("Animations");
	Menu::SubTitle("Animations");
	Menu::MenuOption("Scenarios", scen);
	if (Menu::Option("Reset")) AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPedId);
	if (Menu::Addintchar("Set Animation Flags", AnimationFlagsName, AnimationFlag_pos, 0, 3)) {}
	if (Menu::Option("Pole Dance")) { doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
	if (Menu::Option("Push Ups")) { doAnimation("amb@world_human_push_ups@male@base", "base"); }
	if (Menu::Option("Sit Ups")) { doAnimation("amb@world_human_sit_ups@male@base", "base"); }
	if (Menu::Option("Meditation")) { doAnimation("rcmcollect_paperleadinout@", "meditiate_idle"); }
	if (Menu::Option("On Fire")) { doAnimation("random@arrests", "kneeling_arrest_idle"); }
	if (Menu::Option("Celebrate")) { doAnimation("rcmfanatic1celebrate", "celebrate"); }
	if (Menu::Option("Electrocution")) { doAnimation("ragdoll@human", "electrocute"); }
	if (Menu::Option("Suicide")) { doAnimation("mp_suicide", "pistol"); }
	if (Menu::Option("Showering")) { doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
	if (Menu::Option("Sex Receiver")) { doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
	if (Menu::Option("Sex Giver")) { doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
	if (Menu::Option("Stripper Dance")) { doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
	if (Menu::Option("Freak Out")) { doAnimation("missfbi5ig_30monkeys", "monkey_b_freakout_loop"); }
	if (Menu::Option("Poop")) { doAnimation("missfbi3ig_0", "shit_loop_trev"); }
	if (Menu::Option("Arm Wrestling Face B")) { doAnimation("mini@arm_wrestling", "nuetral_idle_b_face"); }
	if (Menu::Option("Arm Wrestling Face A")) { doAnimation("mini@arm_wrestling", "nuetral_idle_a_face"); }
	if (Menu::Option("Arm Wrestling Face Win B")) { doAnimation("mini@arm_wrestling", "win_b_ped_b_face"); }
	if (Menu::Option("Arm Wrestling Face Win A")) { doAnimation("mini@arm_wrestling", "win_a_ped_b_face"); }
	if (Menu::Option("Security Guard Idle")) { doAnimation("anim@move_m@security_guard", "idle"); }
	if (Menu::Option("Security Guard Idle 2")) { doAnimation("anim@move_m@security_guard", "idle_var_05"); }
	if (Menu::Option("Security Guard Idle 3")) { doAnimation("anim@move_m@security_guard", "idle_var_01"); }
	if (Menu::Option("Dart Throw")) { doAnimation("anim@amb@clubhouse@mini@darts@", "throw_idle_a_down"); }
	if (Menu::Option("Dart Outro")) { doAnimation("anim@amb@clubhouse@mini@darts@", "outro"); }
	if (Menu::Option("Wary Loop")) { doAnimation("mp_am_hold_up", "WARY_LOOP"); }
	if (Menu::Option("Beast Transformation")) { doAnimation("ANIM@MP_FM_EVENT@INTRO", "BEAST_TRANSFORM"); }
	if (Menu::Option("Park Attendant")) { doAnimation("amb@world_human_car_park_attendant@male@base", "base"); }
	if (Menu::Option("Robbery worried")) { doAnimation("random@robbery", "stand_worried_female"); }
	if (Menu::Option("Robbery Flee")) { doAnimation("random@robbery", "exit_flee"); }
	if (Menu::Option("Robbery Distressed")) { doAnimation("random@robbery", "f_distressed_loop"); }
	if (Menu::Option("Robbery Kneel")) { doAnimation("random@shop_robbery", "kneel_loop_p"); }
	if (Menu::Option("Robbery Action P")) { doAnimation("random@shop_robbery", "robbery_action_p"); }
	if (Menu::Option("Monkey Dance")) { doAnimation("missfbi5ig_30monkeys", "monkey_a_freakout_loop"); }
}

void Local::Anim1()
{
	Menu::Title("Animations");
	Menu::SubTitle("Animations");
	Menu::MenuOption("Scenarios", scen11);
	if (Menu::Option("Reset")) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				AI::CLEAR_PED_TASKS_IMMEDIATELY(peds[OffsetID]);
			}
		}
	}
	if (Menu::Addintchar("Set Animation Flags", AnimationFlagsName, AnimationFlag_pos, 0, 3)) {}
	if (Menu::Option("Pole Dance")) { doAnimation1("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
	if (Menu::Option("Push Ups")) { doAnimation1("amb@world_human_push_ups@male@base", "base"); }
	if (Menu::Option("Sit Ups")) { doAnimation1("amb@world_human_sit_ups@male@base", "base"); }
	if (Menu::Option("Meditation")) { doAnimation1("rcmcollect_paperleadinout@", "meditiate_idle"); }
	if (Menu::Option("On Fire")) { doAnimation1("random@arrests", "kneeling_arrest_idle"); }
	if (Menu::Option("Celebrate")) { doAnimation1("rcmfanatic1celebrate", "celebrate"); }
	if (Menu::Option("Electrocution")) { doAnimation1("ragdoll@human", "electrocute"); }
	if (Menu::Option("Suicide")) { doAnimation1("mp_suicide", "pistol"); }
	if (Menu::Option("Showering")) { doAnimation1("mp_safehouseshower@male@", "male_shower_idle_b"); }
	if (Menu::Option("Sex Receiver")) { doAnimation1("rcmpaparazzo_2", "shag_loop_poppy"); }
	if (Menu::Option("Sex Giver")) { doAnimation1("rcmpaparazzo_2", "shag_loop_a"); }
	if (Menu::Option("Stripper Dance")) { doAnimation1("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
	if (Menu::Option("Freak Out")) { doAnimation1("missfbi5ig_30monkeys", "monkey_b_freakout_loop"); }
	if (Menu::Option("Poop")) { doAnimation1("missfbi3ig_0", "shit_loop_trev"); }
	if (Menu::Option("Arm Wrestling Face B")) { doAnimation1("mini@arm_wrestling", "nuetral_idle_b_face"); }
	if (Menu::Option("Arm Wrestling Face A")) { doAnimation1("mini@arm_wrestling", "nuetral_idle_a_face"); }
	if (Menu::Option("Arm Wrestling Face Win B")) { doAnimation1("mini@arm_wrestling", "win_b_ped_b_face"); }
	if (Menu::Option("Arm Wrestling Face Win A")) { doAnimation1("mini@arm_wrestling", "win_a_ped_b_face"); }
	if (Menu::Option("Security Guard Idle")) { doAnimation1("anim@move_m@security_guard", "idle"); }
	if (Menu::Option("Security Guard Idle 2")) { doAnimation1("anim@move_m@security_guard", "idle_var_05"); }
	if (Menu::Option("Security Guard Idle 3")) { doAnimation1("anim@move_m@security_guard", "idle_var_01"); }
	if (Menu::Option("Dart Throw")) { doAnimation1("anim@amb@clubhouse@mini@darts@", "throw_idle_a_down"); }
	if (Menu::Option("Dart Outro")) { doAnimation1("anim@amb@clubhouse@mini@darts@", "outro"); }
	if (Menu::Option("Wary Loop")) { doAnimation1("mp_am_hold_up", "WARY_LOOP"); }
	if (Menu::Option("Beast Transformation")) { doAnimation1("ANIM@MP_FM_EVENT@INTRO", "BEAST_TRANSFORM"); }
	if (Menu::Option("Park Attendant")) { doAnimation1("amb@world_human_car_park_attendant@male@base", "base"); }
	if (Menu::Option("Robbery worried")) { doAnimation1("random@robbery", "stand_worried_female"); }
	if (Menu::Option("Robbery Flee")) { doAnimation1("random@robbery", "exit_flee"); }
	if (Menu::Option("Robbery Distressed")) { doAnimation1("random@robbery", "f_distressed_loop"); }
	if (Menu::Option("Robbery Kneel")) { doAnimation1("random@shop_robbery", "kneel_loop_p"); }
	if (Menu::Option("Robbery Action P")) { doAnimation1("random@shop_robbery", "robbery_action_p"); }
	if (Menu::Option("Monkey Dance")) { doAnimation1("missfbi5ig_30monkeys", "monkey_a_freakout_loop"); }

}

void Local::Scen1()
{
	Menu::Title("");
	Menu::SubTitle("Scenarios");
	if (Menu::Option("Reset")) {
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;
		Ped* peds = new Ped[ArrSize];
		peds[0] = ElementAmount;
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				AI::CLEAR_PED_TASKS_IMMEDIATELY(peds[OffsetID]);
			}
		}
	}
	if (Menu::Option("Standing")) allpedscenario("STANDING");
	if (Menu::Option("Coffee")) allpedscenario("WORLD_HUMAN_AA_COFFEE");
	if (Menu::Option("Smoking")) allpedscenario("WORLD_HUMAN_AA_SMOKE");
	if (Menu::Option("Binocular")) allpedscenario("WORLD_HUMAN_BINOCULARS");
	if (Menu::Option("Bum Freeway")) allpedscenario("WORLD_HUMAN_BUM_FREEWAY");
	if (Menu::Option("Bum Slumped")) allpedscenario("WORLD_HUMAN_BUM_SLUMPED");
	if (Menu::Option("Bum Standing")) allpedscenario("WORLD_HUMAN_BUM_STANDING");
	if (Menu::Option("Bum Wash")) allpedscenario("WORLD_HUMAN_BUM_WASH");
	if (Menu::Option("Parking Attendant")) allpedscenario("WORLD_HUMAN_CAR_PARK_ATTENDANT");
	if (Menu::Option("Cheering")) allpedscenario("WORLD_HUMAN_CHEERING");
	if (Menu::Option("Clipboard")) allpedscenario("WORLD_HUMAN_CLIPBOARD");
	if (Menu::Option("Clipboard Facility")) allpedscenario("WORLD_HUMAN_CLIPBOARD_FACILITY");
	if (Menu::Option("Drill")) allpedscenario("WORLD_HUMAN_CONST_DRILL");
	if (Menu::Option("Police Idle")) allpedscenario("WORLD_HUMAN_COP_IDLES");
	if (Menu::Option("Drinking")) allpedscenario("WORLD_HUMAN_DRINKING");
	if (Menu::Option("Drinking Facility")) allpedscenario("WORLD_HUMAN_DRINKING_FACILITY");
	if (Menu::Option("Drinking Casino")) allpedscenario("WORLD_HUMAN_DRINKING_CASINO_TERRACE");
	if (Menu::Option("Drug Dealer")) allpedscenario("WORLD_HUMAN_DRUG_DEALER");
	if (Menu::Option("Drug Dealer Hard")) allpedscenario("WORLD_HUMAN_DRUG_DEALER_HARD");
	if (Menu::Option("Drug Worker Rake")) allpedscenario("WORLD_HUMAN_DRUG_FIELD_WORKERS_RAKE");
	if (Menu::Option("Drug Worker Weeding")) allpedscenario("WORLD_HUMAN_DRUG_FIELD_WORKERS_WEEDING");
	if (Menu::Option("Drug Process Coke")) allpedscenario("WORLD_HUMAN_DRUG_PROCESSORS_COKE");
	if (Menu::Option("Drug Process Weed")) allpedscenario("WORLD_HUMAN_DRUG_PROCESSORS_WEED");
	if (Menu::Option("Film Shocking")) allpedscenario("WORLD_HUMAN_MOBILE_FILM_SHOCKING");
	if (Menu::Option("Leaf Blower")) allpedscenario("WORLD_HUMAN_GARDENER_LEAF_BLOWER");
	if (Menu::Option("Gardening")) allpedscenario("WORLD_HUMAN_GARDENER_PLANT");
	if (Menu::Option("Golf")) allpedscenario("WORLD_HUMAN_GOLF_PLAYER");
	if (Menu::Option("Guard Patrol")) allpedscenario("WORLD_HUMAN_GUARD_PATROL");
	if (Menu::Option("Guard Stand")) allpedscenario("WORLD_HUMAN_GUARD_STAND");
	if (Menu::Option("Guard Stand Casino")) allpedscenario("WORLD_HUMAN_GUARD_STAND_CASINO");
	if (Menu::Option("Guard Stand Clubhouse")) allpedscenario("WORLD_HUMAN_GUARD_STAND_CLUBHOUSE");
	if (Menu::Option("Guard Stand Facility")) allpedscenario("WORLD_HUMAN_GUARD_STAND_FACILITY");
	if (Menu::Option("Guard Stand Army")) allpedscenario("WORLD_HUMAN_GUARD_STAND_ARMY");
	if (Menu::Option("Hammering")) allpedscenario("WORLD_HUMAN_HAMMERING");
	if (Menu::Option("Hang Out Street")) allpedscenario("WORLD_HUMAN_HANG_OUT_STREET");
	if (Menu::Option("Hang Out Clubhouse")) allpedscenario("WORLD_HUMAN_HANG_OUT_STREET_CLUBHOUSE");
	if (Menu::Option("Hiker")) allpedscenario("WORLD_HUMAN_HIKER");
	if (Menu::Option("Hiker Standing")) allpedscenario("WORLD_HUMAN_HIKER_STANDING");
	if (Menu::Option("Human Statue")) allpedscenario("WORLD_HUMAN_HUMAN_STATUE");
	if (Menu::Option("Inspect Crouched")) allpedscenario("WORLD_HUMAN_INSPECT_CROUCH");
	if (Menu::Option("Inspect Standing")) allpedscenario("WORLD_HUMAN_INSPECT_STAND");
	if (Menu::Option("Janitor")) allpedscenario("WORLD_HUMAN_JANITOR");
	if (Menu::Option("Joging")) allpedscenario("WORLD_HUMAN_JOG");
	if (Menu::Option("Joging Still")) allpedscenario("WORLD_HUMAN_JOG_STANDING");
	if (Menu::Option("Leaning")) allpedscenario("WORLD_HUMAN_LEANING");
	if (Menu::Option("Leaning Casino")) allpedscenario("WORLD_HUMAN_LEANING_CASINO_TERRACE");
	if (Menu::Option("Cleaning")) allpedscenario("WORLD_HUMAN_MAID_CLEAN");
	if (Menu::Option("Muscle Flex")) allpedscenario("WORLD_HUMAN_MUSCLE_FLEX");
	if (Menu::Option("Muscle free Weight")) allpedscenario("WORLD_HUMAN_MUSCLE_FREE_WEIGHTS");
	if (Menu::Option("Musician")) allpedscenario("WORLD_HUMAN_MUSICIAN");
	if (Menu::Option("Paparazzi")) allpedscenario("WORLD_HUMAN_PAPARAZZI");
	if (Menu::Option("Partying")) allpedscenario("WORLD_HUMAN_PARTYING");
	if (Menu::Option("Picnic")) allpedscenario("WORLD_HUMAN_PICNIC");
	if (Menu::Option("Power Walking")) allpedscenario("WORLD_HUMAN_POWER_WALKER");
	if (Menu::Option("Prostitute High Class")) allpedscenario("WORLD_HUMAN_PROSTITUTE_HIGH_CLASS");
	if (Menu::Option("Prostitute Low Class")) allpedscenario("WORLD_HUMAN_PROSTITUTE_LOW_CLASS");
	if (Menu::Option("Push Ups")) allpedscenario("WORLD_HUMAN_PUSH_UPS");
	if (Menu::Option("Seat Ledge")) allpedscenario("WORLD_HUMAN_SEAT_LEDGE");
	if (Menu::Option("Seat Ledge Eating")) allpedscenario("WORLD_HUMAN_SEAT_LEDGE_EATING");
	if (Menu::Option("Seat Steps")) allpedscenario("WORLD_HUMAN_SEAT_STEPS");
	if (Menu::Option("Seat Wall")) allpedscenario("WORLD_HUMAN_SEAT_WALL");
	if (Menu::Option("Seat Wall Eating")) allpedscenario("WORLD_HUMAN_SEAT_WALL_EATING");
	if (Menu::Option("Seat Wall Table")) allpedscenario("WORLD_HUMAN_SEAT_WALL_TABLET");
	if (Menu::Option("Shine Torch")) allpedscenario("WORLD_HUMAN_SECURITY_SHINE_TORCH");
	if (Menu::Option("Sit Ups")) allpedscenario("WORLD_HUMAN_SIT_UPS");
	if (Menu::Option("Smoking")) allpedscenario("WORLD_HUMAN_SMOKING");
	if (Menu::Option("Smoking Clubhouse")) allpedscenario("WORLD_HUMAN_SMOKING_CLUBHOUSE");
	if (Menu::Option("Smoking Pot")) allpedscenario("WORLD_HUMAN_SMOKING_POT");
	if (Menu::Option("Smoking Pot Clubhouse")) allpedscenario("WORLD_HUMAN_SMOKING_POT_CLUBHOUSE");
	if (Menu::Option("Stand Fire")) allpedscenario("WORLD_HUMAN_STAND_FIRE");
	if (Menu::Option("Stand Fishing")) allpedscenario("WORLD_HUMAN_STAND_FISHING");
	if (Menu::Option("Stand Impatient")) allpedscenario("WORLD_HUMAN_STAND_IMPATIENT");
	if (Menu::Option("Stand Impatient Clubhouse")) allpedscenario("WORLD_HUMAN_STAND_IMPATIENT_CLUBHOUSE");
	if (Menu::Option("Stand Impatient Facility")) allpedscenario("WORLD_HUMAN_STAND_IMPATIENT_FACILITY");
	if (Menu::Option("Stand Impatient Upright")) allpedscenario("WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT");
	if (Menu::Option("Stand Impatient Upright Facility")) allpedscenario("WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT_FACILITY");
	if (Menu::Option("Stand Mobile")) allpedscenario("WORLD_HUMAN_STAND_MOBILE");
	if (Menu::Option("Stand Mobile Clubhouse")) allpedscenario("WORLD_HUMAN_STAND_MOBILE_CLUBHOUSE");
	if (Menu::Option("Stand Mobile Facility")) allpedscenario("WORLD_HUMAN_STAND_MOBILE_FACILITY");
	if (Menu::Option("Stand Mobile Upright")) allpedscenario("WORLD_HUMAN_STAND_MOBILE_UPRIGHT");
	if (Menu::Option("Stand Mobile Upright Clubhouse")) allpedscenario("WORLD_HUMAN_STAND_MOBILE_UPRIGHT_CLUBHOUSE");
	if (Menu::Option("Strip Watch Stand")) allpedscenario("WORLD_HUMAN_STRIP_WATCH_STAND");
	if (Menu::Option("Stupor")) allpedscenario("WORLD_HUMAN_STUPOR");
	if (Menu::Option("Stupor Clubhouse")) allpedscenario("WORLD_HUMAN_STUPOR_CLUBHOUSE");
	if (Menu::Option("Browse Showroom")) allpedscenario("WORLD_HUMAN_WINDOW_SHOP_BROWSE_SHOWROOM");
	if (Menu::Option("Sunbathe")) allpedscenario("WORLD_HUMAN_SUNBATHE");
	if (Menu::Option("SunBathe Back")) allpedscenario("WORLD_HUMAN_SUNBATHE_BACK");
	if (Menu::Option("Super Hero")) allpedscenario("WORLD_HUMAN_SUPERHERO");
	if (Menu::Option("Swiming")) allpedscenario("WORLD_HUMAN_SWIMMING");
	if (Menu::Option("Tenis")) allpedscenario("WORLD_HUMAN_TENNIS_PLAYER");
	if (Menu::Option("Tourist Map")) allpedscenario("WORLD_HUMAN_TOURIST_MAP");
	if (Menu::Option("Tourist Mobile")) allpedscenario("WORLD_HUMAN_TOURIST_MOBILE");
	if (Menu::Option("Valet")) allpedscenario("WORLD_HUMAN_VALET");
	if (Menu::Option("Mechanic")) allpedscenario("WORLD_HUMAN_VEHICLE_MECHANIC");
	if (Menu::Option("Welding")) allpedscenario("WORLD_HUMAN_WELDING");
	if (Menu::Option("Window Shop Browse")) allpedscenario("WORLD_HUMAN_WINDOW_SHOP_BROWSE");
	if (Menu::Option("Yoga")) allpedscenario("WORLD_HUMAN_YOGA");
	if (Menu::Option("Walk")) allpedscenario("Walk");
	if (Menu::Option("Walk Facility")) allpedscenario("Walk_Facility");
	if (Menu::Option("Boar Grazing")) allpedscenario("WORLD_BOAR_GRAZING");
	if (Menu::Option("Cat Sleeping Ground")) allpedscenario("WORLD_CAT_SLEEPING_GROUND");
	if (Menu::Option("Cat Sleeping Ledge")) allpedscenario("WORLD_CAT_SLEEPING_LEDGE");
	if (Menu::Option("Cow Grazing")) allpedscenario("WORLD_COW_GRAZING");
	if (Menu::Option("Coyote Howl")) allpedscenario("WORLD_COYOTE_HOWL");
	if (Menu::Option("Coyote Rest")) allpedscenario("WORLD_COYOTE_REST");
	if (Menu::Option("Coyote Wander")) allpedscenario("WORLD_COYOTE_WANDER");
	if (Menu::Option("Coyote Walk")) allpedscenario("WORLD_COYOTE_WALK");
	if (Menu::Option("ChickenHawk Feeding")) allpedscenario("WORLD_CHICKENHAWK_FEEDING");
	if (Menu::Option("ChickenHawk Standing")) allpedscenario("WORLD_CHICKENHAWK_STANDING");
	if (Menu::Option("Cormorant Standing")) allpedscenario("WORLD_CORMORANT_STANDING");
	if (Menu::Option("Crow Feeding")) allpedscenario("WORLD_CROW_FEEDING");
	if (Menu::Option("Crow Standing")) allpedscenario("WORLD_CROW_STANDING");
	if (Menu::Option("Deer Grazing")) allpedscenario("WORLD_DEER_GRAZING");
	if (Menu::Option("Dog Barking Rottweiler")) allpedscenario("WORLD_DOG_BARKING_ROTTWEILER");
	if (Menu::Option("Dog Golden Retriever")) allpedscenario("WORLD_DOG_BARKING_RETRIEVER");
	if (Menu::Option("Dog German Shepherd")) allpedscenario("WORLD_DOG_BARKING_SHEPHERD");
	if (Menu::Option("Dog Sitting Rottweiler")) allpedscenario("WORLD_DOG_SITTING_ROTTWEILER");
	if (Menu::Option("Dog Sitting Golden Retriever")) allpedscenario("WORLD_DOG_SITTING_RETRIEVER");
	if (Menu::Option("Dog Sitting German Shepherd")) allpedscenario("WORLD_DOG_SITTING_SHEPHERD");
	if (Menu::Option("Dog Barking Small")) allpedscenario("WORLD_DOG_BARKING_SMALL");
	if (Menu::Option("Dog Bitting Small")) allpedscenario("WORLD_DOG_SITTING_SMALL");
	if (Menu::Option("Dolphin Swim")) allpedscenario("WORLD_DOLPHIN_SWIM");
	if (Menu::Option("Fish Flee")) allpedscenario("WORLD_FISH_FLEE");
	if (Menu::Option("Fish Idle")) allpedscenario("WORLD_FISH_IDLE");
	if (Menu::Option("Sea Gull Feeding")) allpedscenario("WORLD_GULL_FEEDING");
	if (Menu::Option("Sea Gull Standing")) allpedscenario("WORLD_GULL_STANDING");
	if (Menu::Option("Hen Flee")) allpedscenario("WORLD_HEN_FLEE");
	if (Menu::Option("Hen Pecking")) allpedscenario("WORLD_HEN_PECKING");
	if (Menu::Option("Hen Standing")) allpedscenario("WORLD_HEN_STANDING");
	if (Menu::Option("Montain Lion Rest")) allpedscenario("WORLD_MOUNTAIN_LION_REST");
	if (Menu::Option("Montain Lion Wander")) allpedscenario("WORLD_MOUNTAIN_LION_WANDER");
	if (Menu::Option("Orca Swim")) allpedscenario("WORLD_ORCA_SWIM");
	if (Menu::Option("Pig Grazing")) allpedscenario("WORLD_PIG_GRAZING");
	if (Menu::Option("Pigeon Feeding")) allpedscenario("WORLD_PIGEON_FEEDING");
	if (Menu::Option("Pigeon Standing")) allpedscenario("WORLD_PIGEON_STANDING");
	if (Menu::Option("Rabbit Eating")) allpedscenario("WORLD_RABBIT_EATING");
	if (Menu::Option("Rabbit Flee")) allpedscenario("WORLD_RABBIT_FLEE");
	if (Menu::Option("Rats Eating")) allpedscenario("WORLD_RATS_EATING");
	if (Menu::Option("Rats Fleeing")) allpedscenario("WORLD_RATS_FLEEING");
	if (Menu::Option("Shark Swim")) allpedscenario("WORLD_SHARK_SWIM");
	if (Menu::Option("Shark Hammerhead Swim")) allpedscenario("WORLD_SHARK_HAMMERHEAD_SWIM");
	if (Menu::Option("Stingray Swim")) allpedscenario("WORLD_STINGRAY_SWIM");
	if (Menu::Option("Whale Swim")) allpedscenario("WORLD_WHALE_SWIM");
	if (Menu::Option("Drive")) allpedscenario("DRIVE");
	if (Menu::Option("Vehicle Attractor")) allpedscenario("WORLD_VEHICLE_ATTRACTOR");
	if (Menu::Option("Park Vehicle")) allpedscenario("PARK_VEHICLE");
	if (Menu::Option("Ambulance")) allpedscenario("WORLD_VEHICLE_AMBULANCE");
	if (Menu::Option("Bmx")) allpedscenario("WORLD_VEHICLE_BICYCLE_BMX");
	if (Menu::Option("Bmx Ballas")) allpedscenario("WORLD_VEHICLE_BICYCLE_BMX_BALLAS");
	if (Menu::Option("Bmx Family")) allpedscenario("WORLD_VEHICLE_BICYCLE_BMX_FAMILY");
	if (Menu::Option("Bmx Harmony")) allpedscenario("WORLD_VEHICLE_BICYCLE_BMX_HARMONY");
	if (Menu::Option("Bmx Vagos")) allpedscenario("WORLD_VEHICLE_BICYCLE_BMX_VAGOS");
	if (Menu::Option("Bicycle Mountain")) allpedscenario("WORLD_VEHICLE_BICYCLE_MOUNTAIN");
	if (Menu::Option("Bicycle Road")) allpedscenario("WORLD_VEHICLE_BICYCLE_ROAD");
	if (Menu::Option("Bike Off Road Race")) allpedscenario("WORLD_VEHICLE_BIKE_OFF_ROAD_RACE");
	if (Menu::Option("Biker")) allpedscenario("WORLD_VEHICLE_BIKER");
	if (Menu::Option("Boat Idle")) allpedscenario("WORLD_VEHICLE_BOAT_IDLE");
	if (Menu::Option("Boat Idle Alamo")) allpedscenario("WORLD_VEHICLE_BOAT_IDLE_ALAMO");
	if (Menu::Option("Boat Idle Marquis")) allpedscenario("WORLD_VEHICLE_BOAT_IDLE_MARQUIS");
	if (Menu::Option("Vehicle Broken Down")) allpedscenario("WORLD_VEHICLE_BROKEN_DOWN");
	if (Menu::Option("Vehicle Bussinessmen")) allpedscenario("WORLD_VEHICLE_BUSINESSMEN");
	if (Menu::Option("Helicopter Lifeguard")) allpedscenario("WORLD_VEHICLE_HELI_LIFEGUARD");
	if (Menu::Option("Clucking Bell Trailer")) allpedscenario("WORLD_VEHICLE_CLUCKIN_BELL_TRAILER");
	if (Menu::Option("Vehicle Construction Solo")) allpedscenario("WORLD_VEHICLE_CONSTRUCTION_SOLO");
	if (Menu::Option("Vehicle Construction Passenger")) allpedscenario("WORLD_VEHICLE_CONSTRUCTION_PASSENGERS");
	if (Menu::Option("Vehicle Drive Passenger")) allpedscenario("WORLD_VEHICLE_DRIVE_PASSENGERS");
	if (Menu::Option("Vehicle Drive Passenger Limited")) allpedscenario("WORLD_VEHICLE_DRIVE_PASSENGERS_LIMITED");
	if (Menu::Option("Vehicle Drive Solo")) allpedscenario("WORLD_VEHICLE_DRIVE_SOLO");
	if (Menu::Option("Vehicle Farm Worker")) allpedscenario("WORLD_VEHICLE_FARM_WORKER");
	if (Menu::Option("Vehicle Firetruck")) allpedscenario("WORLD_VEHICLE_FIRE_TRUCK");
	if (Menu::Option("Vehicle Empty")) allpedscenario("WORLD_VEHICLE_EMPTY");
	if (Menu::Option("Vehicle Mariachi")) allpedscenario("WORLD_VEHICLE_MARIACHI");
	if (Menu::Option("Vehicle Mechanic")) allpedscenario("WORLD_VEHICLE_MECHANIC");
	if (Menu::Option("Military Big Plane")) allpedscenario("WORLD_VEHICLE_MILITARY_PLANES_BIG");
	if (Menu::Option("Military Small Plane")) allpedscenario("WORLD_VEHICLE_MILITARY_PLANES_SMALL");
	if (Menu::Option("Vehicle Park Parallel")) allpedscenario("WORLD_VEHICLE_PARK_PARALLEL");
	if (Menu::Option("Vehicle Park Nose First")) allpedscenario("WORLD_VEHICLE_PARK_PERPENDICULAR_NOSE_IN");
	if (Menu::Option("Vehicle Exit Passenger")) allpedscenario("WORLD_VEHICLE_PASSENGER_EXIT");
	if (Menu::Option("Bike Police")) allpedscenario("WORLD_VEHICLE_POLICE_BIKE");
	if (Menu::Option("Vehicle Police")) allpedscenario("WORLD_VEHICLE_POLICE_CAR");
	if (Menu::Option("Vehicle Police Close By")) allpedscenario("WORLD_VEHICLE_POLICE_NEXT_TO_CAR");
	if (Menu::Option("Vehicle Quarry")) allpedscenario("WORLD_VEHICLE_QUARRY");
	if (Menu::Option("Vehicle Salton")) allpedscenario("WORLD_VEHICLE_SALTON");
	if (Menu::Option("Vehicle Dirtbike")) allpedscenario("WORLD_VEHICLE_SALTON_DIRT_BIKE");
	if (Menu::Option("Vehicle Security")) allpedscenario("WORLD_VEHICLE_SECURITY_CAR");
	if (Menu::Option("Vehicle Street Race")) allpedscenario("WORLD_VEHICLE_STREETRACE");
	if (Menu::Option("Vehicle Tourbus")) allpedscenario("WORLD_VEHICLE_TOURBUS");
	if (Menu::Option("Vehicle Tourist")) allpedscenario("WORLD_VEHICLE_TOURIST");
	if (Menu::Option("TANDL")) allpedscenario("WORLD_VEHICLE_TANDL");
	if (Menu::Option("Tractor")) allpedscenario("WORLD_VEHICLE_TRACTOR");
	if (Menu::Option("Tractor Beach")) allpedscenario("WORLD_VEHICLE_TRACTOR_BEACH");
	if (Menu::Option("Truck Logs")) allpedscenario("WORLD_VEHICLE_TRUCK_LOGS");
	if (Menu::Option("Truck Trailer")) allpedscenario("WORLD_VEHICLE_TRUCKS_TRAILERS");
	if (Menu::Option("Bird In Tree")) allpedscenario("PROP_BIRD_IN_TREE");
	if (Menu::Option("Empty Ground")) allpedscenario("WORLD_VEHICLE_DISTANT_EMPTY_GROUND");
	if (Menu::Option("Telegraph Pole")) allpedscenario("PROP_BIRD_TELEGRAPH_POLE");
	if (Menu::Option("ATM")) allpedscenario("PROP_HUMAN_ATM");
	if (Menu::Option("BBQ")) allpedscenario("PROP_HUMAN_BBQ");
	if (Menu::Option("Bum Bin")) allpedscenario("PROP_HUMAN_BUM_BIN");
	if (Menu::Option("Shoping Cart")) allpedscenario("PROP_HUMAN_BUM_SHOPPING_CART");
	if (Menu::Option("Chin Ups")) allpedscenario("PROP_HUMAN_MUSCLE_CHIN_UPS");
	if (Menu::Option("Chin Ups Army")) allpedscenario("PROP_HUMAN_MUSCLE_CHIN_UPS_ARMY");
	if (Menu::Option("Chin Ups Prison")) allpedscenario("PROP_HUMAN_MUSCLE_CHIN_UPS_PRISON");
	if (Menu::Option("Parking Meter")) allpedscenario("PROP_HUMAN_PARKING_METER");
	if (Menu::Option("Seat Armchair")) allpedscenario("PROP_HUMAN_SEAT_ARMCHAIR");
	if (Menu::Option("Seat Bar")) allpedscenario("PROP_HUMAN_SEAT_BAR");
	if (Menu::Option("Seat Bench")) allpedscenario("PROP_HUMAN_SEAT_BENCH");
	if (Menu::Option("Seat Bench Facility")) allpedscenario("PROP_HUMAN_SEAT_BENCH_FACILITY");
	if (Menu::Option("Seat Bench Drink")) allpedscenario("PROP_HUMAN_SEAT_BENCH_DRINK");
	if (Menu::Option("Seat Bench Drink Facility")) allpedscenario("PROP_HUMAN_SEAT_BENCH_DRINK_FACILITY");
	if (Menu::Option("Seat Bench Beer")) allpedscenario("PROP_HUMAN_SEAT_BENCH_DRINK_BEER");
	if (Menu::Option("Seat Bench Food")) allpedscenario("PROP_HUMAN_SEAT_BENCH_FOOD");
	if (Menu::Option("Seat Bench Food Facility")) allpedscenario("PROP_HUMAN_SEAT_BENCH_FOOD_FACILITY");
	if (Menu::Option("Seat Bus Stop")) allpedscenario("PROP_HUMAN_SEAT_BUS_STOP_WAIT");
	if (Menu::Option("Seat Chair")) allpedscenario("PROP_HUMAN_SEAT_CHAIR");
	if (Menu::Option("Seat Drink")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_DRINK");
	if (Menu::Option("Seat Drink Beer")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_DRINK_BEER");
	if (Menu::Option("Seat Food")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_FOOD");
	if (Menu::Option("Seat Upright")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_UPRIGHT");
	if (Menu::Option("Seat Upright Showroom")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_UPRIGHT_SHOWROOM");
	if (Menu::Option("Seat Multiplayer")) allpedscenario("PROP_HUMAN_SEAT_CHAIR_MP_PLAYER");
	if (Menu::Option("Seat Computer")) allpedscenario("PROP_HUMAN_SEAT_COMPUTER");
	if (Menu::Option("Seat Computer Low")) allpedscenario("PROP_HUMAN_SEAT_COMPUTER_LOW");
	if (Menu::Option("Seat Deckchair")) allpedscenario("PROP_HUMAN_SEAT_DECKCHAIR");
	if (Menu::Option("Seat Deckchair Drink")) allpedscenario("PROP_HUMAN_SEAT_DECKCHAIR_DRINK");
	if (Menu::Option("Bench")) allpedscenario("PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS");
	if (Menu::Option("Bench Prison")) allpedscenario("PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS_PRISON");
	if (Menu::Option("Seat Sewing")) allpedscenario("PROP_HUMAN_SEAT_SEWING");
	if (Menu::Option("Seat Strip Watch")) allpedscenario("PROP_HUMAN_SEAT_STRIP_WATCH");
	if (Menu::Option("Seat Lounger")) allpedscenario("PROP_HUMAN_SEAT_SUNLOUNGER");
	if (Menu::Option("Stand Impatient")) allpedscenario("PROP_HUMAN_STAND_IMPATIENT");
	if (Menu::Option("Cower")) allpedscenario("CODE_HUMAN_COWER");
	if (Menu::Option("Cross Road Wait")) allpedscenario("CODE_HUMAN_CROSS_ROAD_WAIT");
	if (Menu::Option("Park Car")) allpedscenario("CODE_HUMAN_PARK_CAR");
	if (Menu::Option("Movie Bulb")) allpedscenario("PROP_HUMAN_MOVIE_BULB");
	if (Menu::Option("Studio Light")) allpedscenario("PROP_HUMAN_MOVIE_STUDIO_LIGHT");
	if (Menu::Option("Medic Kneel")) allpedscenario("CODE_HUMAN_MEDIC_KNEEL");
	if (Menu::Option("Medic Tend To Dead")) allpedscenario("CODE_HUMAN_MEDIC_TEND_TO_DEAD");
	if (Menu::Option("Medic Time Of Death")) allpedscenario("CODE_HUMAN_MEDIC_TIME_OF_DEATH");
	if (Menu::Option("Police Crowd Control")) allpedscenario("CODE_HUMAN_POLICE_CROWD_CONTROL");
	if (Menu::Option("Police Investigate")) allpedscenario("CODE_HUMAN_POLICE_INVESTIGATE");
	if (Menu::Option("Chaining Entry")) allpedscenario("CHAINING_ENTRY");
	if (Menu::Option("Chaining Exit")) allpedscenario("CHAINING_EXIT");
	if (Menu::Option("Stand Cower")) allpedscenario("CODE_HUMAN_STAND_COWER");
	if (Menu::Option("Texting")) allpedscenario("EAR_TO_TEXT");
	if (Menu::Option("Texting Fat")) allpedscenario("EAR_TO_TEXT_FAT");
	if (Menu::Option("Looking")) allpedscenario("WORLD_LOOKAT_POINT");

}

void Local::Scen()
{
	Menu::Title("");
	Menu::SubTitle("Scenarios");
	if (Menu::Option("Reset")) AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPedId);
	if (Menu::Option("Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "STANDING", 0, true);
	if (Menu::Option("Coffee")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_AA_COFFEE", 0, true);
	if (Menu::Option("Smoking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_AA_SMOKE", 0, true);
	if (Menu::Option("Binocular")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_BINOCULARS", 0, true);
	if (Menu::Option("Bum Freeway")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_BUM_FREEWAY", 0, true);
	if (Menu::Option("Bum Slumped")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_BUM_SLUMPED", 0, true);
	if (Menu::Option("Bum Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_BUM_STANDING", 0, true);
	if (Menu::Option("Bum Wash")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_BUM_WASH", 0, true);
	if (Menu::Option("Parking Attendant")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_CAR_PARK_ATTENDANT", 0, true);
	if (Menu::Option("Cheering")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_CHEERING", 0, true);
	if (Menu::Option("Clipboard")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_CLIPBOARD", 0, true);
	if (Menu::Option("Clipboard Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_CLIPBOARD_FACILITY", 0, true);
	if (Menu::Option("Drill")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_CONST_DRILL", 0, true);
	if (Menu::Option("Police Idle")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_COP_IDLES", 0, true);
	if (Menu::Option("Drinking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRINKING", 0, true);
	if (Menu::Option("Drinking Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRINKING_FACILITY", 0, true);
	if (Menu::Option("Drinking Casino")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRINKING_CASINO_TERRACE", 0, true);
	if (Menu::Option("Drug Dealer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_DEALER", 0, true);
	if (Menu::Option("Drug Dealer Hard")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
	if (Menu::Option("Drug Worker Rake")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_FIELD_WORKERS_RAKE", 0, true);
	if (Menu::Option("Drug Worker Weeding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_FIELD_WORKERS_WEEDING", 0, true);
	if (Menu::Option("Drug Process Coke")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_PROCESSORS_COKE", 0, true);
	if (Menu::Option("Drug Process Weed")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_DRUG_PROCESSORS_WEED", 0, true);
	if (Menu::Option("Film Shocking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
	if (Menu::Option("Leaf Blower")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
	if (Menu::Option("Gardening")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GARDENER_PLANT", 0, true);
	if (Menu::Option("Golf")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GOLF_PLAYER", 0, true);
	if (Menu::Option("Guard Patrol")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_PATROL", 0, true);
	if (Menu::Option("Guard Stand")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_STAND", 0, true);
	if (Menu::Option("Guard Stand Casino")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_STAND_CASINO", 0, true);
	if (Menu::Option("Guard Stand Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_STAND_CLUBHOUSE", 0, true);
	if (Menu::Option("Guard Stand Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_STAND_FACILITY", 0, true);
	if (Menu::Option("Guard Stand Army")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_GUARD_STAND_ARMY", 0, true);
	if (Menu::Option("Hammering")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HAMMERING", 0, true);
	if (Menu::Option("Hang Out Street")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HANG_OUT_STREET", 0, true);
	if (Menu::Option("Hang Out Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HANG_OUT_STREET_CLUBHOUSE", 0, true);
	if (Menu::Option("Hiker")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HIKER", 0, true);
	if (Menu::Option("Hiker Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HIKER_STANDING", 0, true);
	if (Menu::Option("Human Statue")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_HUMAN_STATUE", 0, true);
	if (Menu::Option("Inspect Crouched")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_INSPECT_CROUCH", 0, true);
	if (Menu::Option("Inspect Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_INSPECT_STAND", 0, true);
	if (Menu::Option("Janitor")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_JANITOR", 0, true);
	if (Menu::Option("Joging")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_JOG", 0, true);
	if (Menu::Option("Joging Still")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_JOG_STANDING", 0, true);
	if (Menu::Option("Leaning")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_LEANING", 0, true);
	if (Menu::Option("Leaning Casino")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_LEANING_CASINO_TERRACE", 0, true);
	if (Menu::Option("Cleaning")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_MAID_CLEAN", 0, true);
	if (Menu::Option("Muscle Flex")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
	if (Menu::Option("Muscle free Weight")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS", 0, true);
	if (Menu::Option("Musician")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_MUSICIAN", 0, true);
	if (Menu::Option("Paparazzi")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PAPARAZZI", 0, true);
	if (Menu::Option("Partying")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PARTYING", 0, true);
	if (Menu::Option("Picnic")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PICNIC", 0, true);
	if (Menu::Option("Power Walking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_POWER_WALKER", 0, true);
	if (Menu::Option("Prostitute High Class")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PROSTITUTE_HIGH_CLASS", 0, true);
	if (Menu::Option("Prostitute Low Class")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PROSTITUTE_LOW_CLASS", 0, true);
	if (Menu::Option("Push Ups")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_PUSH_UPS", 0, true);
	if (Menu::Option("Seat Ledge")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_LEDGE", 0, true);
	if (Menu::Option("Seat Ledge Eating")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_LEDGE_EATING", 0, true);
	if (Menu::Option("Seat Steps")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_STEPS", 0, true);
	if (Menu::Option("Seat Wall")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_WALL", 0, true);
	if (Menu::Option("Seat Wall Eating")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_WALL_EATING", 0, true);
	if (Menu::Option("Seat Wall Table")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SEAT_WALL_TABLET", 0, true);
	if (Menu::Option("Shine Torch")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
	if (Menu::Option("Sit Ups")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SIT_UPS", 0, true);
	if (Menu::Option("Smoking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SMOKING", 0, true);
	if (Menu::Option("Smoking Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SMOKING_CLUBHOUSE", 0, true);
	if (Menu::Option("Smoking Pot")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SMOKING_POT", 0, true);
	if (Menu::Option("Smoking Pot Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SMOKING_POT_CLUBHOUSE", 0, true);
	if (Menu::Option("Stand Fire")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_FIRE", 0, true);
	if (Menu::Option("Stand Fishing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_FISHING", 0, true);
	if (Menu::Option("Stand Impatient")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_IMPATIENT", 0, true);
	if (Menu::Option("Stand Impatient Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_IMPATIENT_CLUBHOUSE", 0, true);
	if (Menu::Option("Stand Impatient Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_IMPATIENT_FACILITY", 0, true);
	if (Menu::Option("Stand Impatient Upright")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT", 0, true);
	if (Menu::Option("Stand Impatient Upright Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT_FACILITY", 0, true);
	if (Menu::Option("Stand Mobile")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_MOBILE", 0, true);
	if (Menu::Option("Stand Mobile Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_MOBILE_CLUBHOUSE", 0, true);
	if (Menu::Option("Stand Mobile Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_MOBILE_FACILITY", 0, true);
	if (Menu::Option("Stand Mobile Upright")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_MOBILE_UPRIGHT", 0, true);
	if (Menu::Option("Stand Mobile Upright Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STAND_MOBILE_UPRIGHT_CLUBHOUSE", 0, true);
	if (Menu::Option("Strip Watch Stand")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STRIP_WATCH_STAND", 0, true);
	if (Menu::Option("Stupor")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STUPOR", 0, true);
	if (Menu::Option("Stupor Clubhouse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_STUPOR_CLUBHOUSE", 0, true);
	if (Menu::Option("Browse Showroom")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_WINDOW_SHOP_BROWSE_SHOWROOM", 0, true);
	if (Menu::Option("Sunbathe")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SUNBATHE", 0, true);
	if (Menu::Option("SunBathe Back")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SUNBATHE_BACK", 0, true);
	if (Menu::Option("Super Hero")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SUPERHERO", 0, true);
	if (Menu::Option("Swiming")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_SWIMMING", 0, true);
	if (Menu::Option("Tenis")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
	if (Menu::Option("Tourist Map")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_TOURIST_MAP", 0, true);
	if (Menu::Option("Tourist Mobile")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_TOURIST_MOBILE", 0, true);
	if (Menu::Option("Valet")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_VALET", 0, true);
	if (Menu::Option("Mechanic")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_VEHICLE_MECHANIC", 0, true);
	if (Menu::Option("Welding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_WELDING", 0, true);
	if (Menu::Option("Window Shop Browse")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_WINDOW_SHOP_BROWSE", 0, true);
	if (Menu::Option("Yoga")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HUMAN_YOGA", 0, true);
	if (Menu::Option("Walk")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "Walk", 0, true);
	if (Menu::Option("Walk Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "Walk_Facility", 0, true);
	if (Menu::Option("Boar Grazing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_BOAR_GRAZING", 0, true);
	if (Menu::Option("Cat Sleeping Ground")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CAT_SLEEPING_GROUND", 0, true);
	if (Menu::Option("Cat Sleeping Ledge")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CAT_SLEEPING_LEDGE", 0, true);
	if (Menu::Option("Cow Grazing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_COW_GRAZING", 0, true);
	if (Menu::Option("Coyote Howl")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_COYOTE_HOWL", 0, true);
	if (Menu::Option("Coyote Rest")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_COYOTE_REST", 0, true);
	if (Menu::Option("Coyote Wander")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_COYOTE_WANDER", 0, true);
	if (Menu::Option("Coyote Walk")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_COYOTE_WALK", 0, true);
	if (Menu::Option("ChickenHawk Feeding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CHICKENHAWK_FEEDING", 0, true);
	if (Menu::Option("ChickenHawk Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CHICKENHAWK_STANDING", 0, true);
	if (Menu::Option("Cormorant Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CORMORANT_STANDING", 0, true);
	if (Menu::Option("Crow Feeding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CROW_FEEDING", 0, true);
	if (Menu::Option("Crow Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_CROW_STANDING", 0, true);
	if (Menu::Option("Deer Grazing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DEER_GRAZING", 0, true);
	if (Menu::Option("Dog Barking Rottweiler")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_BARKING_ROTTWEILER", 0, true);
	if (Menu::Option("Dog Golden Retriever")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_BARKING_RETRIEVER", 0, true);
	if (Menu::Option("Dog German Shepherd")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_BARKING_SHEPHERD", 0, true);
	if (Menu::Option("Dog Sitting Rottweiler")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_SITTING_ROTTWEILER", 0, true);
	if (Menu::Option("Dog Sitting Golden Retriever")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_SITTING_RETRIEVER", 0, true);
	if (Menu::Option("Dog Sitting German Shepherd")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_SITTING_SHEPHERD", 0, true);
	if (Menu::Option("Dog Barking Small")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_BARKING_SMALL", 0, true);
	if (Menu::Option("Dog Bitting Small")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOG_SITTING_SMALL", 0, true);
	if (Menu::Option("Dolphin Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_DOLPHIN_SWIM", 0, true);
	if (Menu::Option("Fish Flee")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_FISH_FLEE", 0, true);
	if (Menu::Option("Fish Idle")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_FISH_IDLE", 0, true);
	if (Menu::Option("Sea Gull Feeding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_GULL_FEEDING", 0, true);
	if (Menu::Option("Sea Gull Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_GULL_STANDING", 0, true);
	if (Menu::Option("Hen Flee")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HEN_FLEE", 0, true);
	if (Menu::Option("Hen Pecking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HEN_PECKING", 0, true);
	if (Menu::Option("Hen Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_HEN_STANDING", 0, true);
	if (Menu::Option("Montain Lion Rest")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_MOUNTAIN_LION_REST", 0, true);
	if (Menu::Option("Montain Lion Wander")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_MOUNTAIN_LION_WANDER", 0, true);
	if (Menu::Option("Orca Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_ORCA_SWIM", 0, true);
	if (Menu::Option("Pig Grazing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_PIG_GRAZING", 0, true);
	if (Menu::Option("Pigeon Feeding")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_PIGEON_FEEDING", 0, true);
	if (Menu::Option("Pigeon Standing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_PIGEON_STANDING", 0, true);
	if (Menu::Option("Rabbit Eating")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_RABBIT_EATING", 0, true);
	if (Menu::Option("Rabbit Flee")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_RABBIT_FLEE", 0, true);
	if (Menu::Option("Rats Eating")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_RATS_EATING", 0, true);
	if (Menu::Option("Rats Fleeing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_RATS_FLEEING", 0, true);
	if (Menu::Option("Shark Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_SHARK_SWIM", 0, true);
	if (Menu::Option("Shark Hammerhead Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_SHARK_HAMMERHEAD_SWIM", 0, true);
	if (Menu::Option("Stingray Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_STINGRAY_SWIM", 0, true);
	if (Menu::Option("Whale Swim")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_WHALE_SWIM", 0, true);
	if (Menu::Option("Drive")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "DRIVE", 0, true);
	if (Menu::Option("Vehicle Attractor")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_ATTRACTOR", 0, true);
	if (Menu::Option("Park Vehicle")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PARK_VEHICLE", 0, true);
	if (Menu::Option("Ambulance")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_AMBULANCE", 0, true);
	if (Menu::Option("Bmx")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_BMX", 0, true);
	if (Menu::Option("Bmx Ballas")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_BMX_BALLAS", 0, true);
	if (Menu::Option("Bmx Family")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_BMX_FAMILY", 0, true);
	if (Menu::Option("Bmx Harmony")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_BMX_HARMONY", 0, true);
	if (Menu::Option("Bmx Vagos")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_BMX_VAGOS", 0, true);
	if (Menu::Option("Bicycle Mountain")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_MOUNTAIN", 0, true);
	if (Menu::Option("Bicycle Road")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BICYCLE_ROAD", 0, true);
	if (Menu::Option("Bike Off Road Race")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BIKE_OFF_ROAD_RACE", 0, true);
	if (Menu::Option("Biker")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BIKER", 0, true);
	if (Menu::Option("Boat Idle")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BOAT_IDLE", 0, true);
	if (Menu::Option("Boat Idle Alamo")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BOAT_IDLE_ALAMO", 0, true);
	if (Menu::Option("Boat Idle Marquis")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BOAT_IDLE_MARQUIS", 0, true);
	if (Menu::Option("Vehicle Broken Down")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BROKEN_DOWN", 0, true);
	if (Menu::Option("Vehicle Bussinessmen")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_BUSINESSMEN", 0, true);
	if (Menu::Option("Helicopter Lifeguard")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_HELI_LIFEGUARD", 0, true);
	if (Menu::Option("Clucking Bell Trailer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_CLUCKIN_BELL_TRAILER", 0, true);
	if (Menu::Option("Vehicle Construction Solo")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_CONSTRUCTION_SOLO", 0, true);
	if (Menu::Option("Vehicle Construction Passenger")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_CONSTRUCTION_PASSENGERS", 0, true);
	if (Menu::Option("Vehicle Drive Passenger")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_DRIVE_PASSENGERS", 0, true);
	if (Menu::Option("Vehicle Drive Passenger Limited")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_DRIVE_PASSENGERS_LIMITED", 0, true);
	if (Menu::Option("Vehicle Drive Solo")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_DRIVE_SOLO", 0, true);
	if (Menu::Option("Vehicle Farm Worker")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_FARM_WORKER", 0, true);
	if (Menu::Option("Vehicle Firetruck")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_FIRE_TRUCK", 0, true);
	if (Menu::Option("Vehicle Empty")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_EMPTY", 0, true);
	if (Menu::Option("Vehicle Mariachi")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_MARIACHI", 0, true);
	if (Menu::Option("Vehicle Mechanic")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_MECHANIC", 0, true);
	if (Menu::Option("Military Big Plane")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_MILITARY_PLANES_BIG", 0, true);
	if (Menu::Option("Military Small Plane")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_MILITARY_PLANES_SMALL", 0, true);
	if (Menu::Option("Vehicle Park Parallel")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_PARK_PARALLEL", 0, true);
	if (Menu::Option("Vehicle Park Nose First")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_PARK_PERPENDICULAR_NOSE_IN", 0, true);
	if (Menu::Option("Vehicle Exit Passenger")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_PASSENGER_EXIT", 0, true);
	if (Menu::Option("Bike Police")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_POLICE_BIKE", 0, true);
	if (Menu::Option("Vehicle Police")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_POLICE_CAR", 0, true);
	if (Menu::Option("Vehicle Police Close By")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_POLICE_NEXT_TO_CAR", 0, true);
	if (Menu::Option("Vehicle Quarry")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_QUARRY", 0, true);
	if (Menu::Option("Vehicle Salton")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_SALTON", 0, true);
	if (Menu::Option("Vehicle Dirtbike")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_SALTON_DIRT_BIKE", 0, true);
	if (Menu::Option("Vehicle Security")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_SECURITY_CAR", 0, true);
	if (Menu::Option("Vehicle Street Race")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_STREETRACE", 0, true);
	if (Menu::Option("Vehicle Tourbus")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TOURBUS", 0, true);
	if (Menu::Option("Vehicle Tourist")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TOURIST", 0, true);
	if (Menu::Option("TANDL")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TANDL", 0, true);
	if (Menu::Option("Tractor")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TRACTOR", 0, true);
	if (Menu::Option("Tractor Beach")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TRACTOR_BEACH", 0, true);
	if (Menu::Option("Truck Logs")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TRUCK_LOGS", 0, true);
	if (Menu::Option("Truck Trailer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_TRUCKS_TRAILERS", 0, true);
	if (Menu::Option("Bird In Tree")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_BIRD_IN_TREE", 0, true);
	if (Menu::Option("Empty Ground")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_VEHICLE_DISTANT_EMPTY_GROUND", 0, true);
	if (Menu::Option("Telegraph Pole")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_BIRD_TELEGRAPH_POLE", 0, true);
	if (Menu::Option("ATM")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_ATM", 0, true);
	if (Menu::Option("BBQ")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_BBQ", 0, true);
	if (Menu::Option("Bum Bin")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_BUM_BIN", 0, true);
	if (Menu::Option("Shoping Cart")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_BUM_SHOPPING_CART", 0, true);
	if (Menu::Option("Chin Ups")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
	if (Menu::Option("Chin Ups Army")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_MUSCLE_CHIN_UPS_ARMY", 0, true);
	if (Menu::Option("Chin Ups Prison")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_MUSCLE_CHIN_UPS_PRISON", 0, true);
	if (Menu::Option("Parking Meter")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_PARKING_METER", 0, true);
	if (Menu::Option("Seat Armchair")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_ARMCHAIR", 0, true);
	if (Menu::Option("Seat Bar")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BAR", 0, true);
	if (Menu::Option("Seat Bench")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH", 0, true);
	if (Menu::Option("Seat Bench Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_FACILITY", 0, true);
	if (Menu::Option("Seat Bench Drink")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_DRINK", 0, true);
	if (Menu::Option("Seat Bench Drink Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_DRINK_FACILITY", 0, true);
	if (Menu::Option("Seat Bench Beer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_DRINK_BEER", 0, true);
	if (Menu::Option("Seat Bench Food")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_FOOD", 0, true);
	if (Menu::Option("Seat Bench Food Facility")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BENCH_FOOD_FACILITY", 0, true);
	if (Menu::Option("Seat Bus Stop")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_BUS_STOP_WAIT", 0, true);
	if (Menu::Option("Seat Chair")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR", 0, true);
	if (Menu::Option("Seat Drink")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_DRINK", 0, true);
	if (Menu::Option("Seat Drink Beer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_DRINK_BEER", 0, true);
	if (Menu::Option("Seat Food")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_FOOD", 0, true);
	if (Menu::Option("Seat Upright")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_UPRIGHT", 0, true);
	if (Menu::Option("Seat Upright Showroom")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_UPRIGHT_SHOWROOM", 0, true);
	if (Menu::Option("Seat Multiplayer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_CHAIR_MP_PLAYER", 0, true);
	if (Menu::Option("Seat Computer")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_COMPUTER", 0, true);
	if (Menu::Option("Seat Computer Low")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_COMPUTER_LOW", 0, true);
	if (Menu::Option("Seat Deckchair")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_DECKCHAIR", 0, true);
	if (Menu::Option("Seat Deckchair Drink")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_DECKCHAIR_DRINK", 0, true);
	if (Menu::Option("Bench")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
	if (Menu::Option("Bench Prison")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS_PRISON", 0, true);
	if (Menu::Option("Seat Sewing")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_SEWING", 0, true);
	if (Menu::Option("Seat Strip Watch")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_STRIP_WATCH", 0, true);
	if (Menu::Option("Seat Lounger")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_SEAT_SUNLOUNGER", 0, true);
	if (Menu::Option("Stand Impatient")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_STAND_IMPATIENT", 0, true);
	if (Menu::Option("Cower")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_COWER", 0, true);
	if (Menu::Option("Cross Road Wait")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_CROSS_ROAD_WAIT", 0, true);
	if (Menu::Option("Park Car")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_PARK_CAR", 0, true);
	if (Menu::Option("Movie Bulb")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_MOVIE_BULB", 0, true);
	if (Menu::Option("Studio Light")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "PROP_HUMAN_MOVIE_STUDIO_LIGHT", 0, true);
	if (Menu::Option("Medic Kneel")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_MEDIC_KNEEL", 0, true);
	if (Menu::Option("Medic Tend To Dead")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_MEDIC_TEND_TO_DEAD", 0, true);
	if (Menu::Option("Medic Time Of Death")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_MEDIC_TIME_OF_DEATH", 0, true);
	if (Menu::Option("Police Crowd Control")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_POLICE_CROWD_CONTROL", 0, true);
	if (Menu::Option("Police Investigate")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_POLICE_INVESTIGATE", 0, true);
	if (Menu::Option("Chaining Entry")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CHAINING_ENTRY", 0, true);
	if (Menu::Option("Chaining Exit")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CHAINING_EXIT", 0, true);
	if (Menu::Option("Stand Cower")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "CODE_HUMAN_STAND_COWER", 0, true);
	if (Menu::Option("Texting")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "EAR_TO_TEXT", 0, true);
	if (Menu::Option("Texting Fat")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "EAR_TO_TEXT_FAT", 0, true);
	if (Menu::Option("Looking")) AI::TASK_START_SCENARIO_IN_PLACE(playerPedId, "WORLD_LOOKAT_POINT", 0, true);
}



//Outfit related
int pcolor = 1;
int wheeletype = 1;
int testingfet = 1;
int scolor = 1;
int Glasses_ = 0;
int Ears_ = 0;
int Mask_ = 0;
int Hair_ = 0;
int Torso_ = 0;
int Legs_ = 0;
int Hands_ = 0;
int Shoes_ = 0;
int Watches_ = 0;
int Special1_ = 0;
int Special2_ = 0;
int Special3_ = 0;
int Texture_ = 0;
int Torso2_ = 0;
int selectedOutfit = 0; 
int Local::selectedLocation = 0;
int outfit1 = 0;
int outfit2 = 0;
int outfit3 = 0;
int outfit4 = 0;
int mask1 = 0;
int mask2 = 0;
int shirt1 = 0;
int pants1 = 0;
int hands1 = 0;
int shoes1 = 0;
int eyes1 = 0;
int Accessories1 = 0;
int mission1 = 0;
int decals1 = 0;
int collars1 = 0;

bool FoxyExist()
{
	DWORD dwAttrib = GetFileAttributesA("C:\\Foxy");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool SolOutfitExist()
{
	DWORD dwAttrib = GetFileAttributesA("C:\\Foxy\\Wardrope");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool SolTeleportExist()
{
	DWORD dwAttrib = GetFileAttributesA("C:\\Foxy\\Location");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool Local::SaveLocations = false;
void Local::savelocation(int outfit)
{
	if (!FoxyExist()) {
		CreateDirectoryA("C:\\Foxy\\Location", NULL);
	}
	Ini* settingsIni = new Ini("C:\\Foxy\\Location\\" + to_string(Local::selectedLocation) + ".ini");
	Vector3 position;
	position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	settingsIni->WriteFloat(position.x, "Location", "X");
	settingsIni->WriteFloat(position.y, "Location", "Y");
	settingsIni->WriteFloat(position.z, "Location", "Z");
	delete settingsIni;
}

bool Local::LoadLocations = false;
void Local::loadlocation(int outfit)
{
	Ini* settingsIni = new Ini("C:\\Foxy\\Location\\" + to_string(Local::selectedLocation) + ".ini");
	tpx = settingsIni->GetFloat("Location", "X");
	tpy = settingsIni->GetFloat("Location", "Y");
	tpz = settingsIni->GetFloat("Location", "Z");
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), tpx, tpy, tpz, 0, 0, 0, false);
	delete settingsIni;
}


bool Local::SaveOutfit = false;
void Local::save(int outfit)
{
	if (!FoxyExist()) {
		CreateDirectoryA("C:\\Foxy\\Wardrope", NULL);
	}
	Ini *settingsIni = new Ini("C:\\Foxy\\Wardrope\\" + to_string(selectedOutfit) + ".ini");
	settingsIni->WriteInt(Local::torso, "outfit", "1");
	settingsIni->WriteInt(Local::torsotexture, "outfit", "2");
	settingsIni->WriteInt(Local::face, "outfit", "3");
	settingsIni->WriteInt(Local::facetexture, "outfit", "4");
	settingsIni->WriteInt(Local::head, "outfit", "5");
	settingsIni->WriteInt(Local::headtexture, "outfit", "6");
	settingsIni->WriteInt(Local::hair, "outfit", "7");
	settingsIni->WriteInt(Local::hairtexture, "outfit", "8");
	settingsIni->WriteInt(Local::legs, "outfit", "9");
	settingsIni->WriteInt(Local::legstexture, "outfit", "10");
	settingsIni->WriteInt(Local::hands, "outfit", "11");
	settingsIni->WriteInt(Local::handstexture, "outfit", "12");
	settingsIni->WriteInt(Local::feet, "outfit", "13");
	settingsIni->WriteInt(Local::feettexture, "outfit", "14");
	settingsIni->WriteInt(Local::eyes, "outfit", "15");
	settingsIni->WriteInt(Local::eyestexture, "outfit", "16");
	settingsIni->WriteInt(Local::accesories, "outfit", "17");
	settingsIni->WriteInt(Local::accesoriestexture, "outfit", "18");
	settingsIni->WriteInt(Local::accesoriessec, "outfit", "19");
	settingsIni->WriteInt(Local::accesoriessectexture, "outfit", "20");
	settingsIni->WriteInt(Local::textures, "outfit", "21");
	settingsIni->WriteInt(Local::texturestexture, "outfit", "22");
	settingsIni->WriteInt(Local::torsosec, "outfit", "23");
	settingsIni->WriteInt(Local::torsosectexture, "outfit", "24");
	settingsIni->WriteInt(Local::hats, "outfit", "25");
	settingsIni->WriteInt(Local::hatstexture, "outfit", "26");
	settingsIni->WriteInt(Local::glasses, "outfit", "29");
	settingsIni->WriteInt(Local::glassestexture, "outfit", "30");
	settingsIni->WriteInt(Local::ears, "outfit", "31");
	settingsIni->WriteInt(Local::earstexture, "outfit", "32");
	settingsIni->WriteInt(Local::watches, "outfit", "33");
	settingsIni->WriteInt(Local::watchestexture, "outfit", "34");
	
}

bool Local::LoadOutfit = false;
void Local::load(int outfit)
{
	Ini *settingsIni = new Ini("C:\\Foxy\\Wardrope\\" + to_string(selectedOutfit) + ".ini");
	Local::torso = settingsIni->GetInt("outfit", "1");
	Local::torsotexture = settingsIni->GetInt("outfit", "2");
	Local::face = settingsIni->GetInt("outfit", "3");
	Local::facetexture = settingsIni->GetInt("outfit", "4");
	Local::head = settingsIni->GetInt("outfit", "5");
	Local::headtexture = settingsIni->GetInt("outfit", "6");
	Local::hair = settingsIni->GetInt("outfit", "7");
	Local::hairtexture = settingsIni->GetInt("outfit", "8");
	Local::legs = settingsIni->GetInt("outfit", "9");
	Local::legstexture = settingsIni->GetInt("outfit", "10");
	Local::hands = settingsIni->GetInt("outfit", "11");
	Local::handstexture = settingsIni->GetInt("outfit", "12");
	Local::feet = settingsIni->GetInt("outfit", "13");
	Local::feettexture = settingsIni->GetInt("outfit", "14");
	Local::eyes = settingsIni->GetInt("outfit", "15");
	Local::eyestexture = settingsIni->GetInt("outfit", "16");
	Local::accesories = settingsIni->GetInt("outfit", "17");
	Local::accesoriestexture = settingsIni->GetInt("outfit", "18");
	Local::accesoriessec = settingsIni->GetInt("outfit", "19");
	Local::accesoriessectexture = settingsIni->GetInt("outfit", "20");
	Local::textures = settingsIni->GetInt("outfit", "21");
	Local::texturestexture = settingsIni->GetInt("outfit", "22");
	Local::torsosec = settingsIni->GetInt("outfit", "23");
	Local::torsosectexture = settingsIni->GetInt("outfit", "24");
	Local::hats = settingsIni->GetInt("outfit", "25");
	Local::hatstexture = settingsIni->GetInt("outfit", "26");
	Local::glasses = settingsIni->GetInt("outfit", "29");
	Local::glassestexture = settingsIni->GetInt("outfit", "30");
	Local::ears = settingsIni->GetInt("outfit", "31");
	Local::earstexture = settingsIni->GetInt("outfit", "32");
	Local::watches = settingsIni->GetInt("outfit", "33");
	Local::watchestexture = settingsIni->GetInt("outfit", "34");
	Local::torser();
	Local::torsertexture();
	Local::facer();
	Local::facertexture();
	Local::header();
	Local::headertexture();
	Local::hairer();
	Local::hairertexture();
	Local::legser();
	Local::legsertexture();
	Local::handser();
	Local::handsertexture();
	Local::feeter();
	Local::feetertexture();
	Local::eyeser();
	Local::eyesertexture();
	Local::accesorieser();
	Local::accesoriesertexture();
	Local::accesoriesersec();
	Local::accesoriesersectexture();
	Local::textureser();
	Local::texturesertexture();
	Local::torsersec();
	Local::torsersectexture();
	Local::hatser();
	Local::hatsertexture();
	Local::glasser();
	Local::glassertexture();
	Local::earser();
	Local::earsertexture();
	Local::watcher();
	Local::watchertexture();
	delete settingsIni;
}



bool FoxyFolder()
{
	DWORD dwAttrib = GetFileAttributesA(".\\Foxy");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool RIDFOLDtfitExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\Foxy\\RID");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

#pragma pack(push, 1)
typedef struct
{
	float X, Y, Z, RotX, RotY, RotZ;
	Hash hash;
} RIDinfo;
#pragma pack(pop)


void saverid(std::string RID, std::string Name, bool bWriteVehicle = 0)
{

	char* Namerr = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());

	char* rockstarID;
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
		rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
	}

	if (FoxyFolder()) {
		CreateDirectoryA("C:\\Foxy\\RID", NULL);
	}
	std::string iniPath = "C:\\Foxy\\Ini Vehicles\\" + Name + ".ini";
	
}


void Local::Outfit()
{
	Menu::Title("Wardrope");
	Menu::SubTitle("Wardrope");


	Menu::Int("Outfit Slot", selectedOutfit, 0, 100);
	if (Menu::Option("Load Ini Outfit")) {
		Local::load(selectedOutfit);
	}
	if (Menu::Option("Save Ini Outfit")) {
		Local::save(selectedOutfit);
	}
	if (Menu::Option("ADD Rockstar Logo")) {
		PED::_APPLY_PED_OVERLAY(PLAYER::PLAYER_PED_ID(), -1398869298, -1730534702);

	}
	if (Menu::Int("Face", Local::face, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0), 1)) Local::facer();
	if (Menu::Int("Face Textures", Local::facetexture, 0, 255, 1)) Local::facertexture();
	if (Menu::Int("Mask", Local::head, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 1), 1)) Local::header();
	if (Menu::Int("Mask Color", Local::headtexture, 0, 255, 1)) Local::headertexture();
	if (Menu::Int("Hair", Local::hair, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 2), 1)) Local::hairer();
	if (Menu::Int("Hair Color", Local::hairtexture, 0, 255, 1)) Local::hairertexture();
	if (Menu::Int("Necklace", Local::eyes, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 7), 1)) Local::eyeser();
	if (Menu::Int("Necklace Textures", Local::eyestexture, 0, 255, 1)) Local::eyesertexture();
	if (Menu::Int("Earrings", Local::ears, 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 2), 1)) Local::earser();
	if (Menu::Int("Earrings Textures", Local::earstexture, 0, 255, 1)) Local::earsertexture();
	if (Menu::Int("Glasses", Local::glasses, 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 1), 1)) Local::glasser();
	if (Menu::Int("Glasses Color", Local::glassestexture, 0, 255, 1)) Local::glassertexture();
	if (Menu::Int("Hats", Local::hats, 0, PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 0), 1)) Local::hatser();
	if (Menu::Int("Hats Color", Local::hatstexture, 0, 255, 1)) Local::hatsertexture();
	if (Menu::Int("Gloves", Local::torso, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 3), 1)) Local::torser();
	if (Menu::Int("Gloves Color", Local::torsotexture, 0, 255, 1)) Local::torsertexture();
	if (Menu::Int("T Shirt", Local::torsosec, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 11), 1)) Local::torsersec();
	if (Menu::Int("T Shirt Color", Local::torsosectexture, 0, 255, 1)) Local::torsersectexture();
	if (Menu::Int("Pants", Local::legs, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 4), 1)) Local::legser();
	if (Menu::Int("Pants Color", Local::legstexture, 0, 255, 1)) Local::legsertexture();
	if (Menu::Int("Shoes", Local::feet, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 6), 1)) Local::feeter();
	if (Menu::Int("Shoes Color", Local::feettexture, 0, 255, 1)) Local::feetertexture();
	if (Menu::Int("Bags", Local::hands, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 5), 1)) Local::handser();
	if (Menu::Int("Bags Color", Local::handstexture, 0, 255, 1)) Local::handsertexture();
	if (Menu::Int("Accesories", Local::accesories, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 8), 1)) Local::accesorieser();
	if (Menu::Int("Accesories Textures", Local::accesoriestexture, 0, 255, 1)) Local::accesoriesertexture();
	if (Menu::Int("Ballistic Vest", Local::accesoriessec, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 9), 1)) Local::accesoriesersec();
	if (Menu::Int("Ballistic Vest Color", Local::accesoriessectexture, 0, 255, 1)) Local::accesoriesersectexture();
	if (Menu::Int("Textures", Local::textures, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), 10), 1)) Local::textureser();
	if (Menu::Int("Textures Textures", Local::texturestexture, 0, 255, 1)) Local::texturesertexture();
}

int Local::EffectsChar = 0;
int pedanimint = 0;

int alphaptfx = 0;
int redptfx = 0;
int greenptfx = 0;
int blueptfx = 0;

bool Local::ToggleGlow;
bool Local::Head; 
bool Local::Arm;
bool Local::Arm2;
bool Local::Foot;
bool Local::Foot2;


bool Local::pToggleGlow;
bool Local::pHead;
bool Local::pArm;
bool Local::pArm2;
bool Local::pFoot;
bool Local::pFoot2;



static char* Local::PTFXChar[] = //
{
	 "No Effect", "Alien", "AlienX", "Clown", "Lightning", "Ghost", "Electric", "BankNotes", "Camera Flash", "FireWork", "Bullets Impact", "Boat Explosion", "Water Explosion", "Train Explosion", "Plane Explosion", "FBI Explosion", "Helicopter Explosion", "Light Explosion", "Magical Flowers", "Meth Smoke", "Car Impact", "Tire Smoke", "Burnout", "Starburst FW", "Fountain FW", "Shotburst FW", "Trailburst FW", "Beast","Mask Flames", "Judgement Ash", "Lens Dirt", "Alien Charging", "Alien Impact", "Alien Beam", "Laser", "Bomb Fuse", "Money Rain", "Champagne", "Pour Drinks",
};

char* Local::GlowThing = "";
char* Local::GlowThing3 = "";
char* Local::GlowThing2 = "";

void Local::PTFXCALLBoneless(char* call1, char* call2, char* name, int bone) {
	float fx = Menu::Settings::bulletp;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, PLAYER::PLAYER_PED_ID(), 0.00f, 0.00f, 0.00f,
		0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
	STREAMING::REMOVE_PTFX_ASSET();

}


void Local::PTFXCALLBoneless2(char* call1, char* call2, char* name, int bone) {
	float fx = Menu::Settings::ptfxsize;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);

	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped* peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			
			int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, peds[OffsetID], 0.00f, 0.00f, 0.00f, 0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_COLOUR( redptfx, greenptfx, blueptfx);
			GRAPHICS::SET_PARTICLE_FX_NON_LOOPED_ALPHA(alphaptfx);
			//SET_PARTICLE_FX_NON_LOOPED_ALPHA
		}
	}
	STREAMING::REMOVE_PTFX_ASSET();

}


void Local::ParticleEffects()
{
	Menu::Title("");
	Menu::SubTitle("Glow");
	if (Menu::intchar("Glow", PTFXChar, Local::EffectsChar, 0, 38))
	{
		if (Local::EffectsChar == 0)
		{
			Local::GlowThing = "";
			Local::GlowThing3 = "";
		}
		if (Local::EffectsChar == 1)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_disintegrate";//done
		}
		if (Local::EffectsChar == 2)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_teleport";//done
		}
		if (Local::EffectsChar == 3)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_clown_appears";//done
		}
		if (Local::EffectsChar == 4)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_clown_death";//done
		}
		if (Local::EffectsChar == 5)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_fbi_dd_breach_smoke";
		}
		if (Local::EffectsChar == 6)
		{
			Local::GlowThing = "scr_agencyheistb";
			Local::GlowThing3 = "scr_agency3b_elec_box";
		}
		if (Local::EffectsChar == 7)
		{
			Local::GlowThing = "scr_ornate_heist";
			Local::GlowThing3 = "scr_heist_ornate_banknotes";
		}
		if (Local::EffectsChar == 8)
		{
			Local::GlowThing = "scr_rcpaparazzo1";
			Local::GlowThing3 = "scr_rcpap1_camera";

		}
		if (Local::EffectsChar == 9)
		{
			Local::GlowThing = "proj_xmas_firework";
			Local::GlowThing3 = "scr_firework_xmas_burst_rgw";

		}
		if (Local::EffectsChar == 10)
		{
			Local::GlowThing = "scr_martin1";
			Local::GlowThing3 = "scr_sol1_sniper_impact";

		}
		if (Local::EffectsChar == 11)//
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_ojdg4_boat_exp";

		}
		if (Local::EffectsChar == 12)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_ojdg4_water_exp";

		}
		if (Local::EffectsChar == 13)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_drug_grd_train_exp";

		}
		if (Local::EffectsChar == 14)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_drug_grd_plane_exp";

		}
		if (Local::EffectsChar == 15)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_fbi_exp_building";

		}
		if (Local::EffectsChar == 16)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_agency3b_heli_expl";//

		}
		if (Local::EffectsChar == 17)
		{
			Local::GlowThing = "scr_josh3";
			Local::GlowThing3 = "scr_josh3_light_explosion";

		}
		if (Local::EffectsChar == 18)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_exp_clown";

		}
		if (Local::EffectsChar == 19)
		{
			Local::GlowThing = "scr_familyscenem";
			Local::GlowThing3 = "scr_meth_pipe_smoke";

		}
		if (Local::EffectsChar == 20)
		{
			Local::GlowThing = "scr_exile2";
			Local::GlowThing3 = "scr_ex2_car_impact";

		}
		if (Local::EffectsChar == 21)
		{
			Local::GlowThing = "scr_mp_creator";
			Local::GlowThing3 = "scr_mp_plane_landing_tyre_smoke";

		}
		if (Local::EffectsChar == 22)
		{
			Local::GlowThing = "scr_recartheft";
			Local::GlowThing3 = "scr_wheel_burnout";

		}
		if (Local::EffectsChar == 23)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_starburst";

		}
		if (Local::EffectsChar == 24)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_fountain";

		}
		if (Local::EffectsChar == 25)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_shotburst";

		}
		if (Local::EffectsChar == 26)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_trailburst";

		}
		if (Local::EffectsChar == 27)
		{
			Local::GlowThing = "scr_powerplay";
			Local::GlowThing3 = "scr_powerplay_beast_appear";

		}
		if (Local::EffectsChar == 28)
		{
			Local::GlowThing = "scr_impexp_jug";
			Local::GlowThing3 = "scr_ie_jug_mask_flame";

		}


		if (Local::EffectsChar == 29)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_ash";

		}


		if (Local::EffectsChar == 30)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_lens_dirt";

		}


		if (Local::EffectsChar == 31)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_charging";

		}


		if (Local::EffectsChar == 32)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_impact";

		}


		if (Local::EffectsChar == 33)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_beam";

		}


		if (Local::EffectsChar == 34)
		{
			Local::GlowThing = "scr_ch_finale";
			Local::GlowThing3 = "scr_ch_finale_laser";//

		}


		if (Local::EffectsChar == 35)
		{
			Local::GlowThing = "scr_stunts";
			Local::GlowThing3 = "scr_stunts_bomb_fuse";

		}


		if (Local::EffectsChar == 36)
		{
			Local::GlowThing = "scr_xs_celebration";
			Local::GlowThing3 = "scr_xs_money_rain";

		}


		if (Local::EffectsChar == 37)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_champagne_spray";

		}


		if (Local::EffectsChar == 38)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_drink_pour";

		}

	} 
	Menu::Toggle("Enable", Local::ToggleGlow);
	Menu::Float("Glow Scale", Menu::Settings::bulletp, 0.f, 10.f);
	if (Menu::Option("~f~[ ~w~BodyParts ~f~]"))
	{
	}
	Menu::Toggle("Head", Local::Head);
	Menu::Toggle("Right Hand", Local::Arm);
	Menu::Toggle("Left Hand", Local::Arm2);
	Menu::Toggle("Right Foot", Local::Foot);
	Menu::Toggle("Left Foot", Local::Foot2);

	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Choose Your Particle Effect | Enter To Select");
	}
	if (Menu::Settings::currentOption == 2) {/*Roupa Personalizada*/
		Menu::OptionInfo("Enable Your Particles");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Size Of Particles");
	}
	if (Menu::Settings::currentOption == 4) {
		
	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Particles On Your Head");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Particles On Your Right Hand");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Particles On Your Left Hand");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Particles On Your Right Foot");
	}
	if (Menu::Settings::currentOption == 9) {
		Menu::OptionInfo("Particles On Your Left Foot");
	}
}

void Local::ParticleEffects2()
{
	Menu::Title("");
	Menu::SubTitle("Glow BETA");
	if (Menu::intchar("Glow", PTFXChar, Local::EffectsChar, 0, 38))
	{
		if (Local::EffectsChar == 0)
		{
			Local::GlowThing = "";
			Local::GlowThing3 = "";
		}
		if (Local::EffectsChar == 1)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_disintegrate";//done
		}
		if (Local::EffectsChar == 2)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_teleport";//done
		}
		if (Local::EffectsChar == 3)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_clown_appears";//done
		}
		if (Local::EffectsChar == 4)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_clown_death";//done
		}
		if (Local::EffectsChar == 5)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_fbi_dd_breach_smoke";
		}
		if (Local::EffectsChar == 6)
		{
			Local::GlowThing = "scr_agencyheistb";
			Local::GlowThing3 = "scr_agency3b_elec_box";
		}
		if (Local::EffectsChar == 7)
		{
			Local::GlowThing = "scr_ornate_heist";
			Local::GlowThing3 = "scr_heist_ornate_banknotes";
		}
		if (Local::EffectsChar == 8)
		{
			Local::GlowThing = "scr_rcpaparazzo1";
			Local::GlowThing3 = "scr_rcpap1_camera";

		}
		if (Local::EffectsChar == 9)
		{
			Local::GlowThing = "proj_xmas_firework";
			Local::GlowThing3 = "scr_firework_xmas_burst_rgw";

		}
		if (Local::EffectsChar == 10)
		{
			Local::GlowThing = "scr_martin1";
			Local::GlowThing3 = "scr_sol1_sniper_impact";

		}
		if (Local::EffectsChar == 11)//
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_ojdg4_boat_exp";

		}
		if (Local::EffectsChar == 12)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_ojdg4_water_exp";

		}
		if (Local::EffectsChar == 13)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_drug_grd_train_exp";

		}
		if (Local::EffectsChar == 14)
		{
			Local::GlowThing = "scr_oddjobtraffickingair";
			Local::GlowThing3 = "scr_drug_grd_plane_exp";

		}
		if (Local::EffectsChar == 15)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_fbi_exp_building";

		}
		if (Local::EffectsChar == 16)
		{
			Local::GlowThing = "scr_agencyheist";
			Local::GlowThing3 = "scr_agency3b_heli_expl";//

		}
		if (Local::EffectsChar == 17)
		{
			Local::GlowThing = "scr_josh3";
			Local::GlowThing3 = "scr_josh3_light_explosion";

		}
		if (Local::EffectsChar == 18)
		{
			Local::GlowThing = "scr_rcbarry2";
			Local::GlowThing3 = "scr_exp_clown";

		}
		if (Local::EffectsChar == 19)
		{
			Local::GlowThing = "scr_familyscenem";
			Local::GlowThing3 = "scr_meth_pipe_smoke";

		}
		if (Local::EffectsChar == 20)
		{
			Local::GlowThing = "scr_exile2";
			Local::GlowThing3 = "scr_ex2_car_impact";

		}
		if (Local::EffectsChar == 21)
		{
			Local::GlowThing = "scr_mp_creator";
			Local::GlowThing3 = "scr_mp_plane_landing_tyre_smoke";

		}
		if (Local::EffectsChar == 22)
		{
			Local::GlowThing = "scr_recartheft";
			Local::GlowThing3 = "scr_wheel_burnout";

		}
		if (Local::EffectsChar == 23)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_starburst";

		}
		if (Local::EffectsChar == 24)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_fountain";

		}
		if (Local::EffectsChar == 25)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_shotburst";

		}
		if (Local::EffectsChar == 26)
		{
			Local::GlowThing = "scr_indep_fireworks";
			Local::GlowThing3 = "scr_indep_firework_trailburst";

		}
		if (Local::EffectsChar == 27)
		{
			Local::GlowThing = "scr_powerplay";
			Local::GlowThing3 = "scr_powerplay_beast_appear";

		}
		if (Local::EffectsChar == 28)
		{
			Local::GlowThing = "scr_impexp_jug";
			Local::GlowThing3 = "scr_ie_jug_mask_flame";

		}
		if (Local::EffectsChar == 29)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_ash";

		}
		if (Local::EffectsChar == 30)
		{
			Local::GlowThing = "scr_bike_adversary";
			Local::GlowThing3 = "scr_adversary_judgement_lens_dirt";

		}
		if (Local::EffectsChar == 31)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_charging";

		}
		if (Local::EffectsChar == 32)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_impact";

		}
		if (Local::EffectsChar == 33)
		{
			Local::GlowThing = "scr_rcbarry1";
			Local::GlowThing3 = "scr_alien_beam";

		}
		if (Local::EffectsChar == 34)
		{
			Local::GlowThing = "scr_ch_finale";
			Local::GlowThing3 = "scr_ch_finale_laser";//

		}
		if (Local::EffectsChar == 35)
		{
			Local::GlowThing = "scr_stunts";
			Local::GlowThing3 = "scr_stunts_bomb_fuse";

		}
		if (Local::EffectsChar == 36)
		{
			Local::GlowThing = "scr_xs_celebration";
			Local::GlowThing3 = "scr_xs_money_rain";

		}
		if (Local::EffectsChar == 37)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_champagne_spray";

		}
		if (Local::EffectsChar == 38)
		{
			Local::GlowThing = "scr_ba_club";
			Local::GlowThing3 = "scr_ba_club_drink_pour";

		}
	}
	Menu::Toggle("Enable", Local::pToggleGlow);
	Menu::Float("Glow Scale", Menu::Settings::ptfxsize, 0.f, 10.f);
	if (Menu::Option("~f~[ ~w~BodyParts ~f~]")){}
	Menu::Toggle("Head", Local::pHead);
	Menu::Toggle("Right Hand", Local::pArm);
	Menu::Toggle("Left Hand", Local::pArm2);
	Menu::Toggle("Right Foot", Local::pFoot);
	Menu::Toggle("Left Foot", Local::pFoot2);
	if (Menu::Option("~f~[ ~w~Glow Settings ~f~]")) {}
	Menu::Int("Red", redptfx, 0, 255);
	Menu::Int("Green", greenptfx, 0, 255);
	Menu::Int("Blue", blueptfx, 0, 255);
	Menu::Int("Alpha", alphaptfx, 0, 255);

	if (Menu::Settings::currentOption == 1) {
		Menu::OptionInfo("Choose Peds Particle Effect | Enter To Select");
	}
	if (Menu::Settings::currentOption == 2) {/*Roupa Personalizada*/
		Menu::OptionInfo("Enable Peds Particles");
	}
	if (Menu::Settings::currentOption == 3) {
		Menu::OptionInfo("Size Of Particles");
	}
	if (Menu::Settings::currentOption == 4) {

	}
	if (Menu::Settings::currentOption == 5) {
		Menu::OptionInfo("Particles On Peds Head");
	}
	if (Menu::Settings::currentOption == 6) {
		Menu::OptionInfo("Particles On Peds Right Hand");
	}
	if (Menu::Settings::currentOption == 7) {
		Menu::OptionInfo("Particles On Peds Left Hand");
	}
	if (Menu::Settings::currentOption == 8) {
		Menu::OptionInfo("Particles On Peds Right Foot");
	}
	if (Menu::Settings::currentOption == 9) {
		Menu::OptionInfo("Particles On Peds Left Foot");
	}
}


bool Local::GODOFRAIN = false;
void Local::godofrain(bool toggle) {
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;  //Start at index 2, and the odd elements are padding
	int vehs[arrSize];
	char* dict = "ragdoll@human"; //"ragdoll@human", "electrocute");
	char* anim = "electrocute";
	char* dict1 = "rcmcollect_paperleadinout@"; //"rcmcollect_paperleadinout@", "meditiate_idle")
	char* anim1 = "meditiate_idle";
	//0 index is the size of the array
	vehs[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
	notifyBottom("Press Shift/RB Kill Everyone Around, Press X/LB Push Vehicles Away, Press V/LT Online Weather");

	if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptRB)) {
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
			Player playerPed = PLAYER::PLAYER_PED_ID();
			Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
			FIRE::ADD_EXPLOSION(pCoords.x + 1, pCoords.y + 1, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x + 1, pCoords.y + 2, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x + 0, pCoords.y + 1, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x + 0, pCoords.y + 2, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x - 0, pCoords.y - 2, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x - 0, pCoords.y - 1, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x - 1, pCoords.y - 2, pCoords.z, 7, 90.0f, false, true, 0.0f);
			FIRE::ADD_EXPLOSION(pCoords.x - 1, pCoords.y - 1, pCoords.z, 7, 90.0f, false, true, 0.0f);

	}
	

	if (GetAsyncKeyState(0x58) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptLB)) {
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		for (int i = 0; i < count; ++i)
		{
			int offsettedID = i * 2 + 2;
			if (ENTITY::DOES_ENTITY_EXIST(vehs[offsettedID]))
			{
				if ((vehs[offsettedID]) == PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0)) continue;
				{
					if (VEHICLE::GET_VEHICLE_ENGINE_HEALTH(vehs[offsettedID]) > 1)
					{
						RequestControlOfEnt(vehs[offsettedID]);
						VEHICLE::START_VEHICLE_HORN(vehs[offsettedID], 5000, AUDIO::_GET_VEHICLE_HORN_HASH(vehs[offsettedID]), true);
						ENTITY::APPLY_FORCE_TO_ENTITY(vehs[offsettedID], 1, 0, 0, 9, 0, 0, 0, 1, false, true, true, true, true);
					}
				}
			}
		}
	}


	if (GetAsyncKeyState(0x42) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptRT)) {
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		Player playerPed = PLAYER::PLAYER_PED_ID();
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		FIRE::ADD_EXPLOSION(pCoords.x + 2, pCoords.y + 2, pCoords.z, 13, 5.f, true, false, 0.f);//
		FIRE::ADD_EXPLOSION(pCoords.x + 3, pCoords.y + 3, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x + 4, pCoords.y + 4, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x + 5, pCoords.y + 5, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x + 6, pCoords.y + 6, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x + 7, pCoords.y + 7, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 2, pCoords.y - 2, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 3, pCoords.y - 3, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 4, pCoords.y - 4, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 5, pCoords.y - 5, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 6, pCoords.y - 6, pCoords.z, 13, 5.f, true, false, 0.f);
		FIRE::ADD_EXPLOSION(pCoords.x - 7, pCoords.y - 7, pCoords.z, 13, 5.f, true, false, 0.f);
	}








	if (GetAsyncKeyState(0x56) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlScriptLT)) {
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), dict1, anim1, 1, 1, -1, 16, 0, false, 0, false);
		
		WAIT(10000);
	
	}
}


int Local::torso = 0;
void Local::torser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, Local::torso, 0, 0);
}

int Local::torsotexture = 0;
void Local::torsertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, Local::torso, Local::torsotexture, 0);
}
//face
int Local::face = 0;
void Local::facer()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, Local::face, 0, 0);
}

int Local::facetexture = 0;
void Local::facertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, Local::face, Local::facetexture, 0);
}
//head
int Local::head = 0;
void Local::header()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, Local::head, 0, 0);
}

int Local::headtexture = 0;
void Local::headertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, Local::head, Local::headtexture, 0);
}
//hair
int Local::hair = 0;
void Local::hairer()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, Local::hair, 0, 0);
}

int Local::hairtexture = 0;
void Local::hairertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, Local::hair, Local::hairtexture, 0);
}
//legs
int Local::legs = 0;
void Local::legser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, Local::legs, 0, 0);
}

int Local::legstexture = 0;
void Local::legsertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, Local::legs, Local::legstexture, 0);
}
//hands
int Local::hands = 0;
void Local::handser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, Local::hands, 0, 0);
}

int Local::handstexture = 0;
void Local::handsertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, Local::hands, Local::handstexture, 0);
}
//feet
int Local::feet = 0;
void Local::feeter()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, Local::feet, 0, 0);
}

int Local::feettexture = 0;
void Local::feetertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, Local::feet, Local::feettexture, 0);
}
//eyes
int Local::eyes = 0;
void Local::eyeser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 7, Local::eyes, 0, 0);
}

int Local::eyestexture = 0;
void Local::eyesertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 7, Local::eyes, Local::eyestexture, 0);
}
//accesories
int Local::accesories = 0;
void Local::accesorieser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Local::accesories, 0, 0);
}

int Local::accesoriestexture = 0;
void Local::accesoriesertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Local::accesories, Local::accesoriestexture, 0);
}
//accesories2
int Local::accesoriessec = 0;
void Local::accesoriesersec()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, Local::accesoriessec, 0, 0);
}

int Local::accesoriessectexture = 0;
void Local::accesoriesersectexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, Local::accesoriessec, Local::accesoriessectexture, 0);
}
//textures
int Local::textures = 0;
void Local::textureser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, Local::textures, 0, 0);
}

int Local::texturestexture = 0;
void Local::texturesertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, Local::textures, Local::texturestexture, 0);
}
//torso2
int Local::torsosec = 0;
void Local::torsersec()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, Local::torsosec, 0, 0);
}

int Local::torsosectexture = 0;
void Local::torsersectexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, Local::torsosec, Local::torsosectexture, 0);
}
//hats
int Local::hats = 0;
void Local::hatser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 0, Local::hats, 0, 0);
}

int Local::hatstexture = 0;
void Local::hatsertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 0, Local::hats, Local::hatstexture, 0);
}
//glasses
int Local::glasses = 0;
void Local::glasser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 1, Local::glasses, 0, 0);
}

int Local::glassestexture = 0;
void Local::glassertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 1, Local::glasses, Local::glassestexture, 0);
}
//Ears
int Local::ears = 0;
void Local::earser()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 2, Local::ears, 0, 0);
}

int Local::earstexture = 0;
void Local::earsertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 2, Local::ears, Local::earstexture, 0);
}
//Watches
int Local::watches = 0;
void Local::watcher()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 3, Local::watches, 0, 0);
}

int Local::watchestexture = 0;
void Local::watchertexture()
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 3, Local::watches, Local::watchestexture, 0);
}


bool Local::Glitchmodel= false;
void Local::glitchmodel(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	PED::SET_PED_PROP_INDEX(playerPed, 3, Local::watches, Local::watchestexture, 1);
	
	PED::SET_PED_PROP_INDEX(playerPed, 2, Local::ears, Local::earstexture, 1);
	
	PED::SET_PED_PROP_INDEX(playerPed, 1, Local::glasses, Local::glassestexture, 1);

	PED::SET_PED_PROP_INDEX(playerPed, 0, Local::hats, Local::hatstexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, Local::torsosec, Local::torsosectexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, Local::accesoriessec, Local::accesoriessectexture, 1);
	
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Local::accesories, Local::accesoriestexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 7, Local::eyes, Local::eyestexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, Local::feet, Local::feettexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, Local::hands, Local::handstexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, Local::legs, Local::legstexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, Local::hair, Local::hairtexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, Local::head, Local::headtexture, 1);
	
	PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, Local::face, Local::facetexture, 1);

	PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, Local::torso, Local::torsotexture, 1);
}