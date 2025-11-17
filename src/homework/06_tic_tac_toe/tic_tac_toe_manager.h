#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>

class TicTacToeManager
{
public:
	void save_game(TicTacToe b);
	void get_winner_total(int& o, int& w, int& t) const;

private:
	void update_winner_count(std::string winner);
	
	std::vector<TicTacToe> games;
	int x_win = 0;
	int o_win = 0;
	int ties = 0;
};

#endif