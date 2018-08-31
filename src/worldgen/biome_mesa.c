#include "biome_mesa.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateMesa(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for (int y = start_h; y < h - 1; y++) {
		
		if (simplex2(x * 0.00091, z * 0.00091, 6, 1, 2) < 0.5) {
		
			// filler to avoid renderer glitch
			//func(x, y, z, 0 * flag, arg);

			if (y < 66) {
				func(x, y+1, z, Item_DIRT * flag, arg);
			}
			if (y < 65) {
				func(x, y+1, z, 51 * flag, arg);
			}
			if (y < 60) {
				func(x, y+1, z, 52 * flag, arg);
			}
			if (y < 55) {
				func(x, y+1, z, 53 * flag, arg);
			}
			if (y < 50) {
				func(x, y+1, z, 54 * flag, arg);
			}
			if (y < 45) {
				func(x, y+1, z, Item_SAND * flag, arg);
				func(x, y, z, Item_SAND * flag, arg);
			}
			
			// I don't even know why it does this but it looks sick
			if (simplex2(x * 0.005, -z * 0.005, 4, 0.8, 2) > 0.7) {
				if (h = 67) {
					func(x, h, z, Item_DIRT * flag, arg);
				}
			}
		}
	}
}
