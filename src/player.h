#ifndef _player_h_
#define _player_h_

#include "state.h"

#define MAX_NAME_LENGTH 32

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    State state;
    State state1;
    State state2;
    GLuint buffer;
} Player;

#endif
