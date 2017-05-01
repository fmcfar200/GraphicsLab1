#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;

class Window
{
public:
	Window(); //constructor
	~Window();	//destructor
	void initialiseDisplay(); //initialises all display data
	void SwapBuffer(); //swapps buffer to window display
	void ClearDisplay(float r, float g, float b, float a); //color of clear

	//getters of width and height
	float GetWidth();
	float GetHeight();


private:

	void ReturnError(std::string eString); //error return
	SDL_Window* window; //holds pointer window
	SDL_GLContext context; //context object
	//width and height
	float screenW;
	float screenH;


};

