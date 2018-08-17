#include "biome_ocean.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateOcean(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {  
	
	for (int y = start_h; y < h; y++) {	
		func(x, y, z, 2 * flag, arg);
	}
	
	for (int yw = 32; yw < 37; yw++) {	
		func(x, yw, z, Item_WATER * flag, arg);
		
		if (simplex3(
			x * 0.001, yw * 0.003, z * 0.001, 6, 1, 1) > 0.7)
		{
			func(x, yw, z, Item_WATER * flag, arg);
		}
	}
	
	
}
