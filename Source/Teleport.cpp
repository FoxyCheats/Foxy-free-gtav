#include "stdafx.h"
#include "Teleport.h"
#include "Local.h"

#define Addoption      Menu::Option
#define Addtitle       Menu::Title
#define Addsubtitle    Menu::SubTitle
#define addint         Menu::Int
#define Addint         Menu::AInt
#define Addsub         Menu::MenuOption
#define Addbool        Menu::Toggle
#define Addbreak       Menu::Break

void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}//
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void Foxy_EngineTP::aparts()
{
	Addtitle("Apartments Online");
	Addsubtitle("Apartments Online");
	if (Addoption("3 Alta St")) { Vector3 Coords;                 Coords.x = -261.747620f; Coords.y = -976.950623f; Coords.z = 30.971106f;                 TPto(Coords); }
	if (Addoption("4 Integrit Way")) { Vector3 Coords;                 Coords.x = -54.668861f; Coords.y = -588.563904f; Coords.z = 36.193024f;                 TPto(Coords); }
	if (Addoption("Bay City Ave Apt 45")) { Vector3 Coords;                 Coords.x = -986.981323f; Coords.y = -1445.468018f; Coords.z = 5.942831f;                 TPto(Coords); }
	if (Addoption("Blvd Del Perro Apt 18")) { Vector3 Coords;                 Coords.x = -1611.278442f; Coords.y = -424.959167f; Coords.z = 40.691673f;                 TPto(Coords); }
	if (Addoption("Cougar Ave Apt 19")) { Vector3 Coords;                 Coords.x = -1538.185791f; Coords.y = -328.037628f; Coords.z = 47.265511f;                 TPto(Coords); }
	if (Addoption("Dream Tower Apt 15")) { Vector3 Coords;                 Coords.x = -755.427124f; Coords.y = -749.572021f; Coords.z = 26.665794f;                 TPto(Coords); }
	if (Addoption("Eclipse Towers")) { Vector3 Coords;                 Coords.x = -773.505920f; Coords.y = 296.763641f; Coords.z = 85.830109f;                 TPto(Coords); }
	if (Addoption("Milton Dr 0504")) { Vector3 Coords;                 Coords.x = -635.008545f; Coords.y = 161.922287f; Coords.z = 59.699619f;                 TPto(Coords); }
	if (Addoption("Milton Dr Apt 13")) { Vector3 Coords;                 Coords.x = -508.407379f; Coords.y = 112.594910f; Coords.z = 63.480057f;                 TPto(Coords); }
	if (Addoption("Power St 1162")) { Vector3 Coords;                 Coords.x = 269.939819f; Coords.y = -150.483261f; Coords.z = 64.293060f;                 TPto(Coords); }
	if (Addoption("Prosperity St Apt 21")) { Vector3 Coords;                 Coords.x = -1556.567627f; Coords.y = -415.096069f; Coords.z = 42.539715f;                 TPto(Coords); }
	if (Addoption("Richard Majestic")) { Vector3 Coords;                 Coords.x = -956.922424f; Coords.y = -403.93678f; Coords.z = 38.278751f;                 TPto(Coords); }
	if (Addoption("South Rockford Dr")) { Vector3 Coords;                 Coords.x = -837.304504f; Coords.y = -849.619080f; Coords.z = 19.522774f;                 TPto(Coords); }
	if (Addoption("South Rockford Dr Apt 13")) { Vector3 Coords;                 Coords.x = -818.702759f; Coords.y = -989.048035f; Coords.z = 13.501397f;                 TPto(Coords); }
	if (Addoption("The Royal Apt 19")) { Vector3 Coords;                 Coords.x = -201.004333f; Coords.y = 91.132614f; Coords.z = 69.530350f;                 TPto(Coords); }
	if (Addoption("Vespucci Blvd Apt 1")) { Vector3 Coords;                 Coords.x = -671.988403f; Coords.y = -854.607910f; Coords.z = 23.965218f;                 TPto(Coords); }
	if (Addoption("Weazel Plaza")) { Vector3 Coords;                 Coords.x = -924.684082f; Coords.y = -465.046417f; Coords.z = 36.882763f;                 TPto(Coords); }
}
void Foxy_EngineTP::Clothingstoress()
{
	Addtitle("Clothing stores");
	Addsubtitle("Clothing stores");
	if (Addoption("Binco - Vespucci")) { Vector3 Coords;                 Coords.x = -814.432800f; Coords.y = -1085.986938f; Coords.z = 10.567306f;                 TPto(Coords); }
	if (Addoption("Binco - Strawberry")) { Vector3 Coords;                 Coords.x = 411.403564f; Coords.y = -806.654907f; Coords.z = 28.742212f;                 TPto(Coords); }
	if (Addoption("Discount Store - Grand Senora")) { Vector3 Coords;                 Coords.x = 1179.679688f; Coords.y = 2691.378662f; Coords.z = 37.124043f;                 TPto(Coords); }
	if (Addoption("Discount Store - Grapeseed")) { Vector3 Coords;                 Coords.x = 1678.057495f; Coords.y = 4819.882324f; Coords.z = 41.299820f;                 TPto(Coords); }
	if (Addoption("Discount Store - Great Chaparral")) { Vector3 Coords;                 Coords.x = -1089.404785f; Coords.y = 2697.033447f; Coords.z = 19.442095f;                 TPto(Coords); }
	if (Addoption("Discount Store - Paleto Bay")) { Vector3 Coords;                 Coords.x = -4.509100f; Coords.y = 6521.252930f; Coords.z = 30.571024f;                 TPto(Coords); }
	if (Addoption("Discount Store - Strawberry")) { Vector3 Coords;                 Coords.x = 89.320786f; Coords.y = -1392.317627f; Coords.z = 28.800083f;                 TPto(Coords); }
	if (Addoption("Masks - Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1342.185913f; Coords.y = -1280.013428f; Coords.z = 4.443256f;                 TPto(Coords); }
	if (Addoption("Ponsonbys - Burton")) { Vector3 Coords;                 Coords.x = -148.234741f; Coords.y = -308.074463f; Coords.z = 38.104240f;                 TPto(Coords); }
	if (Addoption("Ponsonbys - Rockford Hills")) { Vector3 Coords;                 Coords.x = -725.551453f; Coords.y = -162.833710f; Coords.z = 36.570301f;                 TPto(Coords); }
	if (Addoption("Ponsonbys - Morningwood")) { Vector3 Coords;                 Coords.x = -1460.654419f; Coords.y = -227.550964f; Coords.z = 48.728519f;                 TPto(Coords); }
	if (Addoption("Suburban - Havick")) { Vector3 Coords;                 Coords.x = 134.122055f; Coords.y = -200.211334f; Coords.z = 53.864090f;                 TPto(Coords); }
	if (Addoption("Suburban - Del Perro")) { Vector3 Coords;                 Coords.x = -1210.620361f; Coords.y = -784.160217f; Coords.z = 16.549015f;                 TPto(Coords); }
	if (Addoption("Suburban - Chumash")) { Vector3 Coords;                 Coords.x = -3166.560547f; Coords.y = 1059.929688f; Coords.z = 20.65988f;                 TPto(Coords); }
	if (Addoption("Suburban - Harmony")) { Vector3 Coords;                 Coords.x = 618.081604f; Coords.y = 2745.795410f; Coords.z = 42.276966f;                 TPto(Coords); }
}
void Foxy_EngineTP::Barberss()
{
	Addtitle("Barbers");
	Addsubtitle("Barbers");
	if (Addoption("Davis")) { Vector3 Coords;                 Coords.x = 1198.025757f; Coords.y = -471.814178f; Coords.z = 68.659100f;                 TPto(Coords); }
	if (Addoption("Havick")) { Vector3 Coords;                 Coords.x = -27.791309f; Coords.y = -136.863708f; Coords.z = 56.515392f;                 TPto(Coords); }
	//if (Addoption("Mirror Park")) { Vector3 Coords;                 Coords.x = 1678.057495f; Coords.y = 4819.882324f; Coords.z = 41.299820f;                 TPto(Coords); }
	if (Addoption("Paleto Bay")) { Vector3 Coords;                 Coords.x = -286.639038f; Coords.y = 6239.389648f; Coords.z = 30.567659f;                 TPto(Coords); }
	if (Addoption("Rockford Hills")) { Vector3 Coords;                 Coords.x = -829.426392f; Coords.y = -191.582718f; Coords.z = 36.921909f;                 TPto(Coords); }
	if (Addoption("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1938.357910f; Coords.y = 3717.808350f; Coords.z = 31.607185f;                 TPto(Coords); }
	if (Addoption("Vespucci")) { Vector3 Coords;                 Coords.x = -1294.995239f; Coords.y = -1117.641724f; Coords.z = 6.157444f;                 TPto(Coords); }
}
void Foxy_EngineTP::telelsc()
{
	Addtitle("Los Santos Customs");
	Addsubtitle("Los Santos Customs");
	if (Addoption("Bennys Garage")) { Vector3 Coords;                 Coords.x = -196, 349442; Coords.y = -1303, 103271; Coords.z = 30, 650515;                 TPto(Coords); }
	if (Addoption("Burton")) { Vector3 Coords;                 Coords.x = -370.533752f; Coords.y = -130.402649f; Coords.z = 38.197617f;                 TPto(Coords); }
	if (Addoption("Beekers Garage")) { Vector3 Coords;                 Coords.x = 116.223175f; Coords.y = 6606.201660f; Coords.z = 31.462461f;                 TPto(Coords); }
	if (Addoption("Los Santos Airport")) { Vector3 Coords;                 Coords.x = -1135.707275f; Coords.y = -1987.154175f; Coords.z = 12.976217f;                 TPto(Coords); }
	if (Addoption("La Mesa")) { Vector3 Coords;                 Coords.x = 709.295471f; Coords.y = -1081.996216f; Coords.z = 21.975765f;                 TPto(Coords); }
	if (Addoption("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1176.822632f; Coords.y = 2657.973145; Coords.z = 37.370682;                 TPto(Coords); }
}
void Foxy_EngineTP::vehtpting()
{
	Addtitle("Other Vehicle TPs");
	Addsubtitle("Other Vehicle TPs");
	if (Addoption("Little Seoul Car Wash")) { Vector3 Coords;                 Coords.x = -701.829956f; Coords.y = -921.928772f; Coords.z = 18.589094f;                 TPto(Coords); }
	if (Addoption("Mort Mutual Insurance")) { Vector3 Coords;    Coords.x = -221.749908f; Coords.y = -1158.249756f; Coords.z = 23.040998f;                 TPto(Coords); }
	if (Addoption("Simeon Docks")) { Vector3 Coords;                 Coords.x = 1205.028442f; Coords.y = -3089.802490f; Coords.z = 5.374923f;                 TPto(Coords); }
	if (Addoption("Strawberry Car Wash")) { Vector3 Coords;                 Coords.x = 57.513451f; Coords.y = -1389.658691f; Coords.z = 28.968079f;                 TPto(Coords); }
}
void Foxy_EngineTP::TPAmmu()
{
	Addtitle("Ammunation");
	Addsubtitle("Ammunation");
	if (Addoption("Chumash")) { Vector3 Coords;                 Coords.x = -3155.888672f; Coords.y = 1073.844482f; Coords.z = 20.188726f;                 TPto(Coords); }
	if (Addoption("Cypress Flats")) { Vector3 Coords;                 Coords.x = 814.442017f; Coords.y = -2130.448486f; Coords.z = 28.867798f;                 TPto(Coords); }
	if (Addoption("Great Chaparral")) { Vector3 Coords;                 Coords.x = -1108.600830f; Coords.y = 2685.694092f; Coords.z = 18.177374f;                 TPto(Coords); }
	if (Addoption("Hawick")) { Vector3 Coords;                 Coords.x = 235.666794f; Coords.y = -42.263149f; Coords.z = 69.221313f;                 TPto(Coords); }
	if (Addoption("La Mesa")) { Vector3 Coords;                 Coords.x = 844.439026f; Coords.y = -1009.422424f; Coords.z = 27.511728f;                 TPto(Coords); }
	if (Addoption("Little Seoul")) { Vector3 Coords;                 Coords.x = -665.232727f; Coords.y = -952.522522f; Coords.z = 20.866556f;                 TPto(Coords); }
	if (Addoption("Morningwood")) { Vector3 Coords;                 Coords.x = -1328.592896f; Coords.y = -387.114410f; Coords.z = 36.126881f;                 TPto(Coords); }
	if (Addoption("Palomino Fwy")) { Vector3 Coords;                 Coords.x = 2571.371826f; Coords.y = 313.879608f; Coords.z = 107.970573f;                 TPto(Coords); }
	if (Addoption("Pillbox Hill")) { Vector3 Coords;                 Coords.x = 17.377790f; Coords.y = -1122.183105f; Coords.z = 28.469843f;                 TPto(Coords); }
	if (Addoption("Paleto Bay")) { Vector3 Coords;                 Coords.x = -318.859039f; Coords.y = 6074.433105f; Coords.z = 30.614943f;                 TPto(Coords); }
	if (Addoption("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1704.671997f; Coords.y = 3748.880615f; Coords.z = 33.286053f;                 TPto(Coords); }
}
void Foxy_EngineTP::tpsportss()
{
	Addtitle("Sports");
	Addsubtitle("Sports");
	Addbreak("Tennis Courts");
	if (Addoption("Alta")) { Vector3 Coords;                 Coords.x = 479.905945f; Coords.y = -235.494492f; Coords.z = 53.536331f;                 TPto(Coords); }
	if (Addoption("GWC and Golfing Society")) { Vector3 Coords;                 Coords.x = -1241.053101f; Coords.y = 355.518005f; Coords.z = 79.737648f;                 TPto(Coords); }
	if (Addoption("La Puerta")) { Vector3 Coords;                 Coords.x = -948.632141f; Coords.y = -1259.970093f; Coords.z = 7.726484f;                 TPto(Coords); }
	if (Addoption("Little Seoul")) { Vector3 Coords;                 Coords.x = -921.126953f; Coords.y = -725.521423f; Coords.z = 19.665815f;                 TPto(Coords); }
	if (Addoption("Richman")) { Vector3 Coords;                 Coords.x = -1628.552979f; Coords.y = 245.169250f; Coords.z = 59.455631f;                 TPto(Coords); }
	if (Addoption("Rockford Hills")) { Vector3 Coords;                 Coords.x = -1357.719360f; Coords.y = -109.870804f; Coords.z = 50.622841f;                 TPto(Coords); }
	if (Addoption("Rockford Hills - Michael")) { Vector3 Coords;                 Coords.x = -787.896729f; Coords.y = 151.680588f; Coords.z = 68.633354f;                 TPto(Coords); }
	if (Addoption("Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1181.297241f; Coords.y = -1642.197021f; Coords.z = 4.363619f;                 TPto(Coords); }

	Addbreak("Darts");
	if (Addoption("Darts")) { Vector3 Coords;                 Coords.x = 1992.516357f; Coords.y = 3057.399658f; Coords.z = 47.058922f;                 TPto(Coords); }

	Addbreak("Golf");
	if (Addoption("Golf")) { Vector3 Coords;                 Coords.x = -1379.665039f; Coords.y = 51.105522f; Coords.z = 53.053589f;                 TPto(Coords); }
}
void Foxy_EngineTP::Telestores()
{
	Addtitle("Stores");
	Addsubtitle("Stores");
	if (Addoption("24/7 - Banham Canyon")) { Vector3 Coords;                 Coords.x = -3037.177246f; Coords.y = 590.165283f; Coords.z = 7.78449f;                 TPto(Coords); }
	if (Addoption("24/7 - Chumash")) { Vector3 Coords;                 Coords.x = -3237.171387f; Coords.y = 1004.163879f; Coords.z = 12.354364f;                 TPto(Coords); }
	if (Addoption("24/7 - Grand Senora Desert")) { Vector3 Coords;                 Coords.x = 2683.951172f; Coords.y = 3281.507324f; Coords.z = 55.347145f;                 TPto(Coords); }
	if (Addoption("24/7 - Harmony")) { Vector3 Coords;                 Coords.x = 543.490784f; Coords.y = 2675.008301f; Coords.z = 42.162228f;                 TPto(Coords); }
	if (Addoption("24/7 - Mount Chiliad")) { Vector3 Coords;                 Coords.x = 1730.461914f; Coords.y = 6410.027344f; Coords.z = 35.384476f;                 TPto(Coords); }
	if (Addoption("24/7 - Sandy Shores - Niland Ave")) { Vector3 Coords;                 Coords.x = 1966.198853f; Coords.y = 3738.300537f; Coords.z = 32.251864f;                 TPto(Coords); }
	if (Addoption("24/7 - Strawberry")) { Vector3 Coords;                 Coords.x = 28.123456f; Coords.y = -1351.123456f; Coords.z = 29.123456f;                 TPto(Coords); }
	if (Addoption("24/7 - Tataviam Mountains")) { Vector3 Coords;                 Coords.x = 2561.452881f; Coords.y = 384.998932f; Coords.z = 108.532890f;                 TPto(Coords); }
	if (Addoption("24/7 - Vinewood")) { Vector3 Coords;                 Coords.x = 376.287079f; Coords.y = 322.833252f; Coords.z = 103.418564f;                 TPto(Coords); }
	if (Addoption("Limited LTD Gasoline - Grapeseed")) { Vector3 Coords;                 Coords.x = 1695.349267f; Coords.y = 4932.165039f; Coords.z = 41.826122f;                 TPto(Coords); }
	if (Addoption("Limited LTD Gasoline - Grove St")) { Vector3 Coords;                 Coords.x = -54.6644520f; Coords.y = -1758.542847f; Coords.z = 29.432362f;                 TPto(Coords); }
	if (Addoption("Limited LTD Gasoline - Little Seoul")) { Vector3 Coords;                 Coords.x = -712.059570f; Coords.y = -919.167175f; Coords.z = 18.835764f;                 TPto(Coords); }
	if (Addoption("Limited LTD Gasoline - Mirror Park")) { Vector3 Coords;                 Coords.x = 1159.879761f; Coords.y = -329.307495f; Coords.z = 68.822609f;                 TPto(Coords); }
	if (Addoption("Limited LTD Gasoline - Richman Glen")) { Vector3 Coords;                 Coords.x = -1821.082275f; Coords.y = 787.085510f; Coords.z = 137.868439f;                 TPto(Coords); }
	if (Addoption("Rob's Liqour - Banham Canyon")) { Vector3 Coords;                 Coords.x = -2976.010742f; Coords.y = 391.081024f; Coords.z = 15.013429f;                 TPto(Coords); }
	if (Addoption("Rob's Liqour - Morningwood")) { Vector3 Coords;                 Coords.x = -1493.295166f; Coords.y = -385.783142f; Coords.z = 39.841709f;                 TPto(Coords); }
	if (Addoption("Rob's Liqour - Murrieta Heights")) { Vector3 Coords;                 Coords.x = 1142.654053f; Coords.y = -980.857788f; Coords.z = 45.945202f;                 TPto(Coords); }
	if (Addoption("Rob's Liqour - Vespucci Canals")) { Vector3 Coords;                 Coords.x = -1227.629639f; Coords.y = -900.404236f; Coords.z = 12.366796f;                 TPto(Coords); }
	if (Addoption("Scoops - Grand Senora Desert")) { Vector3 Coords;                 Coords.x = 1166.794556f; Coords.y = 2700.728027f; Coords.z = 38.224377f;                 TPto(Coords); }
	if (Addoption("N/A - Algonquin Blvd")) { Vector3 Coords;                 Coords.x = 1394.642578f; Coords.y = 3598.434082f; Coords.z = 34.892509f;                 TPto(Coords); }
}
void Foxy_EngineTP::Cinemakek()
{
	Addtitle("Cinema");
	Addsubtitle("Cinema");
	if (Addoption("Oriental Theater")) { Vector3 Coords;                 Coords.x = 293.089f; Coords.y = 180.466f; Coords.z = 104.301f;                 TPto(Coords); }
	if (Addoption("Ten Cent")) { Vector3 Coords;                 Coords.x = 400.111111f; Coords.y = -711.111111f; Coords.z = 29.752497f;                 TPto(Coords); }
	if (Addoption("Morningwood")) { Vector3 Coords;                 Coords.x = -1421.111111f; Coords.y = -193.111111f; Coords.z = 46.789345f;                 TPto(Coords); }
}
void Foxy_EngineTP::TPtattoo()
{
	Addtitle("Tattoos");
	Addsubtitle("Tattoos");
	if (Addoption("Chumash")) { Vector3 Coords;                 Coords.x = -3155.888672f; Coords.y = 1073.844482f; Coords.z = 20.188726f;                 TPto(Coords); }
	if (Addoption("El Burro Heights")) { Vector3 Coords;                 Coords.x = 1318.160889f; Coords.y = -1642.176147f; Coords.z = 51.787762f;                 TPto(Coords); }
	if (Addoption("Paleto Bay")) { Vector3 Coords;                 Coords.x = -285.123456f; Coords.y = 6202.123456f; Coords.z = 30.123456f;                 TPto(Coords); }
	if (Addoption("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1853.771851f; Coords.y = 3746.440918f; Coords.z = 32.395195f;                 TPto(Coords); }
	if (Addoption("Vespucci")) { Vector3 Coords;                 Coords.x = -1163.504639f; Coords.y = -1413.232788f; Coords.z = 4.360025f;                 TPto(Coords); }
	if (Addoption("Vinewood")) { Vector3 Coords;                 Coords.x = 318.228790f; Coords.y = 164.457535f; Coords.z = 103.146561f;                 TPto(Coords); }
}
void Foxy_EngineTP::TPairports()
{
	Addtitle("Airports");
	Addsubtitle("Airports");
	if (Addoption("Los Santos Airport")) { Vector3 Coords;                 Coords.x = -1070.906250f; Coords.y = -2972.122803f; Coords.z = 13.773568f;                 TPto(Coords); }
	if (Addoption("McKenzie Airfield")) { Vector3 Coords;                 Coords.x = 2124.625732f; Coords.y = 4805.270020f; Coords.z = 40.479958f;                 TPto(Coords); }
	if (Addoption("Flight School")) { Vector3 Coords;                 Coords.x = -1142.084229f; Coords.y = -2697.341553f; Coords.z = 13.324973f;                 TPto(Coords); }
	if (Addoption("Fort Zancudo ATC entrance")) { Vector3 Coords;                 Coords.x = -2344.373f; Coords.y = 3267.498f; Coords.z = 32.811f;                 TPto(Coords); }
	if (Addoption("Fort Zancudo ATC top floor")) { Vector3 Coords;                 Coords.x = -2358.132f; Coords.y = 3249.754f; Coords.z = 101.451f;                 TPto(Coords); }
	if (Addoption("Fort Zancudo Front")) { Vector3 Coords;                 Coords.x = -1563.743286f; Coords.y = 2769.382080f; Coords.z = 16.819347f;                 TPto(Coords); }
	if (Addoption("Fort Zancudo")) { Vector3 Coords;                 Coords.x = -2446.711182f; Coords.y = 3142.811035f; Coords.z = 32.194775f;                 TPto(Coords); }
	if (Addoption("Sandy Shores")) { Vector3 Coords;                 Coords.x = 1682.196411f; Coords.y = 3279.987793f; Coords.z = 40.647972f;                 TPto(Coords); }
}
void Foxy_EngineTP::tpnotfun()
{
	Addtitle("Fun");
	Addsubtitle("Fun");
	if (Addoption("Burnt FIB Building")) { Vector3 Coords;                 Coords.x = 153.344131f; Coords.y = -734.524353f; Coords.z = 253.848343f;                 TPto(Coords); }
	if (Addoption("FIB Roof")) { Vector3 Coords;                 Coords.x = 150.126f; Coords.y = -754.591f; Coords.z = 262.865f;                 TPto(Coords); }
	if (Addoption("FIB Top Floor")) { Vector3 Coords;                 Coords.x = 135.733f; Coords.y = -749.216f; Coords.z = 258.152f;                 TPto(Coords); }
	if (Addoption("IAA Roof")) { Vector3 Coords;                 Coords.x = 134.085f; Coords.y = -637.859f; Coords.z = 262.851f;                 TPto(Coords); }
	if (Addoption("IAA Office")) { Vector3 Coords;                 Coords.x = 117.220f; Coords.y = -620.938f; Coords.z = 206.047f;                 TPto(Coords); }
	if (Addoption("Mile High Club")) { Vector3 Coords;                 Coords.x = -144.274f; Coords.y = -946.813f; Coords.z = 269.135f;                 TPto(Coords); }
	if (Addoption("Play Boy Mansion")) { Vector3 Coords;                 Coords.x = -1475.234f; Coords.y = 167.088f; Coords.z = 55.841f;                 TPto(Coords); }
	if (Addoption("Strip Club")) { Vector3 Coords;                 Coords.x = 135.548096f; Coords.y = -1308.388306f; Coords.z = 28.344141f;                 TPto(Coords); }
	if (Addoption("Strip Club - DJ Booth")) { Vector3 Coords;                 Coords.x = 122.416924f; Coords.y = -1281.09976f; Coords.z = 29.480480f;                 TPto(Coords); }
	if (Addoption("Torture Room X")) { Vector3 Coords;                 Coords.x = 147.170f; Coords.y = -2201.804f; Coords.z = 4.688f;                 TPto(Coords); }
	if (Addoption("Weed Farm")) { Vector3 Coords;                 Coords.x = 2208.777f; Coords.y = 5578.235f; Coords.z = 53.735f;                 TPto(Coords); }
}
void Foxy_EngineTP::TPmisc()
{
	Addtitle("Other");
	Addsubtitle("Other");
	if (Addoption("Abandon Mine")) { Vector3 Coords;                 Coords.x = -595.342f; Coords.y = 2086.008f; Coords.z = 131.412f;                 TPto(Coords); }
	if (Addoption("Airplane Graveyard Airplane Tail")) { Vector3 Coords;                 Coords.x = 2395.096f; Coords.y = 3049.616f; Coords.z = 60.053f;                 TPto(Coords); }
	if (Addoption("Altruist Cult Camp")) { Vector3 Coords;                 Coords.x = -1170.841f; Coords.y = 4926.646f; Coords.z = 224.295f;                 TPto(Coords); }
	if (Addoption("Beach Skatepark")) { Vector3 Coords;                 Coords.x = -1374.881f; Coords.y = -1398.835f; Coords.z = 6.141f;                 TPto(Coords); }
	if (Addoption("Calafia Train Bridge")) { Vector3 Coords;                 Coords.x = -517.869f; Coords.y = 4425.284f; Coords.z = 89.795897f;                 TPto(Coords); }
	if (Addoption("Cargo Ship")) { Vector3 Coords;                 Coords.x = 899.678f; Coords.y = -2882.191f; Coords.z = 19.013f;                 TPto(Coords); }
	if (Addoption("Casino")) { Vector3 Coords;                 Coords.x = 925.329f; Coords.y = 46.152f; Coords.z = 80.908f;                 TPto(Coords); }
	if (Addoption("Chicken")) { Vector3 Coords;                 Coords.x = -31.010f; Coords.y = 6316.830f; Coords.z = 40.083f;                 TPto(Coords); }
	if (Addoption("Chumash Historic Family Pier")) { Vector3 Coords;                 Coords.x = -3426.683f; Coords.y = 967.738f; Coords.z = 8.347f;                 TPto(Coords); }
	if (Addoption("Del Perro Pier")) { Vector3 Coords;                 Coords.x = -1850.127f; Coords.y = -1231.751f; Coords.z = 13.017f;                 TPto(Coords); }
	if (Addoption("Devin Weston's House")) { Vector3 Coords;                 Coords.x = -2639.872f; Coords.y = 1866.812f; Coords.z = 160.135f;                 TPto(Coords); }
	if (Addoption("El Gordo Lighthouse - Floor")) { Vector3 Coords;                 Coords.x = 3422.703125f; Coords.y = 5174.532715f; Coords.z = 7.382134f;                 TPto(Coords); }
	if (Addoption("El Gordo Lighthouse - Top")) { Vector3 Coords;                 Coords.x = 3431.182617f; Coords.y = 5173.422852f; Coords.z = 41.371891f;                 TPto(Coords); }
	if (Addoption("Epsilon Building")) { Vector3 Coords;                 Coords.x = -695.025f; Coords.y = 82.955f; Coords.z = 55.855f;                 TPto(Coords); }
	if (Addoption("Floyd's Apartment")) { Vector3 Coords;                 Coords.x = -1150.703f; Coords.y = -1520.713f; Coords.z = 10.633f;                 TPto(Coords); }
	if (Addoption("Galileo Observatory Roof")) { Vector3 Coords;                 Coords.x = -438.804f; Coords.y = 1076.097f; Coords.z = 352.411f;                 TPto(Coords); }
	if (Addoption("God's thumb")) { Vector3 Coords;                 Coords.x = -1006.402f; Coords.y = 6272.383f; Coords.z = 1.503f;                 TPto(Coords); }
	if (Addoption("Hippy Camp")) { Vector3 Coords;                 Coords.x = 2476.712f; Coords.y = 3789.645f; Coords.z = 41.226f;                 TPto(Coords); }
	if (Addoption("Humane Labs Entrance")) { Vector3 Coords;                 Coords.x = 3613.750000f; Coords.y = 3747.294180f; Coords.z = 28.59690090f;                 TPto(Coords); }
	if (Addoption("Humane Labs Tunnel")) { Vector3 Coords;                 Coords.x = 3525.495f; Coords.y = 3705.301f; Coords.z = 20.992f;                 TPto(Coords); }
	if (Addoption("Jolene Ghost - Time 23:00/24:00")) { Vector3 Coords;                 Coords.x = 3059.620f; Coords.y = 5564.246f; Coords.z = 197.091f;                 TPto(Coords); }
	if (Addoption("Kortz Center")) { Vector3 Coords;                 Coords.x = -2243.810f; Coords.y = 264.048f; Coords.z = 174.615f;                 TPto(Coords); }
	if (Addoption("La Puerta Freeway Bridge")) { Vector3 Coords;                 Coords.x = -543.932f; Coords.y = -2225.543f; Coords.z = 122.366f;                 TPto(Coords); }
	if (Addoption("Land Act Dam")) { Vector3 Coords;                 Coords.x = 1660.369f; Coords.y = -12.013f; Coords.z = 170.020f;                 TPto(Coords); }
	if (Addoption("Lester's House")) { Vector3 Coords;                 Coords.x = 1273.898f; Coords.y = -1719.304f; Coords.z = 54.771f;                 TPto(Coords); }
	if (Addoption("Little Portola")) { Vector3 Coords;                 Coords.x = -635.463f; Coords.y = -242.402f; Coords.z = 38.175f;                 TPto(Coords); }
	if (Addoption("Little Seoul")) { Vector3 Coords;                 Coords.x = -889.655f; Coords.y = -853.499f; Coords.z = 20.566f;                 TPto(Coords); }
	if (Addoption("Marlowe Vineyards")) { Vector3 Coords;                 Coords.x = -1868.971f; Coords.y = 2095.674f; Coords.z = 139.115f;                 TPto(Coords); }
	if (Addoption("Merryweather Dock")) { Vector3 Coords;                 Coords.x = 486.417f; Coords.y = -3339.692f; Coords.z = 6.070f;                 TPto(Coords); }
	if (Addoption("Mirror Park")) { Vector3 Coords;                 Coords.x = 1070.206f; Coords.y = -711.958f; Coords.z = 58.483f;                 TPto(Coords); }
	if (Addoption("Mount Gordo")) { Vector3 Coords;                 Coords.x = 2877.633f; Coords.y = 5911.078f; Coords.z = 369.624f;                 TPto(Coords); }
	if (Addoption("NOOSE Headquarters")) { Vector3 Coords;                 Coords.x = 2535.243f; Coords.y = -383.799f; Coords.z = 92.993f;                 TPto(Coords); }
	if (Addoption("Pacific Bluffs Country Club")) { Vector3 Coords;                 Coords.x = -3022.222f; Coords.y = 39.968f; Coords.z = 13.611f;                 TPto(Coords); }
	if (Addoption("Paleto Bay Pier")) { Vector3 Coords;                 Coords.x = -275.522f; Coords.y = 6635.835f; Coords.z = 7.425f;                 TPto(Coords); }
	if (Addoption("Paleto Forest Sawmill Chimney")) { Vector3 Coords;                 Coords.x = -549.467f; Coords.y = 5308.221f; Coords.z = 114.146f;                 TPto(Coords); }
	if (Addoption("Palmer-Taylor Power Station")) { Vector3 Coords;                 Coords.x = 2732.931f; Coords.y = 1577.540f; Coords.z = 83.671f;                 TPto(Coords); }
	if (Addoption("Police Station")) { Vector3 Coords;                 Coords.x = 436.491f; Coords.y = -982.172f; Coords.z = 30.699f;                 TPto(Coords); }
	if (Addoption("Quarry")) { Vector3 Coords;                 Coords.x = 2954.196f; Coords.y = 2783.410f; Coords.z = 41.004f;                 TPto(Coords); }
	if (Addoption("Rebel Radio")) { Vector3 Coords;                 Coords.x = 736.153f; Coords.y = 2583.143f; Coords.z = 79.634f;                 TPto(Coords); }
	if (Addoption("Rocket")) { Vector3 Coords;                 Coords.x = 1608.698f; Coords.y = 6438.096f; Coords.z = 37.637f;                 TPto(Coords); }
	if (Addoption("Sandy Shores Crane")) { Vector3 Coords;                 Coords.x = 1051.209f; Coords.y = 2280.452f; Coords.z = 89.727f;                 TPto(Coords); }
	if (Addoption("Satellite Dish Antenna")) { Vector3 Coords;                 Coords.x = 2034.988f; Coords.y = 2953.105f; Coords.z = 74.602f;                 TPto(Coords); }
	if (Addoption("Satellite Dishes")) { Vector3 Coords;                 Coords.x = 2062.123f; Coords.y = 2942.055f; Coords.z = 47.431f;                 TPto(Coords); }
	if (Addoption("Sisyphus Theater Stage")) { Vector3 Coords;                 Coords.x = 205.316f; Coords.y = 1167.378f; Coords.z = 227.005f;                 TPto(Coords); }
	if (Addoption("Snowman")) { Vector3 Coords;                 Coords.x = 971.245f; Coords.y = -1620.993f; Coords.z = 30.111f;                 TPto(Coords); }
	if (Addoption("Stab City")) { Vector3 Coords;                 Coords.x = 126.975f; Coords.y = 3714.419f; Coords.z = 46.827f;                 TPto(Coords); }
	if (Addoption("The Richman Hotel")) { Vector3 Coords;                 Coords.x = -1330.911f; Coords.y = 340.871f; Coords.z = 64.078f;                 TPto(Coords); }
	if (Addoption("Top of Mt Chilad")) { Vector3 Coords;                 Coords.x = 450.718f; Coords.y = 5566.614f; Coords.z = 806.183f;                 TPto(Coords); }
	if (Addoption("Trevor's Meth Lab")) { Vector3 Coords;                 Coords.x = 1391.773f; Coords.y = 3608.716f; Coords.z = 38.942f;                 TPto(Coords); }
	if (Addoption("Underpass Skatepark")) { Vector3 Coords;                 Coords.x = 718.341f; Coords.y = -1218.714f; Coords.z = 26.014f;                 TPto(Coords); }
	if (Addoption("University of San Andreas")) { Vector3 Coords;                 Coords.x = -1696.866f; Coords.y = 142.747f; Coords.z = 64.372f;                 TPto(Coords); }
	if (Addoption("Vinewood Bowl Stage")) { Vector3 Coords;                 Coords.x = 686.245f; Coords.y = 577.950f; Coords.z = 130.461f;                 TPto(Coords); }
	if (Addoption("Vinewood sign")) { Vector3 Coords;                 Coords.x = 711.362f; Coords.y = 1198.134f; Coords.z = 348.526f;                 TPto(Coords); }
	if (Addoption("Windmill Top")) { Vector3 Coords;                 Coords.x = 2026.677f; Coords.y = 1842.684f; Coords.z = 133.313f;                 TPto(Coords); }
}
void Foxy_EngineTP::underwater()
{
	Addtitle("Underwater");
	Addsubtitle("Underwater");
	if (Addoption("Dead Sea Monster")) { Vector3 Coords;                 Coords.x = -3373.726f; Coords.y = 504.714f; Coords.z = -24.656f;                 TPto(Coords); }
	if (Addoption("Sunken Body")) { Vector3 Coords;                 Coords.x = -3161.078f; Coords.y = 3001.998f; Coords.z = -37.974f;                 TPto(Coords); }
	if (Addoption("Sunken Cargo Ship")) { Vector3 Coords;                 Coords.x = 3199.748f; Coords.y = -379.018f; Coords.z = -22.500f;                 TPto(Coords); }
	if (Addoption("Sunken Plane")) { Vector3 Coords;                 Coords.x = -942.350f; Coords.y = 6608.752f; Coords.z = -20.912f;                 TPto(Coords); }
	if (Addoption("Sunken Plane2")) { Vector3 Coords;                 Coords.x = 1848.025879f; Coords.y = -2938.081787f; Coords.z = -24.797621f;                 TPto(Coords); }
	if (Addoption("Underwater Hatch")) { Vector3 Coords;                 Coords.x = 4273.950f; Coords.y = 2975.714f; Coords.z = -170.746f;                 TPto(Coords); }
	if (Addoption("Underwater UFO")) { Vector3 Coords;                 Coords.x = 762.426f; Coords.y = 7380.371f; Coords.z = -111.377f;                 TPto(Coords); }
	if (Addoption("Underwater WW2 Tank")) { Vector3 Coords;                 Coords.x = 4201.633f; Coords.y = 3643.821f; Coords.z = -39.016f;                 TPto(Coords); }
}
void Foxy_EngineTP::atmtp()
{
	Addtitle("ATM's");
	Addsubtitle("ATM's");
	if (Addoption("ATM1")) { Vector3 Coords;                 Coords.x = -1109.797f; Coords.y = -1690.808f; Coords.z = 4.375014f;                 TPto(Coords); }
	if (Addoption("ATM2")) { Vector3 Coords;                 Coords.x = -821.6062f; Coords.y = -1081.885f; Coords.z = 11.13243f;                 TPto(Coords); }
	if (Addoption("ATM3")) { Vector3 Coords;                 Coords.x = -537.8409f; Coords.y = -854.5145f; Coords.z = 29.28953f;                 TPto(Coords); }
	if (Addoption("ATM4")) { Vector3 Coords;                 Coords.x = -1315.744f; Coords.y = -834.6907f; Coords.z = 16.96173f;                 TPto(Coords); }
	if (Addoption("ATM5")) { Vector3 Coords;                 Coords.x = -1314.786f; Coords.y = -835.9669f; Coords.z = 16.96015f;                 TPto(Coords); }
	if (Addoption("ATM6")) { Vector3 Coords;                 Coords.x = -1570.069f; Coords.y = -546.6727f; Coords.z = 34.95547f;                 TPto(Coords); }
	if (Addoption("ATM7")) { Vector3 Coords;                 Coords.x = -1571.018f; Coords.y = -547.3666f; Coords.z = 34.95734f;                 TPto(Coords); }
	if (Addoption("ATM8")) { Vector3 Coords;                 Coords.x = -866.6416f; Coords.y = -187.8008f; Coords.z = 37.84286f;                 TPto(Coords); }
	if (Addoption("ATM9")) { Vector3 Coords;                 Coords.x = -867.6165f; Coords.y = -186.1373f; Coords.z = 37.8433f;                 TPto(Coords); }
	if (Addoption("ATM10")) { Vector3 Coords;                 Coords.x = -721.1284f; Coords.y = -415.5296f; Coords.z = 34.98175f;                 TPto(Coords); }
	if (Addoption("ATM11")) { Vector3 Coords;                 Coords.x = -254.3758f; Coords.y = -692.4947f; Coords.z = 33.63751f;                 TPto(Coords); }
	if (Addoption("ATM12")) { Vector3 Coords;                 Coords.x = 24.37422f; Coords.y = -946.0142f; Coords.z = 29.35756f;                 TPto(Coords); }
	if (Addoption("ATM13")) { Vector3 Coords;                 Coords.x = 130.1186f; Coords.y = -1292.669f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Addoption("ATM14")) { Vector3 Coords;                 Coords.x = 129.7023f; Coords.y = -1291.954f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Addoption("ATM15")) { Vector3 Coords;                 Coords.x = 129.2096f; Coords.y = -1291.14f; Coords.z = 29.26953f;                 TPto(Coords); }
	if (Addoption("ATM16")) { Vector3 Coords;                 Coords.x = 288.8256f; Coords.y = -1282.364f; Coords.z = 29.64128f;                 TPto(Coords); }
	if (Addoption("ATM17")) { Vector3 Coords;                 Coords.x = 1077.768f; Coords.y = -776.4548f; Coords.z = 58.23997f;                 TPto(Coords); }
	if (Addoption("ATM18")) { Vector3 Coords;                 Coords.x = 527.2687f; Coords.y = -160.7156f; Coords.z = 57.08937f;                 TPto(Coords); }
	if (Addoption("ATM19")) { Vector3 Coords;                 Coords.x = -867.5897f; Coords.y = -186.1757f; Coords.z = 37.84291f;                 TPto(Coords); }
	if (Addoption("ATM20")) { Vector3 Coords;                 Coords.x = -866.6556f; Coords.y = -187.7766f; Coords.z = 37.84278f;                 TPto(Coords); }
	if (Addoption("ATM21")) { Vector3 Coords;                 Coords.x = -1205.024f; Coords.y = -326.2916f; Coords.z = 37.83985f;                 TPto(Coords); }
	if (Addoption("ATM22")) { Vector3 Coords;                 Coords.x = -1205.703f; Coords.y = -324.7474f; Coords.z = 37.85942f;                 TPto(Coords); }
	if (Addoption("ATM23")) { Vector3 Coords;                 Coords.x = -57.64693f; Coords.y = -92.66162f; Coords.z = 57.77995f;                 TPto(Coords); }
	if (Addoption("ATM24")) { Vector3 Coords;                 Coords.x = 527.3583f; Coords.y = -160.6381f; Coords.z = 57.0933f;                 TPto(Coords); }
	if (Addoption("ATM25")) { Vector3 Coords;                 Coords.x = -165.1658f; Coords.y = 234.8314f; Coords.z = 94.92194f;                 TPto(Coords); }
	if (Addoption("ATM26")) { Vector3 Coords;                 Coords.x = -165.1503f; Coords.y = 232.7887f; Coords.z = 94.92194f;                 TPto(Coords); }
	if (Addoption("ATM27")) { Vector3 Coords;                 Coords.x = -2072.445f; Coords.y = -317.3048f; Coords.z = 13.31597f;                 TPto(Coords); }
	if (Addoption("ATM28")) { Vector3 Coords;                 Coords.x = -3241.082f; Coords.y = 997.5428f; Coords.z = 12.55044f;                 TPto(Coords); }
	if (Addoption("ATM29")) { Vector3 Coords;                 Coords.x = -1091.462f; Coords.y = 2708.637f; Coords.z = 18.95291f;                 TPto(Coords); }
	if (Addoption("ATM30")) { Vector3 Coords;                 Coords.x = 1172.492f; Coords.y = 2702.492f; Coords.z = 38.17477f;                 TPto(Coords); }
	if (Addoption("ATM31")) { Vector3 Coords;                 Coords.x = 1171.537f; Coords.y = 2702.492f; Coords.z = 38.17542f;                 TPto(Coords); }
	if (Addoption("ATM32")) { Vector3 Coords;                 Coords.x = 1822.637f; Coords.y = 3683.131f; Coords.z = 34.27678f;                 TPto(Coords); }
	if (Addoption("ATM33")) { Vector3 Coords;                 Coords.x = 1686.753f; Coords.y = 4815.806f; Coords.z = 42.00874f;                 TPto(Coords); }
	if (Addoption("ATM34")) { Vector3 Coords;                 Coords.x = 1701.209f; Coords.y = 6426.569f; Coords.z = 32.76408f;                 TPto(Coords); }
	if (Addoption("ATM35")) { Vector3 Coords;                 Coords.x = -95.54314f; Coords.y = 6457.19f; Coords.z = 31.46093f;                 TPto(Coords); }
	if (Addoption("ATM36")) { Vector3 Coords;                 Coords.x = -97.23336f; Coords.y = 6455.469f; Coords.z = 31.46682f;                 TPto(Coords); }
	if (Addoption("ATM37")) { Vector3 Coords;                 Coords.x = -386.7451f; Coords.y = 6046.102f; Coords.z = 31.50172f;                 TPto(Coords); }
	if (Addoption("ATM38")) { Vector3 Coords;                 Coords.x = -1091.42f; Coords.y = 2708.629f; Coords.z = 18.95568f;                 TPto(Coords); }
	if (Addoption("ATM39")) { Vector3 Coords;                 Coords.x = 5.132f; Coords.y = -919.7711f; Coords.z = 29.55953f;                 TPto(Coords); }
	if (Addoption("ATM40")) { Vector3 Coords;                 Coords.x = -660.703f; Coords.y = -853.971f; Coords.z = 24.484f;                 TPto(Coords); }
	if (Addoption("ATM41")) { Vector3 Coords;                 Coords.x = -2293.827f; Coords.y = 354.817f; Coords.z = 174.602f;                 TPto(Coords); }
	if (Addoption("ATM42")) { Vector3 Coords;                 Coords.x = -2294.637f; Coords.y = 356.553f; Coords.z = 174.602f;                 TPto(Coords); }
	if (Addoption("ATM43")) { Vector3 Coords;                 Coords.x = -2295.377f; Coords.y = 358.241f; Coords.z = 174.648f;                 TPto(Coords); }
	if (Addoption("ATM44")) { Vector3 Coords;                 Coords.x = -1409.782f; Coords.y = -100.41f; Coords.z = 52.387f;                 TPto(Coords); }
	if (Addoption("ATM45")) { Vector3 Coords;                 Coords.x = -1410.279f; Coords.y = -98.649f; Coords.z = 52.436f;                 TPto(Coords); }
}
void Foxy_EngineTP::bankss()
{
	Addtitle("Banks");
	Addsubtitle("Banks");
	if (Addoption("Blaine County Bank")) { Vector3 Coords;                 Coords.x = -109.299f; Coords.y = 6464.035f; Coords.z = 31.627f;                 TPto(Coords); }
	if (Addoption("Pacific Standard Bank")) { Vector3 Coords;                 Coords.x = 235.046f; Coords.y = 216.434f; Coords.z = 106.287f;                 TPto(Coords); }
	if (Addoption("Pacific Standard Bank Vault")) { Vector3 Coords;                 Coords.x = 255.851f; Coords.y = 217.030f; Coords.z = 101.683f;                 TPto(Coords); }
	if (Addoption("Maze Bank Arena Roof")) { Vector3 Coords;                 Coords.x = -324.300f; Coords.y = -1968.545f; Coords.z = 67.002f;                 TPto(Coords); }
	if (Addoption("Maze Bank Roof")) { Vector3 Coords;                 Coords.x = -75.015f; Coords.y = -818.215f; Coords.z = 326.176f;                 TPto(Coords); }
}
void Foxy_EngineTP::Rpss()
{
	Addtitle("Rp Statues");
	Addsubtitle("Rp Statues");
	if (Addoption("1")) { Vector3 Coords; Coords.x = -2557.405f, Coords.y = 2315.502f, Coords.z = 33.742f; TPto(Coords); }
	if (Addoption("2")) { Vector3 Coords; Coords.x = 2487.128f, Coords.y = 3759.327f, Coords.z = 42.317f; TPto(Coords); }
	if (Addoption("3")) { Vector3 Coords; Coords.x = 457.198f, Coords.y = 5573.861f, Coords.z = 780.184f; TPto(Coords); }
	if (Addoption("4")) { Vector3 Coords; Coords.x = -1280.407f, Coords.y = 2549.743f, Coords.z = 17.534f; TPto(Coords); }
	if (Addoption("5")) { Vector3 Coords; Coords.x = -107.722f, Coords.y = -856.981f, Coords.z = 38.261f; TPto(Coords); }
	if (Addoption("6")) { Vector3 Coords; Coords.x = -1050.513f, Coords.y = -522.612f, Coords.z = 36.634f; TPto(Coords); }
	if (Addoption("7")) { Vector3 Coords; Coords.x = 693.306f, Coords.y = 1200.583f, Coords.z = 344.524f; TPto(Coords); }
	if (Addoption("8")) { Vector3 Coords; Coords.x = 2500.654f, Coords.y = -389.482f, Coords.z = 94.245f; TPto(Coords); }
	if (Addoption("9")) { Vector3 Coords; Coords.x = 483.4f, Coords.y = -3110.621f, Coords.z = 6.627f; TPto(Coords); }
	if (Addoption("10")) { Vector3 Coords; Coords.x = -2169.277f, Coords.y = 5192.986f, Coords.z = 16.295f; TPto(Coords); }
	if (Addoption("11")) { Vector3 Coords; Coords.x = 177.674f, Coords.y = 6394.054f, Coords.z = 31.376f; TPto(Coords); }
	if (Addoption("12")) { Vector3 Coords; Coords.x = 2416.942f, Coords.y = 4994.557f, Coords.z = 45.239f; TPto(Coords); }
	if (Addoption("13")) { Vector3 Coords; Coords.x = 1702.9f, Coords.y = 3291.0f, Coords.z = 48.72f; TPto(Coords); }
	if (Addoption("14")) { Vector3 Coords; Coords.x = -600.813f, Coords.y = 2088.011f, Coords.z = 132.336f; TPto(Coords); }
	if (Addoption("15")) { Vector3 Coords; Coords.x = 2399.505f, Coords.y = 3062.746f, Coords.z = 53.4703f; TPto(Coords); }
	if (Addoption("16")) { Vector3 Coords; Coords.x = -3019.793f, Coords.y = 41.9486f, Coords.z = 10.2924f; TPto(Coords); }
	if (Addoption("17")) { Vector3 Coords; Coords.x = -485.4648f, Coords.y = -54.441f, Coords.z = 38.9945f; TPto(Coords); }
	if (Addoption("18")) { Vector3 Coords; Coords.x = -1350.785f, Coords.y = -1547.089f, Coords.z = 4.675f; TPto(Coords); }
	if (Addoption("19")) { Vector3 Coords; Coords.x = 379.535f, Coords.y = -1509.398f, Coords.z = 29.34f; TPto(Coords); }
	if (Addoption("20")) { Vector3 Coords; Coords.x = 2548.713f, Coords.y = 385.386f, Coords.z = 108.423f; TPto(Coords); }
	if (Addoption("21")) { Vector3 Coords; Coords.x = -769.346f, Coords.y = 877.307f, Coords.z = 203.424f; TPto(Coords); }
	if (Addoption("22")) { Vector3 Coords; Coords.x = -1513.54f, Coords.y = 1517.184f, Coords.z = 111.305f; TPto(Coords); }
	if (Addoption("23")) { Vector3 Coords; Coords.x = -1023.899f, Coords.y = 190.912f, Coords.z = 61.282f; TPto(Coords); }
	if (Addoption("24")) { Vector3 Coords; Coords.x = 1136.355f, Coords.y = -666.404f, Coords.z = 57.044f; TPto(Coords); }
	if (Addoption("25")) { Vector3 Coords; Coords.x = 3799.76f, Coords.y = 4473.048f, Coords.z = 6.032f; TPto(Coords); }
	if (Addoption("26")) { Vector3 Coords; Coords.x = 1243.588f, Coords.y = -2572.136f, Coords.z = 42.603f; TPto(Coords); }
	if (Addoption("27")) { Vector3 Coords; Coords.x = 219.811f, Coords.y = 97.162f, Coords.z = 96.336f; TPto(Coords); }
	if (Addoption("28")) { Vector3 Coords; Coords.x = -1545.826f, Coords.y = -449.397f, Coords.z = 40.318f; TPto(Coords); }
	if (Addoption("29")) { Vector3 Coords; Coords.x = -928.683f, Coords.y = -2938.691f, Coords.z = 13.059f; TPto(Coords); }
	if (Addoption("30")) { Vector3 Coords; Coords.x = -1647.926f, Coords.y = -1094.716f, Coords.z = 12.736f; TPto(Coords); }
	if (Addoption("31")) { Vector3 Coords; Coords.x = -2185.939f, Coords.y = 4249.814f, Coords.z = 48.803f; TPto(Coords); }
	if (Addoption("32")) { Vector3 Coords; Coords.x = -262.339f, Coords.y = 4729.229f, Coords.z = 137.329f; TPto(Coords); }
	if (Addoption("33")) { Vector3 Coords; Coords.x = -311.701f, Coords.y = 6315.024f, Coords.z = 31.978f; TPto(Coords); }
	if (Addoption("34")) { Vector3 Coords; Coords.x = 3306.444f, Coords.y = 5194.742f, Coords.z = 17.432f; TPto(Coords); }
	if (Addoption("35")) { Vector3 Coords; Coords.x = 1389.886f, Coords.y = 3608.834f, Coords.z = 35.06f; TPto(Coords); }
	if (Addoption("36")) { Vector3 Coords; Coords.x = 852.846f, Coords.y = 2166.327f, Coords.z = 52.717f; TPto(Coords); }
	if (Addoption("37")) { Vector3 Coords; Coords.x = -1501.96f, Coords.y = 814.071f, Coords.z = 181.433f; TPto(Coords); }
	if (Addoption("38")) { Vector3 Coords; Coords.x = 2634.972f, Coords.y = 2931.061f, Coords.z = 44.608f; TPto(Coords); }
	if (Addoption("39")) { Vector3 Coords; Coords.x = 660.57f, Coords.y = 549.947f, Coords.z = 129.157f; TPto(Coords); }
	if (Addoption("40")) { Vector3 Coords; Coords.x = -710.626f, Coords.y = -905.881f, Coords.z = 19.015f; TPto(Coords); }
	if (Addoption("41")) { Vector3 Coords; Coords.x = 1207.701f, Coords.y = -1479.537f, Coords.z = 35.166f; TPto(Coords); }
	if (Addoption("42")) { Vector3 Coords; Coords.x = -90.151f, Coords.y = 939.849f, Coords.z = 232.515f; TPto(Coords); }
	if (Addoption("43")) { Vector3 Coords; Coords.x = -180.059f, Coords.y = -631.866f, Coords.z = 48.534f; TPto(Coords); }
	if (Addoption("44")) { Vector3 Coords; Coords.x = -299.634f, Coords.y = 2847.173f, Coords.z = 55.485f; TPto(Coords); }
	if (Addoption("45")) { Vector3 Coords; Coords.x = 621.365f, Coords.y = -409.254f, Coords.z = -1.308f; TPto(Coords); }
	if (Addoption("46")) { Vector3 Coords; Coords.x = -988.92f, Coords.y = -102.669f, Coords.z = 40.157f; TPto(Coords); }
	if (Addoption("47")) { Vector3 Coords; Coords.x = 63.999f, Coords.y = 3683.868f, Coords.z = 39.763f; TPto(Coords); }
	if (Addoption("48")) { Vector3 Coords; Coords.x = -688.668f, Coords.y = 5829.006f, Coords.z = 16.775f; TPto(Coords); }
	if (Addoption("49")) { Vector3 Coords; Coords.x = 1540.435f, Coords.y = 6323.453f, Coords.z = 23.519f; TPto(Coords); }
	if (Addoption("50")) { Vector3 Coords; Coords.x = 2725.806f, Coords.y = 4142.14f, Coords.z = 43.293f; TPto(Coords); }
	if (Addoption("51")) { Vector3 Coords; Coords.x = 1297.977f, Coords.y = 4306.744f, Coords.z = 37.897f; TPto(Coords); }
	if (Addoption("52")) { Vector3 Coords; Coords.x = 1189.579f, Coords.y = 2641.222f, Coords.z = 38.413f; TPto(Coords); }
	if (Addoption("53")) { Vector3 Coords; Coords.x = -440.796f, Coords.y = 1596.48f, Coords.z = 358.648f; TPto(Coords); }
	if (Addoption("54")) { Vector3 Coords; Coords.x = -2237.557f, Coords.y = 249.282f, Coords.z = 175.352f; TPto(Coords); }
	if (Addoption("55")) { Vector3 Coords; Coords.x = -1211.932f, Coords.y = -959.965f, Coords.z = 0.393f; TPto(Coords); }
	if (Addoption("56")) { Vector3 Coords; Coords.x = 153.845f, Coords.y = -3077.341f, Coords.z = 6.744f; TPto(Coords); }
	if (Addoption("57")) { Vector3 Coords; Coords.x = -66.231f, Coords.y = -1451.825f, Coords.z = 31.164f; TPto(Coords); }
	if (Addoption("58")) { Vector3 Coords; Coords.x = 987.982f, Coords.y = -136.863f, Coords.z = 73.454f; TPto(Coords); }
	if (Addoption("59")) { Vector3 Coords; Coords.x = -507.032f, Coords.y = 393.905f, Coords.z = 96.411f; TPto(Coords); }
	if (Addoption("60")) { Vector3 Coords; Coords.x = 172.1275f, Coords.y = -564.1393f, Coords.z = 22.145f; TPto(Coords); }
	if (Addoption("61")) { Vector3 Coords; Coords.x = 1497.202f, Coords.y = -2133.147f, Coords.z = 76.302f; TPto(Coords); }
	if (Addoption("62")) { Vector3 Coords; Coords.x = -2958.706f, Coords.y = 386.41f, Coords.z = 14.434f; TPto(Coords); }
	if (Addoption("63")) { Vector3 Coords; Coords.x = 1413.963f, Coords.y = 1162.483f, Coords.z = 114.351f; TPto(Coords); }
	if (Addoption("64")) { Vector3 Coords; Coords.x = -1648.058f, Coords.y = 3018.313f, Coords.z = 31.25f; TPto(Coords); }
	if (Addoption("65")) { Vector3 Coords; Coords.x = -1120.2f, Coords.y = 4977.292f, Coords.z = 185.445f; TPto(Coords); }
	if (Addoption("66")) { Vector3 Coords; Coords.x = 2394.721f, Coords.y = 3062.689f, Coords.z = 51.2379f; TPto(Coords); }
	if (Addoption("67")) { Vector3 Coords; Coords.x = 1310.683f, Coords.y = 6545.917f, Coords.z = 4.798f; TPto(Coords); }
	if (Addoption("68")) { Vector3 Coords; Coords.x = 1714.573f, Coords.y = 4790.844f, Coords.z = 41.539f; TPto(Coords); }
	if (Addoption("69")) { Vector3 Coords; Coords.x = 1886.644f, Coords.y = 3913.758f, Coords.z = 32.039f; TPto(Coords); }
	if (Addoption("70")) { Vector3 Coords; Coords.x = 543.476f, Coords.y = 3074.79f, Coords.z = 40.324f; TPto(Coords); }
	if (Addoption("71")) { Vector3 Coords; Coords.x = 1408.045f, Coords.y = 2157.34f, Coords.z = 97.575f; TPto(Coords); }
	if (Addoption("72")) { Vector3 Coords; Coords.x = -3243.858f, Coords.y = 996.179f, Coords.z = 12.486f; TPto(Coords); }
	if (Addoption("73")) { Vector3 Coords; Coords.x = -1905.566f, Coords.y = -709.6311f, Coords.z = 8.766f; TPto(Coords); }
	if (Addoption("74")) { Vector3 Coords; Coords.x = -1462.089f, Coords.y = 182.089f, Coords.z = 54.953f; TPto(Coords); }
	if (Addoption("75")) { Vector3 Coords; Coords.x = 86.997f, Coords.y = 812.619f, Coords.z = 211.062f; TPto(Coords); }
	if (Addoption("76")) { Vector3 Coords; Coords.x = -886.554f, Coords.y = -2096.579f, Coords.z = 8.699f; TPto(Coords); }
	if (Addoption("77")) { Vector3 Coords; Coords.x = 367.684f, Coords.y = -2113.475f, Coords.z = 16.274f; TPto(Coords); }
	if (Addoption("78")) { Vector3 Coords; Coords.x = 679.009f, Coords.y = -1522.824f, Coords.z = 8.834f; TPto(Coords); }
	if (Addoption("79")) { Vector3 Coords; Coords.x = 1667.377f, Coords.y = 0.119f, Coords.z = 165.118f; TPto(Coords); }
	if (Addoption("80")) { Vector3 Coords; Coords.x = -293.486f, Coords.y = -342.485f, Coords.z = 9.481f; TPto(Coords); }
	if (Addoption("81")) { Vector3 Coords; Coords.x = 462.664f, Coords.y = -765.675f, Coords.z = 26.358f; TPto(Coords); }
	if (Addoption("82")) { Vector3 Coords; Coords.x = -57.784f, Coords.y = 1939.74f, Coords.z = 189.655f; TPto(Coords); }
	if (Addoption("83")) { Vector3 Coords; Coords.x = 2618.411f, Coords.y = 1692.395f, Coords.z = 31.9462f; TPto(Coords); }
	if (Addoption("84")) { Vector3 Coords; Coords.x = -1894.554f, Coords.y = 2043.517f, Coords.z = 140.9093f; TPto(Coords); }
	if (Addoption("85")) { Vector3 Coords; Coords.x = 2221.858f, Coords.y = 5612.785f, Coords.z = 54.0631f; TPto(Coords); }
	if (Addoption("86")) { Vector3 Coords; Coords.x = -551.3712f, Coords.y = 5330.728f, Coords.z = 73.9861f; TPto(Coords); }
	if (Addoption("87")) { Vector3 Coords; Coords.x = -2171.406f, Coords.y = 3441.188f, Coords.z = 32.175f; TPto(Coords); }
	if (Addoption("88")) { Vector3 Coords; Coords.x = 1848.131f, Coords.y = 2700.702f, Coords.z = 63.008f; TPto(Coords); }
	if (Addoption("89")) { Vector3 Coords; Coords.x = -1719.602f, Coords.y = -232.886f, Coords.z = 54.4441f; TPto(Coords); }
	if (Addoption("90")) { Vector3 Coords; Coords.x = -55.3785f, Coords.y = -2519.755f, Coords.z = 7.2875f; TPto(Coords); }
	if (Addoption("91")) { Vector3 Coords; Coords.x = 874.8454f, Coords.y = -2163.998f, Coords.z = 32.3688f; TPto(Coords); }
	if (Addoption("92")) { Vector3 Coords; Coords.x = -43.6983f, Coords.y = -1747.961f, Coords.z = 29.2778f; TPto(Coords); }
	if (Addoption("93")) { Vector3 Coords; Coords.x = 173.324f, Coords.y = -1208.43f, Coords.z = 29.6564f; TPto(Coords); }
	if (Addoption("94")) { Vector3 Coords; Coords.x = 2936.323f, Coords.y = 4620.483f, Coords.z = 48.767f; TPto(Coords); }
	if (Addoption("95")) { Vector3 Coords; Coords.x = 3514.655f, Coords.y = 3754.687f, Coords.z = 34.4766f; TPto(Coords); }
	if (Addoption("96")) { Vector3 Coords; Coords.x = 656.9f, Coords.y = -1046.931f, Coords.z = 21.5745f; TPto(Coords); }
	if (Addoption("97")) { Vector3 Coords; Coords.x = -141.1536f, Coords.y = 234.8366f, Coords.z = 99.0008f; TPto(Coords); }
	if (Addoption("98")) { Vector3 Coords; Coords.x = -1806.68f, Coords.y = 427.6159f, Coords.z = 131.765f; TPto(Coords); }
	if (Addoption("99")) { Vector3 Coords; Coords.x = -908.9565f, Coords.y = -1148.917f, Coords.z = 2.3868f; TPto(Coords); }
	if (Addoption("100")) { Vector3 Coords; Coords.x = 387.9323f, Coords.y = 2570.408f, Coords.z = 43.299f; TPto(Coords); }
	
}
void Foxy_EngineTP::servicesss()
{
	Addtitle("Services");
	Addsubtitle("Services");
	if (Addoption("Fire Station - Davis, Macdonald")) { Vector3 Coords;                 Coords.x = 213.927261f; Coords.y = -1639.267090f; Coords.z = 29.692514f;                 TPto(Coords); }
	if (Addoption("Fire Station - Fort Zancudo")) { Vector3 Coords;                 Coords.x = -2113.866699f; Coords.y = 2847.312988f; Coords.z = 32.558411f;                 TPto(Coords); }
	if (Addoption("Fire Station - LS HQ")) { Vector3 Coords;                 Coords.x = -639.470703f; Coords.y = -122.451233f; Coords.z = 38.112556f;                 TPto(Coords); }
	if (Addoption("Fire Station - LS Station 7")) { Vector3 Coords;                 Coords.x = 1200.554443f; Coords.y = -1457.295044f; Coords.z = 35.248623f;                 TPto(Coords); }
	if (Addoption("Fire Station - Paleto Bay")) { Vector3 Coords;                 Coords.x = -387.178131f; Coords.y = 6125.819336f; Coords.z = 31.586800f;                 TPto(Coords); }
	if (Addoption("Fire Station - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1691.670166f; Coords.y = 3579.191895f; Coords.z = 35.636360f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 1")) { Vector3 Coords;                 Coords.x = -1290.980835f; Coords.y = -1757.102905f; Coords.z = 3.058975f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 2")) { Vector3 Coords;                 Coords.x = -1373.146851f; Coords.y = -1627.157837f; Coords.z = 3.364384f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 3")) { Vector3 Coords;                 Coords.x = -1432.086426f; Coords.y = -1512.424316f; Coords.z = 3.214696f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 4")) { Vector3 Coords;                 Coords.x = -1468.421753f; Coords.y = -1391.712158f; Coords.z = 3.525731f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 5")) { Vector3 Coords;                 Coords.x = -1520.238281f; Coords.y = -1275.765625f; Coords.z = 2.950766f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 6")) { Vector3 Coords;                 Coords.x = -1560.793945f; Coords.y = -1158.407593f; Coords.z = 3.295668f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 7")) { Vector3 Coords;                 Coords.x = -1798.075684f; Coords.y = -858.578857f; Coords.z = 8.840805f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 8")) { Vector3 Coords;                 Coords.x = -1904.379150f; Coords.y = -713.960449f; Coords.z = 8.344188f;                 TPto(Coords); }
	if (Addoption("Hospital - Lifeguard 9")) { Vector3 Coords;                 Coords.x = -2006.548340f; Coords.y = -560.289368f; Coords.z = 12.898447f;                 TPto(Coords); }
	if (Addoption("Hospital - Paleto Bay")) { Vector3 Coords;                 Coords.x = -440.541779f; Coords.y = 6019.399902f; Coords.z = 31.262650f;                 TPto(Coords); }
	if (Addoption("Hospital - Rockford Hills")) { Vector3 Coords;                 Coords.x = -475.191345f; Coords.y = -353.762787f; Coords.z = 34.002174f;                 TPto(Coords); }
	if (Addoption("Hospital - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1850.026367f; Coords.y = 3679.041748f; Coords.z = 33.983913f;                 TPto(Coords); }
	if (Addoption("Hospital - Strawberry Ave")) { Vector3 Coords;                 Coords.x = 337.111145f; Coords.y = -1393.440063f; Coords.z = 32.257248f;                 TPto(Coords); }
	if (Addoption("Hospital - textile City")) { Vector3 Coords;                 Coords.x = 376.534027f; Coords.y = -581.015381f; Coords.z = 28.707024f;                 TPto(Coords); }
	if (Addoption("Police - La Mesa")) { Vector3 Coords;                 Coords.x = 817.000000f; Coords.y = -1290.000000f; Coords.z = 26.146124f;                 TPto(Coords); }
	if (Addoption("Police - Mission Row")) { Vector3 Coords;                 Coords.x = 429.601593f; Coords.y = -982.458923f; Coords.z = 30.463333f;                 TPto(Coords); }
	if (Addoption("Police - Paleto Bay")) { Vector3 Coords;                 Coords.x = -440.541779f; Coords.y = 6019.399902f; Coords.z = 31.262650f;                 TPto(Coords); }
	if (Addoption("Police - Rancho")) { Vector3 Coords;                 Coords.x = 360.000000f; Coords.y = -1583.000000f; Coords.z = 29.105696f;                 TPto(Coords); }
	if (Addoption("Police - Rockford Hills")) { Vector3 Coords;                 Coords.x = -557.245789f; Coords.y = -142.276871f; Coords.z = 38.247066f;                 TPto(Coords); }
	if (Addoption("Police - Sandy Shores")) { Vector3 Coords;                 Coords.x = 1858.026367f; Coords.y = 3679.041748f; Coords.z = 33.983913f;                 TPto(Coords); }
	if (Addoption("Police - Vespucci Beach")) { Vector3 Coords;                 Coords.x = -1312.137085f; Coords.y = -1528.899658f; Coords.z = 4.159692f;                 TPto(Coords); }
	if (Addoption("Police - Vespucci HQ")) { Vector3 Coords;                 Coords.x = -1110.682617f; Coords.y = -846.652466f; Coords.z = 19.361103f;                 TPto(Coords); }
	if (Addoption("Police - Vinewood")) { Vector3 Coords;                 Coords.x = 642.722046f; Coords.y = 0.252486f; Coords.z = 82.890823f;                 TPto(Coords); }
	if (Addoption("Police - Vinewood Hills Ranger")) { Vector3 Coords;                 Coords.x = 388.549255f; Coords.y = 791.305176f; Coords.z = 190.476166f;                 TPto(Coords); }
}
void Foxy_EngineTP::Teleportmainsub()
{

	Addtitle("TP");
	Addsubtitle("Teleports");
	if (Addoption("Waypoint")) {
		{
			Vector3 coords = get_blip_marker();


			// get entity to teleport
			Entity e = PLAYER::PLAYER_PED_ID();
			if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
			{
				e = PED::GET_VEHICLE_PED_IS_USING(e);
			}

			// load needed map region and check height levels for ground existence
			bool groundFound = false;
			static float groundCheckHeight[] =
			{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(100);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
				{
					groundFound = true;
					coords.z += 3.0;
					break;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				coords.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), 0xFBAB5776, 1, 0);
			}
			//do it
			teleport_to_coords(e, coords);
			CAM::DO_SCREEN_FADE_IN(200);
		}
	}
	addint("Location Slot", Local::selectedLocation, 0, 100);
	if (Addoption("Save Location Ini")) { Local::savelocation(Local::selectedLocation); }
	if (Addoption("Teleport To Ini Location")) { Local::loadlocation(Local::selectedLocation); }
	Addsub("Clothing Stores", TPClothingStore);
	Addsub("Barbers", TPBarbers);
	Addsub("Los Santos Customs", TPLSC);
	Addsub("Other Vehicle TPs", TPOVehicle);
	Addsub("Ammunation", TPAmmunation);
	Addsub("Sports", TPSports);
	Addsub("Stores", TPStores);
	Addsub("Cinema", TPCinema);
	Addsub("Tattoos", TPTattos);
	Addsub("Airports", TPAir);
	Addsub("Fun", TPFun);
	Addsub("Other", TPOther);
	Addsub("Underwater", TPUnderwater);
	Addsub("ATM's", TPATMs);
	Addsub("Banks", TPBanks);
	Addsub("Services", TPServices);
	Addsub("Apartments Online", TPAparts);
	Addsub("Statues", TPRp);
}
