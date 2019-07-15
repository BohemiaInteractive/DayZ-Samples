class CfgPatches
{
	class Test_Crafting
	{
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class Test_Crafting
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/test_crafting/scripts/4_world"};
			};
		}
	};
};

class CfgVehicles
{
	class Hammer;
	class MagicHammer: Hammer		// Simple custom item which will serve as new component for our recipe
	{
		displayName = "Magic Hammer";
		descriptionShort = "The great deconstructor";
	};
};
