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
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glEnd();

	// SWAP BUFFER HERE

	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gameDisplay.swapBuffer();

}
