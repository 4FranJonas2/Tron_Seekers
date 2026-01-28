#pragma once

#include "../utilities.h"

namespace tron_seekers
{
	struct Player
	{
		Rectangle player_hit_box;
		Vector2 player_pos;
		
	};

	void InitPlayer(Player& player);
	void DrawPlayer(Player player);
}