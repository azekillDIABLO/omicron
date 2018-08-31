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
    vec4 color = vec4(texture2D(sampler, fragment_uv));
    
    if (color == vec4(1.0, 0.0, 1.0, 1.0)) {
        discard;
    }
    
    bool cloud = color == vec4(1.0, 1.0, 1.0, 1.0);
    if (cloud && bool(ortho)) {
        discard;
    }
   
    float df = cloud ? 1.0 - diffuse * 0.2 : diffuse;
    float ao = cloud ? 1.0 - (1.0 - fragment_ao) * 0.2 : fragment_ao;
    ao = min(1.0, ao + fragment_light);
    df = min(1.0, df + fragment_light);
 
    float value = max(0.3, daylight + fragment_light);
    value = (value*0.5+0.2) + (value*0.3+0.1) * df;
    value = (value*1.2) * (ao*0.7);
    vec4 light_color = vec4(value, value, value, 1.0);
    
    vec3 a = vec3(texture2D(sky_sampler, vec2(timer, fog_height))) * sky_tint;
    vec4 sky_color = vec4(a, 1.0);
    
    if (color.a == 1.0) {
        color.a = 0.0;
    }
	
    color = color * light_color;
    color = mix(color, sky_color, fog_factor);

    gl_FragColor = vec4(color);
}
