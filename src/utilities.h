#pragma once

#include "raylib.h"
#include "raymath.h"

namespace tron_seekers
{
	enum class SceneStatus
	{
		GAMEMENU = 1,
		GAMERULES,
		GAMECREDITS,
		FIRSTGAME,
		GAMEPLAY,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND,
		SIMEND
	};

	struct GameStats
	{
		SceneStatus gameStatus = SceneStatus::GAMEMENU;

		int fontSize = 25;
		const int kScreenWidth = 1024;
		const int kScreenHeight = 768;
	};

	enum class EntitieMovemment
	{
		NONE =1,
		UP,
		RIGTH,
		DOWN,
		LEFT,
		INMERSE
	};
}