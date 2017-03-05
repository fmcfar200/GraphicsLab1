#include "Game.h"
#include <iostream>
#include <string>



Game::Game()
{
	gameState = State::PLAY;
	Display* gameDisp = new Display();

}


Game::~Game()
{
}

void Game::RunGame()
{
	initSystems();
	gLoop();

}

void Game::initSystems()
{
	gameDisplay.initialiseDisplay();
}

void Game::updateInput()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			gameState = State::EXIT;
			break;
		}
	}
}

void Game::gLoop()
{
	while (gameState != State::EXIT)
	{
		updateInput();
		draw();
	}
}

void Game::draw()
{

	
	gameDisplay.ClearDisplay();

	Vertex vertices[]
	{
		glm::vec3(-0.5f, -0.5f, 0.0f),
		glm::vec3(0, 0.5f, 0.0f),
		glm::vec3(0.5, -0.5f, 0.0f)
	}; //array of verts

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0])); //mesh object
	Shader shader("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\"); //shader obj
	shader.BindShader();//bind shader
	mesh.Draw();//draws mesh

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();


	
	gameDisplay.swapBuffer();

}

