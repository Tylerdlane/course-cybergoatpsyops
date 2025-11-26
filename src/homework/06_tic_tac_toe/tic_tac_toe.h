#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <iostream>

class TicTacToe
{
public:
    TicTacToe() = default;

    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }

    // I/O operator overloads
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    std::vector<std::string> pegs{9, " "};
    std::string player;
    std::string winner;

    void set_next_player();
    bool check_board_full();
    void clear_board();

    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();

    void set_winner(std::string);
};

#endif


