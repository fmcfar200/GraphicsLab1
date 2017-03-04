#include "Display.h"



Display::Display()
{
	window = nullptr;
	screenH = 768;
	screenW = 1024;

}


Display::~Display()
{
}

void Display::initialiseDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window); //create gl context

	GLenum error = glewInit();// init glew

	if (window == nullptr)
	{
		//return error
	}

	if (context == nullptr)
	{
		//return error
	}

	if (error != GLEW_OK)
	{
		//return errpr
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //sets background colour
}

void Display::swapBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Display::returnError(std::string eString)
{
}
