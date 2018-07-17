#include "biome_mesa.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateMesa(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for (int y = start_h; y < h - 1; y++) {
		//int watery;
		//for (int watery = 30; watery > 37; watery++) {
		//func(x, 37, z, Item_WATER * flag, arg);
		//func(x, 36, z, Item_WATER * flag, arg);
		//}
		if (y < 66) {
			func(x, y, z, Item_DIRT * flag, arg);
		}
		if (y < 65) {
			func(x, y, z, 51 * flag, arg);
		}
		if (y < 60) {
			func(x, y, z, 52 * flag, arg);
		}
		if (y < 55) {
			func(x, y, z, 53 * flag, arg);
		}
		if (y < 50) {
			func(x, y, z, 54 * flag, arg);
		}
		if (y < 45) {
			func(x, y, z, Item_SAND * flag, arg);
		}
		
		// I don't even know why it does this but it looks sick
		if (simplex2(x * 0.005, -z * 0.005, 4, 0.8, 2) > 0.7) {
			if (h = 67) {
				func(x, h-1, z, Item_DIRT * flag, arg);
			}
		}
    }
}
