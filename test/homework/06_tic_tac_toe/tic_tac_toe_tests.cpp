#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

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

TEST_CASE("Test manager get winner total")
{
	TicTacToeManager manager;
	TicTacToe game1, game2, game3, game4;

	// Game 1: X wins
	game1.start_game("X");
	game1.mark_board(1);  // X
	game1.mark_board(2);  // O
	game1.mark_board(4);  // X
	game1.mark_board(5);  // O
	game1.mark_board(7);  // X wins
	REQUIRE(game1.game_over() == true);
	REQUIRE(game1.get_winner() == "X");
	manager.save_game(game1);

	// Game 2: O wins
	game2.start_game("O");
	game2.mark_board(1);  // O
	game2.mark_board(2);  // X
	game2.mark_board(5);  // O
	game2.mark_board(3);  // X
	game2.mark_board(9);  // O wins
	REQUIRE(game2.game_over() == true);
	REQUIRE(game2.get_winner() == "O");
	manager.save_game(game2);

	// Game 3: Tie
	game3.start_game("X");
	game3.mark_board(1);  // X
	game3.mark_board(2);  // O
	game3.mark_board(3);  // X
	game3.mark_board(4);  // O
	game3.mark_board(5);  // X
	game3.mark_board(7);  // O
	game3.mark_board(6);  // X
	game3.mark_board(9);  // O
	game3.mark_board(8);  // X - tie
	REQUIRE(game3.game_over() == true);
	REQUIRE(game3.get_winner() == "C");
	manager.save_game(game3);

	// Game 4: X wins again
	game4.start_game("X");
	game4.mark_board(1);  // X
	game4.mark_board(3);  // O
	game4.mark_board(5);  // X
	game4.mark_board(6);  // O
	game4.mark_board(9);  // X wins
	REQUIRE(game4.game_over() == true);
	REQUIRE(game4.get_winner() == "X");
	manager.save_game(game4);

	int o_wins = 0, x_wins = 0, ties = 0;
	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(x_wins == 2);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);
}

