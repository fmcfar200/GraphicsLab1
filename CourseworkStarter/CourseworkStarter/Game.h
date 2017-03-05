#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Mesh.h"
#include "Shader.h"

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

	Display gameDisplay;
	State gameState;

};

