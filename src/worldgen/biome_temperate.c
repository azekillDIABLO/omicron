#include "biome_temperate.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateTemperate(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    
    for (int y = start_h; y < h - 1; y++) {	
		//for (int y = 30; y = 37; y++) {
			//func(x, 37, z, Item_WATER * flag, arg);
			//func(x, 36, z, Item_WATER * flag, arg);
		//}
        func(x, y, z, Item_DIRT * flag, arg);
    }
    func(x, h - 1, z, Item_GRASS * flag, arg); 

    // grass
    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.5) {
		if (h > 38) {
			func(x, h, z, 17 * flag, arg);
		}
    }
    
    // flowers
    if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
        int w = 18 + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 7;
        if (h > 38) {
			func(x, h, z, w * flag, arg);
		}
    }
    
    // rocks
    if (simplex2(-x * 0.01, z * 0.01, 1, 1, 1) * (simplex2(-x * 0.1, z * 0.1, 1, 0.8, 2)) > 0.64) {
        if (h > 72) {
			func(x, h-1, z, Item_STONE * flag, arg);
			func(x, h, z, Item_STONE * flag, arg);
		}
    }

    // trees
    if (h > 38) {
		int ok = 1;
		if (dx - 4 < 0 || dz - 4 < 0 ||
			dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
		{
			ok = 0;
		}

		if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
			for (int y = h + 3; y < h + 8; y++) {
				for (int ox = -3; ox <= 3; ox++) {
					for (int oz = -3; oz <= 3; oz++) {
						int d = (ox * ox) + (oz * oz) +
							(y - (h + 4)) * (y - (h + 4));
						if (d < 11) {
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
	
	// elder trees
    if (h > 38) {
		int ok = 1;
		if (dx - 4 < 0 || dz - 4 < 0 ||
			dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
		{
			ok = 0;
		}

		if (ok && simplex2(x, z, 7, 0.6, 2) > 0.85) {
			for (int y = h + 4; y < h + 18; y++) {
				for (int ox = -4; ox <= 4; ox++) {
					for (int oz = -4; oz <= 4; oz++) {
						int d = (ox * ox) + (oz * oz) +
							(y - (h + 6)) * (y - (h + 6));
						if (d < 18) {
							func(x + ox, y, z + oz, 15, arg);
						}
					}
				}
			}
			for (int y = h; y < h + 10; y++) {		
				func(x, y, z, 5, arg);
			}
		}
	}
	
	// some wip ugly river don't touch the water is lava
	/*
    if (simplex2(-x * 0.001, z * 0.001, 4, 0.8, 2) > 0.7) {
		//if (h < 38) {
			func(x, h, z, 42 * flag, arg);
		//}
    }
    */
    
}
