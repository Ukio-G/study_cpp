#version 330 core

in vec3 vColor;
in vec2 TexCoord;

out vec4 FragColor;
uniform vec4 color_u;


uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
   FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5) + vec4(vColor, 1.0);
}
