#include "game_run.h"

#include <iostream>

#include "raylib.h"

#include "entities/player.h"

namespace tron_seekers
{
	GameStats game_status;
	Player player;

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
		InitWindow(game_status.kScreenWidth, game_status.kScreenHeight, "Tron Seekers v0.1.1");
		InitAudioDevice();
		InitPlayer(player);
	}
	void Input()
	{
		InputPlayer(player);
	}
	void Update()
	{
		UpdatePlayer(player);
	}
	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		//poner el texto de la version en una funcion en otro archivo mas tarde
		// y generar locales para las variables magicas 
		DrawText("v 0.1", game_status.kScreenWidth - 40, game_status.kScreenHeight - 20, 15, WHITE);

		DrawPlayer(player);

		EndDrawing();
	}
}