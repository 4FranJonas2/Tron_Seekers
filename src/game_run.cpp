#include "game_run.h"

#include <iostream>

#include "raylib.h"

#include "entities/player.h"

namespace tron_seekers
{
	GameStats game_status;

	static void Init();
	static void Input();
	static void Update();
	static void Draw();

	void GameRun()
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
		InitWindow(game_status.kScreenWidth, game_status.kScreenHeight, "Tron Seekers");
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