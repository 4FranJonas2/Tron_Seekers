#include "player.h"


namespace tron_seekers
{
	GameStats aux_game_stats;

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
	}

	void DrawPlayer(Player player)
	{
		float aux_rec_lines = 2.0f;
		Color aux_player_color = RED;

		DrawRectangleLinesEx(player.player_hit_box, aux_rec_lines, aux_player_color);
	}
}