
#include <cctype>
#include <iostream>
#include "tic_tac_toe.h"

using std::cin;
using std::cout;
using std::endl;

namespace
{
std::string normalize_player_input(std::string value)
{
	if (!value.empty())
	{
		value[0] = static_cast<char>(std::toupper(value[0]));
	}
	return value;
}
}

int main()
{
	TicTacToe game;
	std::string continue_choice = "Y";

	while (continue_choice == "Y" || continue_choice == "y")
	{
		std::string first_player;
		cout << "Enter the first player (X or O): ";
		cin >> first_player;
		first_player = normalize_player_input(first_player);

		while (first_player != "X" && first_player != "O")
		{
			cout << "Invalid player. Please enter X or O: ";
			cin >> first_player;
			first_player = normalize_player_input(first_player);
		}

		game.start_game(first_player);

		while (!game.game_over())
		{
			game.display_board();
			int position = 0;
			cout << "Player " << game.get_player() << ", enter a position (1-9): ";
			cin >> position;

			while (position < 1 || position > 9)
			{
				cout << "Invalid position. Enter a number between 1 and 9: ";
				cin >> position;
			}

			game.mark_board(position);
		}

		cout << "\nFinal board:\n";
		game.display_board();
		cout << "Game over! Board is full." << endl;

		cout << "Play again? (Y/N): ";
		cin >> continue_choice;
	}

	cout << "Thanks for playing!" << endl;
	return 0;
}