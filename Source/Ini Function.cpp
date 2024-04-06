#include "stdafx.h"
#include "Ini Function.h"


void INI::WriteString(std::string file, std::string string, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}
std::string INI::GetString(std::string file, std::string app, std::string key)
{
	char buf[100];//100
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());//100
	return (std::string)buf;
}

void INI::WriteInt(std::string file, int value, std::string app, std::string key)
{
	INI::WriteString(file, std::to_string(value), app, key);
}
int INI::GetInt(std::string file, std::string app, std::string key)
{
	return std::stoi(INI::GetString(file, app, key));
}

void INI::WriteFloat(std::string file, float value, std::string app, std::string key)
{
	INI::WriteString(file, std::to_string(value), app, key);
}
float INI::GetFloat(std::string file, std::string app, std::string key)
{
	return std::stof(INI::GetString(file, app, key));
}

void INI::WriteVector3(std::string file, Vector3 value, std::string app)
{
	INI::WriteString(file, std::to_string(value.x), app, "X");
	INI::WriteString(file, std::to_string(value.y), app, "Y");
	INI::WriteString(file, std::to_string(value.z), app, "Z");
}
Vector3 INI::GetVector3(std::string file, std::string app)
{
	Vector3 out;
	out.x = stof(INI::GetString(file, app, "X"));
	out.y = stof(INI::GetString(file, app, "Y"));
	out.z = stof(INI::GetString(file, app, "Z"));
	return out;
}

void INI::WriteChar(std::string file, char* value, std::string app, std::string key)
{
	std::string var0(value);
	INI::WriteString(file, var0, app, key);
}
char* INI::GetChar(std::string file, std::string app, std::string key)
{
	std::string str = INI::GetString(file, app, key);
	char *cstr = new char[str.length() + 1];
	return strcpy(cstr, str.c_str());
}

void INI::WriteRGBA(std::string file, RGBA value, std::string app)
{
	INI::WriteInt(file, value.r, app, "R");
	INI::WriteInt(file, value.g, app, "G");
	INI::WriteInt(file, value.b, app, "B");
	INI::WriteInt(file, value.a, app, "A");
}
RGBA INI::GetRGBA(std::string file, std::string app)
{
	RGBA out;
	out.r = INI::GetInt(file, app, "R");
	out.g = INI::GetInt(file, app, "G");
	out.b = INI::GetInt(file, app, "B");
	out.a = INI::GetInt(file, app, "A");
	return out;
}

void INI::WriteBool(std::string file, bool value, std::string app, std::string key)
{
	value ? INI::WriteString(file, "true", app, key) : INI::WriteString(file, "false", app, key);
}

bool INI::GetBool(std::string file, std::string app, std::string key)
{
	if (INI::GetString(file, app, key) == "true") {
		return true;
	}
	else if (INI::GetString(file, app, key) == "false") {
		return false;
	}
}


/*Component ID - Name

0 - Head
1 - Beard
2 - Hair
3 - Torso
4 - Legs
5 - Hands
6 - Foot
7 - None?
8 - Accessories like parachute, scuba tank
9 - Accessories like bags, mask, scuba mask
10- Decals and mask
11 - Auxiliary parts for torso*/

int drawablemax, texturemax, drawid, textid;
int Bearddrawablemax, Beardtexturemax, Bearddrawid, Beardtextid;
int Hairdrawablemax, Hairtexturemax, Hairdrawid, Hairtextid;
int Torsodrawablemax, Torsotexturemax, Torsodrawid, Torsotextid;
int Legsdrawablemax, Legstexturemax, Legsdrawid, Legstextid;
int HBdrawablemax, HBtexturemax, HBdrawid, HBtextid;
int Shoedrawablemax, Shoetexturemax, Shoedrawid, Shoetextid;
int TSNBdrawablemax, TSNBtexturemax, TSNBdrawid, TSNBtextid;
int Topdrawablemax, Toptexturemax, Topdrawid, Toptextid;
int TAdrawablemax, TAtexturemax, TAdrawid, TAtextid;
int EDdrawablemax, EDtexturemax, EDdrawid, EDtextid;
int Tops2drawablemax, Tops2texturemax, Tops2drawid, Tops2textid;

int Hatsdrawablemax, Hatstexturemax, Hatsdrawid, Hatstextid;
int Glassesdrawablemax, Glassestexturemax, Glassesdrawid, Glassestextid;
int EarPiecesdrawablemax, EarPiecestexturemax, EarPiecesdrawid, EarPiecestextid;
int Watchesdrawablemax, Watchestexturemax, Watchesdrawid2, Watchestextid3;
int Banglesdrawablemax, Banglestexturemax, Banglesdrawid2, Banglestextid3;
int Unknowndrawablemax1, Unknowntexturemax1, Unknowndrawid1, Unknowntextid1;
int Unknowndrawablemax2, Unknowntexturemax2, Unknowndrawid2, Unknowntextid2;
int Unknowndrawablemax3, Unknowntexturemax3, Unknowndrawid3, Unknowntextid3;
int Unknowndrawablemax4, Unknowntexturemax4, Unknowndrawid4, Unknowntextid4;
int Unknowndrawablemax5, Unknowntexturemax5, Unknowndrawid5, Unknowntextid5;


//Prop_Component("Hats", 0, Hatsdrawablemax, Hatstexturemax, Hatsdrawid, Hatstextid);
//Prop_Component("Glasses", 1, Glassesdrawablemax, Glassestexturemax, Glassesdrawid, Glassestextid);
//Prop_Component("Ear Pieces", 2, EarPiecesdrawablemax, EarPiecestexturemax, EarPiecesdrawid, EarPiecestextid);
//Prop_Component("Watches", 6, Watchesdrawablemax, Watchestexturemax, Watchesdrawid2, Watchestextid3);
//Prop_Component("Bangles", 7, Banglesdrawablemax, Banglestexturemax, Banglesdrawid2, Banglestextid3);
//Prop_Component("Unknown1", 3, Unknowndrawablemax1, Unknowntexturemax1, Unknowndrawid1, Unknowntextid1);
//Prop_Component("Unknown2", 4, Unknowndrawablemax2, Unknowntexturemax2, Unknowndrawid2, Unknowntextid2);
//Prop_Component("Unknown3", 5, Unknowndrawablemax3, Unknowntexturemax3, Unknowndrawid3, Unknowntextid3);
//Prop_Component("Unknown4", 8, Unknowndrawablemax4, Unknowntexturemax4, Unknowndrawid4, Unknowntextid4);
//Prop_Component("Unknown5", 9, Unknowndrawablemax5, Unknowntexturemax5, Unknowndrawid5, Unknowntextid5);

void Clothing_Component(char* Option, int colthing, int drawablemax, int texturemax, int drawid, int textid)
{

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	std::string Style = (" Style");
	std::string fullname = Option + Style;
	drawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, colthing);
	texturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, colthing, drawid);
	drawid = PED::GET_PED_DRAWABLE_VARIATION(playerPed, colthing);
	textid = PED::GET_PED_TEXTURE_VARIATION(playerPed, colthing);
	if (Menu::Int(Option, drawid, 0, drawablemax))
		PED::SET_PED_COMPONENT_VARIATION(playerPed, colthing, drawid, textid, 0);
	if (Menu::Int(Menu::Tools::StringToChar(fullname), textid, 0, texturemax))
		PED::SET_PED_COMPONENT_VARIATION(playerPed, colthing, drawid, textid, 0);
}

void Prop_Component(char* Option, int prop, int drawablemax, int texturemax, int drawid, int textid)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	std::string Style = (" Style");
	std::string fullname = Option + Style;
	drawablemax = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, prop);
	texturemax = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(playerPed, prop, drawid);
	if (Menu::Int(Option, drawid, 0, drawablemax))
		PED::SET_PED_PROP_INDEX(playerPed, prop, drawid, textid, 0);
	if (Menu::Int(Menu::Tools::StringToChar(fullname), textid, 0, texturemax))
		PED::SET_PED_PROP_INDEX(playerPed, prop, drawid, textid, 0);
}

void colthing()
{
	Menu::Title("");
	Menu::SubTitle("Clothing/Props");
	Clothing_Component("Beard/Mask", 1, Bearddrawablemax, Beardtexturemax, Bearddrawid, Beardtextid);
	Clothing_Component("Hair", 2, Hairdrawablemax, Hairtexturemax, Hairdrawid, Hairtextid);
	Clothing_Component("Torso", 3, Torsodrawablemax, Torsotexturemax, Torsodrawid, Torsotextid);
	Clothing_Component("Legs", 4, Legsdrawablemax, Legstexturemax, Legsdrawid, Legstextid);
	Clothing_Component("Hands/Back", 5, HBdrawablemax, HBtexturemax, HBdrawid, HBtextid);
	Clothing_Component("shoe", 6, Shoedrawablemax, Shoetexturemax, Shoedrawid, Shoetextid);
	Clothing_Component("Teeth/Scarf/Necklace/Bracelets", 7, TSNBdrawablemax, TSNBtexturemax, TSNBdrawid, TSNBtextid);
	Clothing_Component("Accessory/Tops", 8, Topdrawablemax, Toptexturemax, Topdrawid, Toptextid);
	Clothing_Component("Task/Armour", 9, TAdrawablemax, TAtexturemax, TAdrawid, TAtextid);
	Clothing_Component("Emblem/Decals", 10, EDdrawablemax, EDtexturemax, EDdrawid, EDtextid);
	Clothing_Component("Tops2 (Outer)", 11, Tops2drawablemax, Tops2texturemax, Tops2drawid, Tops2textid);

	Prop_Component("Hats", 0, Hatsdrawablemax, Hatstexturemax, Hatsdrawid, Hatstextid);
	Prop_Component("Glasses", 1, Glassesdrawablemax, Glassestexturemax, Glassesdrawid, Glassestextid);
	Prop_Component("Ear Pieces", 2, EarPiecesdrawablemax, EarPiecestexturemax, EarPiecesdrawid, EarPiecestextid);
	Prop_Component("Watches", 6, Watchesdrawablemax, Watchestexturemax, Watchesdrawid2, Watchestextid3);
	Prop_Component("Bangles", 7, Banglesdrawablemax, Banglestexturemax, Banglesdrawid2, Banglestextid3);
	Prop_Component("Unknown1", 3, Unknowndrawablemax1, Unknowntexturemax1, Unknowndrawid1, Unknowntextid1);
	Prop_Component("Unknown2", 4, Unknowndrawablemax2, Unknowntexturemax2, Unknowndrawid2, Unknowntextid2);
	Prop_Component("Unknown3", 5, Unknowndrawablemax3, Unknowntexturemax3, Unknowndrawid3, Unknowntextid3);
	Prop_Component("Unknown4", 8, Unknowndrawablemax4, Unknowntexturemax4, Unknowndrawid4, Unknowntextid4);
	Prop_Component("Unknown5", 9, Unknowndrawablemax5, Unknowntexturemax5, Unknowndrawid5, Unknowntextid5);
}