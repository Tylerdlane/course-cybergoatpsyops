#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win() const
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

bool TicTacToe3::check_row_win() const
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

bool TicTacToe3::check_diagonal_win() const
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
