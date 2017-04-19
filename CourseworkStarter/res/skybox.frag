#version 120

in vec2 texCoords;
out vec4 color;

uniform samplerCube skybox;


void main()
{
	color = texture(skybox,texCoords);
}


