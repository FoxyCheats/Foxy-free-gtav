#include "stdafx.h"


void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
//	UI::SET_TEXT_DROPSHADOW(0, 255, 255, 255, 0);
//	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
//	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}


void Menu::Drawing::Text2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	UI::SET_TEXT_DROPSHADOW(0, 255, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}



void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
}

float gGlareDir;
float conv360(float base, float min, float max)
{
	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= SYSTEM::ROUND(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}
static float ScrollerSpeed = 0.10f; // Scroller speed okie dokie 0.45
float prevf;

void scroll(int* prev, const int cur) {
	if (prevf == NULL)
		prevf = *prev * 0.035f + 0.1415f;
	const auto curf = cur * 0.035f + 0.1415f;
	if (*prev != cur) {
		GRAPHICS::DRAW_RECT(Menu::Settings::menuX, cur * 0.035f + 0.1415f,
			Menu::Settings::menuXscale, 0.038f, Menu::Settings::scroller.r,
			Menu::Settings::scroller.g, Menu::Settings::scroller.b,
			Menu::Settings::scroller.a);

		GRAPHICS::DRAW_RECT(Menu::Settings::menuX, cur * 0.035f + 0.1415f + 0.150f,Menu::Settings::menuXscale, 0.08f, Menu::Settings::scroller.r,Menu::Settings::scroller.g, Menu::Settings::scroller.b,Menu::Settings::scroller.a);


		if (prevf < curf) {
			if (prevf + ScrollerSpeed > curf)
				prevf = prevf + (curf - prevf);
			else
				prevf = prevf + ScrollerSpeed;
			GRAPHICS::DRAW_RECT(Menu::Settings::menuX, prevf,
				Menu::Settings::menuXscale, 0.035f,
				Menu::Settings::scroller.r, Menu::Settings::scroller.g,
				Menu::Settings::scroller.b, Menu::Settings::scroller.a);

			GRAPHICS::DRAW_RECT(Menu::Settings::menuX + 0.12f, prevf + 0.150f ,Menu::Settings::menuXscale, 0.08f, Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b, Menu::Settings::scroller.a);


			if (prevf >= curf) {
				prevf = curf;
				*prev = cur;
			}
		}
		if (prevf > curf) {
			if (prevf - ScrollerSpeed < curf)
				prevf = prevf - (prevf - curf);
			prevf = prevf - ScrollerSpeed;
			GRAPHICS::DRAW_RECT(Menu::Settings::menuX, prevf,
				Menu::Settings::menuXscale, 0.035f,
				Menu::Settings::scroller.r, Menu::Settings::scroller.g,
				Menu::Settings::scroller.b, Menu::Settings::scroller.a);
			if (prevf <= curf) {
				prevf = curf;
				*prev = cur;
			}
		}
	}
	else {
		*prev = cur;
		GRAPHICS::DRAW_RECT(Menu::Settings::menuX, cur * 0.035f + 0.1415f,
			Menu::Settings::menuXscale, 0.035f, Menu::Settings::scroller.r,
			Menu::Settings::scroller.g, Menu::Settings::scroller.b,
			Menu::Settings::scroller.a);
	}
}

float Menu::Settings::menuXscale = 0.21f;
float Menu::Settings::menuX = 0.17f;
bool Menu::Settings::selectPressed = false;
float Menu::Settings::bulletp;
float Menu::Settings::ptfxsizeveh;
float Menu::Settings::ptfxsize;
bool Menu::Settings::selectPressed2 = true;
bool Menu::Settings::leftPressed = false;
bool Menu::Settings::rightPressed = false;
bool Menu::Settings::upPressed = false;
bool Menu::Settings::downPressed = false;
bool Menu::Settings::animatedheader = false;
int Menu::Settings::hornpower = 100;
float Menu::Settings::scrollbarX = 0.9300f;
float Menu::Settings::pitch1;//pitch1
bool firstopen = true;
int Menu::Settings::maxVisOptions = 16;
int Menu::Settings::maxVisOptionsEnd = 12;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;
int Menu::Settings::Title2 = 0;
SubMenus Menu::Settings::currentMenu;
int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];
SubMenus Menu::Settings::menusArray[1000];


float Menu::Settings::test1 = 0.78f;
float Menu::Settings::test2 = 0.180f;
float Menu::Settings::test3 = 0.55f;
float Menu::Settings::test4 = 0.183f;
float Menu::Settings::test5 = 0.21f;
float Menu::Settings::test6 = 0.17f;
float Menu::Settings::test7 = 0.21f;



RGBA Menu::Settings::wantedlevel{ 0, 5, 0 };
RGBA Menu::Settings::powervalue{ 1, 1000, 0 }; // Power
RGBA Menu::Settings::torquevalue{ 1, 1000, 0 }; // Torque
RGBA Menu::Settings::frictionvalue{ 1, 1000, 0 }; // Friction
RGBA Menu::Settings::accelerationvalue{ 1, 1000, 0 }; // Acceleration
RGBA Menu::Settings::suspentionvalue{ 1, 1000, 0 }; // camera
RGBA Menu::Settings::lightvalue{ 1, 1000, 0 }; // Light

RGBA Menu::Settings::Suspention{ 1, 1000, 0 }; // Suspention heigh
RGBA Menu::Settings::Suspention2{ 1, 1000, 0 }; // force
RGBA Menu::Settings::Suspention3{ 1, 1000, 0 }; // custom
RGBA Menu::Settings::Mass{ 1, 1000, 0 }; // Mass
RGBA Menu::Settings::Buoyancy{ 1, 1000, 0 }; //Buoyancy








RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::count2{ 135, 2, 201, 255, 6 };
RGBAF Menu::Settings::titleText{ 255, 255, 255, 255, 7 };
RGBA Menu::Settings::titleRect{ 181, 235, 245, 255 };//here
RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::SubtitleText{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 1 };
RGBAF Menu::Settings::arrow{ 255, 255, 255, 255, 3 };                          // Mod Menu Colors 
RGBA Menu::Settings::optionRect{ 181, 235, 245, 150 };//here
RGBA Menu::Settings::MoveY{ 0, 0, 255, 150 };
RGBA Menu::Settings::SubTitle{ 0, 0, 0, 255 };//here

RGBA Menu::Settings::scroller{ 0, 184, 217, 255 };//here
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 2 };
RGBA Menu::Settings::line{ 0, 0, 0, 255 };
RGBA Menu::Settings::InfoRect{ 0, 0, 0, 255 };
RGBA Menu::Settings::InfoRect1{ 0, 0, 0, 255 };
RGBA Menu::Settings::line2{ 255, 255, 255, 255 };
RGBA Menu::Settings::primary{ 255, 0, 0 };
RGBA Menu::Settings::secondary{ 0, 255, 0 };
RGBA Menu::Settings::Running{ 0, 20, 0 };
//jiggy
RGBA Menu::Settings::JiggyLine{ 255, 255, 255, 255 };

RGBA Menu::Settings::JiggyRect{ 0, 0, 0, 220 };
RGBAF Menu::Settings::JiggyTittle{ 255, 255, 255, 255, 1 };

//Independence
RGBAF Menu::Settings::SubtitleText4{ 255, 255, 255, 255, 7 };
RGBA Menu::Settings::color4{ 105, 245, 66, 255 };

//Quantum 
RGBA Menu::Settings::color5{ 9, 15, 24, 255 };
RGBA Menu::Settings::color6{ 57, 196, 194, 255 };
RGBA Menu::Settings::color7{ 9, 15, 24, 200 };
RGBAF Menu::Settings::rgbafcolor6{ 57, 196, 194, 255, 6 };

//Astolfo
RGBAF Menu::Settings::color8{ 208, 0, 255, 255, 6 };
RGBAF Menu::Settings::color9{ 81, 0, 255, 255, 6 };

//Furry - Spec 

RGBA Menu::Settings::SpecLine{ 230, 184, 230, 255 };



//Hell Vengence v4
float Menu::Settings::topmiddleX = 0.000f;
float Menu::Settings::topmiddleY = 0.131f;
float Menu::Settings::topmiddleW = 0.201f;
float Menu::Settings::topmiddleH = 0.004f;
RGBA Menu::Settings::HellLine{ 255, 0, 0, 255 };


float Menu::Settings::down1Y = 0.775994f;
float Menu::Settings::down1X = 0.000f;
float Menu::Settings::down1W = 0.198f;
float Menu::Settings::down1H = 0.004f;



float Menu::Settings::down2X = 0.000f;
float Menu::Settings::down2Y = 0.720994f;
float Menu::Settings::down2W = 0.198f;
float Menu::Settings::down2H = 0.004f;


float Menu::Settings::Header1X = 0.000f;
float Menu::Settings::Header1Y =  -0.034f;
float Menu::Settings::Header1W = 0.000f;
float Menu::Settings::Header1H = 0.070f;

float Menu::Settings::Header2X = 0.000f;
float Menu::Settings::Header2Y = 0.330999f;
float Menu::Settings::Header3Y = 0.781993f;
float Menu::Settings::Header4Y = 0.330999f;
float Menu::Settings::Header2W = 0.000f;
float Menu::Settings::Header2H = 0.517997f;
float Menu::Settings::Header3H = 0.239000f;
float Menu::Settings::Header4H = 0.517997f;


float Menu::Settings::CreditX = 0.000f;
float Menu::Settings::CreditY = 0.000f;
float Menu::Settings::CreditW = 0.000f;
float Menu::Settings::CreditH = 0.000f;




//Other stuff
char* Menu::Settings::Animated_Header;
int  Menu::Settings::current_frame;
int  Menu::Settings::delay = 40;


int  Menu::Settings::toggler = 43;
int  Menu::Settings::toggleg = 0;
int  Menu::Settings::toggleb = 255;



void UdateLoop()
{
	static auto ticker = GetTickCount();
	if ((GetTickCount() - ticker) >= Menu::Settings::delay) {
		if (Menu::Settings::current_frame >= 10) {
			Menu::Settings::current_frame = 1;
		}
		else {
			Menu::Settings::current_frame++;
		}
		Menu::Settings::Animated_Header = _strdup(("frame" + std::to_string(Menu::Settings::current_frame)).c_str());
		ticker = GetTickCount();
	}


}

bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

static fpFileRegister file_register = (fpFileRegister)(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<decltype(file_register)>());

int Menu::Settings::CurSub = 0;
int Menu::Settings::CurHeader = 5;

void YTD()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("Header", false);
}

void YTD3()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionRectUI", false);
}
void YTD4()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionScrollerUI", false);
}
void YTD5()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionEndUI", false);
}

void YTD6()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionScrollBarAUI", false);
}

void YTD7()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionScrollBarBUI", false);
}

void YTD8()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionScrollBarTopUI", false);
}

void YTD9()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionScrollBarEndUI", false);
}


void YTD10()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionToggleOnUI", false);
}

void YTD11()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("OptionToggleOffUI", false);
}

void YTD12()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("SterlingRect", false);
}
void YTD13()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("FoxyLogo", false);
}

void YTD14()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("SterlingGradient", false);
}


void YTD15()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("FoxyCrashLogo", false);
}

void YTD16()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("HellVengence", false);
}

void drawvehicle(char* carname)
{
	std::string path = "C://Foxy/";
	std::string name = "FoxyCar.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath)) {
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(carname, false);
		
			Menu::Drawing::Spriter("FoxyCar", carname, Menu::Settings::menuX + 0.20f, 0.15f + (0.038f / 2.f) + 0.0075f, 0.13f, 0.13f, 0, 0, 0, 0, 0);
		
	}
}

void drawCustomBanner() {
	if (Menu::Settings::animatedheader == true) {
		Menu::Drawing::Spriter("Foxy", Menu::Settings::Animated_Header, Menu::Settings::menuX, 0.097f, 0.20f, 0.073f, 0, 255, 255, 255, 0);
	}
	if (Menu::Settings::animatedheader == false) {
		if (Menu::Settings::CurHeader == 0) {
			Menu::Drawing::Spriter("Foxy", "Header", Menu::Settings::menuX, 0.097f -0.004f, 0.20f, 0.073f, 0, 255, 255, 255, 255);
		}
		if (Menu::Settings::CurHeader == 1) {
			Menu::Drawing::Spriter("Foxy", "Header2", Menu::Settings::menuX, 0.097f - 0.004f, 0.20f, 0.073f, 0, 255, 255, 255, 255);
		}
		if (Menu::Settings::CurHeader == 2) {
			Menu::Drawing::Text("~p~J~b~i~p~g~b~g~p~y", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.06f }, { 0.85f, 0.85f }, true);
			Menu::Drawing::Rect(Menu::Settings::JiggyLine, { Menu::Settings::menuX + 0.10f, 0.09f }, { 0.002f, 10.f });// right 
			Menu::Drawing::Rect(Menu::Settings::JiggyLine, { Menu::Settings::menuX - 0.1f, 0.09f }, { 0.002f, 10.f });// Left (Jiggy UI) 
		}
		if (Menu::Settings::CurHeader == 3) {

		}
		if (Menu::Settings::CurHeader == 4) {
			Menu::Drawing::Text("~p~Sterling", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.06f }, { 1.20f, 1.20f }, true);
			//Drawing::Rect(Settings::color4, { Settings::menuX, 0.147f - 0.023f }, { 0.20f, 0.0706f });
		}
		if (Menu::Settings::CurHeader == 5) {
			Menu::Drawing::Spriter("Foxy", "Header4", Menu::Settings::menuX, 0.097f - 0.004f, 0.20f, 0.073f, 0, 255, 255, 255, 255);
		}
		if (Menu::Settings::CurHeader == 6) {
			Menu::Drawing::Text("~q~Gaymer", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.06f }, { 1.20f, 1.20f }, true);
		}
		if (Menu::Settings::CurHeader == 9) {
			//Hell vengence v4
			Menu::Drawing::Spriter("Foxy", "HellVengence", Menu::Settings::menuX + Menu::Settings::Header1X, 0.097f - 0.004f + Menu::Settings::Header1Y, 0.20f+ Menu::Settings::Header1W, 0.073f + Menu::Settings::Header1H, 0, 255, 255, 255, 255); //Header Pos 
			Menu::Drawing::Spriter("Foxy", "HellVengenceBackground", Menu::Settings::menuX + Menu::Settings::Header2X, 0.097f - 0.004f + Menu::Settings::Header2Y, 0.20f+ Menu::Settings::Header2W, 0.073f + Menu::Settings::Header2H, 0, 255, 255, 255, 255); //Header Pos 
			Menu::Drawing::Spriter("Foxy", "HellVengenceBackground2", Menu::Settings::menuX + Menu::Settings::Header2X, 0.097f - 0.004f + Menu::Settings::Header3Y, 0.20f+ Menu::Settings::Header2W, 0.073f + Menu::Settings::Header3H, 0, 255, 255, 255, 255); //Header Pos 
		//	Menu::Drawing::Spriter("Foxy", "HellVengenceBackground3", Menu::Settings::menuX + Menu::Settings::Header2X, 0.097f - 0.004f + Menu::Settings::Header4Y, 0.20f+ Menu::Settings::Header2W, 0.073f + Menu::Settings::Header4H, 0, 255, 255, 255, 255); //Header Pos 
			if (NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == PLAYER::PLAYER_PED_ID()) {
				Menu::Drawing::Text2("Status : Host", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.06f }, { 0.85f, 0.85f }, true);
				Menu::Drawing::Text2("Devlopped By Foxy", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, Menu::Settings::CreditY }, { Menu::Settings::CreditW, Menu::Settings::CreditH }, false);
			}
			else {
				Menu::Drawing::Text2("Status : Not Host", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.06f }, { 0.85f, 0.85f }, true);
				Menu::Drawing::Text2("Devlopped By Foxy", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, Menu::Settings::CreditY }, { Menu::Settings::CreditW, Menu::Settings::CreditH }, false);
			}
			Menu::Drawing::Rect(Menu::Settings::HellLine, { Menu::Settings::menuX + 0.10f, 0.09f }, { 0.002f, 10.f });// right 
			Menu::Drawing::Rect(Menu::Settings::HellLine, { Menu::Settings::menuX - 0.1f, 0.09f }, { 0.002f, 10.f });// Left 

			//Menu::Drawing::Text2("Devlopped By Foxy", Menu::Settings::JiggyTittle, { Menu::Settings::menuX, Menu::Settings::CreditY }, { Menu::Settings::CreditW, Menu::Settings::CreditH }, false);
			Menu::Drawing::Rect(Menu::Settings::HellLine, { Menu::Settings::menuX  + Menu::Settings::topmiddleX, Menu::Settings::topmiddleY }, { Menu::Settings::topmiddleW, Menu::Settings::topmiddleH });// top middle   
			Menu::Drawing::Rect(Menu::Settings::HellLine, { Menu::Settings::menuX + Menu::Settings::down1X, Menu::Settings::down1Y }, { Menu::Settings::down1W,  Menu::Settings::down1H });//  down 1
			Menu::Drawing::Rect(Menu::Settings::HellLine, { Menu::Settings::menuX + Menu::Settings::down2X, Menu::Settings::down2Y }, { Menu::Settings::down2W,  Menu::Settings::down2H });//  down 2
		}
	}
}
////Drawing::Rect(Settings::color4, { Settings::menuX, 0.147f - 0.023f }, { 0.20f, 0.0706f });

void YTD1() 
{
	static uint32_t* (*pRegisterFile)(int*, const char*, bool, const char*, bool) = reinterpret_cast<decltype(pRegisterFile)>(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<void>(0));
	std::string path = "C://Foxy/";
	std::string name = "Sub.ytd";
	const std::string fullPath = path + name;

	int textureID;
	pRegisterFile(&textureID, fullPath.c_str(), true, name.c_str(), false);
}


void Menu::Drawing::DrawGlare(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b)
{

	float g_glare_dir = 0;

	auto g_glare_handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(static_cast<char*>("MP_MENU_GLARE"));

	const auto rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);

	const auto dir = conv360(rot.z, 0, 360);

	if ((g_glare_dir == 0 || g_glare_dir - dir > 0.5) || g_glare_dir - dir < -0.5)

	{

		g_glare_dir = dir;

		GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(g_glare_handle, static_cast<char*>("SET_DATA_SLOT"));

		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(g_glare_dir);

		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

	}

	GRAPHICS::DRAW_SCALEFORM_MOVIE(g_glare_handle, x, y, sx, sy, r, g, b, 20, 0);

	GRAPHICS::_SCREEN_DRAW_POSITION_END();

}

void Menu::Title(const char * title)
{

	//Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.095f }, { 0.85f, 0.85f }, true);
	
	if (Menu::Settings::CurHeader == 0) {
		Drawing::Spriter("Foxy", "Foxy", Settings::menuX, 0.097f - 0.004f, 0.20f, 0.073f, 0, 255, 255, 255, 255);
	}
	if (Menu::Settings::CurHeader == 1) {
		//Drawing::Spriter("Foxy", "Foxy", Settings::menuX, 0.097f - 0.004f, 0.20f, 0.073f, 0, 255, 255, 255, 255);
	}
	if (Menu::Settings::CurHeader == 2) {
		Drawing::Spriter("Foxy", "Foxy", Settings::menuX, 1.0f, 0.20f, 10.0f, 0, 0, 0, 0, 220);
		Drawing::Rect(Settings::JiggyLine, { Settings::menuX + 0.10f,1.0f }, { 0.002f, 10.0f });// right 
		Drawing::Rect(Settings::JiggyLine, { Settings::menuX - 0.1f,1.0f }, { 0.002f, 10.0f });// Left (Jiggy UI) 
	}
	if (Menu::Settings::CurHeader == 3) {
		
	}
	if (Menu::Settings::CurHeader == 4) {

	}
	if (Menu::Settings::CurHeader == 5) {

	}

	if (Menu::Settings::CurHeader == 9) {
	//	Drawing::Spriter("Foxy", "Foxy", Settings::menuX, 1.0f, 0.20f, 10.0f, 0, 0, 0, 0, 220);
		Drawing::Rect(Settings::JiggyLine, { Settings::menuX + 0.10f,1.0f }, { 0.002f, 10.0f });// right 
		Drawing::Rect(Settings::JiggyLine, { Settings::menuX - 0.1f,1.0f }, { 0.002f, 10.0f });// Left (Jiggy UI) 
	}

	drawCustomBanner();
	//ScrollBar();

	// Disable Controls
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
}


//Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.099f }, { 0.85f, 0.85f }, true);
 //Drawing::Rect(Settings::titleRect, { Settings::menuX, 0.0800f }, { 0.21f, 0.090f });
 //Drawing::DrawGlare(0.516999f, 0.481000f, 1.088999f, 0.902000f, 255, 255, 255); //Globe





void Menu::SubTitle(const char * title2)
{
	int opcount = Settings::optionCount;
	int currop = Settings::currentOption;           //longueur  hauteur  { 0.20f, 0.035f });
	if (Menu::Settings::CurHeader == 0) {

		Drawing::Rect(Settings::SubTitle, { Settings::menuX, 0.147f - 0.004f }, { 0.20f, 0.0353f });
		Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX, 0.125f }, { 0.45f, 0.45f }, true);// menux - 0.097f
		//scroll bar top
		Drawing::Rect(Settings::SubTitle, { Settings::menuX + 0.12f, 0.147f - 0.007f }, { 0.011f, 0.0353f });
		Drawing::Spriter("commonmenu", "arrowleft", Settings::menuX + 0.12f, 0.144f, 0.008f, 0.025f, 90, 255, 255, 255, 255);
	}
	if (Menu::Settings::CurHeader == 1) {
		Menu::Drawing::Spriter("Foxy", "OptionRectUI", Menu::Settings::menuX, 0.147f - 0.004f, 0.20f, 0.0353f, 0, 255, 255, 255, 255);
		Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX, 0.125f }, { 0.45f, 0.45f }, true);// menux - 0.097f
		Menu::Drawing::Spriter("Foxy", "OptionScrollBarTopUI", Menu::Settings::menuX + 0.12f, 0.144f, 0.025f, 0.035f, 0, 255, 255, 255, 255);

	}
	if (Menu::Settings::CurHeader == 2) {

		Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX, 0.125f }, { 0.45f, 0.45f }, true);// menux - 0.097f
		
	}
	if (Menu::Settings::CurHeader == 3) {

		Drawing::Text(title2, Settings::SubtitleText4, { Settings::menuX, 0.115f }, { 0.75f, 0.65f }, true);// menux - 0.097f
		Drawing::Rect(Settings::color4, { Settings::menuX, 0.147f - 0.023f }, { 0.20f, 0.0706f });
		Drawing::Rect(Settings::color4, { Settings::menuX + 0.10f,  0.147f - 0.023f }, { 0.004f, 0.0706f });// right 
		Drawing::Rect(Settings::color4, { Settings::menuX - 0.10f,  0.147f - 0.023f }, { 0.004f, 0.0706f }); //left
	}
	if (Menu::Settings::CurHeader == 4) {
		//Drawing::Rect(Settings::color4, { Settings::menuX, 0.147f - 0.023f }, { 0.20f, 0.0706f });

		Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX - 0.080f, 0.100f  }, { 0.45f, 0.45f }, true);
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count2, { Settings::menuX + 0.078f,0.100f }, { 0.35f, 0.35f }, true);
	    Menu::Drawing::Spriter("Foxy", "SterlingGradient", Menu::Settings::menuX, 0.41975f, 0.22f, 17 * 0.03711f + 0.18f, 0, 255, 255, 255, 255);
		Menu::Drawing::Spriter("Foxy", "SterlingRect", Menu::Settings::menuX,  0.47825f, 0.20f, 17 * 0.03711f, 0, 255, 255, 255, 255);
		Menu::Drawing::Spriter("Foxy", "Header3", Menu::Settings::menuX, 0.090f, 0.20f, 0.123f, 0, 255, 255, 255, 255);


	}
	if (Menu::Settings::CurHeader == 5) {

		Drawing::Rect(Settings::color5, { Settings::menuX, 0.147f - 0.004f }, { 0.20f, 0.0353f });
		if (opcount >= 16) {

			Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX - 0.0780f,17 * 0.035f + 0.130f }, { 0.45f, 0.45f }, false);

		}
		else if (opcount > 0) {
			Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX - 0.0780f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.45f, 0.45f }, false);

		}
	
	}
	if (Menu::Settings::CurHeader == 6) {
		Menu::Drawing::Spriter("Foxy", "Header6", Menu::Settings::menuX, 0.47825f, 0.20f, 17 * 0.03711f, 0, 255, 255, 255, 255);
		Menu::Drawing::Spriter("Foxy", "Header5", Menu::Settings::menuX, 0.091f, 0.20f, 0.123f + 0.020f, 0, 255, 255, 255, 255);
	}
	if (Menu::Settings::CurHeader == 7) {
		//Spec image
		Menu::Drawing::Spriter("Foxy", "Header7", Menu::Settings::menuX, 0.47825f, 0.20f, 17 * 0.03711f, 0, 255, 255, 255, 255);
		Drawing::Rect(Settings::SpecLine, { Settings::menuX + 0.10f,  0.47825f }, { 0.004f, 17 * 0.03711f });// right 
		Drawing::Rect(Settings::SpecLine, { Settings::menuX - 0.10f,  0.47825f }, { 0.004f, 17 * 0.03711f }); //left
		Drawing::Rect(Settings::SpecLine, { Settings::menuX,  0.47825f + 0.315f }, { 0.204f, 0.004f }); //Bottom


		//Spec Header
		Menu::Drawing::Spriter("Foxy", "Header8", Menu::Settings::menuX, 0.091f, 0.20f, 0.123f + 0.020f, 0, 255, 255, 255, 255);
		Drawing::Rect(Settings::SpecLine, { Settings::menuX,  0.020f}, { 0.204f, 0.004f }); //Top
		Drawing::Rect(Settings::SpecLine, { Settings::menuX + 0.10f,  0.091f }, { 0.004f,  0.123f + 0.020f });// right 
		Drawing::Rect(Settings::SpecLine, { Settings::menuX - 0.1f,  0.091f}, { 0.004f,  0.123f + 0.020f }); //left
	}
	if (Menu::Settings::CurHeader == 8) { //Blasts
		Drawing::Text(title2, Settings::SubtitleText, { Settings::menuX - 0.102f, 0.125f }, { 0.45f, 0.45f }, false);// menux - 0.097f
		Drawing::Rect({ 120, 20, 0, 255 }, { Settings::menuX, 0.147f - 0.004f }, { 0.21f, 0.035f });
	}
	if (Menu::Settings::CurHeader == 9) {//Hell
		Drawing::Text2(title2, Menu::Settings::JiggyTittle, { Menu::Settings::menuX, 0.005f }, { 0.85f, 0.85f }, true);
		//Drawing::Rect({ 120, 20, 0, 255 }, { Settings::menuX, 0.147f - 0.004f }, { 0.21f, 0.035f });
	}
}


void ScrollBar() //255, 0, 255,
{// 181, 235, 245,
	int CurrentOpt = Menu::Settings::currentOption;
	int MaxVision = Menu::Settings::maxVisOptions;
	int OptCount = Menu::Settings::optionCount;
	int SR = 99;
	int SG = 0;
	int SB = 110;
	int SA = 255;
	int SR2 = 89;
	int SG2 = 67;
	int SB2 = 99;
	int SA2 = 150;
	bool onThis = CurrentOpt == OptCount ? true : false;
		//(Settings::optionCount * 0.035f + 0.141f)
			GRAPHICS::DRAW_RECT(Menu::Settings::menuX + 0.12f, (Menu::Settings::optionCount * 0.035f + 0.141f), 0.011f, 0.9f, SR2, SG2, SB2, SA2);
			///                 float pos x              float pos y   wide    Height           color 
			GRAPHICS::DRAW_RECT(Menu::Settings::menuX + 0.12f, ((((MaxVision * (CurrentOpt * 0.030f)) / OptCount))) + 0.150f, 0.008f, 0.025f, SR, SG, SB, SA);
			///                          float pos x                 float pos y                                             wide    Height           color 
}

bool Menu::Option(const char * option)
{
RGBA ArrowLeft{ 26, 3, 90, 255 };
	Settings::optionCount++;
	if (Menu::Settings::CurHeader == 0) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.12f, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.011f, 0.035f });
			//Drawing::Spriter("Textures", "Background", Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f, 0.26f, 0.035f, 0, custom.r, custom.g, custom.b, 255);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX + 0.12f, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.008f, 0.025f }) : NULL;// done
			//onThis ? Drawing::Rect(ArrowLeft, { Settings::menuX - 0.12f, (Settings::optionCount)*0.035f + 0.1415f }, { 0.05f, 0.035f }) : NULL;
			//ScrollBar();

		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.12f,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.011f, 0.035f });
			//Drawing::Spriter("Textures", "Background", Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f, 0.26f, 0.035f, 0, custom.r, custom.g, custom.b, 255);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX + 0.12f,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.008f, 0.025f }) : NULL;
			//onThis ? Drawing::Rect(ArrowLeft, { Settings::menuX - 0.12f,  (Settings::optionCount - (Settings::currentOption - 16))*0.02f + 0.1415f }, { 0.05f, 0.035f }) : NULL;
			//ScrollBar();
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 1) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			Menu::Drawing::Spriter("Foxy", "OptionRectUI", Menu::Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255);
		
			Menu::Drawing::Spriter("Foxy", "OptionScrollBarBUI", Menu::Settings::menuX + 0.12f, (Settings::optionCount) * 0.035f + 0.1415f, 0.025f, 0.0358f, 0, 255, 255, 255, 255);

			onThis ? Drawing::Spriter("Foxy", "OptionScrollerUI", Menu::Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255) : NULL;
			onThis ? Drawing::Spriter("Foxy", "OptionScrollBarAUI", Menu::Settings::menuX + 0.12f, (Settings::optionCount) * 0.035f + 0.1415f, 0.023f, 0.035f, 0, 255, 255, 255, 255) : NULL;

		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			Menu::Drawing::Spriter("Foxy", "OptionRectUI", Menu::Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255);
			
			Menu::Drawing::Spriter("Foxy", "OptionScrollBarBUI", Menu::Settings::menuX + 0.12f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, 0.025f, 0.0358f, 0, 255, 255, 255, 255);

			onThis ? Drawing::Spriter("Foxy", "OptionScrollerUI", Menu::Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255) : NULL;
			onThis ? Drawing::Spriter("Foxy", "OptionScrollBarAUI", Menu::Settings::menuX + 0.12f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, 0.023f, 0.035f, 0, 255, 255, 255, 255) : NULL;

		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 2) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			//Drawing::Rect(Settings::JiggyRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;


		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			//Drawing::Rect(Settings::JiggyRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f });

			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 3) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::DrawGlare(0.514f, 0.476f, 1.089f, 0.902f - 0.050f, 255, 255, 255) : NULL;
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color4, { Settings::menuX + 0.10f, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.004f, 0.035f });// right 
			Drawing::Rect(Settings::color4, { Settings::menuX - 0.10f, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.004f, 0.035f }); //left
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::DrawGlare(0.514f, 0.476f, 1.089f, 0.902f - 0.050f, 255, 255, 255) : NULL;
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color4, { Settings::menuX + 0.10f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.004f, 0.035f });// right 
			Drawing::Rect(Settings::color4, { Settings::menuX - 0.10f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.004f, 0.035f }); //left
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 4) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Spriter("Foxy", "OptionScrollerUI1", Menu::Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255) : NULL;	
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);//0.03711
			onThis ? Drawing::Spriter("Foxy", "OptionScrollerUI1", Menu::Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255) : NULL;
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}

	if (Menu::Settings::CurHeader == 5) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::color5, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			Drawing::Rect(Settings::color7, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color6, { Settings::menuX + 0.099f, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.0025f, 0.035f });// right 

		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::color5, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			Drawing::Rect(Settings::color7, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color6, { Settings::menuX + 0.099f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.0025f, 0.035f });// right 
			
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 6) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::color8, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::color8, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 7) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.195f, 0.035f }) : NULL;
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.097f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.122f }, { 0.5f, 0.5f }, false);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.195f, 0.035f }) : NULL;
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 8) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
			Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text(option, Settings::optionText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
			Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 9) {
		bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
		if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
		{
			Drawing::Text2(option, Settings::optionText, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f }, { 0.195f, 0.035f }) : NULL;
		}
		else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
		{
			Drawing::Text2(option, Settings::optionText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
			
			onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.195f, 0.035f }) : NULL;
		}
		if (Settings::currentOption == Settings::optionCount)
		{
			if (Settings::selectPressed)
			{
				return true;
			}
		}
		return false;
	}

}
int prevOption = 0; //Add prevOption = 1 to open key on chechKeys in gui.cpp and on numpad0 (back)

void Menu::Drawing::Text2(char* text, int font, float x, float y, float scalex,
	float scaley, RGBA rgba, bool center) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(rgba.r, rgba.g, rgba.b, rgba.a);
	UI::SET_TEXT_CENTRE(center);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

bool Menu::Optionini(const char * option)
{
	Settings::optionCount++;
	bool onThis =
		Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16) {
		Drawing::Text(option, Settings::optionText,
			{ Settings::menuX - 0.100f, (Settings::optionCount) * 0.035f
					+ 0.125f }, { 0.45f, 0.45f }, false);
		Drawing::Rect(Settings::optionRect,
			{ Settings::menuX, (Settings::optionCount) * 0.035f + 0.1415f },
			{ Settings::menuXscale, 0.035f });
		if (Settings::optionCount >= 16) {
			onThis ?
				Drawing::Rect(Settings::scroller,
					{ Settings::menuX, (Settings::optionCount) * 0.035f
							+ 0.1415f },
					{ Settings::menuXscale, 0.035f }) :
				NULL;
		}
		else if (Settings::optionCount > 0) {
			onThis ? scroll(&prevOption, Menu::Settings::currentOption) : NULL;
		}
	}
	else if (Settings::optionCount > (Settings::currentOption - 16)
		&& Settings::optionCount <= Settings::currentOption) {
		Drawing::Text(option, Settings::optionText,
			{ Settings::menuX - 0.100f, (Settings::optionCount
					- (Settings::currentOption - 16)) * 0.035f + 0.125f }, {
					0.45f, 0.45f }, false);
		Drawing::Rect(Settings::optionRect,
			{ Settings::menuX, (Settings::optionCount
					- (Settings::currentOption - 16)) * 0.035f + 0.1415f },
			{ Settings::menuXscale, 0.035f });
		onThis ?
			Drawing::Rect(Settings::scroller,
				{ Settings::menuX, (Settings::optionCount
						- (Settings::currentOption - 16)) * 0.035f
						+ 0.1415f }, { Settings::menuXscale, 0.035f }) :
			NULL;
		if (Settings::optionCount >= 16) {
			onThis ?
				Drawing::Rect(Settings::scroller,
					{ Settings::menuX, (Settings::optionCount
							- (Settings::currentOption - 16)) * 0.035f
							+ 0.1415f },
					{ Settings::menuXscale, 0.035f }) :
				NULL;
		}
		else if (Settings::optionCount > 0) {
			onThis ? scroll(&prevOption, Menu::Settings::currentOption) : NULL;
		}
	}
	if (Settings::currentOption == Settings::optionCount) {
		if (Settings::selectPressed) {
			return true;
		}
	}
	return false;
}



bool Menu::Break(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount)*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.20f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.20f, 0.035f });
	}
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
	YTD1();

	Option(option);
	if (Menu::Settings::CurHeader == 5) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub3", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 0);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub3", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 0);
		}
	}
	if (Menu::Settings::CurHeader == 6) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub1", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub1", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 0) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 1) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 2) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 3) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 4) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 7) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 8) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Text("", Settings::titleText, { Settings::menuX, Settings::optionCount * 0.035f + 0.128f }, { 0.35f, 0.35f }, true);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Text("", Settings::titleText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 14)) * 0.035f + 0.128f }, { 0.35f, 0.35f }, true);
		}
	}
	if (Menu::Settings::CurHeader == 9) {
		if (Menu::Settings::CurSub == 0) {
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, (Settings::optionCount * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "Sub", Settings::menuX + 0.085f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.012f, 0.025f, 0, 255, 255, 255, 255);
		}
	}

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}
void Menu::PlayerOption(int i) {
	if (Menu::Option(PLAYER::GET_PLAYER_NAME(i))) {
		selectedPlayer = i;
		MenuLevelHandler::MoveMenu(pmenu);
	}
}

bool Menu::ListVector(const char * option, std::vector<char*> Vector, int & position)
{

	constexpr static const VECTOR2_2 textSize = { 0.32f, 0.32f };

	Option(option);
	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Menu::Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Menu::Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)Vector[position] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, Menu::Settings::optionCount * 0.035f + 0.128f }, { 0.45f, 0.45f }, true);
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)Vector[position] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, Menu::Settings::optionCount * 0.035f + 0.128f }, { 0.45f, 0.45f }, true);

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed) return true;

	else
		return false;

}

bool Menu::Addintchar(const char * option, char* display[], int & _int, int min, int max)
{
	Option(option);
	int integre;
	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		if (Menu::Settings::rightPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Menu::Settings::leftPressed) {
			_int > min ? _int-- : _int = max;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, Menu::Settings::optionCount * 0.035f + 0.128f }, { 0.45f, 0.45f }, true);
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions))*0.035f + 0.128f }, { 0.45f, 0.45f }, true);

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::leftPressed && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::rightPressed && Menu::Settings::selectPressed) return true;
	return false;
}


int rwws = 255, gwws = 0, bwws = 0;
void RGBFades()
{
	if (rwws > 0 && bwws == 0) {
		rwws--;
		gwws++;
	}
	if (gwws > 0 && rwws == 0) {
		gwws--;
		bwws++;
	}
	if (bwws > 0 && gwws == 0) {
		rwws++;
		bwws--;
	}
}

void Menu::OptionInfo(const char * info)
{
	
	if (Settings::optionCount >= 18)
	{
		RGBFades();
		Drawing::Text2(Tools::StringToChar(info), 6, 0.42f, 0.685f, 0.4f, 0.4f, { 0, 184, 217, 255 }, false);

		//Info Box
		Drawing::Rect({ 0, 0, 0, 200 }, { 0.50f, 0.7f }, { Settings::menuXscale, 0.057f });

		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.50f, 0.67f }, { 0.212f, 0.005f });//small  line top
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.50f, 0.73f }, { 0.212f, 0.005f });//small line down
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.395f, 0.70f }, { 0.002f, 0.0601f });//small line left
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.605f, 0.70f }, { 0.002f, 0.0601f });//small line right
	
		//Drawing::Rect(Settings::InfoRect1, { Settings::menuX, (Settings::optionCount + 2) * 0.035f + 0.1235f }, { 0.20f, 0.035f }); menux = 0.17f menuxscale = 0.21f
		
		// 0.011f, 0.035f
	}
	else if (Settings::optionCount > 0) 
	{

		RGBFades();
		Drawing::Text2(Tools::StringToChar(info), 6, 0.42f, 0.685f, 0.4f, 0.4f, { 0, 184, 217, 255 }, false);

		//Info Box
		Drawing::Rect({ 0, 0, 0, 200 }, { 0.50f, 0.7f }, { Settings::menuXscale, 0.057f });

		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.50f, 0.67f }, { 0.212f, 0.005f });//small  line top
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.50f, 0.73f }, { 0.212f, 0.005f });//small line down
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.395f, 0.70f }, { 0.002f, 0.0601f });//small line left
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.605f, 0.70f }, { 0.002f, 0.0601f });//small line right
		
	//	Drawing::Rect(Settings::InfoRect1, { Settings::menuX, (Settings::optionCount + 2) * 0.035f + 0.1235f }, { 0.20f, 0.035f });
	}

	
}
		
	

	


bool Menu::Addintchar2(const char * option, char* display[], int & _int, int min, int max)
{
	Option(option);
	int integre;
	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		if (Menu::Settings::rightPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Menu::Settings::leftPressed) {
			_int > min ? _int-- : _int = max;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, Menu::Settings::optionCount * 0.035f + 0.128f }, { 0.45f, 0.45f }, true);
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions))*0.035f + 0.128f }, { 0.45f, 0.45f }, true);

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed2) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::leftPressed && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::rightPressed && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::upPressed && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::downPressed && Menu::Settings::selectPressed) return true;
	return false;
}

bool Menu::Addoption(const char * option, std::function<void()> function)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Toggle(const char* option, bool& b00l)
{

	Option(option);
	if (Menu::Settings::CurHeader == 1) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Spriter("Foxy", "OptionToggleOnUI", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 255);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Spriter("Foxy", "OptionToggleOnUI", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("Foxy", "OptionToggleOffUI", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 255);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("Foxy", "OptionToggleOffUI", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 255);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 3) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "Shop_Box_Tick", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "Shop_Box_Tick", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "Shop_Box_Blank", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "Shop_Box_Blank", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 4) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "MP_SpecItem_Weed", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 0, 255, 0, 255);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "MP_SpecItem_Weed", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 0, 255, 0, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "MP_SpecItem_Weed", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "MP_SpecItem_Weed", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 5) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 57, 196, 194, 255);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 57, 196, 194, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 5) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 247, 205, 236, 255);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 247, 205, 236, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 8) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 247, 205, 236, 255);// Toggle on
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 247, 205, 236, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);// Toggle off
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 0, 0, 255);
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	if (Menu::Settings::CurHeader == 9) {

		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
				Drawing::Spriter("commonmenu", "Shop_Box_Tick", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);// Toggle on
				//notifyBottom("ON");
			}
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
				Drawing::Spriter("commonmenu", "Shop_Box_Tick", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);
				//notifyBottom("ON");
			}
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions) {
				Drawing::Spriter("commonmenu", "Shop_Box_Blank", Menu::Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);// Toggle off
				//notifyBottom("OFF");
			}
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption) {
				Drawing::Spriter("commonmenu", "Shop_Box_Blank", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 255, 255, 255, 200);
				//notifyBottom("OFF");
			}
		}// toggle off
		if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
			b00l ^= 1;
			return true;
		}
		return false;
	}
	else
		if (b00l)
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, Menu::Settings::toggler, Menu::Settings::toggleg, Menu::Settings::toggleb, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, Menu::Settings::toggler, Menu::Settings::toggleg, Menu::Settings::toggleb, 255);
		}//
		else
		{
			if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, (Settings::optionCount * 0.035f + 0.141f), 0.015f, 0.025f, 0, 0, 0, 0, 255);
			else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
				Drawing::Spriter("commonmenu", "common_medal", Settings::menuX + 0.084f, ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.015f, 0.025f, 0, 0, 0, 0, 255);
		}
	    if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		    b00l ^= 1;
		    return true;
	    }
	    return false;
}

bool Menu::Toggle1(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Int(const char * option, int & _int, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int-- : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}


bool Menu::Float2(const char* option, float& _float, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.001f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.001f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}


bool Menu::intchar(const char * option, char* display[], int & _int, int min, int max)
{
	Option(option);
	int integre;
	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		if (Menu::Settings::rightPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Menu::Settings::leftPressed) {
			_int > min ? _int-- : _int = max;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, Menu::Settings::optionCount * 0.035f + 0.128f }, { 0.45f, 0.45f }, true);
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption)
		Menu::Drawing::Text(Menu::Tools::StringToChar("[ " + (std::string)display[_int] + " ]"), Menu::Settings::optionText, { Menu::Settings::menuX + 0.070f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions))*0.035f + 0.128f }, { 0.45f, 0.45f }, true);

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::leftPressed && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::rightPressed && Menu::Settings::selectPressed) return true;
	return false;
}

bool Menu::AInt(const char * option, int & _int, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int >= min ? _int-- : _int = max;
		}
		if (Settings::rightPressed) {
			_int < max ? _int++ : _int = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_int)), Settings::optionText, { Settings::menuX + 0.085f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_int)), Settings::optionText, { Settings::menuX + 0.085f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

bool Menu::Float(const char * option, float & _float, int min, int max, int step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.5f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.5f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4244)
#pragma warning(disable: 4267)
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4267)
bool Menu::Teleport(const char * option, Vector3 coords)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		Entity handle;
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords, std::function<void()> function)
{
	Teleport(option, coords);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
void Menu::info(const char * info)
{
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, 17 * 0.035f + 0.1600f }, { 0.25f, 0.25f }, false); }
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1300f }, { 0.25f, 0.25f }, false); }
	}
}



void Menu::End()
{
	int opcount = Settings::optionCount;
	int currop = Settings::currentOption;
	if (Menu::Settings::CurHeader == 0) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			//Drawing::Text("0.5", Settings::SubtitleText, { Settings::menuX + 0.075f, 0.130f }, { 0.39f, 0.39f }, false); - 0.097f
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Rect(Settings::line, { Settings::menuX, 17 * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			//Drawing::Rect(Settings::line, { Settings::menuX, 17 * 0.035f + 0.1235f }, { 0.21f, 0.002f });
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);

			//	onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount + 1 ) * 0.035f + 0.1415f }, { 0.20f, 0.035f }) : NULL;
			Drawing::Rect(Settings::line, { Settings::menuX + 0.12f, 17 * 0.035f + 0.1415f }, { 0.011f, 0.035f });
			Drawing::Spriter("commonmenu", "arrowleft", Settings::menuX + 0.12f, ((16 + 1) * 0.035f + 0.1415f), 0.008f, 0.025f, -90, 255, 255, 255, 255);

		}
		else if (opcount > 0) {
			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			//Drawing::Text("0.5", Settings::SubtitleText, { Settings::menuX + 0.075f, 0.130f }, { 0.39f, 0.39f }, false);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Rect(Settings::line, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			//Drawing::Rect(Settings::line, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1235f }, { 0.21f, 0.002f });
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);
			Drawing::Rect(Settings::line, { Settings::menuX + 0.12f, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.011f, 0.035f });
			Drawing::Spriter("commonmenu", "arrowleft", Settings::menuX + 0.12f, ((Settings::optionCount + 1) * 0.035f + 0.1415f), 0.008f, 0.025f, -90, 255, 255, 255, 255);

		}
	}
	if (Menu::Settings::CurHeader == 1) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Menu::Drawing::Spriter("Foxy", "OptionEndUI", Menu::Settings::menuX, 17 * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255);
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);

			Menu::Drawing::Spriter("Foxy", "OptionScrollBarEndUI", Menu::Settings::menuX + 0.12f, 17 * 0.035f + 0.1415f, 0.025f, 0.035f, 0, 255, 255, 255, 255);
		}
		else if (opcount > 0) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Menu::Drawing::Spriter("Foxy", "OptionEndUI", Menu::Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f, 0.20f, 0.035f, 0, 255, 255, 255, 255);
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);

			Menu::Drawing::Spriter("Foxy", "OptionScrollBarEndUI", Menu::Settings::menuX + 0.12f, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.025f, 0.035f, 0, 255, 255, 255, 255);
		}
	}
	if (Menu::Settings::CurHeader == 2) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);

		}
		else if (opcount > 0) {
			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);

		}
	}
	if (Menu::Settings::CurHeader == 3) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Rect(Settings::color4, { Settings::menuX, 17 * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color4, { Settings::menuX + 0.10f, 17 * 0.035f + 0.1415f }, { 0.004f, 0.035f });// right 
			Drawing::Rect(Settings::color4, { Settings::menuX - 0.10f, 17 * 0.035f + 0.1415f }, { 0.004f, 0.035f }); //left
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);

		}
		else if (opcount > 0) {
			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Rect(Settings::color4, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Rect(Settings::color4, { Settings::menuX + 0.10f, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.004f, 0.035f });// right 
			Drawing::Rect(Settings::color4, { Settings::menuX - 0.10f, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.004f, 0.035f }); //left
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line2.r, Settings::line2.g, Settings::line2.b, Settings::line2.a);

		}
	}
	if (Menu::Settings::CurHeader == 4) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			
		}
		else if (opcount > 0) {
			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			

		}
	}
	if (Menu::Settings::CurHeader == 5) {

		if (opcount >= 16) {

			Drawing::Rect(Settings::color5, { Settings::menuX, 17 * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::rgbafcolor6, { Settings::menuX + 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, 57, 196, 194, 255);
			
		}
		else if (opcount > 0) {
			Drawing::Rect(Settings::color5, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.20f, 0.035f });
			Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::rgbafcolor6, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);
			Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, 57, 196, 194, 255);
			
		}
	}
	if (Menu::Settings::CurHeader == 6) {

		if (opcount >= 16) {

			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, 17 * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);

		}
		else if (opcount > 0) {
			Drawing::Text(" Free Version", Settings::count, { Settings::menuX - 0.078f, (Settings::optionCount + 1) * 0.035f + 0.130f }, { 0.35f, 0.35f }, true);


		}
	}
}

int IconNotification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_GANGAPP", "CHAR_GANGAPP", false, 7, text2, Subject, 1.0, "___Menu");
	return UI::_DRAW_NOTIFICATION(1, 1);
}
void PlaySoundFrontend_default(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}

int Menu::Settings::keyPressDelay = 200;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
int Menu::Settings::keyPressDelay2 = 100;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();
int Menu::Settings::openKey = VK_F6;
int Menu::Settings::backKey = VK_NUMPAD0;
int Menu::Settings::upKey = VK_NUMPAD8;
int Menu::Settings::downKey = VK_NUMPAD2;
int Menu::Settings::leftKey = VK_NUMPAD4;
int Menu::Settings::rightKey = VK_NUMPAD6;
int Menu::Settings::selectKey = VK_NUMPAD5;
int Menu::Settings::arrowupKey = VK_UP;
int Menu::Settings::arrowdownKey = VK_DOWN;
int Menu::Settings::arrowleftKey = VK_LEFT;
int Menu::Settings::arrowrightKey = VK_RIGHT;
int Menu::Settings::enterKey = VK_RETURN;
int Menu::Settings::deleteKey = VK_BACK;

#pragma endregion

bool Menu::Settings::controllerinput = true;
void Menu::Checks::Controlls()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
		if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
			if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
				if (IsKeyPressed(VK_F6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel >= 1 ? MenuLevelHandler::BackMenu() : NULL;
					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput) {
					Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("BACK");

					Settings::keyPressPreviousTick = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
					Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
					Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick2 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
					Settings::leftPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
					Settings::rightPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("NAV_UP_DOWN");

					Settings::keyPressPreviousTick3 = GetTickCount();
				}
				else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput) {
					Settings::selectPressed = true;
					if (Settings::menuLevel > 0)
						PlaySoundFrontend_default("SELECT");

					Settings::keyPressPreviousTick = GetTickCount();
				}
			}
		}
	}
	Settings::optionCount = 0;
}
#pragma warning(default : 4018)
void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
}

void Menu::MenuLevelHandler::BackMenu()
{
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
}

char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
	return (std::string)buf;
}

void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}

int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}

float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}

bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}

void Menu::Vehicle(std::string texture1, std::string texture2)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); }
	}
	else { if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); } }
}
void Menu::Speedometer(char* text)
{
	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
}

void MenuCopyRight()
{
	std::string path = "C://Foxy/";
	std::string name = "Foxy.ytd";
	const std::string fullPath = path + name;

	int textureID;
	if (FileExists(fullPath))
		file_register(&textureID, fullPath.c_str(), true, name.c_str(), false);
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("Copyright", false);
}


void Menu::fps(char* text)
{
	Drawing::Text(text, Settings::optionText, { 0.90f, 0.050f }, { 0.50f, 0.50f }, true);
	Menu::Drawing::Spriter("Foxy", "Copyright", 0.90f, 0.070f, 0.06f, 0.06f, 0, 255, 255, 255, 255);
	if (Menu::Settings::CurHeader == 7) {
		

		Drawing::Text(text, Settings::optionText, { 0.90f, 0.050f }, { 0.50f, 0.50f }, true);
		Menu::Drawing::Spriter("Foxy", "Copyright2", 0.90f, 0.070f, 0.06f, 0.06f, 0, 255, 255, 255, 255);
		
	};


}

/*float Menu::Settings::test1 = 0.78f;
float Menu::Settings::test2 = 0.180f;
float Menu::Settings::test3 = 0.55f;
float Menu::Settings::test4 = 0.183f;
float Menu::Settings::test5 = 0.21f;
float Menu::Settings::test6 = 0.17f;
float Menu::Settings::test7 = 0.21f;*/

void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < Settings::test1)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.195f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.195f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.195f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.195f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo(char* text, short line)
{
	RGBFades();
	//float Menu::Settings::menuX = 0.17f;
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {   
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.195f, ((27 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 27 * 0.035f + -0.193f });
		}
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { Settings::menuX - Settings::test4,  (line * 0.020f) + 0.123f }, { 0.002f, 0.0601f });//small line left
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.423f,  (line * 0.020f) + 0.123f }, { 0.002f, 0.0601f });//small line right
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.195f, ((27 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 27 * 0.035f + -0.193f });
		}
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { Settings::menuX - Settings::test4,  (line * 0.020f) + 0.123f }, { 0.002f, 0.0601f });//small line left
		Drawing::Rect({ rwws, bwws, gwws, 255 }, { 0.423f,  (line * 0.020f) + 0.123f }, { 0.002f, 0.0601f });//small line right
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.3f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}



void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}

void Menu::AddSmallTitle3(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}