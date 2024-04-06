#pragma once

namespace Protections {

	void UpdateLoop();

	void MainMenu();

	extern bool Crash;
	extern bool Crashh;
	extern bool Swap1;
	void crash();
	void crashh();
	extern bool AntiCrash;
	void anticrash(bool toggle);

	void RequestControlOfid(Entity netid);
	void RequestControlOfid(DWORD netid);

	void see();
	void nee();
	void aa();

	void sw(bool toggle);
	
	extern bool reccontrolblocc;

	extern bool B;
	

	extern bool RockstarCheck;
	void RockstarAdminCheck(bool toggle);

	extern bool Kick;
	void kick(bool toggle);

	extern bool Crasherzz;
	void crasherzz(bool toggle);

	extern bool ExplosionProtection;
	void explosionprotection(bool toggle);
}

void Notifica(std::uintptr_t sourcePlayer, std::uintptr_t targetPlayer);