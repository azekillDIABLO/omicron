#version 120

uniform mat4 matrix;

attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

varying vec2 fragment_uv;

uniform vec4  lightPositionOC;   // in object coordinates
uniform vec3  spotDirectionOC;   // in object coordinates
uniform float spotCutoff;        // in degrees

void main(void) {
   vec3 lightPosition;
   vec3 spotDirection;
   vec3 lightDirection;
   float angle;

    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    // Transforms light position and direction into eye coordinates
    lightPosition  = (lightPositionOC * gl_ModelViewMatrix).xyz;
    spotDirection  = normalize(spotDirectionOC * gl_NormalMatrix);

    // Calculates the light vector (vector from light position to vertex)
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;
    lightDirection = normalize(vertex.xyz - lightPosition.xyz);

    // Calculates the angle between the spot light direction vector and the light vector
    angle = dot( normalize(spotDirection),
                -normalize(lightDirection));
    angle = max(angle,0);   

   // Test whether vertex is located in the cone
   if(acos(angle) < radians(spotCutoff))
       gl_FrontColor = vec4(1,1,0,1); // lit (yellow)
   else
       gl_FrontColor = vec4(0,0,0,1); // unlit(black)   
}
