modded class OpenCan extends RecipeBase
{
	override void Init()
	{
		super.Init();
		InsertIngredient(1,"MagicHammer");
		RemoveIngredient(1,"CanOpener");
	}
}