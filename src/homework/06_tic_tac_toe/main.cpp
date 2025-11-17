
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

std::string prompt_player()
{
	std::string player_choice;
	cout << "Enter the first player (X or O): ";
	cin >> player_choice;
	player_choice = normalize_player_input(player_choice);

	while (player_choice != "X" && player_choice != "O")
	{
		cout << "Invalid player. Please enter X or O: ";
		cin >> player_choice;
		player_choice = normalize_player_input(player_choice);
	}

	return player_choice;
}

int prompt_position()
{
	int position = 0;
	cout << "Enter a position (1-9): ";
	cin >> position;

	while (position < 1 || position > 9)
	{
		cout << "Invalid position. Enter a number between 1 and 9: ";
		cin >> position;
	}

	return position;
}

std::string prompt_continue()
{
	std::string choice;
	cout << "Play again? (Y/N): ";
	cin >> choice;
	choice = normalize_player_input(choice);

	while (choice != "Y" && choice != "N")
	{
		cout << "Invalid choice. Enter Y to continue or N to quit: ";
		cin >> choice;
		choice = normalize_player_input(choice);
	}

	return choice;
}
}

int main()
{
	TicTacToe game;
	std::string continue_choice = "Y";

	cout << "Welcome to Tic Tac Toe!" << endl;

	while (continue_choice == "Y")
	{
		const std::string first_player = prompt_player();
		game.start_game(first_player);

		while (!game.game_over())
		{
			cout << "\nCurrent board:\n";
			game.display_board();
			cout << "Player " << game.get_player() << "'s turn." << endl;
			const int position = prompt_position();
			game.mark_board(position);
		}

		cout << "\nFinal board:\n";
		game.display_board();
		const std::string winner = game.get_winner();
		if (winner == "C")
		{
			cout << "It's a tie!" << endl;
		}
		else
		{
			cout << "Player " << winner << " wins!" << endl;
		}

		continue_choice = prompt_continue();
	}

	cout << "Thanks for playing!" << endl;
	return 0;
}