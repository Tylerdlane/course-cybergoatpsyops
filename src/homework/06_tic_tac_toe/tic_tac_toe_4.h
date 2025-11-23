#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe
{
public:
	TicTacToe4() : TicTacToe(4) {}

private:
	bool check_column_win() const override;
	bool check_row_win() const override;
	bool check_diagonal_win() const override;
};

#endif