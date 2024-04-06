#include "stdafx.h"
#include "math.h"
#include "types.h"
#include "SelectedPlayer.h"
#include "Functions.h"
#include "natives.h"

//1737847354
 //1955543594

#define Playerlocation ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 1)
#define playerPedId	PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())
#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0x1E9A99F8 // skid use this 
#define pickup_money_wallet 3379096726
#define pickup_money_dep_bag 1141753539
#define pickup_money_purse 1732239030
#define pickup_money_med_bag 2183826132
#define pickup_money_paper_bag 196067644
#define pickup_money_security_case 233405277
#define prop_ld_health_pack 0x113FD533
#define PICKUP_HEALTH_STANDARD 0x1E9A99F8
#define PROP_MONEY_BAG_02 -1666779307
#define Rp_Statues_01 1298470051 //alien
#define Rp_Statues_02 437412629 //Princess
#define nocolle 1737847354 //beast
#define colle 1955542584 //beast
#define customscript 738282662 //Custom pickup script skid use 0x2C014CA6
#define Rp_Card_01 1226474661 //queen
#define Rp_Card_02 3642186697 //jack
#define Rp_Card_03 158316850 //king



Vehicle SpawnVehicle33(char* modelg, Vector3 coords, bool tpinto = 0, float heading = 0.0f) {
	DWORD model = GAMEPLAY::GET_HASH_KEY(modelg);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}

}

namespace rage
{

	template <typename T>
	class atArray
	{
	public:
		T* begin()
		{
			return m_data;
		}

		T* end()
		{
			return m_data + m_size;
		}

		const T* begin() const
		{
			return m_data;
		}

		const T* end() const
		{
			return m_data + m_size;
		}

		T* data()
		{
			return m_data;
		}

		const T* data() const
		{
			return m_data;
		}

		std::uint16_t size() const
		{
			return m_size;
		}

		std::uint16_t capacity() const
		{
			return m_capacity;
		}

		T& operator[](std::uint16_t index)
		{
			return m_data[index];
		}

		const T& operator[](std::uint16_t index) const
		{
			return m_data[index];
		}
	private:
		T* m_data;
		std::uint16_t m_size;
		std::uint16_t m_capacity;
	};
}

bool SPlayer::SpectateBool = false;

//Weapon Modifications

bool SPlayer::Shootmoney = false;
bool SPlayer::Shootcars = false;
int SPlayer::exptypeonline = 18;
bool SPlayer::Shootexp = false;
bool SPlayer::Force = false;
bool SPlayer::Dropall = false; //Onetap
bool SPlayer::Shootairstrike = false;
bool SPlayer::Deletegunr = false;
bool SPlayer::PedGunv2 = false;
bool SPlayer::FireGun = false;
bool SPlayer::WaterGun = false;
int SPlayer::Allamount = 2500;
int SPlayer::DropDelay = 200;
int SPlayer::asset = 0;
bool SPlayer::Shootcarrs = false;
bool SPlayer::RainbowHeadlight = false;
bool SPlayer::Shootcarrrs = false;
bool SPlayer::ShootRp = false;
bool SPlayer::Remotefly = false;
bool SPlayer::Insanegun = false;

char* car = "adder";

char* carr = "CARGOPLANE";

char* carrr = "KOSATKA";

//Vehicle spawn for other player
bool SPlayer::Vehicle_Atach = false;

bool SPlayer::givecarr1 = false;

int Vehicle_Hash4 = 0;
 
bool SPlayer::Jumpplayer = false;

bool SPlayer::Ragdollplayer = false;

bool SPlayer::Freezeplayer = false;

bool SPlayer::fpscrash = false;

bool SPlayer::fpscrash2 = false;

bool SPlayer::poolcrash2 = false;

bool loadinfo = true;

//#include "utils.h"


int rgb1 = 255, rgb3 = 0, rgb2 = 0;
void RGBZN()
{
	if (rgb1 > 0 && rgb2 == 0) {
		rgb1--;
		rgb3++;
	}
	if (rgb3 > 0 && rgb1 == 0) {
		rgb3--;
		rgb2++;
	}
	if (rgb2 > 0 && rgb3 == 0) {
		rgb1++;
		rgb2--;
	}
}


int SPlayer::intmarker = 0;
int SPlayer::intvisibility = 255;
int SPlayer::intdirx = 0;
int SPlayer::intdiry = 0;
int SPlayer::intdirz = 0;
int SPlayer::introtx = 0;
int SPlayer::introty = 0;
int SPlayer::introtz = 0;
int SPlayer::intscax = 2;
int SPlayer::intscay = 2;
int SPlayer::intscaz = 2;


char* request;
char* use;
char* Nameptfx;

void PTFXCALLSP(char* call1, char* call2, char* name)
{

	request = call1;
	use = call2;
	Nameptfx = name;

	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 15.0, false, false, false);

}

void SPlayer::UpdateLoop()
{
	mf ? Mf(true) : NULL;

	mf1 ? Mf1(true) : NULL;

	ft ? Freezetoggle(true) : NULL;

	ft1234 ? Freezetoggle1234(true) : NULL;

	CRASHV3 ? crashv3(true) : NULL;

	mf11234 ? Mf11234(true) : NULL;

	Moneydrop ? moneydrop(true) : NULL;

	Moneydrop2 ? moneydrop2(true) : NULL;

	Rpdrop ? rpdrop(true) : NULL;

	Rpdrop2 ? rpdrop2(true) : NULL;

	Carddrop ? carddrop(true) : NULL;
	

	if (SpectateBool) {
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
		RGBZN();
		GRAPHICS::DRAW_MARKER(intmarker, pos.x, pos.y, pos.z + 2.f, intdirx, intdiry, intdirz, introtx, introty, introtz, intscax, intscay, intscaz, rgb1, rgb2, rgb3, intvisibility, false, false, 0, false, NULL, NULL, false);
	}
	else
	{
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, PLAYER::PLAYER_PED_ID());
	}
	if (fpscrash)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
		Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
		Vehicle cargoplane = SpawnVehicle("CARGOPLANE", Ocoords, 0, 0.0f);
		ENTITY::SET_ENTITY_INVINCIBLE(cargoplane, 0);
		int Handle2 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle2);
		Vector3 pCoords2 = ENTITY::GET_ENTITY_COORDS(Handle2, 0);
		Vector3 Ocoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle2, 0.0, 5.0, 0.0);
		Vehicle kosatka = SpawnVehicle("KOSATKA", Ocoords2, 0, 0.0f);
		ENTITY::SET_ENTITY_INVINCIBLE(kosatka, 0);
		Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, 29, 999, true, false, 10);
		PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);

	}
	if (fpscrash2)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
		PTFXCALLSP("scr_rcbarry2", "scr_rcbarry2", "scr_exp_clown");
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
		Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
		Vehicle cargoplane = SpawnVehicle("CARGOPLANE", Ocoords, 0, 0.0f);
		ENTITY::SET_ENTITY_INVINCIBLE(cargoplane, 0);
		int Handle2 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle2);
		Vector3 pCoords2 = ENTITY::GET_ENTITY_COORDS(Handle2, 0);
		Vector3 Ocoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle2, 0.0, 5.0, 0.0);
		Vehicle kosatka = SpawnVehicle("KOSATKA", Ocoords2, 0, 0.0f);
		ENTITY::SET_ENTITY_INVINCIBLE(kosatka, 0);
		Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, 29, 999, true, false, 10);
		PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);
	}

	int Vehicle_Hash = 0;
	int Ped_Hash = 0;
	int Object_Hash = 0;
	if (poolcrash2)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		Vehicle_Hash = GAMEPLAY::GET_HASH_KEY("CARGOPLANE");
		{
			STREAMING::REQUEST_MODEL(Vehicle_Hash);
			if (STREAMING::HAS_MODEL_LOADED(Vehicle_Hash));
			{
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				int Handle = VEHICLE::CREATE_VEHICLE(Vehicle_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
				if (ENTITY::DOES_ENTITY_EXIST(Handle))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
				}
			}
		}
		Ped_Hash = GAMEPLAY::GET_HASH_KEY("a_c_husky");
		{
			STREAMING::REQUEST_MODEL(Ped_Hash);
			if (STREAMING::HAS_MODEL_LOADED(Ped_Hash));
			{
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				int Handle = PED::CREATE_PED(1, Ped_Hash, Coords.x, Coords.y, Coords.z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), TRUE, TRUE);
				if (ENTITY::DOES_ENTITY_EXIST(Handle))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
				}
			}
		}

		Object_Hash = GAMEPLAY::GET_HASH_KEY("p_fin_vaultdoor_s");
		{
			STREAMING::REQUEST_MODEL(Object_Hash);
			if (STREAMING::HAS_MODEL_LOADED(Object_Hash));
			{
				Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				int Handle = OBJECT::CREATE_OBJECT(Object_Hash, Coords.x, Coords.y, Coords.z, 0, true, false);
				if (ENTITY::DOES_ENTITY_EXIST(Handle))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Handle, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 1);
				}
			}
		}

	}

	if (Freezeplayer)
	{
		Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
		AI::CLEAR_PED_TASKS(vic);
		AI::CLEAR_PED_SECONDARY_TASK(vic);
	}
	else
	{

	}

	if (Jumpplayer)
	{
		Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		AI::TASK_JUMP(vic, 1);
	}
	else
	{

	}


	if (Ragdollplayer)
	{
		Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(vic, FALSE);
		PED::SET_PED_TO_RAGDOLL_WITH_FALL(vic, 1500,1 ,1, playerPosition.x, playerPosition.y, playerPosition.z, 1.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);
	}
	else
	{

	}


	if (Dropall)
	{
		for (int i = 0; i < 32; i++)
		{
			if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::PLAYER_PED_ID())
			{
				if ((timeGetTime() - SPlayer::TimePD2) > CashInt) // Time between drops
				{
					Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
					if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02)) {
						WAIT(0);
					}
					else
					{
						Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
						OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + CashHeight, 2500, CashAmount, PROP_MONEY_BAG_02, FALSE, TRUE);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
					}
					TimePD2 = timeGetTime();

				}
			}
		}
	}
	else
	{

	}

	if (Force)
	{
		Player playerPed = selectedPlayer;
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		FIRE::ADD_EXPLOSION(pCoords.x + 2, pCoords.y + 2, pCoords.z, 7, 9.0f, false, true, 0.0f);
		FIRE::ADD_EXPLOSION(pCoords.x + 3, pCoords.y + 3, pCoords.z, 7, 9.0f, false, true, 0.0f);
		FIRE::ADD_EXPLOSION(pCoords.x + 4, pCoords.y + 4, pCoords.z, 7, 9.0f, false, true, 0.0f);
		FIRE::ADD_EXPLOSION(pCoords.x + 5, pCoords.y + 5, pCoords.z, 7, 9.0f, false, true, 0.0f);
		FIRE::ADD_EXPLOSION(pCoords.x + 6, pCoords.y + 6, pCoords.z, 7, 9.0f, false, true, 0.0f);
		FIRE::ADD_EXPLOSION(pCoords.x + 7, pCoords.y + 7, pCoords.z, 7, 9.0f, false, true, 0.0f);
	}
	else
	{

	}
	if (Vehicle_Atach)
	{

	}




}




#define vw_prop_vw_colle_pogo 2513890

int SPlayer::CashAmount = 2500;
int SPlayer::CashInt = 1000;
int SPlayer::CashHeight = 1;
int SPlayer::HeadlightInt = 400;
int SPlayer::TimePD2;
int SPlayer::RpAmount = 5;
int SPlayer::Rpint = 0;
int SPlayer::Rphieght = 1;
int SPlayer::TimepD3;
int SPlayer::TimePD3;
int SPlayer::TimePD4;
int SPlayer::CashAmount2 = 2500;
int SPlayer::CashInt2 = 1000;
int SPlayer::RpInt2 = 1000;
int SPlayer::CashHeight2 = 1;
int SPlayer::Cardhieght = 1;



bool SPlayer::Moneydrop2 = false;
void SPlayer::moneydrop2(bool toggle)
{
	
   Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	float dx = coordsOf(iPed).x;
	float dy = coordsOf(iPed).y;
	float dz = coordsOf(iPed).z;
	float randX = rndInt(-7, 7);
	float randY = rndInt(-7, 7);
	float randZ = rndInt(5, 5);
	float offsetX = dx + randX;
	float offsetY = dy + randY;
	float offsetZ = dz + randZ;
	
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
    if ((timeGetTime() - SPlayer::TimePD3) > SPlayer::CashInt2) // Time between drops
	{
		Hash MoneyHASH = GAMEPLAY::GET_HASH_KEY("prop_gold_bar");
		STREAMING::REQUEST_MODEL(MoneyHASH);
		if (!STREAMING::HAS_MODEL_LOADED(MoneyHASH)) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, offsetX, offsetY, offsetZ, 1, CashAmount2, MoneyHASH, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(MoneyHASH);

			SPlayer::TimePD3 = timeGetTime();
		}
	}
}

bool SPlayer::Moneydrop = false;
void SPlayer::moneydrop(bool toggle)
{
	if ((timeGetTime() - SPlayer::TimePD2) > CashInt) // Time between drops
	{
		
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		Hash moneyhash = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_SECURITY_CASE");
		STREAMING::REQUEST_MODEL(Rp_Statues_02);
		if (!STREAMING::HAS_MODEL_LOADED(Rp_Statues_02)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(moneyhash, playerPosition.x, playerPosition.y, playerPosition.z + CashHeight, 0, CashAmount, Rp_Statues_02, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Rp_Statues_02);
		}
		TimePD2 = timeGetTime();

	}
}





void ModelCallback() {
	STREAMING::REQUEST_MODEL(437412629);
	while (!STREAMING::HAS_MODEL_LOADED(437412629)) { WAIT(0); }
}


bool SPlayer::Rpdrop = false;
void SPlayer::rpdrop(bool toggle)
{
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
		Hash statueModel = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(statueModel);
		if (!STREAMING::HAS_MODEL_LOADED(statueModel)) {

		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + Rphieght, 0, 1, statueModel, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(statueModel);
		}
}


bool SPlayer::Rpdrop2 = false;
void SPlayer::rpdrop2(bool toggle)
{
	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	float dx = coordsOf(iPed).x;
	float dy = coordsOf(iPed).y;
	float dz = coordsOf(iPed).z;
	float randX = rndInt(-7, 7);
	float randY = rndInt(-7, 7);
	float randZ = rndInt(5, 5);
	float offsetX = dx + randX;
	float offsetY = dy + randY;
	float offsetZ = dz + randZ;
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
	if ((timeGetTime() - SPlayer::TimePD4) > SPlayer::RpInt2) // Time between drops
	{
		Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");
		STREAMING::REQUEST_MODEL(RPHASH);
		if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {
			WAIT(0);
		}
		else {
			OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, offsetX, offsetY, offsetZ, 1, 1, RPHASH, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);

			SPlayer::TimePD4 = timeGetTime();
		}
	}
}



bool SPlayer::Carddrop = false;
void SPlayer::carddrop(bool toggle)
{
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), true);
	Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_lux_card_01a");
	STREAMING::REQUEST_MODEL(RPHASH);
	if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

	}
	else {
		OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, pos.x, pos.y, pos.z + SPlayer::Cardhieght, 0, 1, RPHASH, FALSE, TRUE);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
	}
}



void SPlayer::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}


bool SPlayer::mf = false;
void SPlayer::Mf(bool toggle)
{
	Vector3 Pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 0.0, 0.0, 0.0);
	Vector3 min, max;
	Vector3 cmin, cmax;

	GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_gold_cont_01"), &cmin, &cmax);

	static Object obj;

	if (toggle == true)
	{
		if (PED::IS_PED_ON_VEHICLE(selectedPlayer), 1)
		{

		}
		else
		{
			notifyBottom("The player has to be in a vehicle");
		}

		if (!STREAMING::HAS_MODEL_LOADED($("prop_gold_cont_01")))
			STREAMING::REQUEST_MODEL($("prop_gold_cont_01"));

		static auto tickeer = GetTickCount();
		if ((GetTickCount() - tickeer) >= 1000) {
			obj;
		}

		static auto ticker = GetTickCount();
		if (ENTITY::DOES_ENTITY_EXIST(obj)) {
			RequestControlOfEnt(obj);
			ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
			ENTITY::DELETE_ENTITY(&obj);
			OBJECT::DELETE_OBJECT(&obj);
		}

	}
	else
	{
		char* objects[1] = { "prop_gold_cont_01" };
		for (int i = 0; i < 5; i++) 
		{
			for (int i = 0; i < 1; i++) 
			{

				if (ENTITY::DOES_ENTITY_EXIST(obj), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))
				{
					RequestControlOfEnt(obj);
					ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
					ENTITY::DELETE_ENTITY(&obj);
					OBJECT::DELETE_OBJECT(&obj);
				}
			}
		}
		if (ENTITY::DOES_ENTITY_EXIST(obj))
		{
			RequestControlOfEnt(obj);
			ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
			ENTITY::DELETE_ENTITY(&obj);
			OBJECT::DELETE_OBJECT(&obj);
		}
		
	}
	



	obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), Pos.x, Pos.y, Pos.z - 1.f, true, false, false);

}

bool SPlayer::Fireloop = false;
void SPlayer::fireloop(bool toggle) {
	Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, 12, 5, true, false, 10);
	PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);
	
}

bool SPlayer::Waterloop = false;
void SPlayer::waterloop(bool toggle) {
	Vector3 GetPlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	FIRE::ADD_EXPLOSION(GetPlayerCoords.x, GetPlayerCoords.y, GetPlayerCoords.z, 13, 5, true, false, 10);
	PED::EXPLODE_PED_HEAD(PLAYER::GET_PLAYER_PED(selectedPlayer), 0x145F1012);
}

bool SPlayer::mf1 = false;
void SPlayer::Mf1(bool toggle)
{
	Vector3 Pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 0.0, 0.0, 0.0);
	Vector3 min, max;
	Vector3 cmin, cmax;

	GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_gold_cont_01"), &cmin, &cmax);

	static Object obj;

	if (PED::IS_PED_IN_ANY_VEHICLE)
	{
		if (toggle == true)
		{
			if (PED::IS_PED_ON_VEHICLE(selectedPlayer), 1)
			{
				if (!STREAMING::HAS_MODEL_LOADED($("prop_gold_cont_01")))
					STREAMING::REQUEST_MODEL($("prop_gold_cont_01"));

				static auto tickeer = GetTickCount();
				if ((GetTickCount() - tickeer) >= 1000) {
					obj;
				}

				static auto ticker = GetTickCount();
				if (ENTITY::DOES_ENTITY_EXIST(obj)) {
					RequestControlOfEnt(obj);
					ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
					ENTITY::DELETE_ENTITY(&obj);
					OBJECT::DELETE_OBJECT(&obj);
				}

			}
			else
			{
				char* objects[1] = { "prop_gold_cont_01" };
				for (int i = 0; i < 5; i++)
				{
					for (int i = 0; i < 1; i++)
					{

						if (ENTITY::DOES_ENTITY_EXIST(obj), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))
						{
							RequestControlOfEnt(obj);
							ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
							ENTITY::DELETE_ENTITY(&obj);
							OBJECT::DELETE_OBJECT(&obj);
						}
					}
				}
				if (ENTITY::DOES_ENTITY_EXIST(obj))
				{
					RequestControlOfEnt(obj);
					ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
					ENTITY::DELETE_ENTITY(&obj);
					OBJECT::DELETE_OBJECT(&obj);
				}

			}
		}
	}
	else
	{
		notifyBottom("The player has to be in a vehicle");
	}

	obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), Pos.x, Pos.y, Pos.z - 1.f, true, false, false);

}

void SPlayer::Kick(Player p)
{
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	unsigned int Bit = (1 << p);

	uint64_t kicks[][4] = {
		{ 2055958901, player, 5, 0 },
		{ 994306218, player, 5, 0 },
		{ -120668417, player, 48, 0 },
		{ -1835749229, player, -1, 0 },
		{ 2077565911, player, 0, 0 },
		{ 4156321, player, 0, 0 },
		{ -1662909539, player, 0, 0 },
		{ 256346004, player, 0, 0 },
		{ -15432926, player, 0, 0 },
		{ -1243184386, player, 0, 0 },
		{ 1642479322, player, 0, 0 },
		{ 27391769, player, 0, 0 },
		{ -2136787743, player, 0, 0 },
		{ -1289983205, player, 0, 0 },
		{ 1586576930, player, 0, 0 },
		{ 1093247513, player, 0, 0 },
		{ 2021867503, player, 0, 0 },
		{ -1184085326, player, 0, 0 },
		{ -1996885757, player, 0, 0 },
		{ 1178932519, player, 0, 0 },
		{ 813647057, player, 0, 0 },
		{ 769347061, player, 0, 0 },
		{ 999090520, player, 0, 0 }
	};

	uint64_t args1[4] = { 2055958901, player, 5, 0 };
	uint64_t args2[4] = { 994306218, player, 5, 0 };
	uint64_t args3[3] = { -120668417, player, 48 };
	uint64_t args4[4] = { -1835749229, player, -1, 0 };
	uint64_t args5[2] = { 2077565911, player };
	uint64_t args6[2] = { 4156321, player };
	uint64_t args7[2] = { -1662909539, player };
	uint64_t args8[2] = { 256346004, player };
	uint64_t args9[2] = { -15432926, player };
	uint64_t args10[2] = { -1243184386, player };
	uint64_t args11[2] = { 1642479322, player };
	uint64_t args12[2] = { 27391769, player };
	uint64_t args13[2] = { -2136787743, player };
	uint64_t args14[2] = { -1289983205, player };
	uint64_t args15[2] = { 1586576930, player };
	uint64_t args16[2] = { 1093247513, player };
	uint64_t args17[2] = { 2021867503, player };
	uint64_t args18[2] = { -1184085326, player };
	uint64_t args19[2] = { -1996885757, player };
	uint64_t args20[2] = { 1178932519, player };
	uint64_t args21[2] = { 813647057, player };
	uint64_t args22[4] = { 769347061, player, 0, 0 };
	uint64_t args23[4] = { 999090520, player, 0, 0 };

	Foxy_Engine::trigger_script_event(1, args1, 4, Bit);
	Foxy_Engine::trigger_script_event(1, args2, 4, Bit);
	Foxy_Engine::trigger_script_event(1, args3, 3, Bit);
	Foxy_Engine::trigger_script_event(1, args4, 4, Bit);
	Foxy_Engine::trigger_script_event(1, args5, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args6, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args7, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args8, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args9, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args10, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args11, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args12, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args13, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args14, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args15, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args16, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args17, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args18, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args19, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args20, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args21, 2, Bit);
	Foxy_Engine::trigger_script_event(1, args22, 4, Bit);
	Foxy_Engine::trigger_script_event(1, args23, 4, Bit);
}

void SPlayer::boosttoggle()
{
	Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
	{
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 300.0);
	}
}

bool SPlayer::ft = false;
void SPlayer::Freezetoggle(bool toggle)
{
	Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
	{
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0);
	}
}

bool SPlayer::ft1234 = false;
void SPlayer::Freezetoggle1234(bool toggle)
{
	for (int i = 0; i < 32; i++)
	{
		if (i != PLAYER::PLAYER_ID())
		{
			Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
			{
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0);
			}
		}
	}
}

bool SPlayer::mf11234 = false;
void SPlayer::Mf11234(bool toggle)
{
	for (int i = 0; i < 32; i++)
	{
		if (i != PLAYER::PLAYER_ID())
		{
			Vector3 Pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0.0, 0.0, 0.0);
			Vector3 min, max;
			Vector3 cmin, cmax;

			GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_gold_cont_01"), &cmin, &cmax);

			static Object obj;

			if (toggle == true)
			{
				if (PED::IS_PED_ON_VEHICLE(selectedPlayer), 1)
				{
					if (!STREAMING::HAS_MODEL_LOADED($("prop_gold_cont_01")))
						STREAMING::REQUEST_MODEL($("prop_gold_cont_01"));

					static auto tickeer = GetTickCount();
					if ((GetTickCount() - tickeer) >= 1000) {
						obj;
					}

					static auto ticker = GetTickCount();
					if (ENTITY::DOES_ENTITY_EXIST(obj)) {
						RequestControlOfEnt(obj);
						ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
						ENTITY::DELETE_ENTITY(&obj);
						OBJECT::DELETE_OBJECT(&obj);
					}

				}
				else
				{
					char* objects[1] = { "prop_gold_cont_01" };
					for (int i = 0; i < 5; i++)
					{
						for (int i = 0; i < 1; i++)
						{

							if (ENTITY::DOES_ENTITY_EXIST(obj), PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer))
							{
								RequestControlOfEnt(obj);
								ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
								ENTITY::DELETE_ENTITY(&obj);
								OBJECT::DELETE_OBJECT(&obj);
							}
						}
					}
					if (ENTITY::DOES_ENTITY_EXIST(obj))
					{
						RequestControlOfEnt(obj);
						ENTITY::SET_ENTITY_COORDS(obj, 0.f, 0.f, 0.f, 1, 1, 1, 0);
						ENTITY::DELETE_ENTITY(&obj);
						OBJECT::DELETE_OBJECT(&obj);
					}

				}
			}
			else
			{
				notifyBottom("The player has to be in a vehicle");
			}

			obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), Pos.x, Pos.y, Pos.z - 1.f, true, false, false);
		}
	}
}



void SPlayer::kickfromveh()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	RequestControlOfEnt(playerPed);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
	AI::CLEAR_PED_TASKS(playerPed);
	AI::CLEAR_PED_SECONDARY_TASK(playerPed);
}

Vehicle SPlayer::SpawnVehicle(char* modelg, Vector3 coords, bool tpinto = 0, float heading = 0.0f)
{
	DWORD model = GAMEPLAY::GET_HASH_KEY(modelg);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}

}

int asset = 255;

void SPlayer::Givecar()
{
	if (givecarr1)
	{
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
		int Hashs = GAMEPLAY::GET_HASH_KEY(car);
		STREAMING::REQUEST_MODEL(Hashs);
		if (STREAMING::HAS_MODEL_LOADED(Hashs))
		{
			VEHICLE::CREATE_VEHICLE(Hashs, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 1, 0);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
		}
	}
}

void SPlayer::OnlineplayerWepmods()
{
	if (Foxy_Engine::chat_cmd_on)
	{
		if (Foxy_Engine::action1_1) {
			//Foxy_Engine::set_session_weather(1, 13, 76, 0);
			notifyMap("ON");
			Foxy_Engine::action1_1 = false; //Do the action only once
		}
		if (Foxy_Engine::action1_2) {
			notifyMap("Off");
			Foxy_Engine::action1_2 = false;
		}
		if (Foxy_Engine::action1_4) {
			for (int i = 0; i < 33; i++)
			{
				if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
				{
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
					FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f);
				}
			}
			notifyMap("They Will Die");
			Foxy_Engine::action1_4 = false;
		}
		if (Foxy_Engine::action2) {
			{
				if ((timeGetTime() - TimePD2) > 1000) // Time between drops
				{
					Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
					STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
					if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02)) {
						WAIT(0);
					}
					else {
						Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
						OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + 1, 0, 2500, PROP_MONEY_BAG_02, FALSE, TRUE);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
					}
					TimePD2 = timeGetTime();

				}
			}
			Foxy_Engine::action2 = false;
		}
	}
	if (Shootcars)
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			int Hashs = GAMEPLAY::GET_HASH_KEY(car);
			STREAMING::REQUEST_MODEL(Hashs);
			if (STREAMING::HAS_MODEL_LOADED(Hashs))
			{
				VEHICLE::CREATE_VEHICLE(Hashs, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0.0f, 1, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
			}
		}
	}
	if (Shootmoney)
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			STREAMING::REQUEST_MODEL((PROP_MONEY_BAG_02));
			while (!STREAMING::HAS_MODEL_LOADED((PROP_MONEY_BAG_02)))WAIT(0); {
				OBJECT::CREATE_AMBIENT_PICKUP((pickup_money_security_case), PlayerPos.x, PlayerPos.y, PlayerPos.z, 0, 2500, (PROP_MONEY_BAG_02), FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((PROP_MONEY_BAG_02)); }

		}
	}
	if (Shootexp)
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			FIRE::ADD_EXPLOSION(PlayerPos.x, PlayerPos.y, PlayerPos.z, exptypeonline, 1000.f, true, false, 0.f);

		}
	}
	if (Shootairstrike)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
			{
				Vector3 PlayerPos;
				 WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
				
					Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
					WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
					while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
						WAIT(0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(PlayerPos.x, PlayerPos.y, PlayerPos.z + 50.f, PlayerPos.x, PlayerPos.y, PlayerPos.z, 250, 1, airStrike, selectedPlayer, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(PlayerPos.x, PlayerPos.y + 20.f, PlayerPos.z + 50.f, PlayerPos.x, PlayerPos.y, PlayerPos.z, 250, 1, airStrike, selectedPlayer, 1, 0, -1.0);
					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(PlayerPos.x + 20.f, PlayerPos.y, PlayerPos.z + 50.f, PlayerPos.x, PlayerPos.y, PlayerPos.z, 250, 1, airStrike, selectedPlayer, 1, 0, -1.0);


			
			}
		}

	}
	if (Deletegunr)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
			{
				Vector3 PlayerPos;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
				GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(PlayerPos.x, PlayerPos.y, PlayerPos.z, 2, 0, 0, 0, 0);
			}
		}
	}
	if (PedGunv2)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
			{
				Vector3 PlayerPos;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
				PED::CREATE_RANDOM_PED(PlayerPos.x, PlayerPos.y, PlayerPos.z);
			}
		}
	}
	if (FireGun)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
			{
				Vector3 PlayerPos;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
				FIRE::ADD_EXPLOSION(PlayerPos.x, PlayerPos.y, PlayerPos.z, 12, 5.f, true, false, 0.f);
			}
		}
	}
	if (WaterGun)
	{
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer))) {
			{
				Vector3 PlayerPos;
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
				FIRE::ADD_EXPLOSION(PlayerPos.x, PlayerPos.y, PlayerPos.z, 13, 5.f, true, false, 0.f);
			}
		}
	}
	if (Shootcarrs)//
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			int Hashs = GAMEPLAY::GET_HASH_KEY(carr);
			STREAMING::REQUEST_MODEL(Hashs);
			if (STREAMING::HAS_MODEL_LOADED(Hashs))
			{
				VEHICLE::CREATE_VEHICLE(Hashs, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0.0f, 1, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
			}
		}
	}
	if (Shootcarrrs)
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			int Hashs = GAMEPLAY::GET_HASH_KEY(carrr);
			STREAMING::REQUEST_MODEL(Hashs);
			if (STREAMING::HAS_MODEL_LOADED(Hashs))
			{
				VEHICLE::CREATE_VEHICLE(Hashs, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0.0f, 1, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Hashs);
			}
		}
	}


	if (Insanegun)
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;  //Start at index 2, and the odd elements are padding
		int vehs[arrSize];
		//0 index is the size of the array
		vehs[0] = numElements;
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);
		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 bulletcoord;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &bulletcoord);
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
							ENTITY::SET_ENTITY_COORDS(vehs[offsettedID], bulletcoord.x, bulletcoord.y, bulletcoord.z + 50.f, false, false, false, false);
							WAIT(0);
							ENTITY::APPLY_FORCE_TO_ENTITY(vehs[offsettedID], 1, 0, 0, -700.0f, 0, 0, 0, 1, false, true, true, true, true);
						}
					}
				}
			}
		}
	}

	if (ShootRp)
	{

		if (PED::IS_PED_SHOOTING(PLAYER::GET_PLAYER_PED(selectedPlayer)))
		{
			Vector3 PlayerPos;
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED(selectedPlayer), &PlayerPos);
			Hash RPHASH = GAMEPLAY::GET_HASH_KEY("vw_prop_vw_colle_prbubble");


			STREAMING::REQUEST_MODEL(RPHASH);
			if (!STREAMING::HAS_MODEL_LOADED(RPHASH)) {

			}
			else {
				OBJECT::CREATE_AMBIENT_PICKUP(0x2C014CA6, PlayerPos.x, PlayerPos.y, PlayerPos.z, 0, 1, RPHASH, FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(RPHASH);
			}
			
		}
	}
	if (Remotefly)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::GET_PLAYER_PED(selectedPlayer))) //GET_PLAYER_PED_SCRIPT_INDEX
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
			RequestControlOfEnt(Veh);
		    VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 500);
		
		}
	}

	if (RainbowHeadlight)
	{

		if (PED::IS_PED_IN_ANY_VEHICLE((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), true))
		{
			int vehicle = PED::GET_VEHICLE_PED_IS_IN((PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer)), false);
			RequestControlOfEnt(vehicle);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(vehicle))
			{
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) // Time between Light change
				{
				 VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				 VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 0);
				 TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt)
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 1);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 2);
				TimePD2 = timeGetTime();

			}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 3);
				TimePD2 = timeGetTime();

		        }
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 4);
				TimePD2 = timeGetTime();
				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 5);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 6);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 7);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 8);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 9);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 10);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 11);
				TimePD2 = timeGetTime();

				}
				if ((timeGetTime() - SPlayer::TimePD2) > HeadlightInt) 
				{
				VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
				VEHICLE::SET_HEADLIGHT_COLOR(vehicle, 12);
				TimePD2 = timeGetTime();

				}//

			}
		}
		else
		{
			notifyMap("Player not in a vehicle or too far away!");
		}



	}


}


void SetBit(int& varible, int bit)
{
	varible |= 1UL << bit;
}
bool CheckBit(int variable, int bit)
{
	return (variable >> bit) & 1U;
}
DWORD crash_cam_timer = 20;
int crash_cam_toggles = 0, crash_cam_entity = 0, crash_cam = 0;
BYTE crash_cam_client = 0;
bool SPlayer::CRASHV3 = false;
void SPlayer::crashv3(bool toggle)
{

	if (!toggle)
	{
		CAM::SET_CAM_ACTIVE(crash_cam, false);
		CAM::DESTROY_CAM(crash_cam, false);
		CAM::RENDER_SCRIPT_CAMS(0, 0, 3000, 1, 0);
		STREAMING::CLEAR_FOCUS();
	}
	else
	{
		if (!CAM::DOES_CAM_EXIST(crash_cam)) crash_cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_COORD(crash_cam, 0.0f, 0.0f, 10000.0f);
		STREAMING::_SET_FOCUS_AREA(0.0f, 0.0f, 10000.0f, 0.0f, 0.0f, 0.0f);
		CAM::SET_CAM_ACTIVE(crash_cam, true);
		CAM::RENDER_SCRIPT_CAMS(1, 0, 3000, 1, 0);
	}

	if (crash_cam_toggles, 2)
	{
		if (GetTickCount() > crash_cam_timer)
		{
			if (ENTITY::DOES_ENTITY_EXIST(crash_cam_entity))
			{
				SetBit(crash_cam_toggles, 15);
				int entity = crash_cam_entity;
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity))
				{
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, 0, 1);
					ENTITY::DETACH_ENTITY(entity, 0, 0);
					ENTITY::DELETE_ENTITY(&entity);
					notifyMap("Step 3/3 completed");
				}
				else NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
			}
			else
			{
				if (!CheckBit(crash_cam_toggles, 15)) notifyMap("Step failed.");
				crashv3(false);
				crash_cam_toggles = 0;
				crash_cam_entity = 0;
			}
		}
		else
		{
			STREAMING::REQUEST_MODEL(0xC1CE1183);
			if (STREAMING::HAS_MODEL_LOADED(0xC1CE1183))
			{
				if (!CheckBit(crash_cam_toggles, 16)) notifyMap("Step 1/3 completed.");
				if (!crash_cam_entity)
				{
					int ped = PLAYER::GET_PLAYER_PED(crash_cam_client);
					Vector3 Position = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 0);
					crash_cam_entity = OBJECT::CREATE_OBJECT(0xC1CE1183, Position.x, Position.y, Position.z, true, true, false);
					if (ENTITY::DOES_ENTITY_EXIST(crash_cam_entity))
					{
						SetBit(crash_cam_toggles, 16);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(crash_cam_entity, ped, -1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 2, 1);
						notifyMap("Step 2/3 completed.");
					}
				}
			}
		}
	}


	std::vector<int> crash_cam_entities;
	if (CheckBit(crash_cam_toggles, 0))
	{
		if (GetTickCount() > crash_cam_timer)
		{
			for (int i = ((int)crash_cam_entities.size() - 1); i >= 0; i--)
			{
				if (ENTITY::DOES_ENTITY_EXIST(crash_cam_entities[i]))
				{
					SetBit(crash_cam_toggles, 15);
					int entity = crash_cam_entities[i];
					if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x2D7030F3);
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(entity, 0, 1);
						ENTITY::DELETE_ENTITY(&entity);
						crash_cam_entities.erase(crash_cam_entities.begin() + i);
						notifyMap("Step 3/3 completed.");
					}
					else NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
				}
				else crash_cam_entities.erase(crash_cam_entities.begin() + i);
			}
			if ((int)crash_cam_entities.size() == 0)
			{
				if (!CheckBit(crash_cam_toggles, 15)) printf("Step failed."); notifyMap("Step failed.");
				crashv3(false);
				crash_cam_toggles = 0;
				crash_cam_entity = 0;
			}
		}
		else
		{
			STREAMING::REQUEST_MODEL(0x2D7030F3);
			if (STREAMING::HAS_MODEL_LOADED(0x2D7030F3))
			{
				if (!CheckBit(crash_cam_toggles, 16)) notifyMap("Step 1/3 completed.");
				int ped = PLAYER::GET_PLAYER_PED(crash_cam_client);
				if ((!crash_cam_entity || !ENTITY::DOES_ENTITY_EXIST(crash_cam_entity)) && (int)crash_cam_entities.size() < 10)
				{
					AI::CLEAR_PED_TASKS_IMMEDIATELY(ped);
					Vector3 Position = ENTITY::GET_ENTITY_COORDS(ped, 0);
					crash_cam_entity = PED::CREATE_PED(26, 0x2D7030F3, Position.x, Position.y, Position.z, 0.0f, 1, 0);
					int netid = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(crash_cam_entity);
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(netid, 1);
				}
				if (ENTITY::DOES_ENTITY_EXIST(crash_cam_entity))
				{
					if (ENTITY::GET_ENTITY_MODEL(crash_cam_entity) == 0x2D7030F3)
					{
						SetBit(crash_cam_toggles, 16);

						crash_cam_entities.push_back(crash_cam_entity);

						//STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crash_cam_hash);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(crash_cam_entity, ped, -1, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 2, 1);
						ENTITY::DETACH_ENTITY(crash_cam_entity, 1, 1);
						ENTITY::FREEZE_ENTITY_POSITION(crash_cam_entity, true);
						notifyMap("Step 2/3 completed.");

						crash_cam_entity = 0;
					}
					else crash_cam_entity = 0;
				}
			}
		}
	}

}

char* valuebuffer(int num)
{
	char buf[30];
	_snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}

char* SPlayer::BodyguardModel1 = "slod_human";


//// SPlayer::LoadPlayerInfo(Foxy_Engine::get_player_name(selectedPlayer), selectedPlayer);
void SPlayer::LoadPlayerInfo(char* playerName, Player p) {
	if (loadinfo)
	{

		//PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p)
		Player self = playerPedId;
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		RequestControlOfEnt(ped);

		//1590535
		//1589819
		int money = globalHandle(1590908).At(p, 874).At(211).At(3).As<int>();
		int rp = globalHandle(1590908).At(p, 874).At(211).At(5).As<int>();
		int rank = globalHandle(1590908).At(p, 874).At(211).At(6).As<int>();
		int kills = globalHandle(1590908).At(p, 874).At(211).At(28).As<int>();
		int deaths = globalHandle(1590908).At(p, 874).At(211).At(29).As<int>();
		float kd = globalHandle(1590908).At(p, 874).At(211).At(26).As<float>();
		int handle = globalHandle(1590908).At(p, 874).At(211).At(56).As<int>();
		int handle2 = globalHandle(1590908).At(p, 874).At(211).At(3).As<int>();
		int bankMoney = handle - handle2;

		/*
	int races = globalHandle(1590682).At(p, 871).At(211).At(15).As<int>();
	int raceslost = globalHandle(1590682).At(p, 871).At(211).At(16).As<int>();
	float kd = globalHandle(1590682).At(p, 871).At(211).At(26).As<float>();
		*/

		std::ostringstream Money, RP, Rank, Kills, Deaths, KD, Bank;

		Money << "~q~Cash [Pocket]:~s~ $" << money;
		Bank << "~q~Cash [Bank]:~s~ $" << bankMoney;
		RP << "~q~RP [Value]:~s~ " << rp;
		Rank << "~q~Rank:~s~ " << rank;
		Kills << "~q~Kills:~s~ " << kills;
		Deaths << "~q~Deaths:~s~ " << deaths;
		KD << "~q~K|D [Ratio]:~s~ " << kd;

		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
		Vector3 position;
		position = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		char Coord_buf[100]; sprintf_s(Coord_buf, sizeof(Coord_buf), "~q~Pos X:~w~ %.3f ~q~Y:~w~ %.3f ~q~Z:~w~ %.3f", position.x, position.y, position.z, ENTITY::GET_ENTITY_HEADING(playerPed));

		Hash streetName, crossingRoad;
		PATHFIND::GET_STREET_NAME_AT_COORD(position.x, position.y, position.z, &streetName, &crossingRoad);
		ostringstream Street; Street << "~q~Road:~s~ " << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);

		char* rockstarID;
		int NETWORK_HANDLE[76];
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(p, &NETWORK_HANDLE[0], 13);
		if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13)) {
			rockstarID = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&NETWORK_HANDLE[0]);
		}
		else {
			rockstarID = "~q~Can't Find";
		}

		ostringstream Ridfinder; Ridfinder << "~q~R'ID:~s~ " << rockstarID;



		float health = (float)ENTITY::GET_ENTITY_HEALTH(ped);
		float maxHealth = (float)ENTITY::GET_ENTITY_MAX_HEALTH(ped);
		float healthPercent = health * 100 / maxHealth;
		std::ostringstream Health; Health << "~q~Health:~s~ " << healthPercent << "%";
		float armor = (float)PED::GET_PED_ARMOUR(ped);
		float maxArmor = (float)PLAYER::GET_PLAYER_MAX_ARMOUR(p);
		float armorPercent = armor * 100 / maxArmor;
		std::ostringstream Armour; Armour << "~q~Armour:~s~ " << armorPercent << "%";
		bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
		char* aliveStatus;
		if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
		std::ostringstream Alive; Alive << "~q~Alive:~s~ " << aliveStatus;
		BOOL inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
		std::ostringstream VehicleModel; VehicleModel << "~q~Vehicle:~s~ ";
		std::ostringstream Speed; Speed << "~q~Speed:~s~ ";
		std::ostringstream IsInAVehicle; IsInAVehicle << "~q~In Vehicle:~s~ ";
		if (inVehicle) {
			IsInAVehicle << "Yes";
			Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
			VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
			float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
			float Vehrealspeed;
			Vehrealspeed = round(vehSpeed * 1.6f);
			Speed << Vehrealspeed << " KM/H";
		}
		else {
			IsInAVehicle << "No";
			float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
			Speed << speed << " M/S";
			VehicleModel << "No Vehicle Found";
		}
		std::ostringstream WantedLevel; WantedLevel << "~r~Wanted [Level]:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);
		std::ostringstream Weapon; Weapon << "~q~Weapon:~s~ ";
		Hash weaponHash;
		if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1)) {
			char* weaponName;
			if (weaponHash == 2725352035) {
				weaponName = "Unarmed";
			}
			else if (weaponHash == 2578778090) {
				weaponName = "Knife";
			}
			else if (weaponHash == 0x678B81B1) {
				weaponName = "Nightstick";
			}
			else if (weaponHash == 0x4E875F73) {
				weaponName = "Hammer";
			}
			else if (weaponHash == 0x958A4A8F) {
				weaponName = "Bat";
			}
			else if (weaponHash == 0x440E4788) {
				weaponName = "GolfClub";
			}
			else if (weaponHash == 0x84BD7BFD) {
				weaponName = "Crowbar";
			}
			else if (weaponHash == 0x1B06D571) {
				weaponName = "Pistol";
			}
			else if (weaponHash == 0x5EF9FEC4) {
				weaponName = "Combat Pistol";
			}
			else if (weaponHash == 0x22D8FE39) {
				weaponName = "AP Pistol";
			}
			else if (weaponHash == 0x99AEEB3B) {
				weaponName = "Pistol 50";
			}
			else if (weaponHash == 0x13532244) {
				weaponName = "Micro SMG";
			}
			else if (weaponHash == 0x2BE6766B) {
				weaponName = "SMG";
			}
			else if (weaponHash == 0xEFE7E2DF) {
				weaponName = "Assault SMG";
			}
			else if (weaponHash == 0xBFEFFF6D) {
				weaponName = "Assault Riffle";
			}
			else if (weaponHash == 0x83BF0278) {
				weaponName = "Carbine Riffle";
			}
			else if (weaponHash == 0xAF113F99) {
				weaponName = "Advanced Riffle";
			}
			else if (weaponHash == 0x9D07F764) {
				weaponName = "MG";
			}
			else if (weaponHash == 0x7FD62962) {
				weaponName = "Combat MG";
			}
			else if (weaponHash == 0x1D073A89) {
				weaponName = "Pump Shotgun";
			}
			else if (weaponHash == 0x7846A318) {
				weaponName = "Sawed-Off Shotgun";
			}
			else if (weaponHash == 0xE284C527) {
				weaponName = "Assault Shotgun";
			}
			else if (weaponHash == 0x9D61E50F) {
				weaponName = "Bullpup Shotgun";
			}
			else if (weaponHash == 0x3656C8C1) {
				weaponName = "Stun Gun";
			}
			else if (weaponHash == 0x05FC3C11) {
				weaponName = "Sniper Rifle";
			}
			else if (weaponHash == 0x0C472FE2) {
				weaponName = "Heavy Sniper";
			}
			else if (weaponHash == 0xA284510B) {
				weaponName = "Grenade Launcher";
			}
			else if (weaponHash == 0x4DD2DC56) {
				weaponName = "Smoke Grenade Launcher";
			}
			else if (weaponHash == 0xB1CA77B1) {
				weaponName = "RPG";
			}
			else if (weaponHash == 0x42BF8A85) {
				weaponName = "Minigun";
			}
			else if (weaponHash == 0x93E220BD) {
				weaponName = "Grenade";
			}
			else if (weaponHash == 0x2C3731D9) {
				weaponName = "Sticky Bomb";
			}
			else if (weaponHash == 0xFDBC8A50) {
				weaponName = "Smoke Grenade";
			}
			else if (weaponHash == 0xA0973D5E) {
				weaponName = "BZGas";
			}
			else if (weaponHash == 0x24B17070) {
				weaponName = "Molotov";
			}
			else if (weaponHash == 0x060EC506) {
				weaponName = "Fire Extinguisher";
			}
			else if (weaponHash == 0x34A67B97) {
				weaponName = "Petrol Can";
			}
			else if (weaponHash == 0xFDBADCED) {
				weaponName = "Digital scanner";
			}
			else if (weaponHash == 0x88C78EB7) {
				weaponName = "Briefcase";
			}
			else if (weaponHash == 0x23C9F95C) {
				weaponName = "Ball";
			}
			else if (weaponHash == 0x497FACC3) {
				weaponName = "Flare";
			}
			else if (weaponHash == 0xF9E6AA4B) {
				weaponName = "Bottle";
			}
			else if (weaponHash == 0x61012683) {
				weaponName = "Gusenberg";
			}
			else if (weaponHash == 0xC0A3098D) {
				weaponName = "Special Carabine";
			}
			else if (weaponHash == 0xD205520E) {
				weaponName = "Heavy Pistol";
			}
			else if (weaponHash == 0xBFD21232) {
				weaponName = "SNS Pistol";
			}
			else if (weaponHash == 0x7F229F94) {
				weaponName = "Bullpup Rifle";
			}
			else if (weaponHash == 0x92A27487) {
				weaponName = "Dagger";
			}
			else if (weaponHash == 0x083839C4) {
				weaponName = "Vintage Pistol";
			}
			else if (weaponHash == 0x7F7497E5) {
				weaponName = "Firework";
			}
			else if (weaponHash == 0xA89CB99E) {
				weaponName = "Musket";
			}
			else if (weaponHash == 0x3AABBBAA) {
				weaponName = "Heavy Shotgun";
			}
			else if (weaponHash == 0xC734385A) {
				weaponName = "Marksman Rifle";
			}
			else if (weaponHash == 0x63AB0442) {
				weaponName = "Homing Launcher";
			}
			else if (weaponHash == 0xAB564B93) {
				weaponName = "Proximity Mine";
			}
			else if (weaponHash == 0x787F0BB) {
				weaponName = "Snowball";
			}
			else if (weaponHash == 0x47757124) {
				weaponName = "Flare Gun";
			}
			else if (weaponHash == 0xE232C28C) {
				weaponName = "Garbage Bag";
			}
			else if (weaponHash == 0xD04C944D) {
				weaponName = "Handcuffs";
			}
			else if (weaponHash == 0x0A3D4D34) {
				weaponName = "Combat PDW";
			}
			else if (weaponHash == 0xDC4DB296) {
				weaponName = "Marksman Pistol";
			}
			else if (weaponHash == 0xD8DF3C3C) {
				weaponName = "Brass Knuckles";
			}
			else if (weaponHash == 0x6D544C99) {
				weaponName = "Railgun";
			}
			else if (weaponHash == 0xAF3696A1) {
			weaponName = "Up-N-Atomizer";
			}
			else if (weaponHash == 0x476BF155) {
			weaponName = "UnHoly Hellbringer";
			}
			else if (weaponHash == 0xB62D1F67) {
			weaponName = "WidowMaker";
			}
			else if (weaponHash == 2441047180) {
			weaponName = "Navy Revolver";
			}
			else if (weaponHash == 3126027122) {
			weaponName = "Hazardous Jerry Can";
			}
			else if (weaponHash == 727643628) {
			weaponName = "Ceramic Pistol";
			}
			else if (weaponHash == 94989220) {
			weaponName = "Military Shotgun";
			}
			else if (weaponHash == 1470379660) {
			weaponName = "Perico Pistol";
			}
			else if (weaponHash == 2636060646) {
			weaponName = "Military Rifle";
			}
			else {
				weaponName = "Unarmed";
			}
			Weapon << weaponName;
		}
		else Weapon << "Unarmed";

			int griefing, annoyingme, hate, offensiveLanguage, offensivetagplate, GameExploit, Exploits;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GRIEFING"), &griefing, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), &annoyingme, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VC_HATE"), &hate, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), &offensiveLanguage, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), &offensivetagplate, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), &GameExploit, 0);
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_EXPLOITS"), &Exploits, 0);
	std::string greifingreps = (std::string)"~q~Griefing Reports:~s~ " + valuebuffer(griefing);
	std::string haterps = (std::string)"~q~Hate Reports [Chat]:~s~ " + valuebuffer(hate);//
	std::string expreps = (std::string)"~q~Exploit Reports [Glitch]:~s~ " + valuebuffer(GameExploit);
	std::string gameexpreps = (std::string)"~q~Exploit Reports [Cheat]:~s~ " + valuebuffer(Exploits);//

	char vehhashed = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));

	 Ped ped1 = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
	 bool hasGodmode = PLAYER::GET_PLAYER_INVINCIBLE(ped1);
	int alpha = ENTITY::GET_ENTITY_ALPHA(ped1);
	 Hash player_model = ENTITY::GET_ENTITY_MODEL(ped1);
	 int rstardev = NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(ped1);
	 int visible = ENTITY::IS_ENTITY_VISIBLE(ped1);
	 std::string Vehiclehash = (std::string)"~q~Vehicle Hash:~s~ " + valuebuffer(vehhashed);
	 std::string ModelHash = (std::string)"~q~Ped Model Hash:~s~ " + valuebuffer(player_model);
	 std::string Alphaped = (std::string)"~q~Player Alpha:~s~ " + valuebuffer(alpha);
	 std::string Ishegod = (std::string)"~q~God Mode Value:~s~ " + valuebuffer(hasGodmode);
	 std::string RstarDevkss = (std::string)"~q~R* Dev Value:~s~ " + valuebuffer(rstardev);
	 std::string Invisible = (std::string)"~q~Visible Value:~s~ " + valuebuffer(visible);
	

		Menu::AddSmallTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		Menu::AddSmallInfo((char*)WantedLevel.str().c_str(), 0);
		Menu::AddSmallInfo((char*)Money.str().c_str(), 1);
		Menu::AddSmallInfo((char*)Bank.str().c_str(), 2);
		Menu::AddSmallInfo((char*)RP.str().c_str(), 3);
		Menu::AddSmallInfo((char*)Rank.str().c_str(), 4);
		Menu::AddSmallInfo((char*)Kills.str().c_str(), 5);
		Menu::AddSmallInfo((char*)Deaths.str().c_str(), 6);
		Menu::AddSmallInfo((char*)KD.str().c_str(), 7);
		Menu::AddSmallInfo((char*)Alive.str().c_str(), 8);
		Menu::AddSmallInfo((char*)Health.str().c_str(), 9);
		Menu::AddSmallInfo((char*)Armour.str().c_str(), 10);
		Menu::AddSmallInfo((char*)Weapon.str().c_str(), 11);
		Menu::AddSmallInfo((char*)IsInAVehicle.str().c_str(), 12);
		Menu::AddSmallInfo((char*)VehicleModel.str().c_str(), 13);
		Menu::AddSmallInfo((char*)Speed.str().c_str(), 14);
		Menu::AddSmallInfo(Coord_buf, 15);
        Menu::AddSmallInfo((char*)Street.str().c_str(), 16);
		Menu::AddSmallInfo((char*)Ridfinder.str().c_str(), 17);
		Menu::AddSmallInfo((char*)greifingreps.c_str(), 18);
		Menu::AddSmallInfo((char*)haterps.c_str(), 19);
		Menu::AddSmallInfo((char*)expreps.c_str(), 20);
		Menu::AddSmallInfo((char*)gameexpreps.c_str(), 21);
		Menu::AddSmallInfo((char*)Vehiclehash.c_str(), 22);
		Menu::AddSmallInfo((char*)ModelHash.c_str(), 23);
		Menu::AddSmallInfo((char*)Alphaped.c_str(), 24);
		Menu::AddSmallInfo((char*)Ishegod.c_str(), 25);
		Menu::AddSmallInfo((char*)RstarDevkss.c_str(), 26);
		Menu::AddSmallInfo((char*)Invisible.c_str(), 27);
		Menu::AddSmallInfo((char*)Ishegod.c_str(), 28);
	}

}

























/*

spoof level
globalHandle(1590446).At(PLAYER::PLAYER_ID(), 871).At(211).At(6).As<int>() = temp1;

spoof wallet money
globalHandle(1590446).At(PLAYER::PLAYER_ID(), 871).At(211).At(3).As<int>() = temp1;

spoof bank money
globalHandle(1590446).At(PLAYER::PLAYER_ID(), 871).At(211).At(56).As<int>() = temp1;

spoof KD
globalHandle(1590446).At(PLAYER::PLAYER_ID(), 871).At(211).At(26).As<int>() = temp1;

spoof kills
globalHandle(1590446).At(PLAYER::PLAYER_ID(), 871).At(211).At(28).As<int>() = temp1;


OFF RADAR 

globalHandle(2424073).At(1 + (PLAYER::PLAYER_ID() * 421)).At(203).As<int>() = 1;
	globalHandle(2437549).At(71).As<int>() = NETWORK::GET_NETWORK_TIME() + amount;


	RECOVERY
	Bool Stats
Code:
AWD_SCOPEOUT
AWD_CREWEDUP
AWD_MOVINGON
AWD_PROMOCAMP
AWD_GUNMAN
AWD_SMASHNGRAB
AWD_INPLAINSI
AWD_UNDETECTED
AWD_ALLROUND
AWD_ELITETHEIF
AWD_PRO
AWD_SUPPORTACT
AWD_SHAFTED
AWD_COLLECTOR
AWD_DEADEYE
AWD_PISTOLSATDAWN
AWD_TRAFFICAVOI
AWD_CANTCATCHBRA
AWD_WIZHARD
AWD_APEESCAPE
AWD_MONKEYKIND
AWD_AQUAAPE
AWD_KEEPFAITH
AWD_TRUELOVE
AWD_NEMESIS
AWD_FRIENDZONED
Int Stats
Code:
AWD_PREPARATION
AWD_ASLEEPONJOB
AWD_DAICASHCRAB
AWD_BIGBRO
AWD_SHARPSHOOTER
AWD_RACECHAMP
AWD_BATSWORD
AWD_COINPURSE
AWD_ASTROCHIMP
AWD_MASTERFUL




*/

	
