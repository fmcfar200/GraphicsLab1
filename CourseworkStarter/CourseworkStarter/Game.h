#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Window.h" 
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
enum class State { PLAY, EXIT };

class Game
{
public:
	Game();
	~Game();

	void RunGame();

private:
	void initSystems();
	void updateInput();
	void gLoop();
	void draw();

	Window gameDisplay;
	State gameState;

	float count = 0;
};

