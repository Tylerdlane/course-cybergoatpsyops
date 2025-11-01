#include "tic_tac_toe.h"

#include <iostream>
#include <algorithm>
#include <cctype>

bool TicTacToe::game_over()
{
	return check_board_full();
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
}