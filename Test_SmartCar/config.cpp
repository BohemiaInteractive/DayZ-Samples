class CfgPatches
{
	class smpl_test_smartcar
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
		author = "yourname";
		name = "addonname";
		url = "websitelink";
	};
};

class CfgMods
{
	class smpl_test_scriptsmartccar
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/test_smartcar/scripts/4_world"};
			};
		}
	};
};