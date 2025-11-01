#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("Test game over when all positions are filled")
{
	TicTacToe game;
	game.start_game("X");

	REQUIRE_FALSE(game.game_over());

	const int positions[] = {1, 2, 3, 4, 5, 7, 6, 9, 8};
	const int last_index = sizeof(positions) / sizeof(positions[0]) - 1;

	for (int i = 0; i <= last_index; ++i)
	{
		game.mark_board(positions[i]);
		if (i != last_index)
		{
			REQUIRE_FALSE(game.game_over());
		}
	}

	REQUIRE(game.game_over());
}

