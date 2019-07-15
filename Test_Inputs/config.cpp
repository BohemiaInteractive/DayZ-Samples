class CfgPatches
{
	class Test_Inputs
	{
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class Test_Inputs
	{
		inputs = "samples\test_inputs\my_new_inputs.xml";
		type = "mod";

		class defs
		{		
			class gameScriptModule
			{
				value="";
				files[]={"samples/test_inputs/scripts/gameModule"};
			};

			class worldScriptModule
			{
				value="";
				files[]={"samples/test_inputs/scripts/worldModule"};
			};
		}
		
		
	};
};

