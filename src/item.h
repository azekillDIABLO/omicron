#ifndef _item_h_
#define _item_h_

typedef enum {
    Item_EMPTY,
    Item_GRASS,
    Item_SAND,
    Item_STONEBRICK,
    Item_BRICK,
    Item_WOOD,
    Item_STONE,
    Item_DIRT,
    Item_PLANK,
    Item_SNOW,
    Item_GLASS,
    Item_COBBLE,
    Item_LIGHT_STONE,
    Item_DARK_STONE,
    Item_CHEST,
    Item_LEAVES,
    Item_CLOUD,
    Item_TALL_GRASS,
    Item_YELLOW_FLOWER,
    Item_RED_FLOWER,
    Item_PURPLE_FLOWER,
    Item_SUN_FLOWER,
    Item_WHITE_FLOWER,
    Item_BLUE_FLOWER,
    Item_COLOR_00 = 32,
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
    Item_COLOR_31,
    Item_PLAYER,
    Item_CACTUS,
    Item_VINE,
    Item_CACTI,
    Item_SLAB_LOWER_STONEBRICK,
    Item_WATER,
    Item_CORESHELL,
    Item_COAL_ORE,
    Item_IRON_ORE,
    Item_GOLD_ORE,
    Item_RUBIS_ORE,
    Item_COAL_BLOCK,
	Item_IRON_BLOCK,
	Item_GOLD_BLOCK,
	Item_RUBIS_BLOCK,
	Item_ICE,
	Item_TNT,
	Item_SANDSTONE,
	Item_SANDSTONE_BRICKS,
	Item_STONE_BRICKS,
	Item_CLAY,
	Item_FERN,
	Item_MUSHROOM,
	Item_MUSHROOMS,
	Item_SWAMP_GRASS,
	Item_SWAMP_TALL_GRASS,
	Item_TORCH,
    Item_max
} Item;

typedef enum {
    NonCubeType_NOT_NONCUBE,
    NonCubeType_SLAB_LOWER
} NonCubeType;

extern const int items[];
extern const int item_count;
extern const int blocks[256][6];
extern const int plants[256];
extern const int obj[256];

int is_plant(int w);
int is_obstacle(int w);
int is_transparent(int w);
int is_invisible(int w);
int is_destructable(int w);
int boom_on_click(int w);
int is_climbable(int w);
int is_noncube(int w);
int is_liquid(int w);
int buildable_to(int w);
int is_placeable(int w);


NonCubeType noncube_type(int w);

typedef struct {
    #define ITEMSPEC_NAME_LEN 32
    #define ITEMSPEC_NAME_FORMAT "%32s"
    char name[32];
    int obstacle;
} ItemSpec;

#endif
