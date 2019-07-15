class CfgPatches
{
	class smpl_utes_surfaces
	{
		requiredAddons[] = {"DZ_Data"};
	};
};


class CfgSurfaces
{
	class DZ_SurfacesInt;
	class DZ_SurfacesExt;

	class utes_concrete: DZ_SurfacesExt
	{
		files = "utes_concrete*";

		rough = 0.01;
		dust = 0.05;

		friction = 0.98;
		restitution = 0.55;
		vpSurface = "Asphalt";

		soundEnviron = "road";
		soundHit = "hard_ground";

		character = "cp_concrete_grass";

		footDamage = 0.117;
		audibility = 1.0;

		impact = "Hit_Concrete";
		deflection = 0.1;
	};
};

class CfgSoundTables
{
	class CfgStepSoundTables
	{
		#include "sounds_animals.hpp"
		#include "sounds_infected.hpp"
		#include "sounds_character.hpp"
	};
};