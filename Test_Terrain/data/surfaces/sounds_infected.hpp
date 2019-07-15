// infected.hpp
//  macros for generating sound lookup tables
#define CHAR_BODYFALL_ZMB_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##shadername##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##shadername##_##surfacesound##_Zmb_SoundSet\
							};\
						}
#define CHAR_BODYFALL_LOOKUPTABLE(shadername)\
			class ##shadername##_Zmb_LookupTable\
			{\
				CHAR_BODYFALL_ZMB_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for CHAR_BODYFALL_ZMB_LOOUPTABLE_CLASS macro:
 *,asphalt_ext, asphalt_int
 * forestBroadleaf
 * grass
 * dirt_ext, dirt_int
 * gravelSmall_ext, gravelSmall_int
 * gravelLarge_ext, gravelLarge_int
 * linoleum_ext, linoleum_int
 * metal_ext, metal_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
*/

// create lookup tables from macros above
CHAR_BODYFALL_LOOKUPTABLE(bodyfall)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_hand)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_slide)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_bare_Zmb_Soundset\
							};\
						}
#define ZMB_STEP_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Bare_Zmb_LookupTable\
			{\
        ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc)
ZMB_STEP_LOOKUPTABLE(runErc)
ZMB_STEP_LOOKUPTABLE(sprintErc)
ZMB_STEP_LOOKUPTABLE(landFeetErc)
ZMB_STEP_LOOKUPTABLE(scuffErc)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOKUPTABLE(movementtype,targetmovement)\
			class ##targetmovement##_Bare_Zmb_LookupTable\
			{\
				ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc,walkRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,runRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,landFootErc)
ZMB_STEP_LOOKUPTABLE(walkErc,walkCro)
ZMB_STEP_LOOKUPTABLE(runErc,runCro)
ZMB_STEP_LOOKUPTABLE(runErc,jumpErc)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_boots_Zmb_Soundset\
							};\
						}
#define ZMB_STEP_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Boots_Zmb_LookupTable\
			{\
				ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc)
ZMB_STEP_LOOKUPTABLE(runErc)
ZMB_STEP_LOOKUPTABLE(sprintErc)
ZMB_STEP_LOOKUPTABLE(landFeetErc)
ZMB_STEP_LOOKUPTABLE(scuffErc)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOKUPTABLE(movementtype,targetmovement)\
			class ##targetmovement##_Boots_Zmb_LookupTable\
			{\
				ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc,walkRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,runRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,landFootErc)
ZMB_STEP_LOOKUPTABLE(walkErc,walkCro)
ZMB_STEP_LOOKUPTABLE(runErc,runCro)
ZMB_STEP_LOOKUPTABLE(runErc,jumpErc)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_sneakers_Zmb_Soundset\
							};\
						}
#define ZMB_STEP_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Sneakers_Zmb_LookupTable\
			{\
				ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc)
ZMB_STEP_LOOKUPTABLE(runErc)
ZMB_STEP_LOOKUPTABLE(sprintErc)
ZMB_STEP_LOOKUPTABLE(landFeetErc)
ZMB_STEP_LOOKUPTABLE(scuffErc)

//  macros for generating sound lookup tables
#define ZMB_STEP_LOOKUPTABLE(movementtype,targetmovement)\
			class ##targetmovement##_Sneakers_Zmb_LookupTable\
			{\
				ZMB_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
ZMB_STEP_LOOKUPTABLE(walkErc,walkRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,runRasErc)
ZMB_STEP_LOOKUPTABLE(runErc,landFootErc)
ZMB_STEP_LOOKUPTABLE(walkErc,walkCro)
ZMB_STEP_LOOKUPTABLE(runErc,runCro)
ZMB_STEP_LOOKUPTABLE(runErc,jumpErc)

//  macros for generating sound lookup tables
#define CHAR_STEP_PRONE_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_Zmb_Soundset\
							};\
						}
#define CHAR_STEP_PRONE_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Zmb_LookupTable\
			{\
				CHAR_STEP_PRONE_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 *,asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
*/

// create lookup tables from macros above
CHAR_STEP_PRONE_LOOKUPTABLE(walkProne)
CHAR_STEP_PRONE_LOOKUPTABLE(runProne)