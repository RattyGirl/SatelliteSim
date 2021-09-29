#version 330 core
in vec2 uv;

uniform sampler2D myTextureSampler;

out vec3 color;

void main(){
    vec3 textureColor = texture( myTextureSampler, uv ).rgb;
    if (textureColor.rgb == vec3(1.0, 0.0, 0.99607843))
    discard;
    color = textureColor;
}