#include "Display.h"



Display::Display()
{
	window = nullptr;
	screenH = 768;
	screenW = 1024;

}


Display::~Display()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Display::initialiseDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING); //init everything


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window); //create gl context

	GLenum error = glewInit();// init glew

	if (window == nullptr)
	{
		returnError("window failed to create");
	}

	if (context == nullptr)
	{
		returnError("SDL_GL context failed to create");
	}

	if (error != GLEW_OK)
	{
		returnError("GLEW failed to initialise");
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //sets background colour
}

void Display::swapBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Display::ClearDisplay()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::returnError(std::string eString)
{
	std::cout << eString << std::endl;
	std::cout << "press any  key to quit...";
	int in;
	std::cin >> in;
	SDL_Quit();
}
