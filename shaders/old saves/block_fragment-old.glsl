#version 120

uniform sampler2D sampler;
uniform sampler2D sky_sampler;
uniform float timer;
uniform float daylight;
uniform int ortho;
uniform vec3 sky_tint;

varying vec2 fragment_uv;
varying float fragment_ao;
varying float fragment_light;
varying float fog_factor;
varying float fog_height;
varying float diffuse;

const float pi = 3.14159265;

void main() {
	//varying out vec4 gl_FragColor;
	vec4 color = texture2D(sampler, fragment_uv);
    //if (color == vec4(1.0)) {
	//	discard;
	//}
    //else {
        color.a = max(color.a, 0.4);
    //}
    gl_FragColor = color;
    
    
    
	/*
    vec4 color = vec4(texture2D(sampler, fragment_uv));
    
    bool cloud = color == vec4(1.0, 1.0, 1.0, 1.0);
    if (cloud && bool(ortho)) {
        discard;
    }
    bool water = color == vec4(0.2, 0.2, 1.0, 0.4);
    if (water && bool(ortho)) {
        discard;
        //out vec4 water;
        //water.a = 0.5;
    }
    float df = cloud ? 1.0 - diffuse * 0.3 : diffuse;
    float ao = cloud ? 1.0 - (1.0 - fragment_ao) * 0.2 : fragment_ao;
    ao = min(0.4, ao + fragment_light);
    df = min(0.4, df + fragment_light);
    float value = min(1.0, daylight + fragment_light);
    vec4 light_color = vec4(value * 0.3 + 0.2);
    vec4 ambient = vec4(value * 0.3 + 0.4);
    vec4 light = ambient + light_color * df;
    color = clamp(color * light * ao, vec4(0.0), vec4(0.5));
    vec4 sky_color = vec4(texture2D(sky_sampler, vec2(timer, fog_height)), 0.1) * sky_tint;
    color = mix(color, sky_color, fog_factor);
    gl_FragColor = vec4(color); //vec4(color, 0.5); 
    */
}
