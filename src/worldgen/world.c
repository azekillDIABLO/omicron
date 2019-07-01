#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../config.h"
#include "../item.h"
#include "noise.h"
#include "../util.h"
#include "world.h"
#include "base_terrain.h"
#include "biome_temperate.h"
#include "biome_desert.h"
#include "biome_rainforest.h"
#include "biome_taiga.h"
#include "biome_mesa.h"
#include "biome_swamp.h"

void create_world(int p, int q, world_func func, void *arg) {
    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int flag = 1;
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                flag = -1;
            }
            int x = p * CHUNK_SIZE + dx;
            int z = q * CHUNK_SIZE + dz;
            float f = simplex2(x * 0.01, z * 0.01, 4, 0.5, 2);
            float g = simplex2(-x * 0.01, -z * 0.01, 2, 0.9, 2);
            
            
			// mh
            int mh = g * simplex2(-x * 0.0005, -z * 0.0005, 2, 16.0, 2);

            mh += simplex2(-x * 0.0002, -z * 0.0002, 2, 16.0, 2) * simplex2(-x * 0.002, -z * 0.002, 2, 16.0, 2) * 100;
        
            mh += simplex2(-x * 0.02, -z * 0.02, 3, 8.0, 2);
            
            if (simplex2(-x * 0.0004, -z * 0.0004, 4, 4.0, 3)> 0.59) {
				mh += 8;
			}
            
            int h = f * mh;
            
            // Floating balls test
             
            /*for (int y = 0; y < 25; y++) {
                if (simplex3(
                    x * 0.001, (y+h) * 0.001, z * 0.001, 6, 1, 2) > 0.52)
                {
					if (y < 255) {
						func(x, (y+h), z, Item_COLOR_13 * flag, arg);
					}
                }
            }*/
			
			
            // Ocean system (generates water under y == 45)
            for (int y = 22; y < 45; y++) { 
				func(x, y, z, Item_WATER * flag, arg);
			}
            
            // ice on frigid biomes
			float biomen = simplex3(-x * 0.0005 * (1 / BIOME_SIZE), -z * 0.0005 * (1 / BIOME_SIZE), q * 0.001, 2, 16.0, 1);
			if(biomen > (1.0f/6.0f) && biomen < (2.0f/6.0f)) {
				// 2 ice layers on water
				if (simplex2(x * 0.0004, z * 0.0004, 8, 1.5, 2) > 0.59) {
					func(x, 43, z, Item_ICE * flag, arg);
					func(x, 44, z, Item_ICE * flag, arg);
				}
            }
            
            //2 other values are needed : a high one for 
            //mountain-like biomes and other for oceans.

            Biome biome = biome_at_pos(q, x, z);

            if (biome == Biome_TEMPERATE) {
                generateTemperate(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            } else if(biome == Biome_DESERT) {
                generateDesert(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            } else if(biome == Biome_RAINFOREST) {
                generateRainforest(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            } else if(biome == Biome_TAIGA) {
                generateTaiga(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            } else if(biome == Biome_MESA) {
                generateMesa(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            } else if(biome == Biome_SWAMP) {
                generateSwamp(dx, dz, x, z, 32, 32 + h, flag, func, arg);
            }
            
            generateBaseTerrain(dx, dz, x, z, 0, 32, flag, func, arg); //the good
            //generateBaseTerrain(dx, dz, x, z, 32, 32 + h, flag, func, arg); //the evil
			

            // clouds
            for (int y = 100; y < 180; y++) {
                if (simplex3(
                    x * 0.001, y * 0.004, z * 0.001, 6, 1, 2) > 0.7)
                {
                    func(x, y, z, 16 * flag, arg);
                }
            }
			
            // Unbreakable Core shell
            func(x, 0, z, Item_CORESHELL * flag, arg);
            if (simplex2(
					x * 0.4, z * 0.4, 7, 3, 5) > 0.52) {
				func(x, 1, z, Item_CORESHELL * flag, arg);
			}
			
			// Buildings
			
			// Brick Mess
			//for (int b = 50; b < 100; b++) {
			//	func(b, b, b, Item_BRICK * flag, arg);
            //}
        }
    }
}

Biome biome_at_pos(int q, int x, int z) {
    float biomen = simplex3(-x * 0.0005 * (1 / BIOME_SIZE), -z * 0.0005 * (1 / BIOME_SIZE), q * 0.001, 2, 16.0, 1);
    Biome biome = Biome_max;

    if(biomen > (1.0f/6.0f)) {
        biome = Biome_TAIGA;
    }
    if(biomen > (2.0f/6.0f)) {
        biome = Biome_SWAMP;
    }
    if(biomen > (3.0f/6.0f)) {
        biome = Biome_TEMPERATE;
    }
   
    if(biomen > (4.0f/6.0f)) {
        biome = Biome_RAINFOREST;
    }
	if(biome == (5.0/6.0)) {
        biome = Biome_DESERT;
    } 
    if(biome == (Biome_max)) {
        biome = Biome_MESA;
    } 
    return biome;
}
