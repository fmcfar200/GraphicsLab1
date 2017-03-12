#include "Game.h"
#include <iostream>
#include <string>

unsigned int inds[] = { 0, 1, 2 };
Transform trans;

Game::Game()
{
	gameState = State::PLAY;
	Window* gameDisp = new Window();

	MeshManager* mesh();

	View* cam();

}


Game::~Game()
{
}

void Game::RunGame()
{
	initialiseSystems();
	gLoop();

}

void Game::initialiseSystems()
{
	gameDisplay.initialiseDisplay();
	mesh1.loadModelFromFile("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\monkey3.obj");
	camera.initialiseCamera(glm::vec3(0, 0, -5), 70.0f, (float)gameDisplay.GetWidth() / gameDisplay.GetHeight(), 0.01f, 1000.0);
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

	
	gameDisplay.ClearDisplay(0.0f,0.0f,0.0f,1.0f);
	
	ShaderManager shader("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\"); //shader obj
	TextureManager texture("C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\bricks.jpg");

	trans.SetPos(glm::vec3(sinf(count), 0.0, 0.0));
	trans.SetRot(glm::vec3(0.0, 0.0, count * 5));
	trans.SetScale(glm::vec3(sinf(count), sinf(count), sinf(count)));

	shader.BindShader();//bind shader
	shader.Update(trans,camera);
	texture.BindTexture(0);
	mesh1.DrawMesh();//draws mesh
	count = count + 0.01f;

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();


	
	gameDisplay.swapBuffer();

}

