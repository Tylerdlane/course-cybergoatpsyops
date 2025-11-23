#include "tic_tac_toe_4.h"

bool TicTacToe4::check_column_win() const
{
	for (int col = 0; col < 4; ++col)
	{
		int index = col;
		if (pegs[index] != " " &&
		    pegs[index] == pegs[index + 4] &&
		    pegs[index] == pegs[index + 8] &&
		    pegs[index] == pegs[index + 12])
		{
			return true;
		}
	}

	return false;
}

bool TicTacToe4::check_row_win() const
{
	for (int row = 0; row < 4; ++row)
	{
		int index = row * 4;
		if (pegs[index] != " " &&
		    pegs[index] == pegs[index + 1] &&
		    pegs[index] == pegs[index + 2] &&
		    pegs[index] == pegs[index + 3])
		{
			return true;
		}
	}

	return false;
}

bool TicTacToe4::check_diagonal_win() const
{
	if (pegs[0] != " " && pegs[0] == pegs[5] && pegs[0] == pegs[10] && pegs[0] == pegs[15])
	{
		return true;
	}

	if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[3] == pegs[9] && pegs[3] == pegs[12])
	{
		return true;
	}

	return false;
}
