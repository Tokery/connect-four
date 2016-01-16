//ICS3UI
//Created by: Kevin Cottington and Rakshith Gangireddy
//April 24, 2014
//Connect 4 game with 3 levels of difficulty

#include "Board.h"
#include "Readtype.h"
using std::cout;

void twoPlayerMode (int player);
int repeats = 0;
Board gameBoard;


int main()
{
	cout << "Welcome to Connect 4!\n\n";


	int gameMode;
	cout << "Do you want to play against another human or the computer?\n";
	cout << "Enter 1 for hotseat or 2 for computer\n";
	std::cin >> gameMode;

	//gameBoard.readHighscore ();

	if (gameMode == 1) //Two players
	{
		twoPlayerMode (1);
	}
	else if (gameMode == 2) //AI
	{
		int columnChoice;
		int difficulty;
		do
		{
			cout << "Please choose your difficulty (1, 2 or 3)\n";
			cin >> difficulty;

			if (difficulty >= 1 && difficulty <= 3) //Checks for valid input
				break;

		} while (true);
		switch (difficulty)
		{


		case 1:
			{
				do //Input selection mode
				{
					system ("cls");
					gameBoard.outputBoard ();
					columnChoice = ReadType<int> ("Which column would you like to drop into?\n"); //Checks for valid input and takes input
					if (columnChoice == -1)
						break;
					gameBoard.insertPiece (1, columnChoice - 1, 0); //Player, column, row (row is a dummy)
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
					gameBoard.insertPiece (2, gameBoard.basic (), 0);
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
				}
				while (true);
				break;
			}
		case 2:
			{
				do //Input selection mode
				{
					system ("cls");
					gameBoard.outputBoard ();
					columnChoice = ReadType<int> ("Which column would you like to drop into?\n"); //Checks for valid input and takes input
					if (columnChoice == -1)
						break;
					gameBoard.insertPiece (1, columnChoice - 1, 0); //Player, column, row (row is a dummy)
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
					gameBoard.insertPiece (2, gameBoard.intermediate (), 0);
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
				}
				while (true);
				break;
			}
		case 3:
			{
				do //Input selection mode
				{
					bool repeat = true;
					system ("cls");
					gameBoard.outputBoard ();
					while (repeat)
					{
						columnChoice = ReadType<int> ("Which column would you like to drop into?\n"); //Checks for valid input and takes input
						if (gameBoard.checkColumnFree (columnChoice))
						{
							repeat = false;
							cout << "Column is full\n";
						}
						if (columnChoice == -1)
							break;
					}
					gameBoard.insertPiece (1, columnChoice - 1, 0); //Player, column, row (row is a dummy)
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
					gameBoard.insertPiece (2, gameBoard.advanced (), 0);
					system ("cls");
					gameBoard.outputBoard ();
					if (gameBoard.checkForWin ())
						break;
				}
				while (true);
				break;
			}
		default:
			{
				cout << "Invalid input! Enter any key to continue\n";
				getchar ();
				break;
			}
		}

	}

	gameBoard.outputWinner ();
	//gameBoard.setHighscore ();
	string dummyString;
	cout << "The game has ended. Enter your final words\n";
	std::cin >> dummyString;


	return 0;
}

void twoPlayerMode (int player) //Recursive input function
{

	int columnChoice;

	int opposite;

	system ("cls");
	gameBoard.outputBoard ();
	cout << "Player " << player << " ";
	bool repeat = true;
	while (repeat)
	{
		columnChoice = ReadType<int> ("Which column would you like to drop into?\n"); //Checks for valid input and takes input
		if (gameBoard.checkColumnFree (columnChoice) == true)
			repeat = false;
		if (columnChoice == -1)
			break;
	}
	gameBoard.insertPiece (player, columnChoice - 1, 0);
	system ("cls");
	gameBoard.outputBoard ();
	if (gameBoard.checkForWin ())
		return;
	if (player == 1)
		opposite = 2;
	else if (player == 2)
		opposite = 1;
	twoPlayerMode (opposite);

	return;
}