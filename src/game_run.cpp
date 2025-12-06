#include "game_run.h"

#include <iostream>

#include "raylib.h"

#include "entities/player.h"

namespace finalX
{
	GameStats gameStatus;

	static void Init();
	static void Input();
	static void Update();
	static void Draw();

	void game_run()
	{
		Init();
		
		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}

		CloseWindow();
	}

	static void Init()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		InitWindow(screenWidth, screenHeight, "finalX");
		InitAudioDevice();
	}
	void Input()
	{
	}
	void Update()
	{
	}
	void Draw()
	{
	}
}