#include "tic_tac_toe.h"

#include <iostream>
#include <algorithm>
#include <cctype>

bool TicTacToe::game_over()
{
	if (check_column_win() || check_row_win() || check_diagonal_win())
	{
		set_winner();
		return true;
	}

	if (check_board_full())
	{
		winner = "C";
		return true;
	}

	return false;
}

void TicTacToe::start_game(std::string first_player)
{
	if (!first_player.empty())
	{
		first_player[0] = static_cast<char>(std::toupper(first_player[0]));
	}

	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
	}
	else
	{
		player = "X";
	}

	clear_board();
	winner.clear();
}

void TicTacToe::mark_board(int position)
{
	if (position >= 1 && position <= static_cast<int>(pegs.size()))
	{
		pegs[position - 1] = player;
		set_next_player();
	}
}

std::string TicTacToe::get_player() const
{
	return player;
}

std::string TicTacToe::get_winner() const
{
	return winner;
}

void TicTacToe::display_board() const
{
	for (std::size_t i = 0; i < pegs.size(); i += board_size)
	{
		std::cout << pegs[i];
		for (int j = 1; j < board_size; ++j)
		{
			std::cout << " | " << pegs[i + j];
		}
		std::cout << '\n';
		if (i < pegs.size() - board_size)
		{
			for (int j = 0; j < board_size * 2 + (board_size - 1); ++j)
			{
				std::cout << '-';
			}
			std::cout << '\n';
		}
	}
}

void TicTacToe::set_next_player()
{
	player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_column_win() const
{
	return false;
}

bool TicTacToe::check_row_win() const
{
	return false;
}

bool TicTacToe::check_diagonal_win() const
{
	return false;
}

bool TicTacToe::check_board_full() const
{
	for (const auto& peg : pegs)
	{
		if (peg == " ")
		{
			return false;
		}
	}

	return true;
}

void TicTacToe::clear_board()
{
	std::fill(pegs.begin(), pegs.end(), " ");
	winner.clear();
}

void TicTacToe::set_winner()
{
	winner = (player == "X") ? "O" : "X";
}