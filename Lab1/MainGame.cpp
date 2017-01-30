#include "MainGame.h"
#include <iostream>
#include <string>


MainGame::MainGame()
{
	_gameState = GameState::PLAY;

	Display* _gameDisplay = new Display;

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
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		///
	}

	switch (event.type)
	{
	case SDL_QUIT:
		GameState::EXIT;
		break;
	}
}

void MainGame::drawGame()
{

	// old code for testing only 
	
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);

	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnd();

	// SWAP BUFFER HERE
	//SDL_GL_SwapWindow();
}

