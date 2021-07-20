class Test_GardenPlot : GardenPlot
{
	private const int TESTPLOT_SLOT_COUNT = 4;
	override int GetGardenSlotsCount()
	{
		return TESTPLOT_SLOT_COUNT;
	}
	
	override void RefreshSlots()
	{
		HideSelection("SeedBase_1");
		HideSelection("SeedBase_2");
		HideSelection("SeedBase_3");
		HideSelection("SeedBase_4");
	}
}