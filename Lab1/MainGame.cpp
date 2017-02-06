#include "MainGame.h"
#include <iostream>
#include <string>

MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	Display* _gameDisplay = new Display(); //new display
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems(); 
	gameLoop();
}

void MainGame::initSystems()
{
	_gameDisplay.initDisplay(); 
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
	
}

void MainGame::drawGame()
{
	_gameDisplay.ClearDisplay();

	Vertex vertices[]
	{
		glm::vec3(-0.5f, -0.5f, 0.0f),
		glm::vec3(0, 0.5f, 0.0f),
		glm::vec3(0.5, -0.5f, 0.0f)
	};

	Mesh mesh(vertices, sizeof(vertices)/ sizeof(vertices[0]));
	Shader shader("C:\\Users\\fmcfar200\\Desktop\\GitHub\\GraphicsLab1\\res");
	shader.Bind();
	mesh.Draw();

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
}