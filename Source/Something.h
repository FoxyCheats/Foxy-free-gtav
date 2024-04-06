#pragma once

namespace Reee {

	extern bool spawnincar;
	extern bool vehSpawnFade;
	extern bool spawnmaxed;
	extern bool skyplane;
	extern bool Vehinfo;
	extern bool spbypass;
	extern bool GiftVehicle;
	extern bool SetGodMode;
	extern bool LicensePlate;
	extern bool RandomModdedColor;
	void spawn_vehicle(char* toSpawn);
	void BypassOnlineVehicleKick(Vehicle vehicle);

	void TPto(Vector3 Coords);

	void PlaceObjectByHash(Hash hash, float x, float y, float z, float pitch, float roll, float yaw, float heading, int id);

	void previewCar(char* carname);
	void previewmodelchanger(char* modelname);

	void SpawnVehicle(char* toSpawn);


	void GiftVehicle2(char* toSpawn);
}