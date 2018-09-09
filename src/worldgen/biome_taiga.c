#include "biome_taiga.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateTaiga(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {  
    for (int y = start_h; y < h - 1; y++) {
		func(x, y, z, Item_STONE * flag, arg);
	}
	for (int y = 0; y < 5; y++) {
		func(x, h-y-1, z, Item_SAND * flag, arg);
	}
     
    if (h > 46) {

		for (int y = start_h; y < h - 1; y++) {
			func(x, y, z, Item_DIRT * flag, arg);
		}
		func(x, h - 1, z, Item_SNOW * flag, arg);
    
		// grass
		if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.71) {
			func(x, h, z, 17 * flag, arg);
		}
		
		// ferns
		if (simplex2(-x * 0.1, z * 0.1, 5, 0.5, 2) > 0.715) {
			func(x, h, z, Item_FERN * flag, arg);
		}
		
		
		// trees
		/** TODO **/
		// Is removing this ok?
		int ok = 1;
		if (dx - 4 < 0 || dz - 4 < 0 ||
			dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
		{
			ok = 0;
		}
			//Leaves
			if (ok && simplex2(x, z, 3, 0.5, 2) > 0.84) {
			for (int y = h + 3; y < h + 22; y++) {
				for (int ox = -12; ox <= 12; ox++) {
					for (int oz = -12; oz <= 12; oz++) {
						int d = (ox * ox) + (oz * oz) +
							(y - (h + 4)) * (y - (h + 4));
						if (d < 20) {
							//func(x + ox/2, y, z + oz/2, 15, arg); // Snow on top (will be added later on)
							
							func(x + ox/2, y, z + oz/2, 15, arg);
					  
							func(x + ox/3, y+6, z + oz/3, 15, arg);
					   
							func(x + ox/4, y+12, z + oz/4, 15, arg);
						}
					}
				}
			}
			
			//Trunk
		   for (int y = h; y < h + 18; y++) {
				func(x, y, z, 5, arg);
		   }
		}
	}
}

