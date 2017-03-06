#include "Game.h"
#include <iostream>
#include <string>



Game::Game()
{
	gameState = State::PLAY;
	Window* gameDisp = new Window();

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

	 //array of verts
	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };


	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0])); //mesh object
	
	Shader shader("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\"); //shader obj
	Texture texture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\bricks.jpg");

	Transform transform;
	transform.SetPos(glm::vec3(sinf(count), 0.0, 0.0));
	transform.SetRot(glm::vec3(0.0, 0.0, count * 5));
	transform.SetScale(glm::vec3(sinf(count), sinf(count), sinf(count)));

	shader.BindShader();//bind shader
	shader.Update(transform);
	texture.BindTexture(0);
	mesh.Draw();//draws mesh

	count = count + 0.01f;

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();


	
	gameDisplay.swapBuffer();

}

