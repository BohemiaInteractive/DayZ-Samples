// animals.hpp
//  macros for generating sound lookup tables
#define ANIMAL_STEP_LOOUPTABLE_CLASS(roadwayname,surfacesound)\
						class ##animaltype####movementtype##stepSound_##roadwayname##\
						{\
							surface = ##roadwayname##;\
					        soundSets[] =\
							{\
								 ##animaltype####movementtype##_##surfacesound##_SoundSet\
							};\
						}
#define ANIMAL_STEP_SOUNDTABLE(animaltype,movementtype)\
			class ##animaltype####movementtype##_LookupTable\
			{\
				ANIMAL_STEP_LOOUPTABLE_CLASS(utes_concrete,Concrete)\
			};

/*
available surface types for macro above:
 Road, Forest, Concrete, Dirt, Grass, Grass_dry, Sand, Gravel, Metal, Wood, Water
*/

// create lookup tables from macros above
ANIMAL_STEP_SOUNDTABLE(Bird,Walk)
ANIMAL_STEP_SOUNDTABLE(Bird,Grazing)
ANIMAL_STEP_SOUNDTABLE(Bird,Bodyfall)

ANIMAL_STEP_SOUNDTABLE(HoofMedium,Walk)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Run)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Grazing)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Bodyfall)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Settle)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Rest2standA)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Rest2standB)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Stand2restA)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Stand2restB)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Stand2restC)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Rub1)
ANIMAL_STEP_SOUNDTABLE(HoofMedium,Rub2)

ANIMAL_STEP_SOUNDTABLE(HoofSmall,Walk)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Run)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Grazing)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,GrazingHard)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,GrazingLeave)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Bodyfall)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Settle)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Rest2standA)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Rest2standB)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Stand2restA)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Stand2restB)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Stand2restC)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Rub1)
ANIMAL_STEP_SOUNDTABLE(HoofSmall,Rub2)

ANIMAL_STEP_SOUNDTABLE(PawBig,Walk)
ANIMAL_STEP_SOUNDTABLE(PawBig,Run)
ANIMAL_STEP_SOUNDTABLE(PawBig,Grazing)
ANIMAL_STEP_SOUNDTABLE(PawBig,Bodyfall)
ANIMAL_STEP_SOUNDTABLE(PawBig,Settle)
ANIMAL_STEP_SOUNDTABLE(PawBig,Rest2standA)
ANIMAL_STEP_SOUNDTABLE(PawBig,Rest2standB)
ANIMAL_STEP_SOUNDTABLE(PawBig,Stand2restA)
ANIMAL_STEP_SOUNDTABLE(PawBig,Stand2restB)
ANIMAL_STEP_SOUNDTABLE(PawBig,Stand2restC)
ANIMAL_STEP_SOUNDTABLE(PawBig,Jump)
ANIMAL_STEP_SOUNDTABLE(PawBig,Impact)

ANIMAL_STEP_SOUNDTABLE(PawMedium,Walk)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Run)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Grazing)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Bodyfall)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Settle)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Rest2standA)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Rest2standB)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Stand2restA)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Stand2restB)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Stand2restC)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Jump)
ANIMAL_STEP_SOUNDTABLE(PawMedium,Impact)

ANIMAL_STEP_SOUNDTABLE(PawSmall,Walk)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Run)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Grazing)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Bodyfall)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Settle)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Rest2standA)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Rest2standB)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Stand2restA)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Stand2restB)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Stand2restC)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Jump)
ANIMAL_STEP_SOUNDTABLE(PawSmall,Impact)