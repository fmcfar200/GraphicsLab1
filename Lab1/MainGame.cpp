#include "MainGame.h"
#include <iostream>
#include <string>

unsigned int indices[] = { 0, 1, 2 };
Transform transform;


MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	Display* _gameDisplay = new Display(); //new display

	Mesh* mesh();

	Camera* camera();


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
	mesh1.loadModel("C:\\Users\\fmcfar200\\Desktop\\GitHub\\GraphicsLab1\\res\\monkey3.obj");
	myCamera.initCamera(glm::vec3(0, 0, -5), 70.0f, (float)_gameDisplay.getWidth() / _gameDisplay.getHeight(), 0.01f, 1000.0);

	
	

	
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
	_gameDisplay.ClearDisplay(0.0f, 0.0f, 0.0f, 1.0f);

	Shader shader("C:\\Users\fmcfar200\Desktop\GitHub\GraphicsLab1\res\shader.frag"); //new shader
	Texture texture("C:\\Users\fmcfar200\Desktop\GitHub\GraphicsLab1\res\bricks.jpg"); //load texture
	Texture texture1("C:\\Users\fmcfar200\Desktop\GitHub\GraphicsLab1\res\bricks.jpg"); //load texture

	transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
	transform.SetRot(glm::vec3(0.0, 0.0, counter * 5));
	transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));

	shader.Bind();
	shader.Update(transform, myCamera);
	texture.Bind(0);
	mesh1.Draw();
	counter = counter + 0.01f;
	glEnableClientState(GL_COLOR_ARRAY);
	glEnd();

	_gameDisplay.swapBuffer();
}
