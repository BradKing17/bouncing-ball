#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Engine/Platform.h>
#include "BouncingBall.h"

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	PSTR pScmdline, int iCmdshow)
{

	// create an instance of the game
	BouncingBall game;
	if (game.init())
	{
		// if it initalised correctly run it
		return game.run();
	}

	// otherwise we error out
	return -1;

}