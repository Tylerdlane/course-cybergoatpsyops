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
	for (std::size_t i = 0; i < pegs.size(); i += 3)
	{
		std::cout << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << '\n';
		if (i < pegs.size() - 3)
		{
			std::cout << "---------" << '\n';
		}
	}
}

void TicTacToe::set_next_player()
{
	player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_column_win() const
{
	for (int col = 0; col < 3; ++col)
	{
		int index = col;
		if (pegs[index] != " " &&
		    pegs[index] == pegs[index + 3] &&
		    pegs[index] == pegs[index + 6])
		{
			return true;
		}
	}

	return false;
}

bool TicTacToe::check_row_win() const
{
	for (int row = 0; row < 3; ++row)
	{
		int index = row * 3;
		if (pegs[index] != " " &&
		    pegs[index] == pegs[index + 1] &&
		    pegs[index] == pegs[index + 2])
		{
			return true;
		}
	}

	return false;
}

bool TicTacToe::check_diagonal_win() const
{
	if (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8])
	{
		return true;
	}

	if (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6])
	{
		return true;
	}

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