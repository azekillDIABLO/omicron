#version 120

uniform sampler2D sampler;
uniform float timer;
uniform vec3 sky_tint;

varying vec2 fragment_uv;

void main(void)
{
   gl_FragColor = gl_Color;
}
