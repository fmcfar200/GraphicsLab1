#version 120

//attributes

attribute vec3 position;
attribute vec2 textureCoord;
attribute vec3 normal;

//varying
varying vec2 textureCoord0;
varying vec3 normal0;

//uniforms
uniform mat4 trans;


void main()
{
	gl_Position = trans*vec4(position, 1.0); //vertex position is calculated
	textureCoord0 = textureCoord; //varying value is set as textture coordinate attrivute value
	normal0 = (trans * vec4(normal, 0.0)).xyz; // normal varying is calculated
	
}
