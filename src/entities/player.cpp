#include "player.h"


namespace tron_seekers
{
	GameStats aux_game_stats;

	float player_width = 20.0f;
	float player_height = 60.0f;

	float inmerse_timer = 0.0f;
	float inmerse_delay = 2.5f;

	static void ChangePLayerDir(Player& player);
	static void InmerseSecuence(Player& player);

	void InitPlayer(Player& player)
	{
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
		inmerse_timer += GetFrameTime();

		switch (player.player_direction)
		{
		case EntitieMovemment::NONE:
			player.player_hit_box = player.player_hit_box;
			break;

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

		case EntitieMovemment::INMERSE:
			InmerseSecuence(player);

			if (inmerse_timer >= inmerse_delay)
			{
				player.player_hit_box.width = player_width;
				player.player_hit_box.height = player_height;

				inmerse_timer = 0;
				player.player_direction = EntitieMovemment::NONE;
			}
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
			{KEY_A, EntitieMovemment::LEFT},
			{KEY_SPACE, EntitieMovemment::INMERSE}
		};

		for (const KeyDir& input : inputs)
		{
			if (IsKeyDown(input.key))
			{
				player.player_direction = input.dir;
				break;
			}
			else if (!IsKeyDown(input.key) && player.player_direction != EntitieMovemment::INMERSE)
			{
				player.player_direction = EntitieMovemment::NONE;
			}
		}
	}

	static void InmerseSecuence(Player& player)
	{
		float aux_inmerse_width = 15.0f;
		float aux_inmerse_heiht = 45.0f;

		player.player_hit_box.width = aux_inmerse_width;
		player.player_hit_box.height = aux_inmerse_heiht;
	}
}