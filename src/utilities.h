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
	};
}