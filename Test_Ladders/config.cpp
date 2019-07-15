class CfgPatches
{
	class smpl_structures_ladders
	{
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class land_sample_laddernest: HouseNoDestruct
	{
		scope = 1;
		model = "samples\test_ladders\laddernest\sample_laddernest.p3d";
	};
};