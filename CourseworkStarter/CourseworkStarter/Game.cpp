#include "Game.h"
#include <iostream>
#include <string>

unsigned int inds[] = { 0, 1, 2 };
Transform trans;
Transform trans2;
Transform trans3;

//CHANGE 
string RESOURCE_PATH = "C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\";

Game::Game()
{
	gameState = State::PLAY;
	Window* gameDisp = new Window();

	MeshManager* mesh1();
	MeshManager* mesh2();
	MeshManager* mesh3();


	Skybox* sky();

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

	mesh1.loadModelFromFile(RESOURCE_PATH + "Barrel_01.obj");
	mesh2.loadModelFromFile(RESOURCE_PATH + "Hatchet.obj");
	mesh3.loadModelFromFile(RESOURCE_PATH + "deer.obj");

	trans.SetPos(glm::vec3(0, 0.0, 0.0));
	trans.SetRot(glm::vec3(0.0, 0, 0));
	trans.SetScale(glm::vec3(1.5, 1.5, 1.5));

	trans2.SetPos(glm::vec3(10.0f, 0.0f, 0.0f));
	trans2.SetRot(glm::vec3(0.0, 0, 0));
	trans2.SetScale(glm::vec3(1, 1, 1));

	trans3.SetPos(glm::vec3(-10.0f, 0.0f, 0.0f));
	trans3.SetRot(glm::vec3(0.0, 4, 0));
	trans3.SetScale(glm::vec3(0.75, 0.75, 0.75));


	//sky.initialiseSkybox();

	cam.initialiseCamera(glm::vec3(5, 0, -40), 70.0f, (float)gameDisplay.GetWidth() / gameDisplay.GetHeight(), 0.01f, 1000.0);
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
				cam.MoveForward(1);
				break;
			case SDLK_DOWN:
				cam.MoveBackwards(1);
				break;
			case SDLK_RIGHT:
				cam.MoveRight(1);
				break;
			case SDLK_LEFT:
				cam.MoveLeft(1);
				break;

			case SDLK_ESCAPE:
				gameState = State::EXIT;
				break;


			}
		}
		cam.MoveMouse();
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


	ShaderManager shader1(RESOURCE_PATH); //shader obj
	TextureManager texture1(RESOURCE_PATH + "metal.png");

	texture1.BindTexture(0);
	shader1.BindShader();//bind shader
	shader1.Update(trans,cam);


	mesh1.DrawMesh();//draws mesh

	ShaderManager shader2(RESOURCE_PATH); //shader obj
	TextureManager texture2(RESOURCE_PATH + "metal2.png");

	texture2.BindTexture(1);
	shader2.BindShader();
	shader2.Update(trans2, cam);


	mesh2.DrawMesh();

	ShaderManager shader3(RESOURCE_PATH); //shader obj
	TextureManager texture3(RESOURCE_PATH + "metal2.png");

	
	texture3.BindTexture(2);
	shader3.BindShader();
	shader3.Update(trans3, cam);


	mesh3.DrawMesh();

	//sky.drawSky(100);

	count = count + 0.01f;

	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();


	
	gameDisplay.swapBuffer();

}

