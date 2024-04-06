#pragma once

namespace Other
{

	//Outfits
	void ResetAppearance();
	void changeAppearance(char* family, int model, int texture);
	
	
	void spawn_vehicle(char* toSpawn);
	void CagePlayer(Ped ped);

	void TPto(Vector3 Coords);

	void set_vehicle_max_upgrades(Vehicle vehicle, bool upgradeIt, bool invincible, INT8 plateType, std::string plateText, bool neonIt, UINT8 NeonR, UINT8 NeonG, UINT8 NeonB, INT16 prim_col_index, INT16 sec_col_index);

}