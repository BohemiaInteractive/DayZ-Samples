class CfgPatches
{
	class Test_MapItem
	{
		requiredAddons[] = {"DZ_Data", "DZ_Gear_Navigation"};
	};
};

class CfgMods
{
	class Test_MapItem
	{
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/test_mapitem/scripts/4_world"};
			};
		}
	};
};

class MapDefaults;
class MapDefaultsUtes: MapDefaults
{
	maxUserMapAlpha = 0.0;
};

class CfgVehicles
{
	class Inventory_Base;
	class ItemMap: Inventory_Base {};
	class UtesMap: ItemMap
	{
		scope = 2;
		displayName = "MapItemName";
		descriptionShort = "MapItemDescription";
		model = "samples\test_mapitem\map_utes.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 40;
		world = "utes";
		selectionPaper = "paper";
		simulation = "ItemMap";
		absorbency = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {
						{1.01,{"samples\test_mapitem\data\map_utes.rvmat"}},
						{0.7,{"samples\test_mapitem\data\map_utes.rvmat"}},
						{0.5,{"samples\test_mapitem\data\map_utes_damage.rvmat"}},
						{0.3,{"samples\test_mapitem\data\map_utes_damage.rvmat"}},
						{0.01,{"samples\test_mapitem\data\map_utes_destruct.rvmat"}}
					};
				};
			};
		};
		class MapProperties: MapDefaultsUtes
		{
			scaleMin = 0.12;
			scaleMax = 0.6;
		};
		class AnimationSources
		{
			class map_closed
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class map_opened
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
		};
	};
};