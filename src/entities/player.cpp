#include "player.h"


namespace tron_seekers
{
	GameStats aux_game_stats;

	static void ChangePLayerDir(Player& player);

	void InitPlayer(Player& player)
	{
		float player_width = 20.0f;
		float player_height = 60.0f;

		player.player_pos.x = aux_game_stats.kScreenWidth * 0.5f;
		player.player_pos.y = aux_game_stats.kScreenHeight * 0.5f;

		player.player_hit_box.x = player.player_pos.x;
		player.player_hit_box.y = player.player_pos.y;
		player.player_hit_box.width = player_width;
		player.player_hit_box.height = player_height;

		player.player_speed = 450.0f;
	}

	void InputPlayer(Player& player)
	{
		ChangePLayerDir(player);
	}

	void UpdatePlayer(Player& player)
	{
		switch (player.player_direction)
		{
		case EntitieMovemment::UP:
			player.player_hit_box.y -= player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::RIGTH:
			player.player_hit_box.x += player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::DOWN:
			player.player_hit_box.y += player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::LEFT:
			player.player_hit_box.x -= player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::NONE:
			player.player_hit_box = player.player_hit_box;
			break;

		default:
			break;
		}
	}

	void DrawPlayer(Player player)
	{
		float aux_rec_lines = 2.0f;
		Color aux_player_color = RED;

		DrawRectangleLinesEx(player.player_hit_box, aux_rec_lines, aux_player_color);
	}

	static void ChangePLayerDir(Player& player)
	{
		struct KeyDir
		{
			KeyboardKey key;
			EntitieMovemment dir;
		};

		KeyDir inputs[] =
		{
			{KEY_W, EntitieMovemment::UP},
			{KEY_D, EntitieMovemment::RIGTH},
			{KEY_S, EntitieMovemment::DOWN},
			{KEY_A, EntitieMovemment::LEFT}
		};

		for (const KeyDir& input : inputs)
		{
			if (IsKeyDown(input.key))
			{
				player.player_direction = input.dir;
				break;
			}
			if (!IsKeyDown(input.key))	
			{
				player.player_direction = EntitieMovemment::NONE;
			}
		}
	}
}