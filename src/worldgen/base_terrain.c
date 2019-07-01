#include <stdio.h>
#include <stdlib.h>
#include "base_terrain.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"
#include "../util.h"

void generateBaseTerrain(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for(int y = start_h; y < h; y++) {
		
		for (int y = 1; y < 34; y++) {
			func(x, y, z, Item_STONE, arg);
        }
        
        // Ores generation system 
        
        for (int y = 2; y < 30; y++) {
			if (simplex3(x * 0.12, y * 0.12, z * 0.12, 6, 0.5, 2) > 0.74) {
				int rand_num = (rand() % 100);
				
				if (y < 10 && rand_num < 15) {
					func(x, y-1, z, Item_RUBIS_ORE * flag, arg);
				} else if (y < 20 && rand_num < 30) {
					func(x, y, z, Item_GOLD_ORE * flag, arg); 
				} else if (y < 20 && rand_num < 65) {
					func(x, y, z, Item_IRON_ORE * flag, arg); 
				} else if (y < 30 && rand_num < 85) {
					func(x, y, z, Item_COAL_ORE * flag, arg);
				}
			}
		}
		
         		
		// Caves  
		for (int y = 1; y < 37; y++) {
			if (simplex3(
						x * 0.06, y * 0.08, z * 0.06, 8, 0.3, 2) > 0.64) { 
				func(x, y, z, 0 * flag, arg);
			}
		}  
		
		// Ravines
		for (int y = 3; y < 30; y++) {
			if (simplex2(x * 0.06, z * 0.006, 8, 0.3, 2) > 0.70 && simplex2(x * 0.006, z * 0.006, 3, 0.8, 2) > 0.70) { 
				func(x, y, z, 0 * flag, arg);
			}
		}
		 
    }
}
