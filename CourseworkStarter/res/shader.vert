#version 120

attribute vec3 position;
attribute vec2 textureCoord;
attribute vec3 normal;

varying vec2 textureCoord0;
varying vec3 normal0;

uniform mat4 trans;


void main()
{
	gl_Position = trans*vec4(position, 1.0);
	textureCoord0 = textureCoord;
	normal0 = (trans * vec4(normal, 0.0)).xyz;
	
}
