#include "base_terrain.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"
#include "../util.h"


const int caveitems[] = {
    // items that caves can "dig" trough (Unused)
    Item_GRASS,
    Item_SAND,
    Item_WOOD,
    Item_STONE,
    Item_DIRT,
    Item_SNOW,
    Item_LEAVES,
    Item_CACTUS,
    Item_TALL_GRASS,
    Item_YELLOW_FLOWER,
    Item_RED_FLOWER,
    Item_PURPLE_FLOWER,
    Item_SUN_FLOWER,
    Item_WHITE_FLOWER,
    Item_BLUE_FLOWER,
    Item_VINE,
    Item_CACTI
};


void generateBaseTerrain(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for(int y = start_h; y < h; y++) {
		
        //-- ugly caves
        
        //float cave1 = simplex3(x, y, z, 8, 1.8, 1.5);
        //float cave2 = simplex3(x, y, z, 12, 2.8, 0.5);
        //float cave1 = simplex2(x, y + 1, 3, 0.8, 0.5);
        //float cave2 = simplex2(x + 1, y, 3, 0.8, 0.5);

        //if(ABS(cave1 - cave2) < 0.1) {
        //    func(x, y, z, Item_STONE, arg);
        //}
        
        //-- ugly caves


		// small caves
        if ((y < 2 || y > 36) || (simplex3(x * 0.05, y * 0.05, z * 0.05, 16, 0.05, 5)
            + simplex3(x * 0.05, y * 0.05, z * 0.05, 16, 0.05, 5) < 1.25)) {
            func(x, y, z, Item_STONE, arg);
        }
        
        // big caves
      //   if ((y < 2 || y > h - 5) || (simplex3(x * 0.005, y * 0.05, z * 0.005, 15, 0.1, 5)
      //      + simplex3(x * 0.005, y * 0.05, z * 0.005, 20, 0.05, 1) < 1.25)) {
      //      func(x, y, z, Item_STONE, arg);
      //}
        
        
    }
}
