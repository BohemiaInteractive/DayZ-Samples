class CfgPatches
{
	class smpl_worlds_utes
	{
		requiredAddons[] = {"DZ_Data"};
	};
};

// scenes for the mission in main menu
class CfgCharacterScenes
{
	class utes
	{
		class loc1
		{
			target[] = {4353.24, 3178.16, 27.91};
			position[] = {4361.72, 3172.31, 1.1};
			fov = 0.5236;
			date[] = {2011, 10, 11, 11, 22};
			overcast = 0.15;
			rain = 0.0;
			fog = 0.0;
		};
	};
};
// mission for the main menu this path does not have to exist, the important is \intro.worldname
class CfgMissions
{
	class Cutscenes
	{
		class UtesMenu
		{
			directory = "\intro.utes";
		};
	};
};

// actual cfgworlds class
class CfgWorlds
{
	class CAWorld;
	class utes: CAWorld
	{
		// name of the world
		description = "Utes";
		
		// position on Earth (for sky simulation)
		longitude = 30.0;	// positive is east
		latitude = -45.0;	// positive is south
		
		// link of wrp file (exported from Terrain Builder)
		worldName = "samples\test_terrain\world\utes.wrp";
		
		// link of world and required cutscene for the main menu
		cutscenes[] = {"UtesMenu"};
		
		// link of default central economy files for this terrain
		// (game will look into this folder when you attempt to init CE in your mission)
		ceFiles = "samples\test_terrain\ce";

		// navmesh definition (path for navmesh inside hpp)
		class Navmesh
		{
			#include "cfgNavmesh.hpp"
		};
		
		// default time and date
		startTime = "14:20";
		startDate = "11/10/2011";

		// for map init
		centerPosition[] = {2560.0, 2560.0, 300.0};

		// how dense grass-clutter should be
		clutterGrid = 1.0;
		// how far visible grass-clutter should be
		clutterDist = 125.0;

		// values for lerp between detailed terrain surfaces and satellite texture
		noDetailDist = 65.0;
		fullDetailDist = 10.0;

		// base height for volFog (see CAWorld Weather class)
		volFogOffset = 0;
		
		// link of materials for detailed terrain surfaces (for specular to work)
		class UsedTerrainMaterials
		{
			material1 = "DZ\surfaces\data\terrain\cp_concrete1.rvmat";
			material2 = "DZ\surfaces\data\terrain\cp_conifer_common1.rvmat";
			material3 = "DZ\surfaces\data\terrain\cp_dirt.rvmat";
			material4 = "DZ\surfaces\data\terrain\cp_grass.rvmat";
			material5 = "DZ\surfaces\data\terrain\cp_grass_tall.rvmat";
			material6 = "DZ\surfaces\data\terrain\cp_gravel.rvmat";
			material7 = "DZ\surfaces\data\terrain\cp_rock.rvmat";
			material8 = "samples\test_terrain\data\surfaces\data\utes_concrete.rvmat";
		};
		
		// mid-distance noise to prevent seeing bluriness of satellite texture at those distances
		midDetailTexture = "samples\test_terrain\data\utes_middlesat_mco.paa";
		
		// normal map for shadowing of grass-clutter
		terrainNormalTexture = "samples\test_terrain\data\utes_global_nohq.paa";
		
		// generated terrain outside of the map borders
		class OutsideTerrain
		{
			satellite = "samples\test_terrain\data\utes_outsidesat_co.paa";
			enableTerrainSynth = false;
			class Layers
			{
				class Layer0
				{
					nopx = "DZ\surfaces\data\terrain\cp_gravel_nopx.paa";
					texture	= "DZ\surfaces\data\terrain\cp_gravel_ca.paa";
				};
			};
		};
		
		// override for sea materials (enfusion materials)
		oceanMaterial = "samples\test_terrain\data\utes_sea.emat";
		oceanNiceMaterial = "samples\test_terrain\data\utes_sea_nice.emat";
		oceanStormMaterial = "samples\test_terrain\data\utes_sea_storm.emat";

		// 2d map location names
		class Names
		{
			#include "cfgNames.hpp"
		};

		// 2d map airfields
		ilsPosition[] = {3330.0, 3610.0};
		ilsDirection[] = {-1.0, 0.08, 0.0};
		ilsTaxiOff[] =
		{
			3520.0,3610.0,
			4040.0,3610.0,
			4050.0,3600.0,
			4050.0,3580.0,
			4045.0,3575.0,
			4040.0,3572.0,
			3540.0,3572.0
		};
		ilsTaxiIn[] =
		{
			3540.0,3572.0,
			3388.0,3572.0,
			3382.0,3578.0,
			3382.0,3600.0,
			3400.0,3610.0
		};
		drawTaxiway = false;
		class SecondaryAirports	{};

		// 2d map grid
		class Grid
		{
			offsetX = 0.0;
			offsetY = 0.0;
			class Zoom1
			{
				zoomMax = 0.15;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100.0;
				stepY = 100.0;
			};
			class Zoom2
			{
				zoomMax = 0.85;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000.0;
				stepY = 1000.0;
			};
			class Zoom3
			{
				zoomMax = 1e+030;
				format = "XY";
				formatX = "0";
				formatY = "0";
				stepX = 10000.0;
				stepY = 10000.0;
			};
		};
		
		// 2D map item params
		mapDisplayNameKey = "#STR_CfgVehicles_ChernarusMap0";
		mapDescriptionKey = "#STR_CfgVehicles_ChernarusMap1";
		mapTextureClosed = "dz\gear\navigation\data\map_chernarus_co.paa";
		mapTextureOpened = "dz\structures\signs\tourist\data\karta_co.paa";
		mapTextureLegend = "dz\structures\signs\tourist\data\karta_side_co.paa";
		userMapPath = "dz\gear\navigation\data\usermap";
		
		minTreesInForestSquare = 10;	// for 2d map (also affects forest controller)
		minRocksInRockSquare = 5;		// for 2d map
		
		soundMapAttenCoef = 0.01;		// sound map params
		class SoundMapValues
		{
			treehard = 0.03;
			treesoft = 0.03;
			bushhard = 0.0;
			bushsoft = 0.0;
			forest = 1.0;
			house = 0.3;
			church = 0.5;
		};
		class Sounds
		{
			sounds[] = {};
		};
		
		// ambient life (flies, leaves,..)
		class Ambient {};
	};
};