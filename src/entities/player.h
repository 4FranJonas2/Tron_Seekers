#pragma once

#include "../utilities.h"

namespace tron_seekers
{
	struct Player
	{
		Rectangle player_hit_box;
		Vector2 player_pos;

		float player_speed;

		Vector2 input_dir;

		bool jump_secuence;

		EntitieMovemment player_direction;
	};

	void InitPlayer(Player& player);
	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
}