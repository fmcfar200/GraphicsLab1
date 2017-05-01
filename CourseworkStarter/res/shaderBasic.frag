#version 120

varying vec2 textureCoord0; //varying texture coordinate 

uniform sampler2D diff;	//sampler of diffuse collour


void main()
{
	gl_FragColor = texture2D(diff,textureCoord0);	//fragment colour is calculated
}


