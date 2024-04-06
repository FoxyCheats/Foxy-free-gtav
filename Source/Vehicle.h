#pragma once

namespace Veh {

	extern bool cargod;

	void UpdateLoop();

	void Multi();

	extern bool Boosttt;

	extern int Boostttt;

	extern bool Boost;

	extern bool HornBoost;
	void hornboost(bool toggle);

	void spawn_vehicle(char* toSpawn);

	void CustomWheelPTFX1(char* streamName, char* PTFXName);
	void CustomWheelPTFX2(char* streamName, char* PTFXName);
	void CustomWheelPTFX3(char* streamName, char* PTFXName);
	void CustomWheelPTFX4(char* streamName, char* PTFXName);

	extern int EffectsChar;

	extern char* PTFXChar[];

	extern int guntype;
	extern char* GlowThing;
	extern char* GlowThing2;
	extern char* GlowThing3;

	extern bool ToggleGlow;
	extern bool Arm;
	extern bool Arm2;
	extern bool Foot;
	extern bool Foot2;

	extern bool Rainbowcar;
	void rainbowcar(bool toggle);

	extern bool FlyCar;
	void Flycar(bool toggle);

	extern bool CR;
	void cr(bool toggle);

	extern bool TorqueMultiplier;
	void torquemultiplier(bool toogle);

	extern bool FrictionMultiplier;
	void frictionmultiplier(bool toggle);
	
	extern bool Suspention;
	void suspention(bool toggle);


	extern bool PowerMultiplier;
	void powermultiplier(bool toogle);

	extern bool LightMultiplier;
	void lightmultiplier(bool toogle);

	extern bool SuspentionMultiplier;
	void suspentionmultiplier(bool toogle);


	extern bool SuspentionMultiplier2;
	void suspentionmultiplier2(bool toogle);


	extern bool SuspentionMultiplier3;
	void suspentionmultiplier3(bool toogle);

	extern bool MassMultiplier;
	void massmultiplier(bool toogle);


	extern bool BuoyancyMultiplier;
	void buoyancymultiplier(bool toogle);


	extern float Speed;
	extern bool Flying;
	extern bool SportMode;
	extern bool BeyBlade;
	void Beyblad();
	void Sportmod();
	void Flyingg();

	extern bool vehlaser;

	extern bool DriveWater;
	void driveWater(bool toggle);

	extern bool bikeNoFall;
	void bikenofall(bool toggle);

	extern bool DV;
	void dv(bool toggle);

	extern bool InstantBreak;
	void instantBreak(bool toggle);

	extern bool Shootrpg;
	void shootrpg(bool toggle);

	extern bool Shootrpg1;
	void shootrpg1(bool toggle);

	extern bool Shootrpg2;
	void shootrpg2(bool toggle);

	extern bool Shootrpg3;
	void shootrpg3(bool toggle);

	extern bool Shootrpg4;
	void shootrpg4(bool toggle);

	extern bool Shootrpg5;
	void shootrpg5(bool toggle);

	extern bool Shootrpg6;
	void shootrpg6(bool toggle);

	extern bool Shootrpg7;
	void shootrpg7(bool toggle);

	extern bool Shootrpg8;
	void shootrpg8(bool toggle);

	void CustomVehicleWeapon(char* weaponbullet);

	extern bool P;
	void px(bool toggle);

	extern bool P1;
	void px1(bool toggle);

	extern bool P2;
	void px2(bool toggle);

	extern bool P3;
	void px3(bool toggle);

	extern bool P4;
	void px4(bool toggle);

	extern bool P5;
	void px5(bool toggle);

	extern bool P6;
	void px6(bool toggle);

	void CarGunMain();

	void vp();

	void Acro();

	void Boostt();
}
