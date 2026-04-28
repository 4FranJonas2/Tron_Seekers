#include "player.h"


namespace tron_seekers
{
	GameStats aux_game_stats;

	float player_width = 20.0f;
	float player_height = 60.0f;

	float inmerse_timer = 0.0f;
	float surface_delay = 2.5f;
	float jump_delay = 1.0f;
	float fall_delay = 1.0f;

	static void ChangePLayerDir(Player& player);
	static void InmerseSecuence(Player& player, float new_width, float new_height);
	static void PlayerDefaultSize(Player& player);

	void InitPlayer(Player& player)
	{
		player.player_pos.x = aux_game_stats.kScreenWidth * 0.5f;
		player.player_pos.y = aux_game_stats.kScreenHeight * 0.5f;

		player.player_hit_box.x = player.player_pos.x;
		player.player_hit_box.y = player.player_pos.y;
		player.player_hit_box.width = player_width;
		player.player_hit_box.height = player_height;

		player.player_speed = 450.0f;

		player.jump_secuence = false;
	}

	void InputPlayer(Player& player)
	{
		ChangePLayerDir(player);
	}

	void UpdatePlayer(Player& player)
	{
		inmerse_timer += GetFrameTime();

		float aux_inmerse_width = 15.0f;
		float aux_inmerse_height = 45.0f;
		float aux_jump_width = 25.0f;
		float aux_jump_height = 75.0f;

		switch (player.player_direction)
		{
		case EntitieMovemment::NONE:
			player.player_pos = player.player_pos;
			break;

		case EntitieMovemment::UP:
			player.player_pos.y += player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::RIGTH:
			player.player_pos.x += player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::DOWN:
			player.player_pos.y -= player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::LEFT:
			player.player_pos.x -= player.player_speed * GetFrameTime();
			break;

		case EntitieMovemment::INMERSE:

			InmerseSecuence(player, aux_inmerse_width, aux_inmerse_height);

			if (inmerse_timer >= surface_delay && inmerse_timer <= (surface_delay + jump_delay))
			{
				PlayerDefaultSize(player);
			}
			if (inmerse_timer >= (surface_delay + jump_delay) && inmerse_timer <= (surface_delay + jump_delay + fall_delay))
			{
				InmerseSecuence(player, aux_jump_width, aux_jump_height);
			}
			if (inmerse_timer >= (surface_delay + jump_delay + fall_delay))
			{
				PlayerDefaultSize(player);

				inmerse_timer = 0;
				player.player_direction = EntitieMovemment::NONE;
				player.jump_secuence = false;
			}
			break;

		default:
			break;
		}
	}

	void DrawPlayer(Player player)
	{
		Color aux_player_color = RED;
		
		Rectangle rect =
			{ aux_game_stats.kScreenWidth / 2 + player.player_pos.x, 
			aux_game_stats.kScreenHeight / 2 - player.player_pos.y,
			player.player_hit_box.width, player.player_hit_box.height };

		Vector2 origin = { player.player_hit_box.width * 0.5f, player.player_hit_box.height * 0.5f };

		DrawRectanglePro(rect, origin, 0.0f, RED);
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

//#ifdef _DEBUG
//				std::cout << "Estado actual: " << input.dir << std::endl;
//#endif // _DEBUG 
				if (player.player_direction == EntitieMovemment::INMERSE)
				{
					player.jump_secuence = true;
				}
				break;
			}
			else if (!IsKeyDown(input.key) && !player.jump_secuence)
			{
				player.player_direction = EntitieMovemment::NONE;
			}
		}
	}

	static void InmerseSecuence(Player& player, float new_width, float new_height)
	{
		player.player_hit_box.width = new_width;
		player.player_hit_box.height = new_height;
	}

	static void PlayerDefaultSize(Player& player)
	{
		player.player_hit_box.width = player_width;
		player.player_hit_box.height = player_height;
	}
}