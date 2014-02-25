#ifndef DATA_GRID_H
#define DATA_GRID_H
#include "Data.h"

#define Int16_Grid(x) short x[GRID_SIZE * GRID_SIZE]
#define Int8_Grid(x) char x[GRID_SIZE * GRID_SIZE]
#define UInt16_Grid(x) unsigned short x[GRID_SIZE * GRID_SIZE]
#define UInt8_Grid(x) unsigned char x[GRID_SIZE * GRID_SIZE]

enum {
	GRID_SIZE = 162,
};

enum {
	Terrain_Tree = 1,
	Terrain_Rock = 2,
	Terrain_Water = 4,
	Terrain_Building = 8,
	Terrain_Scrub = 0x10,
	Terrain_Garden = 0x20,
	Terrain_Road = 0x40,
	Terrain_ReservoirRange = 0x80,
	Terrain_Aqueduct = 0x100,
	Terrain_Elevation = 0x200,
	Terrain_AccessRamp = 0x400,
	Terrain_Meadow = 0x800,
	Terrain_Rubble = 0x1000,
	Terrain_FountainRange = 0x2000,
	Terrain_Wall = 0x4000,
	Terrain_Gatehouse = 0x8000,
	// flagged items
	Terrain_NotClear = 0xd77f,
	Terrain_NaturalElements = 0x1677
};

EXTERN UInt16_Grid(Data_Grid_graphicIds);
EXTERN UInt16_Grid(Data_Grid_buildingIds);
EXTERN UInt16_Grid(Data_Grid_walkerIds);
EXTERN UInt16_Grid(Data_Grid_terrain);

EXTERN UInt8_Grid(Data_Grid_edge);
EXTERN UInt8_Grid(Data_Grid_bitfields);
EXTERN UInt8_Grid(Data_Grid_random);
EXTERN UInt8_Grid(Data_Grid_elevation);
EXTERN UInt8_Grid(Data_Grid_aqueducts);
EXTERN UInt8_Grid(Data_Grid_animation);
EXTERN Int8_Grid(Data_Grid_desirability);
EXTERN UInt8_Grid(Data_Grid_buildingDamage);

enum {
	Bitfield_Size1 = 0x00,
	Bitfield_Size2 = 0x01,
	Bitfield_Size3 = 0x02,
	Bitfield_Size4 = 0x04,
	Bitfield_Size5 = 0x08,
	Bitfield_Sizes = 0x0f,
	Bitfield_Overlay = 0x10,
	Bitfield_Plaza = 0x80,
	Edge_LeftmostTile = 0x40,
	Edge_NativeLand = 0x80,
};

#endif