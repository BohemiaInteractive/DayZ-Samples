class CfgPatches
{
	class smpl_test_scriptcommandswim
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
	class smpl_test_scriptcommandswim
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/test_scriptcmdswim/scripts/4_world"};
			};
		}
	};
};