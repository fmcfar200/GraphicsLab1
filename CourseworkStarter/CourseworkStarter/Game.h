#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Window.h" 
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "View.h"
enum class State { PLAY, EXIT };

class Game
{
public:
	Game();
	~Game();

	void RunGame();

private:
	void initialiseSystems();
	void updateInput();
	void gLoop();
	void draw();

	Window gameDisplay;
	State gameState;

	Mesh mesh1;
	Mesh mesh2;

	View camera;

	float count = 0;
};

