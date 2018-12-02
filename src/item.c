#include "item.h"
#include "util.h"

const int items[] = {
    // items the user can build
    Item_GRASS,
    Item_SWAMP_GRASS,
    Item_SAND,
    Item_SANDSTONE,
    Item_SANDSTONE_BRICKS,
    Item_STONEBRICK,
    Item_SLAB_LOWER_STONEBRICK,
    Item_BRICK,
    Item_WOOD,
    Item_STONE,
    Item_STONE_BRICKS,
    Item_DIRT,
    Item_PLANK,
    Item_SNOW,
    Item_GLASS,
    Item_COBBLE,
    Item_LIGHT_STONE,
    Item_DARK_STONE,
    Item_CHEST,
    Item_TNT,
    Item_LEAVES,
    Item_CLAY,
    //Item_CLOUD,
    //Item_CORESHELL,
    Item_WATER,
    Item_ICE,
    Item_CACTUS,
    Item_PLAYER,
    Item_COAL_ORE,
	Item_IRON_ORE,
	Item_GOLD_ORE,
	Item_RUBIS_ORE,
    Item_COAL_BLOCK,
	Item_IRON_BLOCK,
	Item_GOLD_BLOCK,
	Item_RUBIS_BLOCK,
    
    //Flowers
    Item_TALL_GRASS,
    Item_SWAMP_TALL_GRASS,
    Item_YELLOW_FLOWER,
    Item_RED_FLOWER,
    Item_PURPLE_FLOWER,
    Item_SUN_FLOWER,
    Item_WHITE_FLOWER,
    Item_BLUE_FLOWER,
    Item_VINE,
    Item_CACTI,
    Item_FERN,
    Item_MUSHROOM,
    Item_MUSHROOMS,
    
    //Colors
    Item_COLOR_00,
    Item_COLOR_01,
    Item_COLOR_02,
    Item_COLOR_03,
    Item_COLOR_04,
    Item_COLOR_05,
    Item_COLOR_06,
    Item_COLOR_07,
    Item_COLOR_08,
    Item_COLOR_09,
    Item_COLOR_10,
    Item_COLOR_11,
    Item_COLOR_12,
    Item_COLOR_13,
    Item_COLOR_14,
    Item_COLOR_15,
    Item_COLOR_16,
    Item_COLOR_17,
    Item_COLOR_18,
    Item_COLOR_19,
    Item_COLOR_20,
    Item_COLOR_21,
    Item_COLOR_22,
    Item_COLOR_23,
    Item_COLOR_24,
    Item_COLOR_25,
    Item_COLOR_26,
    Item_COLOR_27,
    Item_COLOR_28,
    Item_COLOR_29,
    Item_COLOR_30,
    Item_COLOR_31
};

const int item_count = sizeof(items) / sizeof(int);

const int blocks[256][6] = {
    // w => (left, right, top, bottom, front, back) tiles
    {0, 0, 0, 0, 0, 0}, // 0 - empty
    {16, 16, 32, 0, 16, 16}, // 1 - grass
    {1, 1, 1, 1, 1, 1}, // 2 - sand
    {2, 2, 2, 2, 2, 2}, // 3 - stonebrick
    {3, 3, 3, 3, 3, 3}, // 4 - brick
    {20, 20, 36, 4, 20, 20}, // 5 - wood
    {5, 5, 5, 5, 5, 5}, // 6 - stone
    {6, 6, 6, 6, 6, 6}, // 7 - dirt
    {7, 7, 7, 7, 7, 7}, // 8 - plank
    {24, 24, 40, 8, 24, 24}, // 9 - snow
    {9, 9, 9, 9, 9, 9}, // 10 - glass
    {21, 21, 21, 21, 21, 21}, // 11 - cobble
    {11, 11, 11, 11, 11, 11}, // 12 - light stone
    {12, 12, 12, 12, 12, 12}, // 13 - dark stone
    {13, 13, 13, 13, 13, 13}, // 14 - chest
    {14, 14, 14, 14, 14, 14}, // 15 - leaves
    {15, 15, 15, 15, 15, 15}, // 16 - cloud
   

    {0, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 0}, // 18
    {0, 0, 0, 0, 0, 0}, // 19
    {0, 0, 0, 0, 0, 0}, // 20
    {0, 0, 0, 0, 0, 0}, // 21
    {0, 0, 0, 0, 0, 0}, // 22
    {0, 0, 0, 0, 0, 0}, // 23
    {0, 0, 0, 0, 0, 0}, // 24
    {0, 0, 0, 0, 0, 0}, // 25
    {0, 0, 0, 0, 0, 0}, // 26
    {0, 0, 0, 0, 0, 0}, // 27
    {0, 0, 0, 0, 0, 0}, // 28
    {0, 0, 0, 0, 0, 0}, // 29
    {0, 0, 0, 0, 0, 0}, // 30
    {0, 0, 0, 0, 0, 0}, // 31

    
    // Color Blocks ----------------// --
    {176, 176, 176, 176, 176, 176}, // 32
    {177, 177, 177, 177, 177, 177}, // 33
    {178, 178, 178, 178, 178, 178}, // 34
    {179, 179, 179, 179, 179, 179}, // 35
    {180, 180, 180, 180, 180, 180}, // 36
    {181, 181, 181, 181, 181, 181}, // 37
    {182, 182, 182, 182, 182, 182}, // 38
    {183, 183, 183, 183, 183, 183}, // 39
    {184, 184, 184, 184, 184, 184}, // 40
    {185, 185, 185, 185, 185, 185}, // 41
    {186, 186, 186, 186, 186, 186}, // 42
    {187, 187, 187, 187, 187, 187}, // 43
    {188, 188, 188, 188, 188, 188}, // 44
    {189, 189, 189, 189, 189, 189}, // 45
    {190, 190, 190, 190, 190, 190}, // 46
    {191, 191, 191, 191, 191, 191}, // 47
    {192, 192, 192, 192, 192, 192}, // 48
    {193, 193, 193, 193, 193, 193}, // 49
    {194, 194, 194, 194, 194, 194}, // 50
    {195, 195, 195, 195, 195, 195}, // 51
    {196, 196, 196, 196, 196, 196}, // 52
    {197, 197, 197, 197, 197, 197}, // 53
    {198, 198, 198, 198, 198, 198}, // 54
    {199, 199, 199, 199, 199, 199}, // 55
    {200, 200, 200, 200, 200, 200}, // 56
    {201, 201, 201, 201, 201, 201}, // 57
    {202, 202, 202, 202, 202, 202}, // 58
    {203, 203, 203, 203, 203, 203}, // 59
    {204, 204, 204, 204, 204, 204}, // 60
    {205, 205, 205, 205, 205, 205}, // 61
    {206, 206, 206, 206, 206, 206}, // 62
    {207, 207, 207, 207, 207, 207}, // 63
    // End of Color Blocks----------// --
    
    {226, 224, 241, 209, 225, 227}, // 64 - player block (Facedir?)
    {210, 210, 210, 210, 210, 210}, // 65 - cactus
    {0, 0, 0, 0, 0, 0}, // 66
    {0, 0, 0, 0, 0, 0}, // 67
    {2, 2, 2, 2, 2, 2}, // 68 - stonebrick slab
    {211, 211, 211, 211, 211, 211}, // 69 - water
    {212, 212, 212, 212, 212, 212}, // 70 - core shell
    {64, 64, 64, 64, 64, 64}, // 71 - coal ore
    {65, 65, 65, 65, 65, 65}, // 72 - iron ore
    {66, 66, 66, 66, 66, 66}, // 73 - gold ore
    {67, 67, 67, 67, 67, 67}, // 74 - rubis ore
    {80, 80, 80, 80, 80, 80}, // 75 - coal block
    {81, 81, 81, 81, 81, 81}, // 76 - iron block
    {82, 82, 82, 82, 82, 82}, // 77 - gold block
    {83, 83, 83, 83, 83, 83}, // 78 - rubis block 
    {213, 213, 213, 213, 213, 213}, // 79 - ice 
    {214, 214, 215, 216, 214, 214}, // 80 - TNT 
    {17, 17, 17, 17, 17, 17}, // 81 - sandstone 
    {33, 33, 33, 33, 33, 33}, // 82 - sandstone bricks
    {10, 10, 10, 10, 10, 10}, // 83 - stone bricks
    {34, 34, 34, 34, 34, 34}, // 85 - clay
    {0, 0, 0, 0, 0, 0}, // 86
    {0, 0, 0, 0, 0, 0}, // 87
    {0, 0, 0, 0, 0, 0}, // 88
    {19, 19, 35, 0, 19, 19}, // 89 - swamp dirt
    {0, 0, 0, 0, 0, 0}, // 90
    {0, 0, 0, 0, 0, 0} // - empty
};

const int plants[256] = {
    // w => tile
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0 - 16
    48, // 17 - tall grass
    49, // 18 - yellow flower
    50, // 19 - red flower
    51, // 20 - purple flower
    52, // 21 - sun flower
    53, // 22 - white flower
    54, // 23 - blue flower
    
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, // 24 - 65
    
    55, // 66 - vine
    56, // 67 - cacti
    
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, // 68 - 85
    
    57, // 86 - fern
    58, // 87 - mushroom
    59, // 88 - mushroom patch
    0,
	60 // 90 - swamp tall grass
    
};

const int obj[256] = {
	60 // 90 - swamp tall grass 
};

int is_plant(int w) {
    switch (w) {
        case Item_TALL_GRASS:
        case Item_YELLOW_FLOWER:
        case Item_RED_FLOWER:
        case Item_PURPLE_FLOWER:
        case Item_SUN_FLOWER:
        case Item_WHITE_FLOWER:
        case Item_BLUE_FLOWER:
        case Item_VINE:
        case Item_CACTI:
        case Item_FERN:
        case Item_MUSHROOM:
        case Item_MUSHROOMS:
        case Item_SWAMP_TALL_GRASS:
            return 1;
        default:
            return 0;
    }
}

int is_obstacle(int w) {
    w = ABS(w);
    if (is_plant(w)) {
        switch(w) {
            default:
                return 0;
        }
    }
    switch (w) {
        case Item_EMPTY:
        case Item_CLOUD:
        case Item_WATER:
            return 0;
        default:
            return 1;
    }
}

int is_transparent(int w) {
    if (w == Item_EMPTY) {
        return 1;
    }
    w = ABS(w);
    if (is_plant(w)) {
        return 1;
    }
    if(is_noncube(w)) {
        return 1;
    }
    switch (w) {
        case Item_EMPTY:
        case Item_GLASS:
        //case Item_LEAVES: //for better performance (8 fps -> 60fps OPTIMIZATION NEEDED!) 
        case Item_WATER: //Just to stop Xray-ing
            return 1;
        default:
            return 0;
    }
}

int is_invisible(int w) {
    if (w == Item_EMPTY) {
        return 1;
    }
    w = ABS(w);
    switch (w) {
		default:
            return 0;
    }
}

int is_destructable(int w) {
    switch (w) {
        case Item_EMPTY:
        case Item_CLOUD:
        case Item_CORESHELL:
        case Item_WATER:
            return 0;
        default:
            return 1;
    }
}

int buildable_to(int w) {
	w = ABS(w);
    if (is_plant(w)) {
        return 0;
    }
	
    switch (w) {
        case Item_WATER:
        case Item_CLOUD:
            return 0;
        default:
            return 1;
    }
}

int boom_on_click(int w) {
    switch (w) {
        case Item_TNT:
            return 0;
        default:
            return 1;
    }
}

int is_climbable(int w) {
    switch(w) {
        case Item_VINE:
            return 1;
        default:
            return 0;
    }
}

int is_liquid(int w) {
    switch(w) {
        case Item_WATER:
            return 1;
        default:
            return 0;
    }
}

int is_noncube(int w) {
    return noncube_type(w) != NonCubeType_NOT_NONCUBE;
}

int is_placeable(int w) {
    w = ABS(w);
    switch (w) {
       //case something
            return 0;
        default:
            return 1;
    }
}

NonCubeType noncube_type(int w) {
    switch(w) {
        case Item_SLAB_LOWER_STONEBRICK:
            return NonCubeType_SLAB_LOWER;
        default:
            return NonCubeType_NOT_NONCUBE;
    }
}
