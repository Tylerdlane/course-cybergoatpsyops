#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

#include <vector>

namespace
{
void play_sequence_and_verify(TicTacToe& game, const std::vector<int>& moves, const std::string& expected_winner)
{
	for (std::size_t i = 0; i < moves.size(); ++i)
	{
		game.mark_board(moves[i]);
		bool over = game.game_over();
		if (i < moves.size() - 1)
		{
			REQUIRE_FALSE(over);
		}
		else
		{
			REQUIRE(over);
			REQUIRE(game.get_winner() == expected_winner);
		}
	}
}
}

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test tie when all positions are filled")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {1, 2, 3, 4, 5, 7, 6, 9, 8}, "C");
}

TEST_CASE("Test win by first column")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {1, 2, 4, 5, 7}, "X");
}

TEST_CASE("Test win by second column")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {2, 1, 5, 3, 8}, "X");
}

TEST_CASE("Test win by third column")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {3, 1, 6, 2, 9}, "X");
}

TEST_CASE("Test win by first row")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {1, 4, 2, 5, 3}, "X");
}

TEST_CASE("Test win by second row")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {4, 1, 5, 2, 6}, "X");
}

TEST_CASE("Test win by third row")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {7, 1, 8, 2, 9}, "X");
}

TEST_CASE("Test win diagonally from top left")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {1, 2, 5, 3, 9}, "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
	TicTacToe game;
	game.start_game("X");
	play_sequence_and_verify(game, {7, 1, 5, 2, 3}, "X");
}

