#pragma once
#include <string>
#include <GL\glew.h>
#include <SDL\SDL.h>
#include "stb_image.h"
#include <cassert>
#include <iostream>
#include "TextureManager.h"


class Skybox
{
public:
	Skybox(); //const
	~Skybox(); //dest

	void initialiseSkybox(); //initiales skyboxs
	void drawSky(float size); //draws skybox vertices and textures
	GLuint loadSkyTexture(const std::string& filename); //loads sky texture

private:
	GLuint textureHandler; //handler for texture
	GLuint skybox[6]; //handler for skybox textures array
	enum 
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		BACK,
		FORWARD
	}; //enums for textures

};

