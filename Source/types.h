#pragma once

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

#pragma pack(push, 1)
typedef struct
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;
} Vector3;
#pragma pack(pop)
class CWorld;
class CPed;
class CNavigation;
class CWorld_Wrap;
class CAttacker;
class CVehicle;
class CPlayerInfo;
class CWeaponManager;
class CWeapon;
class CAmmoInfo;
typedef struct
{
	float x;
	float y;
	float z;
} v3;
class CPedStyle;
class CPed
{
public:
	char pad_0x0000[0x28]; //0x0000
	BYTE btEntityType; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	BYTE btInvisible; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CNavigation* pCNavigation; //0x0030 
	char pax_0x0038[0x10]; //0x0038
	CPedStyle* pCPedStyle; //0x0048
	char pad_0x0038[0x40]; //0x0050
	v3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	bool btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x70]; //0x02B0
	v3 v3Velocity; //0x0320 
	char pad_0x032C[0x9FC]; //0x032C
	CVehicle* pCVehicleLast; //0x0D28 
	char pad_0x0D30[0x378]; //0x0D30
	BYTE btNoRagdoll; //0x10A8 
	char pad_0x10A9[0xF]; //0x10A9
	CPlayerInfo* pCPlayerInfo; //0x10B8 
	char pad_0x10C0[0x8]; //0x10C0
	CWeaponManager* pCWeaponManager; //0x10C8 
	char pad_0x10D0[0x31C]; //0x10D0
	BYTE btSeatBelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x1]; //0x13F9
	BYTE btCanSwitchWeapons;
	char pad_0x13FB[0x5];
	BYTE btForcedAim; //0x1400 
	BYTE N00000936; //0x1401 
	BYTE N00000939; //0x1402 
	BYTE N00000937; //0x1403 
	char pad_0x1404[0x67]; //0x1404
	BYTE btIsInVehicle; //0x146B 
	char pad_0x146C[0x44]; //0x146C
	float fArmor; //0x14B0 
	char pad_0x14B4[0x20]; //0x14B4
	float fFatiguedHealthThreshold; //0x14D4 
	float fInjuredHealthThreshold; //0x14D8 
	float fDyingHealthThreshold; //0x14DC 
	float fHurtHealthThreshold; //0x14E0 
	char pad_0x14E4[0xC]; //0x14E4
	CVehicle* pCVehicleLast2; //0x14F0 
	char pad_0x14F8[0xDC]; //0x14F8
	__int32 iCash; //0x15D4
};
#pragma pack(push, 1)
typedef struct
{
	float x;
	float y;
	float z;
} Vector3_t;
#pragma pack(pop)

struct Blip_t {
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	Vector3 PlayerPos;
	char _0x001C[6];
	BYTE bFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE bInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE bZIndex; //0x0057 
	BYTE bDisplay; //0x0058  Also Visibility 0010
	BYTE bAlpha; //0x0059
};//Size=0x005A

struct BlipList {
public:
	Blip_t* m_Blips[1500]; //0x0000 

};//Size=0x2F18


class CAutomobile;
class CBaseModelInfo;
class CNavigation;
namespace rage {
	template <typename T>
	//Net Defines
	class netLoggingInterface;
	class netLogStub;
	class netGameEvent;
	class netEventMgr;
	class netSyncTreeNode;
	class netSyncTree {
	public:
		char pad_0000[48]; //0x0000
		class netSyncTreeNode* m_sync_tree_node; //0x0030
	}; //Size: 0x0038
	class netSyncTreeNode {
	public:
		char pad_0000[192]; //0x0000
		uint32_t m_player_model; //0x00C0
		uint32_t m_ped_model; //0x00C4
		uint32_t m_vehicle_model; //0x00C8
		char pad_00CC[84]; //0x00CC
		uint32_t m_pickup_model; //0x0120
		char pad_0124[44]; //0x0124
		uint32_t m_object_model; //0x0150
		char pad_0154[692]; //0x0154
	}; //Size: 0x0408
	class netObject {
	public:
		int16_t m_object_type; //0x0008
		int16_t m_object_id; //0x000A
		char pad_000C[61]; //0x000C
		int8_t m_owner_id; //0x0049
		int8_t m_control_id; //0x004A
		int8_t m_next_owner_id; //0x004B
		bool m_is_remote; //0x004C
		bool m_wants_to_delete; //0x004D
		char pad_004E[1]; //0x004E
		bool m_should_not_be_delete; //0x004F

		virtual ~netObject();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
		virtual void Function10();
		virtual void Function11();
		virtual void Function12();
		virtual void Function13();
		virtual void Function14();
		virtual void Function15();
		virtual void Function16();
		virtual void Function17();
		virtual void Function18();
		virtual void Function19();
		virtual void Function20();
		virtual void Function21();
		virtual void Function22();
		virtual void Function23();
		virtual void Function24();
		virtual void Function25();
		virtual void Function26();
		virtual void Function27();
		virtual void Function28();
		virtual void Function29();
		virtual void Function30();
		virtual void Function31();
		virtual void Function32();
		virtual void Function33();
		virtual void Function34();
		virtual void Function35();
		virtual void Function36();
		virtual void Function37();
		virtual void Function38();
		virtual void Function39();
		virtual void Function40();
		virtual void Function41();
		virtual void Function42();
		virtual void Function43();
		virtual void Function44();
		virtual void Function45();
		virtual void Function46();
		virtual void Function47();
		virtual void Function48();
		virtual void Function49();
		virtual void Function50();
		virtual void Function51();
		virtual void Function52();
		virtual void Function53();
		virtual void Function54();
		virtual void Function55();
		virtual void Function56();
		virtual void Function57();
		virtual void Function58();
		virtual void Function59();
		virtual void Function60();
		virtual void Function61();
		virtual void Function62();
		virtual void Function63();
		virtual void Function64();
		virtual void Function65();
		virtual void Function66();
		virtual void Function67();
		virtual void Function68();
		virtual void Function69();
		virtual void Function70();
		virtual void Function71();
		virtual void Function72();
		virtual void Function73();
		virtual void Function74();
		virtual void Function75();
		virtual void Function76();
		virtual void Function77();
		virtual void Function78();
		virtual void Function79();
		virtual void Function80();
		virtual void Function81();
		virtual void Function82();
		virtual void Function83();
		virtual void Function84();
		virtual void Function85();
		virtual void Function86();
		virtual void Function87();
		virtual void Function88();
		virtual void Function89();
		virtual void Function90();
		virtual void Function91();
		virtual void Function92();
		virtual void Function93();
		virtual void Function94();
		virtual void Function95();
		virtual void Function96();
		virtual void Function97();
		virtual void Function98();
		virtual void Function99();
		virtual void Function100();
		virtual void Function101();
	}; //Size: 0x0050
//	static_assert(sizeof(netObject) == 0x50);
	class netObjectMgrBase;
	class netPlayer;
	class netPlayerMgr;
	//Invoker Defines
	class scrNativeCallContext;
	class scrNativeRegistration;
	class scrNativeRegistrationTable;
	//Fw Defines
	class fwRefAwareBase;
	class fwExtensibleBase;
	class fwDrawData {
	public:
		char pad_0000[904]; //0x0000
		uint8_t m_primary_color; //0x0388
		char pad_0389[3]; //0x0389
		uint8_t m_pearlescent; //0x038C
		char pad_038D[3]; //0x038D
		uint8_t m_secondary_color; //0x0390
		char pad_0391[15]; //0x0391
		uint8_t m_neon_blue; //0x03A0
		uint8_t m_neon_green; //0x03A1
		uint8_t m_neon_red; //0x03A2
		char pad_03A3[15]; //0x03A3
		uint8_t m_spoiler; //0x03B2
		uint8_t m_bumper_front; //0x03B3
		uint8_t m_bumper_rear; //0x03B4
		uint8_t m_sideskirts; //0x03B5
		uint8_t m_exhaust; //0x03B6
		uint8_t m_frame; //0x03B7
		uint8_t m_grille; //0x03B8
		uint8_t m_hood; //0x03B9
		uint8_t m_fenders; //0x03BA
		uint8_t m_bullbars; //0x03BB
		uint8_t m_roof; //0x03BC
		char pad_03BD[3]; //0x03BD
		uint8_t m_ornaments; //0x03C0
		char pad_03C1[1]; //0x03C1
		uint8_t m_dail_design; //0x03C2
		uint8_t m_sunstrips; //0x03C3
		uint8_t m_seats; //0x03C4
		uint8_t m_steering_wheel; //0x03C5
		uint8_t m_column_shifter_levers; //0x03C6
		char pad_03C7[2]; //0x03C7
		uint8_t m_truck_beds; //0x03C9
		char pad_03CA[4]; //0x03CA
		uint8_t m_roll_cages; //0x03CE
		uint8_t m_skid_plate; //0x03CF
		uint8_t m_secondary_light_surrounds; //0x03D0
		uint8_t m_hood_accessories; //0x03D1
		uint8_t m_doors; //0x03D2
		uint8_t m_snorkel; //0x03D3
		uint8_t m_livery; //0x03D4
		char pad_03D5[1]; //0x03D5
		uint8_t m_engine; //0x03D6
		uint8_t m_brakes; //0x03D7
		uint8_t m_transmission; //0x03D8
		uint8_t m_horn; //0x03D9
		uint8_t m_suspension; //0x03DA
		uint8_t m_armor; //0x03DB
		char pad_03DC[1]; //0x03DC
		uint8_t m_turbo; //0x03DD
		char pad_03DE[3]; //0x03DE
		uint8_t m_xenon; //0x03E1
		uint8_t m_tire_design; //0x03E2
		char pad_03E3[16]; //0x03E3
		uint8_t m_truck_bed; //0x03F3
		char pad_03F4[5]; //0x03F4
		uint8_t m_wheel_color; //0x03F9
		char pad_03FA[5]; //0x03FA
		uint8_t m_window; //0x03FF
		char pad_0400[2]; //0x0400
		uint8_t m_neon_left; //0x0402
		uint8_t m_neon_right; //0x0403
		uint8_t m_neon_front; //0x0404
		uint8_t m_neon_rear; //0x0405
	}; //Size: 0x0406
	//static_assert(sizeof(fwDrawData) == 0x406);
#pragma pack(push, 4)
	class fwEntity {
	public:
		char pad_0000[32]; //0x0000
		CBaseModelInfo* m_model_info; //0x0020
		char pad_0028[1]; //0x0028
		int8_t m_entity_type; //0x0029
		char pad_002A[2]; //0x002A
		uint8_t m_invisible; //0x002C
		char pad_002D[3]; //0x002D
		CNavigation* m_navigation; //0x0030
		char pad_0038[16]; //0x0038
		rage::fwDrawData* m_draw_data; //0x0048
		char pad_0050[128]; //0x0050
		rage::netObject* m_net_object; //0x00D0
		char pad_00D8[176]; //0x00D8
		uint32_t m_damage_bits; //0x0188
	}; //Size: 0x018C
	//static_assert(sizeof(fwEntity) == 0x18C);
#pragma pack(pop)
	class fwArchetype;
	class datBitBuffer;
	class sysMemAllocator;
	//Script Defines
	class scriptIdBase;
	class scriptId;
	class scriptHandler;
	class scriptHandlerNetComponent;
	class scriptHandlerObject;
	class scriptHandlerMgr;
	class tlsContext;
	//Native Defines
	class sysMemAllocator
	{
	public:
		virtual ~sysMemAllocator() = 0;

		virtual void SetQuitOnFail(bool) = 0;
		virtual void* Allocate(size_t size, size_t align, int subAllocator) = 0;

		inline void* allocate(size_t size, size_t align, int subAllocator)
		{
			return Allocate(size, align, subAllocator);
		}

		virtual void* TryAllocate(size_t size, size_t align, int subAllocator) = 0;

		virtual void Free(void* pointer) = 0;

		virtual void free(void* pointer)
		{
			return Free(pointer);
		}

		virtual void TryFree(void* pointer) = 0;

		virtual void Resize(void* pointer, size_t size) = 0;

		virtual sysMemAllocator* GetAllocator(int allocator) const = 0;

		virtual sysMemAllocator* GetAllocator(int allocator) = 0;

		virtual sysMemAllocator* GetPointerOwner(void* pointer) = 0;

		virtual size_t GetSize(void* pointer) const = 0;

		virtual size_t GetMemoryUsed(int memoryBucket) = 0;

		virtual size_t GetMemoryAvailable() = 0;

	public:

		static auto UpdateAllocatorValue()
		{
			//B9 ? ? ? ? 48 8B 0C 01 45 33 C9 49 8B D2 48
			auto g_gtaTlsEntry = *(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8); //This has been 0xC8 since 323, I'm not adding this signature to pointers...

			if (g_gtaTlsEntry == nullptr)

				*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8) = g_gtaTlsEntry;
			*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8 - 8) = g_gtaTlsEntry;

			return g_gtaTlsEntry;
		}
	};
	struct scrNativeCallContext
	{
	public:
		void* m_Return;
		std::uint32_t m_ArgCount;
		char padding[4];
		void* m_Args;
		std::uint32_t m_DataCount;
		char padding1[4];
		alignas(std::uintptr_t) std::uint8_t m_VectorSpace[192];
	};
	using scrNativeHash = std::uint64_t;
	using scrNativeHandler = void(*)(scrNativeCallContext*);

	class scrVector {
	public:
		scrVector() = default;
		scrVector(float x, float y, float z) : x(x), y(y), z(z) {}
	public:
		float x{};
	private:
		char m_paddingx[0x04];
	public:
		float y{};
	private:
		char m_paddingy[0x04];
	public:
		float z{};
	private:
		char m_paddingz[0x04];
	};
	class netLoggingInterface2 {
	public:
	};
	class nonPhysicalPlayerDataBase {
	public:
		virtual ~nonPhysicalPlayerDataBase() = default;    // 0 (0x00)
		virtual void unk_0x08() = 0;                       // 1 (0x08)
		virtual void unk_0x10() = 0;                       // 2 (0x10)
		virtual void unk_0x18() = 0;                       // 3 (0x18)
		virtual void log(netLoggingInterface2* logger) = 0; // 4 (0x20)
	};
#pragma pack(pop)
	//Joaat Defines
	using joaat_t = std::uint32_t;
	inline constexpr char joaat_to_lower(char c) { return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c; }
	inline joaat_t joaat(std::string str) {
		joaat_t hash = 0;
		for (char c : str) {
			hash += joaat_to_lower(c);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		return hash;
	}
	inline joaat_t joaat(const char* str) {
		joaat_t hash = 0;
		while (*str) {
			hash += joaat_to_lower(*(str++));
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		return hash;
	}
	template <std::size_t CharCount>
	struct constexpr_joaat
	{
		char data[CharCount];

		template <std::size_t... Indices>
		constexpr constexpr_joaat(const char* str, std::index_sequence<Indices...>) :
			data{ (str[Indices])... }
		{
		}

		constexpr joaat_t operator()()
		{
			joaat_t hash = 0;

			for (std::size_t i = 0; i < CharCount; ++i)
			{
				hash += joaat_to_lower(data[i]);
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}

			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);

			return hash;
		}
	};
	//Vector Defines
	using Vector3 = scrVector;
	struct vector2 { float x; float y; };
	struct vector3 { float x; float y; float z; };
	struct vector4 { float x; float y; float z; float w; };
	//SHV Pools
	class GenericPool {
	public:
		uint64_t poolStartAddress;
		uint8_t* byteArray;
		int  size;
		int  itemSize;
		inline bool isValid(int i) {
			//assert(i >= 0);
			return mask(i) != 0;
		}
		inline uint64_t getAddress(int i) {
			//assert(i >= 0);
			return mask(i) & (poolStartAddress + i * itemSize);
		}
	private:
		inline long long mask(int i) {
			//assert(i >= 0);
			long long num1 = byteArray[i] & 0x80; //Check for high bit.
			return ~((num1 | -num1) >> 63);
		}
	};
	class VehiclePool {
	public:
		uint64_t* listAddress;
		int  size;
		char _padding2[36];
		uint32_t* bitArray;
		char _padding3[40];
		int  itemCount;
		inline bool isValid(int i) {
			//assert(i >= 0);
			return (bitArray[i >> 5] >> (i & 0x1F)) & 1;
		}
		inline uint64_t getAddress(int i) {
			return listAddress[i];
		}
		std::vector<CAutomobile*> getAllVehicles() {
			std::vector<CAutomobile*> vehs;
			for (std::int32_t i = 0; i < size; ++i) {
				if (!isValid(i))
					continue;
				auto addr = getAddress(i);
				if (addr) {
					CAutomobile* veh = (CAutomobile*)addr;
					vehs.push_back(veh);
				}
			}
			return vehs;
		}
	};
};
#define RAGE_JOAAT_IMPL(str) (::rage::constexpr_joaat<sizeof(str) - 1>((str), std::make_index_sequence<sizeof(str) - 1>())())
#define RAGE_JOAAT(str) (std::integral_constant<rage::joaat_t, RAGE_JOAAT_IMPL(str)>::value)
class CAutomobile;
class CPed;
class GtaThread;
class CGameScriptId;
class CGameScriptHandler;
class CGameScriptHandlerNetwork;
class CGameScriptHandlerMgr;
class CEntity;
class CDynamicEntity;
class CPhysical;
class CObject;
class CPickup;
class CPedFactory;
class CVehicleFactory;
class CNetworkPlayerMgr;
class CPlayerInfo;
class CNetworkObjectMgr;
typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int Pickup;
typedef int Object;
typedef int Interior;
typedef int Blip;
typedef int Camera;
typedef int Sphere;
typedef int ScrHandle;
//using Vector3 = rage::scrVector;

//Enums (GameState etc)
enum eGameState : std::uint32_t {
	Invalid = -1,
	Playing,
	Died,
	Arrested,
	FailedMission,
	LeftGame,
	Respawn,
	InMPCutscene
};
enum EntityPoolType : uint16_t {
	PoolTypeVehicle = 1,
	PoolTypePed = 2,
	PoolTypeObject = 4,
	PoolTypePickup = 8,
	PoolTypeCamera = 16
};

//ReClass (Offsets)
class CBaseModelInfo {
public:
	char pad_0000[0x18]; //0x0000
	uint32_t m_model; //0x0018
	char pad_001C[0x81]; //0x001C
	BYTE m_model_type; //0x009D
	char pad_009D[0x2A2]; //0x009E
	int32_t m_handlingType; //0x0340
}; //Size: 0x0344
class CPedDrawHandler;
class CCustomShaderEffectTree;
enum class eDamageType : int32_t {
	Unknown,
	None,
	Melee,
	Bullet,
	_0xC5403EC0,
	Explosive,
	Fire,
	_0xA869C908,
	Fall,
	_0xCAE075C0,
	Electric,
	BarbedWire,
	FireExtinguisher,
	Smoke,
	WaterCannon,
	_0x1C8E59AE
};
enum class eFireType : int32_t {
	None,
	Melee,
	InstantHit,
	DelayedHit,
	ProjectTile,
	VolumetricParticle
};
enum class eWheelSlot : int32_t {
	Pistol,
	SMG,
	Rifle,
	Sniper,
	UnarmedMelee,
	ShotGun,
	Heavy,
	Throwable
};
enum class eAmmoSpecialType : int32_t {
	None,
	ArmorPiercing,
	Explosive,
	FMJ,
	HollowPoint,
	Incendiary,
	Tracer
};
class AimingInfo;
class CAmmoInfo {
public:
	int32_t m_ammo_max; //0x0020
	int32_t m_ammo_max_50; //0x0024
	int32_t m_ammo_max_100; //0x0028
	int32_t m_ammo_max_mp; //0x002C
	int32_t m_ammo_max_50_mp; //0x0030
	int32_t m_ammo_max_100_mp; //0x0034
	uint32_t m_ammo_flags; //0x0038
	eAmmoSpecialType m_ammo_special_type; //0x003C
	char pad_0040[24]; //0x0040
	float m_missile_speed; //0x0058
	char pad_005C[284]; //0x005C
	uint32_t m_lock_on_time; //0x0178
}; //Size: 0x017C
class CWeaponInfo {
public:
	eDamageType m_damage_type; //0x0020
	char pad_0024[48]; //0x0024
	eFireType m_fire_type; //0x0054
	eWheelSlot m_wheel_slot; //0x0058
	uint32_t m_group; //0x005C
	CAmmoInfo* m_ammo_info; //0x0060
	AimingInfo* m_aiming_info; //0x0068
	uint32_t m_clip_size; //0x0070
	float m_accuracy_spread; //0x0074
	float m_accurate_mode_accuracy_modifier; //0x0078
	float m_run_and_gun_accuracy; //0x007C
	float m_run_and_gun_min_accuracy; //0x0080
	float m_recoil_accuracy_max; //0x0084
	float m_recoil_error_time; //0x0088
	float m_recoil_recovery_rate; //0x008C
	float m_recoil_accuracy_to_allow_headshot_ai; //0x0090
	float m_min_headshot_distance_ai; //0x0094
	float m_max_headshot_distance_ai; //0x0098
	float m_headshot_damage_modifier_ai; //0x009C
	float m_recoil_accuracy_to_allow_headshot_player; //0x00A0
	float m_min_headshot_distance_player; //0x00A4
	float m_max_headshot_distance_player; //0x00A8
	float m_headshot_damage_modifier_player; //0x00AC
	float m_damage; //0x00B0
	float m_damage_time; //0x00B4
	float m_damage_time_in_vehicle; //0x00B8
	float m_damage_time_in_vehicle_headshot; //0x00BC
	float N000008F9; //0x00C0
	uint32_t N00000898; //0x00C4
	float m_hit_limbs_damage_modifier; //0x00C8
	float m_network_hit_limbs_damage_modifier; //0x00CC
	float m_lightly_armoured_damage_modifier; //0x00D0
	float m_vehicle_damage_modifier; //0x00D4
	float m_force; //0x00D8
	float m_force_on_ped; //0x00DC
	float m_force_on_vehicle; //0x00E0
	float m_force_on_heli; //0x00E4
	char pad_00E8[16]; //0x00E8
	float m_force_max_strength_mult; //0x00F8
	float m_force_falloff_range_start; //0x00FC
	float m_force_falloff_range_end; //0x0100
	float m_force_falloff_range_min; //0x0104
	float m_project_force; //0x0108
	float m_frag_impulse; //0x010C
	float m_penetration; //0x0110
	float m_vertical_launch_adjustment; //0x0114
	float m_drop_forward_velocity; //0x0118
	float m_speed; //0x011C
	uint32_t m_bullets_in_batch; //0x0120
	float m_batch_spread; //0x0124
	float m_reload_time_mp; //0x0128
	float m_reload_time_sp; //0x012C
	float m_vehicle_reload_time; //0x0130
	float m_anim_reload_time; //0x0134
	int32_t m_bullets_per_anime_loop; //0x0138
	float m_time_between_shots; //0x013C
	float m_time_left_between_shots_where_should_fire_is_cached; //0x0140
	float m_spinup_time; //0x0144
	float m_spin_time; //0x0148
	float m_spindown_time; //0x014C
	float m_alternate_wait_time; //0x0150
	char pad_0154[296]; //0x0154
	float m_network_player_damage_modifier; //0x027C
	float m_network_ped_damage_modifier; //0x0280
	float m_network_headshot_modifier; //0x0284
	float m_lock_on_range; //0x0288
	float m_weapon_range; //0x028C
	char pad_0290[8]; //0x0290
	float m_damage_fall_off_range_min; //0x0298
	float m_damage_fall_off_range_max; //0x029C
	float m_damage_fall_off_modifier; //0x02A0
	char pad_02A4[64]; //0x02A4
	uint32_t m_recoil_shake_hash; //0x02E4
	uint32_t m_recoil_shake_hash_first_person; //0x02E8
	float m_min_time_between_recoil_shakes; //0x02EC
	float m_recoil_shake_amplitude; //0x02F0
	float m_explosion_shake_amplitude; //0x02F4
}; //Size=0x0880
class CHandlingData;
class CNavigation {
public:
	char pad_0000[32]; //0x0000
	float m_heading; //0x0020
	float m_heading2; //0x0024
	char pad_0028[8]; //0x0028
	Vector3 m_rotation; //0x0030
	char pad_003C[20]; //0x003C
	Vector3 m_position; //0x0050
}; //Size: 0x005C
class CAutomobile : public rage::fwEntity {
public:
	char pad_018C[244]; //0x018C
	float m_health; //0x0280
	char pad_0284[28]; //0x0284
	float m_health_max; //0x02A0
	char pad_02A4[116]; //0x02A4
	uint8_t m_boost_state; //0x0318
	char pad_0319[2]; //0x0319
	uint8_t m_boost_allow_recharge; //0x031B
	char pad_031C[4]; //0x031C
	float m_boost; //0x0320
	float m_rocket_recharge_speed; //0x0324
	char pad_0328[136]; //0x0328
	float m_jump_boost_charge; //0x03B0
	char pad_03B4[1164]; //0x03B4
	float m_body_health; //0x0840
	float m_petrol_tank_health; //0x0844
	char pad_0848[192]; //0x0848
	float m_engine_health; //0x0908
	char pad_090C[44]; //0x090C
	CHandlingData* m_handling; //0x0938
	char pad_0940[2]; //0x0940
	uint8_t m_is_drivable; //0x0942
	uint8_t m_tyres_can_burst; //0x0943
	uint8_t m_deform_god; //0x0944
	char pad_0945[179]; //0x0945
	float m_dirt_level; //0x09F8
	char pad_09FC[194]; //0x09FC
	uint8_t m_is_targetable; //0x0ABE
	char pad_0ABF[413]; //0x0ABF
	float m_gravity; //0x0C5C
	char pad_0C60[8]; //0x0C60
	CPed* m_driver; //0x0C68
	CPed* m_passengers[15]; //0x0C70
	CPed* m_last_driver; //0x0CE8
}; //Size: 0x0CF0
//static_assert(sizeof(CAutomobile) == 0xCF0);
class CPedWeaponManager {
public:
	char pad_0000[16]; //0x0000
	class CPed* m_owner; //0x0010
	uint32_t m_selected_weapon_hash; //0x0018
	char pad_001C[4]; //0x001C
	CWeaponInfo* m_weapon_info; //0x0020
	char pad_0028[72]; //0x0028
	CWeaponInfo* m_vehicle_weapon_info; //0x0070
}; //Size=0x0078
class CPedInventory {
public:
	char pad_0x0000[0x10]; //0x0000
	CPed* m_Ped; //0x0010 
	char pad_0x0018[0x10]; //0x0018
	CPedWeaponManager* m_WeaponManager; //0x0028 
	char pad_0x0030[0x68]; //0x0030
	CCustomShaderEffectTree* m_CustomShaderEffectTree; //0x0098 
	char pad_0x00A0[0x7A0]; //0x00A0
}; //Size=0x0840
class CPedModelInfo
{
public:
	char pad_0000[24]; //0x0000
	uint32_t m_model_hash; //0x0018
}; //Size: 0x001C
//static_assert(sizeof(CPedModelInfo) == 0x1C);
class pgBase {
public:
	char pad_0000[80]; //0x0000
	rage::vector3 m_pos; //0x0050
}; //Size: 0x005C
//static_assert(sizeof(pgBase) == 0x5C);
#pragma pack(push, 1)
class CPed2 {
public:
	char pad_0000[32]; //0x0000
	CPedModelInfo* m_ped_model_info; //0x0020
	uint8_t m_entity_type; //0x0028
	char pad_0029[3]; //0x0029
	uint8_t m_invisible; //0x002C
	char pad_002D[1]; //0x002D
	uint8_t m_freeze_momentum; //0x002E
	char pad_002F[1]; //0x002F
	pgBase* m_posbase; //0x0030
	char pad_0038[88]; //0x0038
	rage::vector3 m_camera; //0x0090
	char pad_009C[237]; //0x009C
	uint8_t m_godmode; //0x0189
	char pad_018A[2]; //0x018A
	uint8_t m_hostility; //0x018C
	char pad_018D[243]; //0x018D
	float m_health; //0x0280
	char pad_0284[28]; //0x0284
	float m_maxhealth; //0x02A0
	char pad_02A4[124]; //0x02A4
	rage::vector3 m_velocity; //0x0320
	char pad_032C[2564]; //0x032C
	CAutomobile* m_vehicle; //0x0D30
	char pad_0D38[912]; //0x0D38
	CPlayerInfo* m_player_info; //0x10C8
	char pad_10D0[8]; //0x10D0
	CPedWeaponManager* m_weapon_manager; //0x10D8
	char pad_10E0[907]; //0x10E0
	uint8_t m_ped_task_flag; //0x146B
	char pad_146C[196]; //0x146C
	float m_armor; //0x1530
}; //Size: 0x1534
//static_assert(sizeof(CPed) == 0x1534);
#pragma pack(pop)
class CPedFactory
{
public:
	char pad_0000[8]; //0x0000
	class CPed* m_local_ped; //0x0008
};
#pragma pack(push, 1)
class CPlayerInfo
{
public:
	char pad_0000[32]; //0x0000
	//class rage::netPlayerData m_net_player_data; //0x0020
	char pad_00B8[184]; //0x00B8
	float m_swim_speed; //0x0170
	char pad_0174[20]; //0x0174
	uint32_t m_water_proof; //0x0188
	char pad_018C[92]; //0x018C
	class CPed* m_ped; //0x01E8
	char pad_01F0[40]; //0x01F0
	uint32_t m_frame_flags; //0x0218
	char pad_021C[52]; //0x021C
	uint32_t m_player_controls; //0x0250
	char pad_0254[1256]; //0x0254
	float m_wanted_can_change; //0x073C
	char pad_0740[304]; //0x0740
	uint32_t m_npc_ignore; //0x0870
	char pad_0874[12]; //0x0874
	bool m_is_wanted; //0x0880
	char pad_0881[7]; //0x0881
	uint32_t m_wanted_level; //0x0888
	uint32_t m_wanted_level_display; //0x088C
	char pad_0890[1120]; //0x0890
	float m_run_speed; //0x0CF0
	float m_stamina; //0x0CF4
	float m_stamina_regen; //0x0CF8
	char pad_0CFC[16]; //0x0CFC
	float m_weapon_damage_mult; //0x0D0C
	float m_weapon_defence_mult; //0x0D10
	char pad_0D14[4]; //0x0D14
	float m_melee_weapon_damage_mult; //0x0D18
	float m_melee_damage_mult; //0x0D1C
	float m_melee_defence_mult; //0x0D20
	char pad_0D24[8]; //0x0D24
	float m_melee_weapon_defence_mult; //0x0D2C
}; //Size: 0x0D30
class CNonPhysicalPlayerData : public rage::nonPhysicalPlayerDataBase
{
public:
	std::int32_t  m_bubble_id; // 0x08
	std::int32_t  m_player_id; // 0x0C
	rage::vector3 m_position;  // 0x10
};
class CNetGamePlayer {
public:
	char pad_0008[8]; //0x0008
	class CNonPhysicalPlayerData* m_non_physical_player; //0x0010
	uint32_t m_msg_id; //0x0018
	char pad_001C[4]; //0x001C
	uint8_t m_active_id; //0x0020
	uint8_t m_player_id; //0x0021
	char pad_0022[126]; //0x0022
	class CPlayerInfo* m_player_info; //0x00A0
}; //Size: 0x00A8
#pragma pack(pop)
class GtaThread {
public:
	rage::joaat_t m_script_hash;                // 0x120
	char m_padding3[0x14];                      // 0x124
	std::int32_t m_instance_id;                 // 0x138
	char m_padding4[0x04];                      // 0x13C
	std::uint8_t m_flag1;                       // 0x140
	bool m_safe_for_network_game;               // 0x141
	char m_padding5[0x02];                      // 0x142
	bool m_is_minigame_script;                  // 0x144
	char m_padding6[0x02];                      // 0x145
	bool m_can_be_paused;                       // 0x147
	bool m_can_remove_blips_from_other_scripts; // 0x148
	char m_padding7[0x0F];                      // 0x149
};

namespace rage {
	class netPlayerMgrBase
	{
	public:
		virtual ~netPlayerMgrBase() = default;
		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void unk_0x18() = 0;
		//virtual CNetGamePlayer* AddPlayer_raw(void* a1, void* a2, void* a3, rage::netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
		virtual void RemovePlayer(CNetGamePlayer* net_game_player) = 0;
		virtual void UpdatePlayerListsForPlayer(CNetGamePlayer* net_game_player) = 0;
	//	virtual CNetGamePlayer* AddPlayer(void* a1, void* a2, void* a3, rage::netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
	}; //Size: 0x0008
	class netPlayer;
	class datBitBuffer;
	class netGameEvent {
	public:
		virtual ~netGameEvent() = default;
		virtual const char* get_name() { return 0; };
		virtual bool is_in_scope(netPlayer* player) { return 0; };
		virtual bool time_to_resend(std::uint32_t time) { return 0; };
		virtual bool can_change_scope() { return 0; };
		virtual void prepare_data(datBitBuffer* buffer, netPlayer* source_player, netPlayer* target_player) {};
		virtual void handle_data(datBitBuffer* buffer, netPlayer* source_player, netPlayer* target_player) {};
		virtual bool decide(netPlayer* source_player, netPlayer* target_player) { return 0; };
		virtual void prepare_reply(datBitBuffer* buffer, netPlayer* reply_player) {};
		virtual void handle_reply(datBitBuffer* buffer, netPlayer* souce_player) {};
		virtual void prepare_extra_data(datBitBuffer* buffer, bool is_reply, netPlayer* player, netPlayer* player2) {};
		virtual void handle_extra_data(datBitBuffer* buffer, bool is_reply, netPlayer* player, netPlayer* player2) {};
	private:
		virtual void unk_0x60() {};
		virtual void unk_0x68() {};
		virtual void unk_0x70() {};
		virtual void unk_0x78() {};
	public:
		virtual bool operator==(netGameEvent const& other) { return 0; };
		virtual bool operator!=(netGameEvent const& other) { return 0; };
		virtual bool must_persist() { return 0; };
		virtual bool must_persist_when_out_of_scope() { return 0; };
		virtual bool has_timed_out() { return 0; };
		std::uint16_t m_id;          // 0x08
		bool m_requires_reply;       // 0x0A
	private:
		char m_padding1[0x05];       // 0x0B
	public:
		netPlayer* m_source_player;  // 0x10
		netPlayer* m_target_player;  // 0x18
		std::uint32_t m_resend_time; // 0x20
	private:
		std::uint16_t m_0x24;        // 0x24
		std::uint8_t m_0x26;         // 0x26
		std::uint8_t m_0x27;         // 0x27
		std::uint32_t m_0x28;        // 0x28
		char m_padding2[0x04];
	};
}

class PresenceEventTarget {
public:
	PresenceEventTarget() = default;
	PresenceEventTarget(uint64_t scid, int16_t unk) : scid(scid), unk(unk) {}
public:
	uint64_t scid; //0x0000
	int16_t unk; //0x0008
}; //Size: 0x000A

class CNetworkPlayerMgr : public rage::netPlayerMgrBase {
public:
	char pad_0008[224]; //0x0008
	class CNetGamePlayer* m_local_net_player; //0x00E8
	char pad_00F0[144]; //0x00F0
	class CNetGamePlayer* m_player_list[32]; //0x0180
	uint16_t m_player_limit; //0x0280
	char pad_0282[10]; //0x0282
	uint16_t m_player_count; //0x028C
}; //Size: 0x028E

class CScriptedGameEvent : public rage::netGameEvent {
public:
	char m_padding[0x40];      // 0x30
	std::int64_t m_args[54];   // 0x70
	std::uint32_t m_bitset;    // 0x220
	std::uint32_t m_args_size; // 0x224
};
class CNetworkIncrementStatEvent : public rage::netGameEvent {
public:
	Hash m_stat;    // 0x30
	std::uint32_t m_amount; // 0x34
};

#pragma pack(push, 1)
class FriendInfo {
public:
	char pad_0000[128]; //0x0000
	char m_name[20]; //0x0080
	char pad_0094[36]; //0x0094
	uint64_t m_rockstar_id; //0x00B8
	uint8_t unk_0xC0; //0x00C0
	char pad_00C1[3]; //0x00C1
	uint32_t m_friend_state; //0x00C4
	char pad_00C8[304]; //0x00C8
	uint32_t m_is_joinable; //0x01F8
	char pad_01FC[4]; //0x01FC
}; //Size: 0x0200
//static_assert(sizeof(FriendInfo) == 0x200);
#pragma pack(pop)
class FriendList {
public:
	class FriendInfo m_data[250]; //0x0000
}; //Size: 0x1F400
//static_assert(sizeof(FriendList) == 0x1F400);
#pragma pack(push, 4)
class FriendRegistry {
public:
	uint32_t m_friend_count; //0x0000
	char pad_0004[8]; //0x0004
	class FriendList* m_friends_list; //0x000C
}; //Size: 0x0014
//static_assert(sizeof(FriendRegistry) == 0x14);
#pragma pack(pop)

#pragma pack(push, 1)
class ScInfo {
public:
	char m_ticket[256]; //0x0000
	char pad_0100[256]; //0x0100
	char m_auth_token[128]; //0x0200
	char pad_0280[16]; //0x0280
	uint64_t m_peer_id; //0x0290
	char pad_0298[132]; //0x0298
	char m_country_code[3]; //0x031C
	char pad_031F[32]; //0x031F
	char m_email[78]; //0x033F
	char pad_038D[24]; //0x038D
	char m_language_code[8]; //0x03A5
	char pad_03AD[2]; //0x03AD
	char m_name[20]; //0x03AF
	char pad_03C3[200]; //0x03C3
}; //Size: 0x048B
//static_assert(sizeof(ScInfo) == 0x48B);
#pragma pack(pop)
