#version 120

//varyings
varying vec2 textureCoord0;
varying vec3 normal0;

//uniforms
uniform sampler2D diff;
uniform vec3 camDirection = vec3(0,0,1);

void main()
{
	//fragment colour is calculated and lighting is multiplied 
	gl_FragColor = texture2D(diff,textureCoord0) * clamp(dot(-camDirection, normal0), 0.1, 1.0);
}


