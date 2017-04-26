#version 120

//attributes
attribute vec3 position;
attribute vec2 textureCoord;
 
varying vec2 textureCoord0; //varying texture coordinate 


uniform mat4 trans; //unform for transform


void main()
{
	gl_Position = trans*vec4(position, 1.0); //vertex position is calculated
	textureCoord0 = textureCoord;	//varying value is set as textture coordinate attrivute value
	
}
