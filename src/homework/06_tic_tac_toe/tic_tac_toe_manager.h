#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>
#include <memory>

class TicTacToeManager
{
public:
	void save_game(std::unique_ptr<TicTacToe>& b);
	void get_winner_total(int& o, int& w, int& t) const;
	void display() const;

private:
	void update_winner_count(std::string winner);
	
	std::vector<std::unique_ptr<TicTacToe>> games;
	int x_win = 0;
	int o_win = 0;
	int ties = 0;
};

#endif