#version 120

attribute vec3 position;
out vec3 texCoords

uniform mat4 view;
uniform mat4 proj;

void main()
{
	vec4 pos = proj * view * vec4(position,1.0f);
	gl_Position = pos.xyww;
	texCoords = position;
	
}
