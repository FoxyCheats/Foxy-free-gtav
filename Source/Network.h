#pragma once
#include "stdafx.h"

namespace Network{

	void UpdateLoop();

	extern bool dropall;

	extern bool Liststyle;

	extern bool Foxyuser;

	extern bool Spoofmoney;

	extern bool Spoofkill;
	extern bool Spoofkd;


	//Money & Rp//
	extern bool burtonMoney;
	extern bool burtonrp;
	extern bool HeliMoney;
	extern bool Helirp;
	extern bool AirportMoney;
	extern bool Airportrp;
	extern bool easteregg2;
	extern bool EasterEgg1;


	void SetName(const std::string& name);

	void MainMenu();

	void ESPMenu();

	extern bool orbitalfucker;
	void orbitalfuckeR(bool toggle);

	void KickAll();

	void Players();

}

extern bool kickPlayer(int selectedPlayer, int type);