#ifndef _rendering_h_
#define _rendering_h_

#include <GL/glew.h>
#include "attrib.h"
#include "chunk.h"
#include "player.h"

GLuint gen_plant_buffer(float x, float y, float z, float n, int w);
GLuint gen_player_buffer(float x, float y, float z, float rx, float ry);
GLuint gen_text_buffer(float x, float y, float n, char *text);
void draw_triangles_3d_ao(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_3d_text(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_3d(Attrib *attrib, GLuint buffer, int count);
void draw_triangles_2d(Attrib *attrib, GLuint buffer, int count);
void draw_lines(Attrib *attrib, GLuint buffer, int components, int count);
void draw_chunk(Attrib *attrib, Chunk *chunk);
void draw_item(Attrib *attrib, GLuint buffer, int count);
void draw_text(Attrib *attrib, GLuint buffer, int length);
void draw_signs(Attrib *attrib, Chunk *chunk);
void draw_sign(Attrib *attrib, GLuint buffer, int length);
void draw_cube(Attrib *attrib, GLuint buffer);
void draw_plant(Attrib *attrib, GLuint buffer);
void draw_player(Attrib *attrib, Player *player);
void render_text(Attrib *attrib, int justify, float x, float y, float n, char *text,
                 int win_width, int win_height);
void render_crosshairs(Attrib *attrib, int width, int height, int scale);

#endif
