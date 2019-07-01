#ifndef _config_h_
#define _config_h_


// TODO: Transfer the maximum of stuff to ingame tweakable config (main.c)


//game
#define FLY_SPEED 70
#define WALK_SPEED 6
#define CLIMB_SPEED 4
#define BUILD_HEIGHT_LIMIT 255
#define NUM_INVENTORY_VISIBLE 7
#define INFINITE_STUFF 1

//mapgen
#define BIOME_SIZE 1.0 //should be small, or you won't see any variety!
//#define ALTITUDE_Y_INT 256

// app parameters
#define DEBUG 1
#define FULLSCREEN 0 //put to zero, fullscreen bugs
#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768
#define VSYNC 0
#define SCROLL_THRESHOLD 0.1
#define MAX_MESSAGES 10
#define DB_PATH "world/omicron-world.db"
#define USE_CACHE 1
#define DAY_LENGTH 500
#define INVERT_MOUSE 0

// rendering options 
// were transfered to
// options in main.c

// key bindings
#define CRAFT_KEY_FORWARD 'W'
#define CRAFT_KEY_BACKWARD 'S'
#define CRAFT_KEY_LEFT 'A'
#define CRAFT_KEY_RIGHT 'D'
#define CRAFT_KEY_JUMP GLFW_KEY_SPACE
#define CRAFT_KEY_DECSEND GLFW_KEY_LEFT_SHIFT
#define CRAFT_KEY_FLY GLFW_KEY_TAB
#define CRAFT_KEY_OBSERVE 'O'
#define CRAFT_KEY_OBSERVE_INSET 'P'
#define CRAFT_KEY_ITEM_NEXT 'E'
#define CRAFT_KEY_ITEM_PREV 'R'
#define CRAFT_KEY_ZOOM 'Z'
#define CRAFT_KEY_ORTHO 'F'
#define CRAFT_KEY_CHAT 't'
#define CRAFT_KEY_COMMAND '/'
#define CRAFT_KEY_SIGN '-'

// advanced parameters
#define CREATE_CHUNK_RADIUS 5
#define RENDER_CHUNK_RADIUS 4
#define RENDER_SIGN_RADIUS 1.5
#define DELETE_CHUNK_RADIUS 6
#define CHUNK_SIZE 32
#define COMMIT_INTERVAL 5

#endif
