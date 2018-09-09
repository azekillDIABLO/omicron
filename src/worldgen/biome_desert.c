#include "biome_desert.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateDesert(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {  
	for (int y = start_h; y < h - 1; y++) {
		func(x, y, z, Item_SANDSTONE * flag, arg);
	}
	for (int y = 0; y < 5; y++) {
		func(x, h-y-1, z, Item_SAND * flag, arg);
	}
     
    if (h > 45) {

		// flower
		if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.8) {
			func(x, h, z, 18 * flag, arg);
		}

		// cacti
		if (simplex2(-x * 0.1, z * 0.1, 3, 0.9, 2) > 0.8) {
			func(x, h, z, 67 * flag, arg); 
		}

		// cactus
		int ok = 1;
		if (dx - 4 < 0 || dz - 4 < 0 ||
			dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
		{
			ok = 0;
		}
		if (ok && simplex2(x * 4, z * 4, 6, 0.45, 2) > 0.88) {
			int height = simplex2(x, z, 6, 0.5, 2) * 16;
			for (int y = h; y < h + height; y++) {
				func(x, y, z, Item_CACTUS, arg);
			}

			int oz = z % 3;

			if(x % 2) {
				func(x + 1, h + height - 4 - oz, z, Item_CACTUS, arg);
				func(x - 1, h + height - 4 + oz, z, Item_CACTUS, arg);

				func(x + 2, h + height - 4 - oz, z, Item_CACTUS, arg);
				func(x - 2, h + height - 4 + oz, z, Item_CACTUS, arg);

				func(x + 2, h + height - 3 - oz, z, Item_CACTUS, arg);
				func(x - 2, h + height - 3 + oz, z, Item_CACTUS, arg);
			} else {
				func(x, h + height - 4 - oz, z + 1, Item_CACTUS, arg);
				func(x, h + height - 4 + oz, z - 1, Item_CACTUS, arg);

				func(x, h + height - 4 - oz, z + 2, Item_CACTUS, arg);
				func(x, h + height - 4 + oz, z - 2, Item_CACTUS, arg);

				func(x, h + height - 3 - oz, z + 2, Item_CACTUS, arg);
				func(x, h + height - 3 + oz, z - 2, Item_CACTUS, arg);
			}
		}
		int px = 42;
		int pz = 42;
		/*Pyramid prototype
		for (int p = 50; p = 0; p--) {
			for (int p2 = 50; p2 = 0; p2--) {
				func(dx + p + p2, 82, dz + p2, Item_SANDSTONE_BRICKS * flag, arg);
			}
		}*/
		//func(dx + p + p2, 82, dz + p2, Item_SANDSTONE_BRICKS * flag, arg);
	}
}
