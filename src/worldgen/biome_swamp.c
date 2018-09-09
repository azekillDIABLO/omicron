#include "biome_swamp.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateSwamp(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for (int y = start_h; y < h - 1; y++) {
		func(x, y, z, Item_STONE * flag, arg);
	}
	for (int y = 0; y < 5; y++) {
		func(x, h-y-1, z, Item_DIRT * flag, arg);
	}
     
    if (h > 44) {
		for (int y = start_h; y < h - 1; y++) {	
			func(x, y, z, Item_DIRT * flag, arg);
		}
		func(x, h - 1, z, Item_SWAMP_GRASS * flag, arg); 

		// grass
		if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.5) {
			if (h > 38) {
				func(x, h, z, Item_SWAMP_TALL_GRASS * flag, arg);
			}
		}

		// cobble
		if (simplex2(-x * 0.02, z * 0.02, 1, 1, 1) * (simplex2(-x * 0.1, z * 0.1, 1, 0.8, 2)) > 0.64) {
			func(x, h-1, z, Item_COBBLE * flag, arg);
			func(x, h, z, Item_COBBLE * flag, arg);
		}

		// forests
		if (simplex2(-x * 0.01, z * 0.01, 6, 0.9, 2) > 0.59) {
			// mushrooms
			if (simplex2(-x * 0.08, z * 0.08, 6, 0.7, 2) > 0.69) {
				func(x, h, z, Item_MUSHROOMS * flag, arg);
			}
			if (simplex2(-x * 0.1, z * 0.1, 5, 0.8, 2) > 0.66) {
				func(x, h, z, Item_MUSHROOM * flag, arg);
			}
			// trees
			if (h > 38) {
				int ok = 1;
				if (dx - 4 < 0 || dz - 4 < 0 ||
					dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
				{
					ok = 0;
				}

				if (ok && simplex2(x, z, 6, 0.5, 2) > 0.71) {
					for (int y = h + 3; y < h + 8; y++) {
						for (int ox = -3; ox <= 3; ox++) {
							for (int oz = -3; oz <= 3; oz++) {
								int d = (ox * ox) + (oz * oz) +
									(y - (h + 4)) * (y - (h + 4));
								if (d < 11) {
									func(x + 2, y-3, z + 1, Item_VINE, arg);
									func(x - 2, y-3, z - 1, Item_VINE, arg);
									func(x + 1, y-3, z - 2, Item_VINE, arg);
									func(x + ox, y, z + oz, 15, arg);
								}
							}
						}
					}
					for (int y = h; y < h + 7; y++) {		
						func(x, y, z, 5, arg);
					}
				}
			}
		}
    }
}
