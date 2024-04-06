#pragma once

extern float testt;

namespace Weap {

	void UpdateLoop();

	extern bool Bottrigger;

	extern bool gravegun;

	extern bool grav_target_locked1;
	extern bool grav_target_locked2;



	extern bool pedgun;

	void aGravityGun();

	extern bool somethinggun;

	extern int LPNPos1;
	void somethinggunn(char* model_one, char* model_two);
	/// <summary>
	/// Offsets (External)
	/// </summary>
	extern bool bulletforce;
	extern bool bulletforcePed;
	extern bool bulletforceHeli;
	extern bool bulletforceStreetVehicle;
	extern bool bulletforceReload;
	extern bool bulletforceRecoil;

	/// <summary>
	/// Normal Option
	/// </summary>

	extern int AutoShootListPos;
	extern int ModeListPos;
	extern int TargetListPos;
	extern int MultiBulletsBool;
	extern int OriginListPos;
	extern int shootDelayInt;
	extern int SelectListPos;



	extern int Amount;

	extern bool ROPEGUN;
	void ropegun(bool toggle);

	extern bool TeleyGun;
	void teleygun(bool toggle);

	extern char* ModelThing2;

	extern bool laser;

	extern char* ModelThing;

	extern bool InfiniteAmmo;
	void infiniteammo(bool toggle);

	extern bool ExplosiveAmmo;
	void explosiveammo(bool toggle);

	extern bool Gravity;
	void GravityGun(bool toggle);

	extern bool RpG;
	void rpg(bool toggle);

	extern bool RPG2;
	void rpg2(bool toggle);

	extern int amountset;
	extern bool MoneyGun;
	void moneygun(bool toggle);

	extern bool MoneyGun;
	void moneygun(bool toggle);

	extern bool FireAmmo;
	void fireammo(bool toggle);

	extern bool Flametrow;
	void flametrow(bool toggle);


	extern bool Drivegun;
	void drivegun(bool toggle);

	extern int TimePD;

	extern bool RpGun;
	void rpgun(bool toggle);

	extern bool TPGun;
	void tpgun(bool toggle);

	extern bool RapidFire;
	void rapidfire(bool toggle);

	extern bool AirstrikeGun;
	void airstrikeGun(bool toggle);

	extern bool Onehit;
	void onehit(bool toggle);

	extern bool DeleteGun;
	void deletegun(bool toggle);

	extern bool Aimbot;
	void aimbot(bool toggle);

	extern bool Aimbot2;
	void aimbot2(bool toggle);

	extern bool NoRecoil;
	void noRecoil(bool toggle);

	extern bool WaterShoot;
	void ShootWater(bool toggle);


	extern bool GuidedMissileInsight;
	void guidedmissileinsight(bool toggle);


	extern bool FireShoot;
	void ShootFire(bool toggle);

	extern bool GravityGunf;
	void gravityGun(bool toggle);

	extern bool PedGun;
	void pedGun(bool toggle);

	extern bool RainbowG;
	void Rainbow(bool toggle);

	extern bool ShootCars;
	void shootCars(bool toggle);

	extern bool ShootCars1;
	void shootCars1(bool toggle);

	extern bool ShootCars2;
	void shootCars2(bool toggle);

	extern bool ShootCars3;
	void shootCars3(bool toggle);

	extern bool ShootCars4;
	void shootCars4(bool toggle);

	extern bool ShootCars5;
	void shootCars5(bool toggle);

	void maingunmenu();
	void marktwoguns();
	void heavyguns();
	void sniperrifles();
	void rifes();
	void handguns();
	void shotgun();
	void machineguns();
	void new_DLC_foursix();
	void Tints();
	void thorwable();
	void meleee();
	void knuckleduster();
	void switchblade();
	void Raygun();
	void RAYCarbine();
	void RAYPistol();
	//mk 2 tintis
	void mk2tints();
	// marksman rifle
	void MarksmanRifleMkII();
	void camos_m();
	void muzzle_m();
	void barrel_m();
	void attachment_m();
	void scope_m();
	void magazine_m();
	//pump shoutgun mk2
	void pump_Shotgun_Mk_II();
	void muzzle_sg();
	void camos_sg();
	void attachment_sg();
	void scope_sg();
	void magazine_sg();
	//bullpup rifle mk
	void bullpup_Rifle_Mk_II();
	void camos_b();
	void muzzle_b();
	void barrel_b();
	void attachment_b();
	void scope_b();
	void magazine_b();
	//Special_Carbine_Mk_II
	void special_Carbine_Mk_II();
	void camos_sc();
	void muzzle_sc();
	void barrel_sc();
	void attachment_sc();
	void scope_sc();
	void magazine_sc();
	//revolver
	void revolver_Mk_II();
	void camos_r();
	void attachment_r();
	void magazine_r();
	// sns pistol
	void sNS_Pistol_Mk_II();
	void camos_sn();
	void attachment_sn();
	void magazine_sn();
	//heavy sniper
	void heavy_Sniper_Mk_II();
	void camos_hs();
	void muzzle_hs();
	void barrel_hs();
	void attachment_hs();
	void scope_hs();
	void magazine_hs();
	// Combat MG MK 2
	void combat_MG_Mk_II();
	void camos_mg();
	void muzzle_mg();
	void barrel_mg();
	void attachment_mg();
	void scope_mg();
	void magazine_mg();
	// carbine rifle mk 2
	void carbine_Rifle_Mk_II();
	void camos_c();
	void muzzle_c();
	void barrel_c();
	void attachment_c();
	void scope_c();
	void magazine_c();
	//AR MK2
	void assault_Rifle_Mk_II();
	void camos_a();
	void muzzle_a();
	void barrel_a();
	void attachment_a();
	void scope_a();
	void magazine_a();
	//SMG MK2
	void sMG_Mk_II();
	void camos_s();
	void muzzle_s();
	void barrel_s();
	void attachment_s();
	void scope_s();
	void magazine_s();
	// MK2 PISTOL
	void mK2_Pistol();
	void camos_p();
	void attachment_p();
	void magazine_p();
	//pistols
	void pistol();
	void marksmanPistol();
	void revolver();
	void Vintage();
	void mACHINE();
	void App();
	void call();
	void snss();
	void Combat();
	void HEavy();
	void flareGun();
	void stunGun();
	//Shot Guns
	void autoshotgun();
	void sawnoffShotgun();
	void doubleBarrelShotgun();
	void HeavyshOtgun();
	void bullpupShotgun();
	void assaultShotgun();
	void PumP();
	void musket();
	//Sub-Guns
	void gusenberg();
	void assultSMG();
	void microSMG();
	void ssmg();
	void combatPDW();
	void combatMG();
	void MGg();
	//AR
	void Bullpuprifle();//MiliTaryrifle
	void Combatsg();
	void Bullpupriflev2();
	void Militaryrifle();
	void Specialcarbine();
	void Advancedrifle();
	void Carbinerifle();
	void assaultRifle();
	void Compactrifle();
	//Sinpers
	void Marksmanrifle();
	void spp();
	void Heavysniper();
	//Heavy Guns
	void RPGg();
	void MinigunN();
	void GrenadeLauncherR();
	void FireworkK();
	void HomingLauncherr();
	void GrenadeLauncherSmokee();
	void CompactLauncherr();
	void Railgunn();


}
