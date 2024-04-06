/*
* This was generated in 2021 By Foxy and is outdated please do not try to use them 
*/


/*OFFSETS*/

//Offset from WORLD
#define OFFSET_PLAYER 0x8 //CPedFactory, m_local_ped

//Offset from ENTITY
#define OFFSET_ENTITY_POSBASE 0x30 //rage::fwEntity, m_navigation
#define OFFSET_ENTITY_POSBASE_POS_X 0x20 //CNavigation, m_transformation_matrix.rows[3].x
#define OFFSET_ENTITY_POSBASE_POS_Y 0x24 //CNavigation, m_transformation_matrix.rows[3].y
#define OFFSET_ENTITY_POSBASE_POS_Z 0x28 //CNavigation, m_transformation_matrix.rows[3].z
#define OFFSET_ENTITY_POS 0x60 //rage::fwEntity, m_transformation_matrix.rows[3]
#define OFFSET_ENTITY_HEALTH 0x280 //rage::CPhysical, m_health
#define OFFSET_ENTITY_HEALTH_MAX 0x284 //rage::CPhysical, m_maxhealth
#define OFFSET_ENTITY_ATTACKER 0x2A8 //CPed, m_attackers
#define OFFSET_ENTITY_GOD 0x188 //rage::CPhysical, m_damage_bits + 1


#define OFFSET_RID 0xC8 //rage::rlGamerInfo, m_unk_gamer_handle.m_rockstar_id

//Offset from PED
#define OFFSET_PLAYER_MONEY 0x1614 //CPed, m_cash
#define OFFSET_PLAYER_ARMOR 0x150C //CPed, m_armour
#define OFFSET_PLAYER_INFO 0x10A8 //CPed, m_player_info
#define OFFSET_PLAYER_INFO_WANTED_CAN_CHANGE 0x78C //CPlayerInfo, m_wanted_can_change
#define OFFSET_PLAYER_INFO_WANTED 0x8D8 //CPlayerInfo, m_wanted_level
#define OFFSET_PLAYER_WANTED_DISPLAY 0x8DC //CPlayerInfo, m_wanted_level_display
#define OFFSET_PLAYER_INFO_RUN_SPD 0xD40 //CPlayerInfo, m_run_speed
#define OFFSET_PLAYER_INFO_WALK_SPD 0x18C //CPlayerInfo, m_walk_speed
#define OFFSET_PLAYER_INFO_SWIM_SPD 0x1C8 //CPlayerInfo, m_swim_speed
#define OFFSET_PLAYER_INFO_FRAMEFLAGS 0x270 //CPlayerInfo, m_frame_flags
#define OFFSET_PLAYER_INFO_STAMINA 0xD44 //CPlayerInfo, m_stamina
#define OFFSET_PLAYER_INFO_STAMINA_REGEN 0xD48 //CPlayerInfo, m_stamina_regen
#define OFFSET_PLAYER_NAME 0xFC //CPlayerInfo, m_gamer_info.m_name
#define OFFSET_PLAYER_RAGDOLL 0x1098 //CPed, m_ped_type
#define OFFSET_PLAYER_SEATBELT 0x143C //CPed, m_ped_type
#define OFFSET_PLAYER_INVEHICLE 0x144B //CPed, m_ped_task_flag
#define OFFSET_PLAYER_SUPERJUMP OFFSET_PLAYER_INFO_FRAMEFLAGS //CPlayerInfo, m_frame_flags
#define OFFSET_PLAYER_INVEHICLE 0x144B //CPed, m_ped_task_flag
#define OFFSET_PLAYER_VEHICLE_DAMAGE_MP 0xD6C //CPlayerInfo, m_melee_damage_mult
#define OFFSET_PLAYER_SUPER_PUNCH OFFSET_PLAYER_VEHICLE_DAMAGE_MP //CPlayerInfo, m_melee_damage_mult
#define OFFSET_PLAYER_WATER_PROOF 0x188 //rage::CPhysical, m_damage_bits
#define OFFSET_FRAME_FLAGS OFFSET_PLAYER_INFO_FRAMEFLAGS //CPlayerInfo, m_frame_flags

#define OFFSET_PED_INTELLIGENCE 0x10A0 //CPed, m_ped_intelligence
#define OFFSET_PED_OXYGEN_TIME 0x278 //CPedIntelligence, m_oxygen_time

//Offset from VEHICLE
#define OFFSET_PLAYER_VEHICLE 0xD10 //CPed, m_vehicle
#define OFFSET_VEHICLE_HEALTH 0x820 //CVehicle, m_body_health
#define OFFSET_VEHICLE_GRAVITY 0xC3C //CVehicle, m_gravity
#define OFFSET_VEHICLE_BULLETPROOF_TIRES 0x923 //CVehicle, m_tyres_can_burst
#define OFFSET_VEHICLE_HANDLING 0x918 //CVehicle, m_handling_data
#define OFFSET_VEHICLE_HANDLING_ACCELERATION 0x4C //CHandlingData, m_acceleration
#define OFFSET_VEHICLE_HANDLING_BRAKEFORCE 0x6C //CHandlingData, m_brake_force
#define OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN 0x90 //CHandlingData, m_traction_curve_min
#define OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MAX 0x88 //CHandlingData, m_traction_curve_max
#define OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER 0xF8 //CHandlingData, m_deformation_mult
#define OFFSET_VEHICLE_HANDLING_COLISION_DAMAGE_MP 0xF0 //CHandlingData, m_collision_damage_mult
#define OFFSET_VEHICLE_HANDLING_UPSHIFT 0x58 //CHandlingData, m_upshift
#define OFFSET_VEHICLE_HANDLING_SUSPENSION_HEIGHT 0xD0 //CHandlingData, m_suspension_raise
#define OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE 0xBC //CHandlingData, m_suspension_force
#define OFFSET_VEHICLE_HEADLIGHT_COLOR 0x406 //CVehicle, m_headlight_color
#define OFFSET_VEHICLE_MASS 0xC //CHandlingData, m_mass
#define OFFSET_VEHICLE_INITIAL_DRIVE_FORCE 0x60 //CHandlingData, m_initial_drive_force
#define OFFSET_VEHICLE_DRIVE_INITIAL 0x54 //CHandlingData, m_drive_inertia
#define OFFSET_VEHICLE_THRUST 0x390 //CVehicle, m_jump_boost_charge
#define OFFSET_VEHICLE_BOUYANCY 0x40 //CHandlingData, m_buoyancy
#define OFFSET_VEHICLE_HANDBRAKE_FORCE 0x7C //CHandlingData, m_handbrake_force
#define OFFSET_VEHICLE_DOWNFORCE 0x14 //CHandlingData, m_downforce_multiplier
#define OFFSET_VEHICLE_ROCKET 0x304 //CVehicle, m_rocket_recharge_speed
#define OFFSET_VEHICLE_ROCKET_MK2 0x308 //CVehicle, m_mkii_rocket_recharge_speed
#define OFFSET_VEHICLE_WHEEL_SCALE_FRONT 0x048C //Cvehicle, Wheel_size_front
#define OFFSET_VEHICLE_WHEEL_SCALE_REAR 0x0490//Cvehicle, Wheel_size_rear

//Offset from WEAPON
#define OFFSET_WEAPON_SHOT_TIME 0x13C //CWeaponInfo, m_time_between_shots
#define OFFSET_WEAPON_MANAGER 0x10B8 //CPed, m_weapon_manager
#define OFFSET_WEAPON_CURRENT 0x20 //CPedWeaponManager, m_weapon_info
#define OFFSET_WEAPON_AMMOINFO 0x60 //CWeaponInfo, m_ammo_info
#define OFFSET_WEAPON_AMMOINFO_MAX 0x20 //CWeaponInfo, m_ammo_max
#define OFFSET_WEAPON_AMMOINFO_CURAMMO 0x18 //CPedWeaponManager, m_selected_weapon_hash
#define OFFSET_WEAPON_SPREAD 0x74 //CWeaponInfo, m_accuracy_spread
#define OFFSET_WEAPON_BULLET_DMG 0xB0 //CWeaponInfo, m_damage
#define OFFSET_WEAPON_RECOIL 0x2F0 //CWeaponInfo, m_recoil_shake_amplitude
#define OFFSET_WEAPON_MODEL_HASH 0x10 //CItemInfo, m_name
#define OFFSET_WEAPON_NAME_HASH 0x10 //CItemInfo, m_name
#define OFFSET_WEAPON_RELOAD_VEHICLE 0x130 //CWeaponInfo, m_vehicle_reload_time
#define OFFSET_WEAPON_RANGE 0x28C //CWeaponInfo, m_weapon_range
#define OFFSET_WEAPON_SPINUP 0x144 //CWeaponInfo, m_spinup_time
#define OFFSET_WEAPON_SPIN 0x148 //CWeaponInfo, m_spin_time
#define OFFSET_WEAPON_BULLET_BATCH 0x120 //CWeaponInfo, m_bullets_in_batch
#define OFFSET_WEAPON_MUZZLE_VELOCITY 0xD8 //CWeaponInfo, m_force
#define OFFSET_WEAPON_RELOAD_SPEED 0x12C //CWeaponInfo, m_reload_time_sp
#define OFFSET_WEAPON_RELOAD_MULTIPLY 0x134 //CWeaponInfo, m_anim_reload_time


/*

//offset from WORLD
#define OFFSET_PLAYER					0x08			//playerbase
#define OFFSET_NET_PLAYER				0x1C8

//entity offsets
#define OFFSET_ENTITY_POSBASE			0x30			//base of a structure that contains entity coords
#define	OFFSET_ENTITY_POSBASE_COS		0x20
#define	OFFSET_ENTITY_POSBASE_SIN		0x30
#define OFFSET_ENTITY_POSBASE_POS		0x50			//vector3
#define OFFSET_ENTITY_POS				0x90			//vector3
#define OFFSET_ENTITY_GOD				0x189			//godmode; on = 1, off = 0; byte
#define OFFSET_ENTITY_HEALTH			0x280			//entity health (except for vehicles); float cur, float max
#define OFFSET_ENTITY_HEALTH_MAX		0x2A0			//they moved this away from curHealth in 1.36 :(
#define OFFSET_ENTITY_ATTACKER			0x2A8			//base to a list of the last 3 entities that attacked the current entity

//player (entity) offsets
#define OFFSET_PLAYER_VEHICLE					0xD30			//ptr to last used vehicle
#define OFFSET_NET_PLAYER_INFO					0xA8
#define OFFSET_PLAYER_INFO						0x10C8			//playerInfo struct
#define OFFSET_PLAYER_INFO_NAME					0x84
#define OFFSET_PLAYER_INFO_SWIM_SPD				0x150			//swim speed; def 1; float
#define	OFFSET_PLAYER_INFO_RUN_SPD				0xCF0			//run speed; def 1; float
#define OFFSET_PLAYER_INFO_FRAMEFLAGS			0x1F9			//frame flags; DWORD
#define OFFSET_PLAYER_INFO_WANTED_CAN_CHANGE	0x71C			//fWantedCanChange
#define OFFSET_PLAYER_INFO_NPC_IGNORE			0x850			//npc ignore; DWORD; everyone = 0x450000;
#define OFFSET_PLAYER_INFO_WANTED				0x868			//wanted level; DWORD
#define OFFSET_PLAYER_INFO_STAMINA				0xCD4			//fStamina, fStaminaMax
#define OFFSET_PLAYER_RAGDOLL					0x10B8			//byte; CPed.noRagdoll: 0x20 = off; 0x00/0x01 = on
#define OFFSET_PLAYER_SEATBELT					0xC00			//byte; CPed.seatBelt: 0xC8 = off; 0xC9 = on
#define OFFSET_PLAYER_INVEHICLE					0x1477
#define OFFSET_PLAYER_ARMOR						0x14E0			//armour
#define OFFSET_PLAYER_WATER_PROOF				0x188			//water proof; DWORD; +0x1000000 = on
#define OFFSET_PLAYER_VEHICLE_DAMAGE_MP			0xCFC			//super punck/kick;float;

//vehicle offsets
#define OFFSET_VEHICLE_HEALTH						0x908			//vehicle health; 0.f-1000.f
#define	OFFSET_VEHICLE_HEALTH2						0x844			//vehicle health2; 0.f-1000.f
#define OFFSET_VEHICLE_HANDLING						0x938
#define OFFSET_VEHICLE_HANDLING_MASS				0xC				//fMass
#define OFFSET_VEHICLE_HANDLING_BUOYANCY			0x40			//fBuoyancy
#define OFFSET_VEHICLE_HANDLING_ACCELERATION		0x4C
#define OFFSET_VEHICLE_HANDLING_UPSHIFT				0x58
#define OFFSET_VEHICLE_HANDLING_DOWNSHIFT			0x5C
#define OFFSET_VEHICLE_HANDLING_BRAKEFORCE			0x6C
#define OFFSET_VEHICLE_HANDLING_HANDBRAKEFORCE		0x7C			//fHandbrakeForce
#define OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN	0x90			//fTractionCurveMin
#define OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE	0xBC			//fSuspensionForce
#define OFFSET_VEHICLE_HANDLING_SUSPENSION_HEIGH	0xD0			//fSuspensionHeight
#define OFFSET_VEHICLE_HANDLING_COLISION_DAMAGE_MP	0xF0			//fColisionDamageMult
#define OFFSET_VEHICLE_HANDLING_WEAPON_DAMAGE_MP	0xF4			//fWeaponDamageMult
#define OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER	0xF8			//fDeformationDamageMult
#define OFFSET_VEHICLE_HANDLING_ENGINE_DAMAGE_MP	0xFC			//fEngineDamageMult
#define OFFSET_VEHICLE_BULLETPROOF_TIRES			0x943			//btBulletproofTires; (btBulletproofTires & 0x20) ? true : false
#define OFFSET_VEHICLE_GRAVITY						0xC5C			//fGravity
#define OFFSET_VEHICLE_BOOST						0x320			//fBoost
#define OFFSET_VEHICLE_RECHARGE_SPEED				0x324			//fRocketRechargeSpeed
#define OFFSET_VEHICLE_MISSLES						0x1280			//btVehicleMissles
#define OFFSET_VEHICLE_BOMBS						0x1294			//btAircraftBombs
#define OFFSET_VEHICLE_COUNTERMEASURES				0x1298			//btAircraftCountermeasures
#define OFFSET_VEHICLE_MK2_MISSLES					0x1284			//btOppressorMK2Misseles
#define OFFSET_VEHICLE_TAMPA_MISSLES				0x127C			//btTampaMissles
#define	OFFSET_VEHICLE_CUSTOM						0x48
#define	OFFSET_VEHICLE_CUSTOM_EMS					0x3D6			//btEngineManagementSystem; 0x3 = max
#define	OFFSET_VEHICLE_CUSTOM_BRAKES				0x3D7			//btBrakes; 0x6 = max
#define	OFFSET_VEHICLE_CUSTOM_TRANSMISSION			0x3D8			//btTransmission; 0x8 = max
#define	OFFSET_VEHICLE_CUSTOM_SUSPENSION			0x3DA			//btSuspension; 0x1B = max
#define	OFFSET_VEHICLE_CUSTOM_ARMOR					0x3DB			//btArmor; 0x1B = max
#define	OFFSET_VEHICLE_CUSTOM_TURBO_TUNING			0x3DD			//btTurboTuning; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHT_R			0x3A2			//btNeonLightRed
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHT_G			0x3A1			//btNeonLightGreen
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHT_B			0x3A0			//btNeonLightBlue
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHTS_L			0x402			//btNeonLightLeft; 0x0 = off; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHTS_R			0x403			//btNeonLightRight; 0x0 = off; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHTS_F			0x404			//btNeonLightFront; 0x0 = off; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_NEON_LIGHTS_B			0x405			//btNeonLightBack; 0x0 = off; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_TYRE_SMOKE			0x3DF			//btTyreSmoke; 0x1 = on
#define	OFFSET_VEHICLE_CUSTOM_TYRE_SMOKE_R			0x3FC			//btTyreSmokeRed
#define	OFFSET_VEHICLE_CUSTOM_TYRE_SMOKE_G			0x3FD			//btTyreSmokeGreen
#define	OFFSET_VEHICLE_CUSTOM_TYRE_SMOKE_B			0x3FE			//btTyreSmokeBlue
#define	OFFSET_VEHICLE_CUSTOM_LIMO_WINDOWS			0x3FF			//btLimoWindows; 0x1 = on

//weapon offsets
#define OFFSET_WEAPON_MANAGER			0x10D8			//from playerbase
#define OFFSET_WEAPON_CURRENT			0x20			//from weapon manager
#define OFFSET_WEAPON_AMMOINFO			0x60			//from weaponbase
#define OFFSET_WEAPON_AMMOINFO_MAX		0x28			//ammoinfo
#define OFFSET_WEAPON_AMMOINFO_CUR_1	0x08			//ptr lvl 1, ptr 1
#define OFFSET_WEAPON_AMMOINFO_CUR_2	0x00			//ptr tr lvl 2, ptr 1
#define OFFSET_WEAPON_AMMOINFO_CURAMMO	0x18			//offset to cur ammo
#define OFFSET_WEAPON_AMMOINFO_TYPE		0x0C			//offset to projectile type?
#define OFFSET_WEAPON_SPREAD			0x7C			//float set to 0
#define OFFSET_WEAPON_BULLET_DMG		0xBC			//float times 10 (so when 0, it will stay 0)
#define OFFSET_WEAPON_RELOAD_MULTIPLIER	0x134			//float times 10
#define OFFSET_WEAPON_RECOIL			0x2F4			//float set to 0
#define OFFSET_WEAPON_MODEL_HASH		0x14
#define OFFSET_WEAPON_NAME_HASH			0x10
#define OFFSET_WEAPON_RELOAD_VEHICLE	0x130
#define OFFSET_WEAPON_RANGE				0x28C
#define OFFSET_WEAPON_SPINUP			0x144
#define OFFSET_WEAPON_SPIN				0x148
#define OFFSET_WEAPON_BULLET_BATCH		0x124			//dwBulletInBatch
#define OFFSET_WEAPON_MUZZLE_VELOCITY	0x11C			//fMuzzleVelocity
#define OFFSET_WEAPON_IMPACT_TYPE		0x20			//dwImpactType; 1: Fists,3; Bullets,5: Explosives
#define OFFSET_WEAPON_IMPACT_EXPLOSION	0x24			//dwImpactExplosion
#define OFFSET_WEAPON_PENETRATION		0x110			//fPenetration
#define OFFSET_WEAPON_FORCE_ON_PED		0xDC			//fForceOnPed
#define OFFSET_WEAPON_FORCE_ON_VEHICLE	0xE0			//fForceOnVehicle(Bullet Mass)
#define OFFSET_WEAPON_FORCE_ON_HELI		0xE4			//fForceOnHeli


//tunable offsets
#define OFFSET_TUNABLE_RP_MULTIPLIER			0x10
#define OFFSET_TUNABLE_AP_MULTIPLIER			0x30F80
#define OFFSET_TUNABLE_MIN_MISSION_PAYOUT		0x4BC8			//fMinMissionPayout
#define OFFSET_TUNABLE_ANTI_IDLE_KICK1			0x2C0			//AFK;DWORD;2000000000 = Anti idle kick
#define OFFSET_TUNABLE_ANTI_IDLE_KICK2			0x2C8
#define OFFSET_TUNABLE_ANTI_IDLE_KICK3			0x2D0
#define OFFSET_TUNABLE_ANTI_IDLE_KICK4			0x2D8
#define OFFSET_TUNABLE_ORBITAL_CANNON_COOLDOWN	0x2C188			//OrbitalCannonCooldown;DWORD
#define OFFSET_TUNABLE_BUNKER_RESEARCH			0x29BB8			//UnlockAllBunkerResearch;DWORD


#define OFFSET_ATTACKER_DISTANCE		0x18			//changed to 0x18, from 0x10

//replay interface offsets
#define OFFSET_REPLAY_PED_INTERFACE			0x18
#define OFFSET_REPLAY_PICKUP_INTERFACE		0x20
#define OFFSET_INTERFACE_LIST				0x100
#define OFFSET_INTERFACE_CUR_NUMS			0x110
#define OFFSET_REPLAY_PICKUP_HASH			0x488

//unk model
#define OFFSET_MODEL_HASH		0x2640

//globals
#define GLOBAL_TUNEABLES		    262145
#define GLOBAL_VEHICLE_HASH		    2460715
#define GLOBAL_MERRYWEATHER		    2537071
#define GLOBAL_BLOCK_SCRIPT_EVENTS	1391799
#define GLOBAL_BUSINESS			    1590535

//feature indexing
#define FEATURE_P_GOD				0x00
#define FEATURE_P_NEVERWANTED		0x01
#define FEATURE_P_ANTINPC			0x02
#define FEATURE_V_GOD				0x03
#define FEATURE_W_SPREAD			0x04
#define FEATURE_W_RECOIL			0x05
#define FEATURE_W_RELOAD			0x06
#define FEATURE_W_DAMAGE			0x07
#define FEATURE_W_AMMO				0x08
#define FEATURE_W_RANGE				0x09
#define FEATURE_W_SPINUP			0x0A
#define FEATURE_P_RUNSPD			0x0B
#define FEATURE_P_SWIMSPD			0x0C
#define FEATURE_P_TRUEGOD			0x0D
#define FEATURE_P_SUPERJUMP			0x0E
#define FEATURE_P_EXPLOSIVEMELEE	0x0F
#define FEATURE_W_EXPLOSIVEAMMO		0x10
#define FEATURE_W_FIREAMMO			0x11
#define FEATURE_V_TRUEGOD			0x12
#define FEATURE_P_NORAGDOLL			0x13
#define FEATURE_V_SEATBELT			0x14
#define FEATURE_W_NORELOAD			0x15
#define FEATURE_V_ACCELERATION		0x16
#define FEATURE_V_BRAKEFORCE		0x17
#define FEATURE_V_TRACTION			0x18
#define FEATURE_V_GRAVITY			0x19
#define FEATURE_V_BULLETPROOFTIRES	0x1A
#define FEATURE_P_WANTED			0x1B
#define FEATURE_W_BULLET_BATCH		0x1C
#define FEATURE_W_MUZZLE_VELOCITY	0x1D
#define FEATURE_V_DEFORMATION		0x1E
#define FEATURE_V_UPSHIFT			0x1F
#define FEATURE_V_SUSPENSION_FORCE	0x21
#define FEATURE_P_STAMINA			0x22
#define FEATURE_V_DOWNSHIFT			0x24
#define FEATURE_P_SUICIDE			0x25
#define FEATURE_W_FILL_AMMO			0x26
#define FEATURE_P_WATER_PROOF		0x27
#define FEATURE_P_HEAL				0x28
#define FEATURE_P_UNDEAD_OFFRADAR	0x29
#define FEATURE_P_SUPER_PUNCH		0x2A
#define FEATURE_V_MASS				0x2B
#define FEATURE_V_BUOYANCY			0x2C
#define FEATURE_V_HANDBRAKEFORCE	0x2D
#define FEATURE_V_SUSPENSION_HEIGH	0x2E
#define FEATURE_V_COLISION_DAMAGE_MP 0x2F
#define FEATURE_V_WEAPON_DAMAGE_MP	0x30
#define FEATURE_V_ENGINE_DAMAGE_MP	0x31
#define FEATURE_V_BOOST				0x32
#define FEATURE_V_RECHARGE_SPEED	0x33
#define FEATURE_V_HEAL				0x34
#define FEATURE_T_RP_MP				0x35
#define FEATURE_T_AP_MP				0x36
#define FEATURE_T_MISSION_PAYOUT	0x37
#define FEATURE_W_FILL_ALL_AMMO		0x38
#define FEATURE_W_FORCE_ON_PED		0x39
#define FEATURE_W_FORCE_ON_VEHICLE	0x3A
#define FEATURE_W_FORCE_ON_HELI		0x3B
#define FEATURE_W_BULLET_EDIT		0x3C
#define FEATURE_P_NPC_IGNORE		0x3D
#define FEATURE_T_ORBITAL_CANNON	0x3E
#define FEATURE_T_BUNKER_RESEARCH	0x3F
#define FEATURE_T_ANTI_IDLE_KICK	0x40
#define FEATURE_P_PLAYER_LIST		0x41
#define FEATURE_P_MONERY_DROP		0x42
#define FEATURE_G_CASINO_CUT_0		0x43
#define FEATURE_G_CASINO_CUT_1		0x44
#define FEATURE_G_CASINO_CUT_2		0x45
#define FEATURE_G_CASINO_CUT_3		0x46
#define FEATURE_G_DISABLE_THE_PHONE	0x47



*/