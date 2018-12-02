#version 330 core

in vec2 UV;

out vec3 color;

uniform sampler2D logo_tex;
uniform float time;

void main(){
    color = texture(logo_tex, UV, 16).xyz;
}
