#pragma once

namespace Local {

	void UpdateLoop();



	void ParticleEffects();
	void ParticleEffects2();
	void super_vision_rudolf();
	extern char* PTFXChar[];


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
	extern int kkeyPressDelay;
	extern int kkeyPressPreviousTick;
	extern int kkeyPressDelay2;
	extern int kkeyPressPreviousTick2;
	extern int kkeyPressDelay3;
	extern int kkeyPressPreviousTick3;

	extern bool OS;
	extern bool antiafk;


	extern bool isAutoRegHealth;
	void AutoRegHealth(bool toggle);

	extern bool isAutoRegArmour;
	void AutoRegArmour(bool toggle);


	/// <summary>
	/// Ini Stuff
	/// </summary>

	extern bool LoadOutfit;
	void load(int outfit);


	extern bool SaveOutfit;
	void save(int outfit);

	extern int selectedLocation;
	extern bool LoadLocations;
	void loadlocation(int outfit);

	extern bool SaveLocations;
	void savelocation(int outfit);

	extern bool God;
	void god(bool toggle);

	extern bool GODOFRAIN;
	void godofrain(bool toggle);

	extern bool Superjump;
	void superjump(bool toggle);

	extern bool Superpunch;
	void superpunch(bool toggle);

	extern bool Nophone;
	void nophone(bool toggle);

	extern bool Pedscale;
	void pedscale(bool toggle);
	extern float pedsize;
	extern float pedwith;

	extern bool Fov;
	void fov1(bool toggle);
	extern float fovrender;


	

	extern bool Ultrajump;
	void ultrajump(bool toggle);

	extern bool SuperRun;
	void Superun(bool toggle);

	extern bool NoClip;
	void noClip(bool toggle);

	extern bool Glitchmodel;
	void glitchmodel(bool toggle);

	extern bool FreeCam;
	void freeCam(bool toggle);

	extern bool Running;
	void running(bool toggle);

	extern bool TinyPlayer;
	void tinyPlayer(bool toggle);

	extern bool NoRagdoll;
	void noragdoll(bool toggle);

	extern bool Force;
	void Field(bool toggle);

	extern bool Swim;
	void swim(bool toggle);

	extern bool NeverWanted;
	void neverWanted(bool toggle);

	extern bool OffRadar;
	void offRadar(bool toggle);

	extern bool MobileRadio;
	void mobileRadio(bool toggle);

	extern bool SlowMotion;
	void slowMotion(bool toggle);

	extern bool SV;
	void sv(bool toggle);

	extern bool SV2;
	void sv2(bool toggle);

	extern bool SV3;
	void sv3(bool toggle);

	extern bool SV4;
	void sv4(bool toggle);

	extern bool SV5;
	void sv5(bool toggle);

	extern bool SV6;
	void sv6(bool toggle);

	extern bool Invisible;
	void invisible(bool toggle);

	extern bool Fly;
	void fly(bool toggle);

	extern int TimePD;
	extern bool FB;
	void fb(bool toggle);

	extern bool O1;
	void o1(bool toggle);

	extern bool O2;
	void o2(bool toggle);

	extern bool O3;
	void o3(bool toggle);

	extern bool O4;
	void o4(bool toggle);

	extern bool O5;
	void o5(bool toggle);

	extern bool O6;
	void o6(bool toggle);

	extern bool O7;
	void o7(bool toggle);

	extern bool O8;
	void o8(bool toggle);

	extern bool O9;
	void o9(bool toggle);

	extern bool O10;
	void o10(bool toggle);

	extern bool O11;
	void o11(bool toggle);

	extern bool O12;
	void o12(bool toggle);

	extern bool KeyNote;
	void keyNote(bool toggle);

	extern bool F4;
	void f4(bool toggle);

	extern bool F7;
	void f7(bool toggle);

	extern bool Particle;
	void particle(bool toggle);

	extern bool Hulk;
	void hulk(bool toggle);



	extern bool STRW;
	void strw(bool toggle);

	//tuneables


	extern char* BodyguardModel2;
	extern char* WeaponThing2;
	extern char* BodyguardModel;
	extern char* WeaponThing;
	extern char* GlowThing;
	extern char* GlowThing2;
	extern char* GlowThing3;
	void Mainbodyguardss();
	void Weaponss();
	void Modelss();
	extern Hash weaponsList[];
	void gae();

	void Visions();
	void Anim();
	void Scen();

	void Anim1();
	void Scen1();


	void Outfit();
	void Locationsub();
	void Effects();

	void PTFXCALLBoneless(char* call1, char* call2, char* name, int bone);

	void PTFXCALLBoneless2(char* call1, char* call2, char* name, int bone);

	void Alien();
	void Clown();

	extern bool ToggleGlow;
	extern bool Head;
	extern bool Arm;
	extern bool Arm2;
	extern bool Foot;
	extern bool Foot2;



	extern bool pToggleGlow;
	extern bool pHead;
	extern bool pArm;
	extern bool pArm2;
	extern bool pFoot;
	extern bool pFoot2;

	extern bool walkinair;

	extern int r, b, g;


	extern int EffectsChar;



	extern int torso;
	void torser();
	extern int torsotexture;
	void torsertexture();
	extern int face;
	void facer();
	extern int facetexture;
	void facertexture();
	extern int head;
	void header();
	extern int headtexture;
	void headertexture();
	extern int hair;
	void hairer();
	extern int hairtexture;
	void hairertexture();
	extern int legs;
	void legser();
	extern int legstexture;
	void legsertexture();
	extern int hands;
	void handser();
	extern int handstexture;
	void handsertexture();
	extern int feet;
	void feeter();
	extern int feettexture;
	void feetertexture();
	extern int eyes;
	void eyeser();
	extern int eyestexture;
	void eyesertexture();
	extern int accesories;
	void accesorieser();
	extern int accesoriestexture;
	void accesoriesertexture();
	extern int accesoriessec;
	void accesoriesersec();
	extern int accesoriessectexture;
	void accesoriesersectexture();
	extern int textures;
	void textureser();
	extern int texturestexture;
	void texturesertexture();
	extern int torsosec;
	void torsersec();
	extern int torsosectexture;
	void torsersectexture();
	extern int hats;
	void hatser();
	extern int hatstexture;
	void hatsertexture();
	extern int glasses;
	void glasser();
	extern int glassestexture;
	void glassertexture();
	extern int ears;
	void earser();
	extern int earstexture;
	void earsertexture();
	extern int watches;
	void watcher();
	extern int watchestexture;
	void watchertexture();
}

