#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;

uniform vec2 camLoc;

out vec2 uv;

void main() {
    vec4 edgePos = vec4((vertexPosition * 2 - vec3(1.0, 1.0, 0.0)) - vec3(camLoc * 0.01, 0.0), 1.0);
    gl_Position = edgePos;
    uv = vertexUV;
}