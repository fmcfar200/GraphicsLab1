#include "Game.h"	//includes class header and libraries
#include <iostream>
#include <string>

Transform trans;
Transform trans2;
Transform trans3;

//CHANGE 
string RESOURCE_PATH = "C:\\Users\\Fraser\\Documents\\Uni\\Year3\\B\\Graphics\\GraphicsLabs\\CourseworkStarter\\res\\"; // path for resource directory

Game::Game()
{
	gameState = State::PLAY;	//state is set to play
	Window* gameDisp = new Window();	//new gameDisplay is defined 

	//all mesh, skybox and camera points to default contructor
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
	initialiseSystems(); //initialises all data
	gLoop();	//starts game loop

}

void Game::initialiseSystems()
{
	gameDisplay.initialiseDisplay();	//game display is set

	//all models are loaded
	mesh1.loadModelFromFile(RESOURCE_PATH + "Barrel_01.obj");
	mesh2.loadModelFromFile(RESOURCE_PATH + "Hatchet.obj");
	mesh3.loadModelFromFile(RESOURCE_PATH + "bear.obj");

	//all transforms are set
	trans.SetPos(glm::vec3(0, 0.0, 0.0));
	trans.SetRot(glm::vec3(0.0, 0, 0));
	trans.SetScale(glm::vec3(1.5, 1.5, 1.5));

	trans2.SetPos(glm::vec3(10.0f, 0.0f, 0.0f));
	trans2.SetRot(glm::vec3(0.0, 0, 0));
	trans2.SetScale(glm::vec3(1, 1, 1));

	trans3.SetPos(glm::vec3(-15.0f, 0.0f, 0.0f));
	trans3.SetRot(glm::vec3(0.0, 4, 0));
	trans3.SetScale(glm::vec3(0.75, 0.75, 0.75));

	//camera is initialised and created
	cam.initialiseCamera(glm::vec3(5, 0, -40), 70.0f, 
		(float)gameDisplay.GetWidth() / gameDisplay.GetHeight(), 0.01f, 1000.0);

	//sky.initialiseSkybox();

	
}

void Game::updateInput()
{
	SDL_Event sdlEvent; //new event object

	while (SDL_PollEvent(&sdlEvent)) //while events are being queued
	{
		switch (sdlEvent.type) //switch dependant on the type of event
		{
		case SDL_QUIT:
			gameState = State::EXIT; //gamestate is changed when sdl is quit
			break;

		case SDL_MOUSEMOTION:
			cam.MoveMouse();
			break;


			//key press
		case SDL_KEYDOWN:
			switch (sdlEvent.key.keysym.sym)
			{
				//camera movement
			case SDLK_w:
				cam.MoveForward(1);
				break;
			case SDLK_s:
				cam.MoveBackwards(1);
				break;
			case SDLK_d:
				cam.MoveRight(1);
				break;
			case SDLK_a:
				cam.MoveLeft(1);
				break;
			

				//object rotation
			case SDLK_UP:
				trans.Rotate(vec3(0.1, 0, 0));
				break;

			case SDLK_DOWN:
				trans.Rotate(-vec3(0.1, 0, 0));
				break;

			case SDLK_LEFT:
				trans.Rotate(-vec3(0, 0.1, 0));
				break;
			case SDLK_RIGHT:
				trans.Rotate(vec3(0, 0.1, 0));
				break;

				//exit if escape
			case SDLK_ESCAPE:
				gameState = State::EXIT;
				break;


			}
		}
		 //move cam by mouse
	}
}

void Game::gLoop()
{
	while (gameState != State::EXIT) //while the state is not exit
	{
		updateInput();	//input is updated
		cam.Update(gameDisplay.GetWidth(),gameDisplay.GetHeight());	//camera is updated
		draw();	//renders screen
	}
}

void Game::draw()
{
	gameDisplay.ClearDisplay(0.5f,0.5f,0.5f,1.0f); //clear display colour is set to grey


	ShaderManager shader1(RESOURCE_PATH + "shaderLight"); //shader obj
	TextureManager texture1(RESOURCE_PATH + "metal.png");	//texture object

	shader1.BindShader();//bind shader
	shader1.UpdateShader(trans,cam);
	texture1.BindTexture(0);//binds texture



	mesh1.DrawMesh();//draws mesh

	ShaderManager shader2(RESOURCE_PATH + "shaderLight"); //shader obj
	TextureManager texture2(RESOURCE_PATH + "Wood.jpg");//texture object

	shader2.BindShader();
	shader2.UpdateShader(trans2, cam);
	texture2.BindTexture(0);



	mesh2.DrawMesh();

	ShaderManager shader3(RESOURCE_PATH + "shaderLight"); //shader obj
	TextureManager texture3(RESOURCE_PATH + "metal2.png");//texture object

	
	shader3.BindShader();
	shader3.UpdateShader(trans3, cam);
	texture3.BindTexture(0);


	mesh3.DrawMesh();

	//sky.drawSky(25);

	count = count + 0.01f;

	glEnableClientState(GL_COLOR_ARRAY); //sets colour states
	glEnd(); //opengl render pass ends


	
	gameDisplay.SwapBuffer(); //buffers are swapped to game display

}

