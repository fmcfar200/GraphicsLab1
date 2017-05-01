#pragma once
//includes to appropriate libraries and header files
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Window.h" 
#include "MeshManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "Transform.h"
#include "View.h"
#include "Skybox.h"

enum class State { PLAY, EXIT }; // specifys state of game application

class Game	//game class
{
public:
	Game(); //constructor
	~Game();	//destructor

	void RunGame(); //method that runs application

private:
	void initialiseSystems();	//sets transforms and models
	void updateInput();	//allows for key and mouse interactions
	void gLoop();	//game loop
	void draw();	//renders features

	Window gameDisplay;	//display window object
	State gameState;	//game state object

	MeshManager mesh1;	//all meshes that will be rendered
	MeshManager mesh2;
	MeshManager mesh3;


	View cam;	//camera object

	Skybox sky; //skybox

	float count = 0;
};

