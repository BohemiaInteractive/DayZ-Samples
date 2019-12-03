class CfgPatches
{
	class smpl_structures_fireplace
	{
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class smpl_structures_fireplace
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/test_buildingfireplace/scripts/4_world"};
			};
		}
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class land_sample_building_fireplace: HouseNoDestruct
	{
		scope = 1;
		model = "samples\test_buildingfireplace\sample_building_fireplace.p3d";
	};
};