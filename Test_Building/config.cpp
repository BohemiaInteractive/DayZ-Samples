class CfgPatches
{
	class smpl_structures_doors
	{
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class land_sample_building: HouseNoDestruct
	{
		scope = 1;
		model = "samples\test_building\sample_building.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "Twin Doors 1";
				component = "doorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1.0;
				initPhase = 0.0;
				initOpened = 0.0;
				soundOpen = "doorMetalTwinBigOpen";
				soundClose = "doorMetalTwinBigClose";
				soundLocked = "doorMetalTwinBigRattle";
				soundOpenABit = "doorMetalTwinBigOpenABit";
			};
			class Door3
			{
				displayName = "Door 3";
				component = "door3";
				soundPos = "door3_action";
				animPeriod = 1.0;
				initPhase = 0.0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class DoorsTwin1
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"door3"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};
};