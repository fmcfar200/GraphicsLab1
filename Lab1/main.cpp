#include <SDL/SDL.h>
#include <iostream>
#include "MainGame.h"

int main(int argc, char** argv) //arguements used to call SDL main
{
	MainGame mainGame;
	mainGame.run();

	return 0;
}