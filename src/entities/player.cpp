#include "player.h"


namespace tron_seekers
{
	GameStats aux_game_stats;

	float player_width = 20.0f;
	float player_height = 60.0f;

	float player_spawnPosX = -220.0f;
	float player_spawnPosY = -150.0f;

	float inmerse_timer = 0.0f;
	float surface_delay = 2.5f;
	float jump_delay = 1.0f;
	float fall_delay = 1.0f;

	static void ChangePLayerDir(Player& player);
	static void SetJumpSecuenceSize(Player& player, float new_width, float new_height);
	static void PlayerDefaultSize(Player& player);
	static void SetHitBoxPos(Player& player);

	void InitPlayer(Player& player)
	{
		player.player_pos.x = player_spawnPosX;
		player.player_pos.y = player_spawnPosY;

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

		Vector2 dir = player.input_dir;

		if (dir.x != 0 || dir.y != 0)
		{
			dir = Vector2Normalize(dir);

			player.player_pos.x += dir.x * player.player_speed * GetFrameTime();
			player.player_pos.y += dir.y * player.player_speed * GetFrameTime();

			SetHitBoxPos(player);
		}

		if (dir.x==0 || dir.y ==0)
		{
			player.player_pos = player.player_pos;
		}
		
		switch (player.player_direction)
		{
		
		case EntitieMovemment::INMERSE:

			SetJumpSecuenceSize(player, aux_inmerse_width, aux_inmerse_height);

			if (inmerse_timer >= surface_delay && inmerse_timer <= (surface_delay + jump_delay))
			{
				PlayerDefaultSize(player);
			}
			if (inmerse_timer >= (surface_delay + jump_delay) && inmerse_timer <= (surface_delay + jump_delay + fall_delay))
			{
				SetJumpSecuenceSize(player, aux_jump_width, aux_jump_height);
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
		Vector2 screenPos = {aux_game_stats.kScreenWidth * 0.5f + player.player_pos.x, aux_game_stats.kScreenHeight * 0.5f - player.player_pos.y };

		Rectangle rect = {screenPos.x, screenPos.y, player.player_hit_box.width, player.player_hit_box.height};

		Vector2 origin = {player.player_hit_box.width * 0.5f, player.player_hit_box.height * 0.5f};

		DrawRectanglePro(rect, origin, 0.0f, RED);
	}

	static void ChangePLayerDir(Player& player)
	{
		player.input_dir = { 0, 0 };

		if (IsKeyDown(KEY_W)) player.input_dir.y += 1;
		if (IsKeyDown(KEY_S)) player.input_dir.y -= 1;
		if (IsKeyDown(KEY_A)) player.input_dir.x -= 1;
		if (IsKeyDown(KEY_D)) player.input_dir.x += 1;

		if (IsKeyDown(KEY_SPACE))
		{
			player.jump_secuence = true;
			player.player_direction = EntitieMovemment::INMERSE;
			return;
		}
	}

	static void SetJumpSecuenceSize(Player& player, float new_width, float new_height)
	{
		player.player_hit_box.width = new_width;
		player.player_hit_box.height = new_height;
	}

	static void PlayerDefaultSize(Player& player)
	{
		player.player_hit_box.width = player_width;
		player.player_hit_box.height = player_height;
	}

	static void SetHitBoxPos(Player& player)
	{
		player.player_hit_box.x = player.player_pos.x;
		player.player_hit_box.y = player.player_pos.y;
	}
}