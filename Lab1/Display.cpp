#include "Display.h"


Display::Display()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHieght = 768;

}


Display::~Display()
{
}

void Display::returnError(std::string errorString)
{
	cout << errorString;
	cout << "press any key to quit...";
	
	//checks keystroke (fix)
	if (SDL_KEYDOWN)
	{
		SDL_Quit();

	}
}

void Display::swapBuffer()
{
	SDL_GL_SwapWindow(_window);
}

void Display::initDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING); //*
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHieght, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	GLenum error = glewInit();

	if (_window == nullptr)
	{
		returnError("Cannot init due to window not existing!");
	}
	if (glContext == nullptr)
	{
		returnError("Cannot init due to glcontext not existing!");
	}
	if (error != GLEW_OK)
	{
		returnError("Cannot init due to glew error!");
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}
