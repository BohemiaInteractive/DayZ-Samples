class CfgPatches
{
	class Test_GardenPlot
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class Test_GardenPlot
	{	
		type = "mod";
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"samples/Test_GardenPlot/Scripts"};
			};
		}
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Test_GardenPlot : Inventory_Base
	{
		scope = 2;
		model = "Samples\Test_GardenPlot\Test_GardenPlot.p3d";

		storageCategory = 1;

		useEntityHierarchy = "true";

		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = { 10,10,10 };
		
		physLayer = "item_large";

		attachments[] = { "SeedBase_1", "SeedBase_2", "SeedBase_3", "SeedBase_4" };

		hiddenSelections[] = 
		{
			"SeedBase_1",
			"SeedBase_2",
			"SeedBase_3",
			"SeedBase_4",
			"slotCovered_01",
			"slotCovered_02",
			"slotCovered_03",
			"slotCovered_04",
		};

		hiddenSelectionsTextures[] = 
		{
			"dz\gear\cultivation\data\soil_cultivated_co.paa",
			"dz\gear\cultivation\data\soil_cultivated_limed_CO.paa",
			"dz\gear\cultivation\data\soil_cultivated_compost_CO.paa",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};

		hiddenSelectionsMaterials[] = 
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};

		class  AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};

			class slotHidden : slotVisible
			{
				initPhase = 1;
			};
			
			class SeedBase_1 : slotVisible {};
			class SeedBase_2 : slotVisible {};
			class SeedBase_3 : slotVisible {};
			class SeedBase_4 : slotVisible {};
			
			class slotCovered_01 : slotHidden {};
			class slotCovered_02 : slotHidden {};
			class slotCovered_03 : slotHidden {};
			class slotCovered_04 : slotHidden {};
		};
		
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = $STR_attachment_Filling0;
				description = "";
				icon = "set:dayz_inventory image:cat_gp_filling";

				attachmentSlots[] = { "SeedBase_1", "SeedBase_2", "SeedBase_3", "SeedBase_4" };
			};
		};
	};
};