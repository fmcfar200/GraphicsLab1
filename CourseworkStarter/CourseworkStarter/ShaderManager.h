#pragma once
#include <string>
#include <GL\glew.h>
#include "Transform.h"
#include "View.h"
class ShaderManager
{
public:
	ShaderManager(const std::string& filename); //constructor
	~ShaderManager(); //destructor

	void BindShader(); //Set gpu to use our shaders

	std::string LoadShaderFromFile(const std::string& fileName); //loads shader from file
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage); //checks errors in shader
	GLuint CreateShader(const std::string& text, unsigned int type); //creates the shader

	void UpdateShader(const Transform& trans, const View& camera); //updates shader data
	


protected:
private:
	static const unsigned int NUM_OF_SHADERS = 2; // number of shaders
	 
	//uniform enums
	enum
	{
		TRANSFORM_UNIF,
		CAMDIRECTION_UNIF,

		NUM_OF_UNIFORMS
	};

	GLuint shaderProg; // Track the shader program
	GLuint shaders[NUM_OF_SHADERS]; //array of shaders
	GLuint uniforms[NUM_OF_UNIFORMS]; //no of uniform vars
};


