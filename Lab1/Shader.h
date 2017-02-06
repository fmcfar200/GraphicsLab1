#pragma once
#include <string>
#include <GL\glew.h>

class Shader
{
public:
	Shader(const std::string& filename);
	void Bind(); //set gpu to use the shader
	std::string LoadShader(const std::string& filename);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);


	~Shader();

protected:
private:
	static const unsigned int NUM_SHADERS = 2; //number of sdhaders
	Shader(const Shader& other){}
	void operator = (const Shader& other){}

	GLuint program; //track the shader program
	GLuint shaders[NUM_SHADERS];//array of shaders

};

