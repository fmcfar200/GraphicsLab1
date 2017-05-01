#include "Window.h"



Window::Window()
{
	window = nullptr;		//sets null pointer for window object
	screenH = 768.0f;	//screen height
	screenW = 1024.0f;	//screen width

}


Window::~Window()
{
	SDL_GL_DeleteContext(context); //destroys gl context
	SDL_DestroyWindow(window);	//destroys window object
	SDL_Quit();	//sets sdl to quit flag
}

void Window::initialiseDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING); //init everything


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);	//sets attrubutes of SDL and GL
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)screenW, (int)screenH, SDL_WINDOW_OPENGL); //window is created
	context = SDL_GL_CreateContext(window); //create gl context

	glEnable(GL_DEPTH_TEST); //enable z-buffering 
	glEnable(GL_CULL_FACE); //dont draw faces that are not pointing at the camera


	GLenum error = glewInit();// init glew

	if (window == nullptr)
	{
		ReturnError("window failed to create");
	}

	if (context == nullptr)
	{
		ReturnError("SDL_GL context failed to create");
	}

	if (error != GLEW_OK)
	{
		ReturnError("GLEW failed to initialise");
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //sets background colour
}

void Window::SwapBuffer()
{
	SDL_GL_SwapWindow(window); //swaos buffer to window
}

void Window::ClearDisplay(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);	//clear colour is set
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //depths and colour buffers are enabled for clear display
}

float Window::GetWidth()
{
	return screenW; //returns screen width
}

float Window::GetHeight()
{
	return screenH;	//returns screen height
}

void Window::ReturnError(std::string eString)
{
	std::cout << eString << std::endl; //returns error message
	std::cout << "press any  key to quit...";	//returns message prompt
	int in;
	std::cin >> in;
	SDL_Quit(); //sets sdl to quit
}
