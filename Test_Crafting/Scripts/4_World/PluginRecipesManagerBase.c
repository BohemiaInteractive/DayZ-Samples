modded class PluginRecipesManagerBase extends PluginBase
{	
	override void RegisterRecipies()
	{
		super.RegisterRecipies();				// Calling base RegisterRecipies()
		RegisterRecipe(new ExampleRecipe);		// Registering our custom ExampleRecipe
		UnregisterRecipe("CraftStoneKnife");	// Removing an existing recipe
	}
};