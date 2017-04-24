#pragma once
#include <string>
#include <GL\glew.h>
#include <SDL\SDL.h>
#include "stb_image.h"
#include <cassert>
#include <iostream>


class Skybox
{
public:
	Skybox();
	~Skybox();

	void initialiseSkybox();
	void drawSky(float size);
	unsigned int loadSkyTexture(const std::string& filename);

private:
	GLuint textureHandler;
	unsigned int skybox[6];
	enum 
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
		BACK,
		FORWARD
	};

};

