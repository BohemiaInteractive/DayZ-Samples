// character.hpp
//  macros for generating sound lookup tables
#define CHAR_STEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_Char_Soundset\
							};\
						}
#define CHAR_STEP_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Char_LookupTable\
			{\
				CHAR_STEP_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_ext, metal_thin_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * gravel_small_ext, gravel_small_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
 * water
*/

// create lookup tables from macros above
CHAR_STEP_LOOKUPTABLE(walkErc)
CHAR_STEP_LOOKUPTABLE(walkRasErc)
CHAR_STEP_LOOKUPTABLE(runErc)
CHAR_STEP_LOOKUPTABLE(runRasErc)
CHAR_STEP_LOOKUPTABLE(sprintErc)
CHAR_STEP_LOOKUPTABLE(landFootErc)
CHAR_STEP_LOOKUPTABLE(landFeetErc)
CHAR_STEP_LOOKUPTABLE(scuffErc)
CHAR_STEP_LOOKUPTABLE(walkCro)
CHAR_STEP_LOOKUPTABLE(runCro)
CHAR_STEP_LOOKUPTABLE(jumpErc)

//  macros for generating sound lookup tables
#define CHAR_STEP_PRONE_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_##surfacesound##_Char_Soundset\
							};\
						}
#define CHAR_STEP_PRONE_LOOKUPTABLE(movementtype)\
			class ##movementtype##_Char_LookupTable\
			{\
				CHAR_STEP_PRONE_LOOUPTABLE_CLASS(utes_concrete,concrete_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_felt_ext, asphalt_felt_int
 * cp_broadleaf_dense1
 * cp_grass_tall
 * concrete_ext, concrete_int
 * ceramic_tiles_ext, ceramic_tiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext, grass_dry_int
 * gravel_small_ext, gravel_small_int
 * metal_thick_ext, metal_thick_int
 * metal_thin_ext, metal_thin_int
 * metal_thin_mesh_ext, metal_thin_mesh_int
 * gravel_small_ext, gravel_small_int
 * sand_ext, sand_int
 * textile_carpet_ext, textile_carpet_int
 * wood_parquet_ext, wood_parquet_int
 * wood_planks_ext, wood_planks_int
 * water
*/

// create lookup tables from macros above
CHAR_STEP_PRONE_LOOKUPTABLE(walkProne)
CHAR_STEP_PRONE_LOOKUPTABLE(runProne)

//  macros for generating sound lookup tables
#define CHAR_STEP_PRONE_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##movementtype##_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##movementtype##_noHS_##surfacesound##_Char_Soundset\
							};\
						}
#define CHAR_STEP_PRONE_LOOKUPTABLE(movementtype)\
			class ##movementtype##_noHS_Char_LookupTable\
			{\
				CHAR_STEP_PRONE_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext
 * cp_broadleaf_dense1
 * dirt_ext
 * grass_dry_ext
 * gravel_small_ext
 * gravel_large_ext
 * wood_planks_ext
 * water
*/

// create lookup tables from macros above
CHAR_STEP_PRONE_LOOKUPTABLE(walkProne)
CHAR_STEP_PRONE_LOOKUPTABLE(walkProneLong)

//  macros for generating sound lookup tables
#define CHAR_HANDSTEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class handstepSound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								Handstep_##surfacesound##_Char_SoundSet\
							};\
						}
#define CHAR_HANDSTEP_LOOKUPTABLE\
			class handstepSound_Char_LookupTable\
			{\
				CHAR_HANDSTEP_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_destroyed_ext, asphalt_destroyed_int
 * cp_broadleaf_dense1
 * forestConifer
 * grass_dry_ext
 * grassTall
 * ceramicTiles_ext, ceramicTiles_int
 * dirt_ext, dirt_int
 * gravelSmall_ext, gravelSmall_int
 * linoleum_ext, linoleum_int
 * metalThick_ext
 * metal_ext, metal_int
 * metalThin_ext, metalThin_int
 * metalThinMesh_ext, metalThinMesh_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * carpet_ext, carpet_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
 * water
*/

// create lookup tables from macros above
CHAR_HANDSTEP_LOOKUPTABLE

//  macros for generating sound lookup tables
#define CHAR_HANDSTEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class handstepSound_Hard_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								Handstep_Hard_##surfacesound##_Char_SoundSet\
							};\
						}
#define CHAR_HANDSTEP_LOOKUPTABLE\
			class handstepSound_Hard_Char_LookupTable\
			{\
				CHAR_HANDSTEP_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_destroyed_ext, asphalt_destroyed_int
 * cp_broadleaf_dense1
 * forestConifer
 * grass_dry_ext
 * grassTall
 * ceramicTiles_ext, ceramicTiles_int
 * dirt_ext, dirt_int
 * gravelSmall_ext, gravelSmall_int
 * linoleum_ext, linoleum_int
 * metalThick_ext
 * metal_ext, metal_int
 * metalThin_ext, metalThin_int
 * metalThinMesh_ext, metalThinMesh_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * carpet_ext, carpet_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
 * water
*/

// create lookup tables from macros above
CHAR_HANDSTEP_LOOKUPTABLE

//  macros for generating sound lookup tables
#define CHAR_HANDSTEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class handsstepSound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								Handsstep_##surfacesound##_Char_SoundSet\
							};\
						}
#define CHAR_HANDSTEP_LOOKUPTABLE\
			class handsstepSound_Char_LookupTable\
			{\
				CHAR_HANDSTEP_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_destroyed_ext, asphalt_destroyed_int
 * cp_broadleaf_dense1
 * forestConifer
 * grass_dry_ext
 * grassTall
 * ceramicTiles_ext, ceramicTiles_int
 * dirt_ext, dirt_int
 * gravelSmall_ext, gravelSmall_int
 * linoleum_ext, linoleum_int
 * metalThick_ext
 * metal_ext, metal_int
 * metalThin_ext, metalThin_int
 * metalThinMesh_ext, metalThinMesh_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * carpet_ext, carpet_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
 * water
*/

// create lookup tables from macros above
CHAR_HANDSTEP_LOOKUPTABLE

//  macros for generating sound lookup tables
#define CHAR_BODYFALL_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##shadername##Sound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								##shadername##_##surfacesound##_Char_SoundSet\
							};\
						}
#define CHAR_BODYFALL_LOOKUPTABLE(shadername)\
			class ##shadername##Sound_Char_LookupTable\
			{\
				CHAR_BODYFALL_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * forestBroadleaf
 * dirt_ext, dirt_int
 * grass
 * gravelSmall_ext, gravelSmall_int
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
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_roll)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_rollHard)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_slide)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_slide_light)
CHAR_BODYFALL_LOOKUPTABLE(bodyfall_hand_light)

//  macros for generating sound lookup tables
#define CHAR_HANDSTEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class handstepSound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								step_ladder_Char_Soundset\
							};\
						}
#define CHAR_HANDSTEP_LOOKUPTABLE\
			class step_ladder_Char_LookupTable\
			{\
				CHAR_HANDSTEP_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_destroyed_ext, asphalt_destroyed_int
 * cp_broadleaf_dense1
 * forestConifer
 * ceramicTiles_ext, ceramicTiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext
 * grassTall
 * gravelSmall_ext, gravelSmall_int
 * linoleum_ext, linoleum_int
 * metalThick_ext
 * metal_ext, metal_int
 * metalThin_ext, metalThin_int
 * metalThinMesh_ext, metalThinMesh_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * carpet_ext, carpet_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
 * water
*/

// create lookup tables from macros above
CHAR_HANDSTEP_LOOKUPTABLE

//  macros for generating sound lookup tables
#define CHAR_HANDSTEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class handstepSound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								step_ladder_run_Char_Soundset\
							};\
						}
#define CHAR_HANDSTEP_LOOKUPTABLE\
			class step_ladder_run_Char_LookupTable\
			{\
				CHAR_HANDSTEP_LOOUPTABLE_CLASS(utes_concrete,asphalt_ext)\
			};

/*
available surface types for macro above:
 * asphalt_ext, asphalt_int
 * asphalt_destroyed_ext, asphalt_destroyed_int
 * cp_broadleaf_dense1
 * forestConifer
 * ceramicTiles_ext, ceramicTiles_int
 * dirt_ext, dirt_int
 * grass_dry_ext
 * grassTall
 * gravelSmall_ext, gravelSmall_int
 * linoleum_ext, linoleum_int
 * metalThick_ext
 * metal_ext, metal_int
 * metalThin_ext, metalThin_int
 * metalThinMesh_ext, metalThinMesh_int
 * rubbleLarge_ext, rubbleLarge_int
 * sand_ext, sand_int
 * carpet_ext, carpet_int
 * woodParquet_ext, woodParquet_int
 * woodPlanks_ext, woodPlanks_int
 * water
*/

// create lookup tables from macros above
CHAR_HANDSTEP_LOOKUPTABLE