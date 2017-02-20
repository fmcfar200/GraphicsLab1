#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;

class Display
{
public:
	Display();
	~Display();
	void initDisplay();
	void swapBuffer();
	void ClearDisplay(float r, float g, float b, float a);

	float getWidth();
	float getHeight();



private:

	void returnError(std::string errorString);

	SDL_Window* _window; //holds pointer to out window
	float _screenWidth;
	float _screenHeight;
	SDL_GLContext glContext;

};

