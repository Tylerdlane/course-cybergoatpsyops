#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>

class TicTacToe
{
public:
	TicTacToe(int size) : pegs(size * size, " "), board_size(size) {}
	virtual ~TicTacToe() = default;
	bool game_over();
	void start_game(std::string first_player);
	void mark_board(int position);
	std::string get_player() const;
	virtual void display_board() const;
	std::string get_winner() const;

protected:
	virtual bool check_column_win() const;
	virtual bool check_row_win() const;
	virtual bool check_diagonal_win() const;
	std::vector<std::string> pegs;
	int board_size;

private:
	void set_winner();
	void set_next_player();
	bool check_board_full() const;
	void clear_board();

	std::string player;
	std::string winner;
};

#endif