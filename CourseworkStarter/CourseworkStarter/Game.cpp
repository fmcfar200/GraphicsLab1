#include "Game.h"
#include <iostream>
#include <string>

unsigned int inds[] = { 0, 1, 2 };
Transform trans;

//CHANGE 
string RESOURCE_PATH = "C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\";

Game::Game()
{
	gameState = State::PLAY;
	Window* gameDisp = new Window();

	MeshManager* mesh1();
	MeshManager* mesh2();

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
	mesh1.loadModelFromFile(RESOURCE_PATH + "monkey3.obj");
	mesh2.loadModelFromFile(RESOURCE_PATH + "monkey3.obj");

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

		case SDL_KEYDOWN:
			switch (sdlEvent.key.keysym.sym)
			{
				//camera movement
			case SDLK_UP:
				camera.MoveForward(0.5f);
				break;
			case SDLK_DOWN:
				camera.MoveBackwards(0.5f);
				break;
			case SDLK_RIGHT:
				camera.MoveRight(0.5f);
				break;
			case SDLK_LEFT:
				camera.MoveLeft(0.5f);
				break;

			case SDLK_ESCAPE:
				gameState = State::EXIT;
				break;


			}
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

	ShaderManager shader(RESOURCE_PATH); //shader obj
	TextureManager texture(RESOURCE_PATH + "bricks.jpg");

	trans.SetPos(glm::vec3(0, 0.0, 0.0));
	trans.SetRot(glm::vec3(0.0, 0.0, 0));
	trans.SetScale(glm::vec3(1, 1, 1));


	shader.BindShader();//bind shader
	shader.Update(trans,camera);

	texture.BindTexture(0);

	mesh1.DrawMesh();//draws mesh
	mesh2.DrawMesh();


	count = count + 0.01f;

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();


	
	gameDisplay.swapBuffer();

}

