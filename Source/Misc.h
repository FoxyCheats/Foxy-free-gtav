#pragma once

void Weather();

namespace Misc 
{
	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int Bags;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	extern int TimePD9;
	extern int TimePD10;
	extern int TimePD11;
	extern int TimePD12;
	extern int TimePD13;
	extern int TimePD14;
	extern int Wave;
	extern bool ft;

	void UpdateLoop();

	void MiscMainSub();

	extern bool Hidehudtoggle;
	extern bool Sell;

	void killNearbyPeds();

	extern bool killpedsbool;
	void killpeds(bool loop);

	extern bool ExVeh;
	void exVeh(bool loop);

	extern bool RideAnimals;
	void rideanimal(bool loop);

	extern bool DeleteVeh;
	void deleteVeh(bool loop);

	extern bool HornVeh;
	void hornVeh(bool loop);

	extern bool FixVeh;
	void fixVeh(bool loop);

	extern bool BurstVeh;
	void burstVeh(bool loop);

	extern bool AS;
	void as(bool toggle);

	extern bool Apodev;
	void apodev(bool toggle);

	extern bool AirstrikeShower;
	void AirstrikehowerToggle(bool toggle);

	extern bool ZombieMode;
	void zombiemod(bool toggle);

}