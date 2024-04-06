#pragma once

namespace SPlayer
{
	void UpdateLoop();

	extern int TimePD1;
	extern int TimePD2;
	extern int CashAmount;
	extern int RpAmount;
	extern int CashInt;
	extern int HeadlightInt;
	extern int CashHeight;
	extern int CashAmount2;
	extern int CashHeight2;
	extern int CashInt2;
	extern int RpInt2;
	extern int TimepD3;
	extern int TimePD3;
	extern int TimePD4;

	static char* marker_name;
	extern int intmarker;
	extern int intvisibility;
	extern int intdirx;
	extern int intdiry;
	extern int intdirz;
	extern int introtx;
	extern int introty;
	extern int introtz;
	extern int intscax;
	extern int intscay;
	extern int intscaz;

	extern int TimepD2;
	extern int CashAmount2;
	extern int RpAmount2;
	extern int Rpint;
	extern int Rphieght;
	extern int Cardhieght;

	extern bool Vehicle_Atach;
	extern bool Shootmoney;
	extern bool Shootcars;
	extern bool Shootairstrike;
	extern bool Deletegunr;
	extern bool PedGunv2;
	extern bool FireGun;
	extern bool WaterGun;
	extern int asset;
	extern int exptypeonline;
	extern bool Shootexp;
	extern bool Force;
	extern bool SpectateBool;
	extern bool Dropall;
	extern int Allamount;
	extern int DropDelay;
	extern bool Shootcarrs;
	extern bool RainbowHeadlight;
	extern bool Shootcarrrs;
	extern bool ShootRp;
	extern bool Remotefly;
	extern bool Insanegun;


	extern bool givecarr1;
	

	extern char* BodyguardModel1;

	void OnlineplayerWepmods();

	void Givecar();

	extern bool Jumpplayer;
	extern bool Ragdollplayer;
	extern bool Freezeplayer;
	extern bool fpscrash;
	extern bool fpscrash2;
	extern bool poolcrash2;

	void DropMoney(Ped player);
	extern bool Moneydrop;
	void moneydrop(bool toggle);

	extern bool Moneydrop2;
	void moneydrop2(bool toggle);

	extern bool Rpdrop2;
	void rpdrop2(bool toggle);

	extern bool Carddrop;
	void carddrop(bool toggle);

	extern bool mf;
	void Mf(bool toggle);

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	extern bool mf1;
	void Mf1(bool toggle);
	void RequestControlOfid(Entity netid);
	
	void boosttoggle();

	extern bool ft;
	void Freezetoggle(bool toggle);

	extern bool CRASHV3;
	void crashv3(bool toggle);

	extern bool ft1234;
	void Freezetoggle1234(bool toggle);

	extern bool Rpdrop;
	void rpdrop(bool toggle);


	extern bool mf11234;
	void Mf11234(bool toggle);
	void RequestControlOfid(Entity netid);

	extern bool Fireloop;
	void fireloop(bool toggle);

	extern bool Waterloop;
	void waterloop(bool toggle);

	void kickfromveh();

	void Kick(Player s);
	void LoadPlayerInfo(char* playerName, Player p);

	extern char* BodyguardModel24;
	extern char* WeaponThing24;
	extern char* BodyguardModel4;
	extern char* WeaponThing4;
	
	extern Hash weaponsList[];
}
extern bool loadinfo;