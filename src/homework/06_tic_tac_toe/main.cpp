
#include <cctype>
#include <iostream>
#include <memory>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

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

int prompt_game_type()
{
	int game_type = 0;
	cout << "Select game type (3 for 3x3, 4 for 4x4): ";
	cin >> game_type;

	while (game_type != 3 && game_type != 4)
	{
		cout << "Invalid game type. Enter 3 or 4: ";
		cin >> game_type;
	}

	return game_type;
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

int prompt_position(int max_position)
{
	int position = 0;
	cout << "Enter a position (1-" << max_position << "): ";
	cin >> position;

	while (position < 1 || position > max_position)
	{
		cout << "Invalid position. Enter a number between 1 and " << max_position << ": ";
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
	TicTacToeManager manager;
	std::string continue_choice = "Y";

	cout << "Welcome to Tic Tac Toe!" << endl;

	while (continue_choice == "Y")
	{
		const int game_type = prompt_game_type();
		std::unique_ptr<TicTacToe> game;

		if (game_type == 3)
		{
			game = std::make_unique<TicTacToe3>();
		}
		else
		{
			game = std::make_unique<TicTacToe4>();
		}

		const int max_position = (game_type == 3) ? 9 : 16;

		const std::string first_player = prompt_player();
		game->start_game(first_player);

		while (!game->game_over())
		{
			cout << "\nCurrent board:\n";
			game->display_board();
			cout << "Player " << game->get_player() << "'s turn." << endl;
			const int position = prompt_position(max_position);
			game->mark_board(position);
		}

		cout << "\nFinal board:\n";
		game->display_board();
		const std::string winner = game->get_winner();
		if (winner == "C")
		{
			cout << "It's a tie!" << endl;
		}
		else
		{
			cout << "Player " << winner << " wins!" << endl;
		}

		manager.save_game(game);

		int o_wins = 0, x_wins = 0, tie_count = 0;
		manager.get_winner_total(o_wins, x_wins, tie_count);
		cout << "\nGame Totals:" << endl;
		cout << "X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << tie_count << endl;

		continue_choice = prompt_continue();
	}

	cout << "\nAll games played:" << endl;
	manager.display();

	cout << "Thanks for playing!" << endl;
	return 0;
}