#include "biome_taiga.h"
#include "noise.h"
#include "../config.h"
#include "../item.h"

void generateTaiga(int dx, int dz, int x, int z, int start_h, int h, int flag, world_func func, void *arg) {
    for (int y = start_h; y < h - 1; y++) {
        func(x, y, z, Item_DIRT * flag, arg);
    }
    func(x, h - 1, z, Item_SNOW * flag, arg);

    // grass
    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.7) {
        func(x, h, z, 17 * flag, arg);
    }

    /*  old trees (modified but still too unatural)
    int ok = 1;
    if (dx - 4 < 0 || dz - 4 < 0 ||
        dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
    {
        ok = 0;
    }
    if (ok && simplex2(x, z, 2, 0.5, 2) > 0.8) {
        for (int y = h + 1; y < h + 20; y += 2) {
            for (int ox = -3; ox <= 3; ox++) {
                for (int oz = -3; oz <= 3; oz++) {
                    int d = (ox * ox) + (oz * oz) +
                        (y - 20 - (h + 2)) * (y - 20 - (h + 2));
                    if (d < 400) {
                        func(x + ox, y, z + oz, 15, arg);
                    }
                }
            }
        }
        for (int y = h; y < h + 18; y++) {
            for (int ox = -1; ox < 1; ox++) {
                for (int oz = 0; oz < 1; oz++) {
                    func(x + ox, y, z + oz, 5, arg);
                }
            }
        }
    }
    */
    
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

