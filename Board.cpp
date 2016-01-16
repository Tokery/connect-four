#include "Board.h"

Board::Board ()
{
	for (int rows = 0; rows < 6; rows++) //Set all board tiles to zero
	{
		for (int columns = 0; columns < 7; columns++)
		{
			boardTiles [rows] [columns] = 0;
		}
	}
	for (int columns = 0; columns <= 7; columns++)
	{
		columnHeight [columns] = 5;
	}

	int advancedRepeat = 0;
}

bool Board::checkColumnFree (int column) 
{
	if (columnHeight [column] <= 0)
	{
		cout << "Fail: Column height is " << columnHeight [column] << endl;
		return false;
	}
	cout << "Column height is " << columnHeight [column] << endl;
	return true;
}

void Board::insertPiece (int player, int column, int row)
{
	if (columnHeight [column] >= 0) //Checks that the column is not full (if it is smaller than one than there are too many pieces)
	{
		boardTiles [columnHeight [column]] [column] = player;
		columnHeight [column] = columnHeight [column] - 1;
		cout << "Column " << column << " lowered to " << columnHeight [column] << endl;
	}

}

bool Board::checkForWin ()
{
	//Check vertical win
	int player1 = 0; //Keeps track of where players are
	int player2 = 0;
	for (int columns = 0; columns < 7; columns++) //Checks column by column
	{
		player1 = 0;
		player2 = 0;
		for (int rows = 0; rows < 6; rows++) //Checks the rows in each column
		{
			if (boardTiles [rows] [columns] == 1)
			{
				player1++;
				player2 = 0;
				if (player1 >= 4)
				{
					winner = 1;
					return true;
				}
			}
			else if (boardTiles [rows] [columns] == 2 || boardTiles [rows] [columns] == 3)
			{
				player2++;
				player1 = 0;
				if (player2 >= 4)
				{
					winner = 2;
					return true;
				}
			}
			else //If there is no piece
			{
				player1 = 0;
				player2 = 0;
			}
			if (player1 != 0 || player2 != 0)
			{
				//cout << "Player 1 in  " << columns << " has " << player1 << endl;
				//cout  << "Player 2 in " << columns << " has " << player2 << endl;
			}
		}

	}


	//Check for diagonal wins

	int up = -1;
	int down = 1;
	int right = 1;
	int left = -1;
	player1 = 0;
	player2 = 0;
	for (int startColumns = 3; startColumns >= -1; startColumns--) //Diagonals 1 to 4
	{
		int row = 6;
		int column = startColumns;
		player1 = 0; //How many tiles each player owns
		player2 = 0;
		do
		{
			if (boardTiles [row] [column] == 1) //If board piece is player 1
			{
				player1++;
				player2 = 0;
				if (player1 >= 4)
				{

					winner = 1;
					return true;
				}
			}
			else if (boardTiles [row] [column] == 2 || boardTiles [row] [column] == 3)
			{
				player2++;
				player1 = 0;
				if (player2 >= 4)
				{
					winner = 2;
					return true;
				}
			}
			//cout << "Finished checking for one\n";
			row += up;
			column += right;
			if (row >= 6 || column >= 7) //Exit condition 
			{
				break;
			}
		}
		while (true);
	}
	for (int startRows = 1; startRows <= 2; startRows++) //Diagonals 5 & 6
	{
		int row = startRows;
		int column = -1;
		player1 = 0;
		player2 = 0;
		do 
		{
			if (boardTiles [row] [column] == 1)
			{
				player1++;
				player2 = 0;
				if (player1 >= 4)
				{
					winner = 1;
					return true;
				}
			}
			if (boardTiles [row] [column] == 2 || boardTiles [row] [column] == 3)
			{
				player2++;
				player1 = 0;
				if (player1 >= 4)
				{
					winner = 2;
					return true;
				}
			}
			row += up;
			column += right;
			if (row < 0 || column >= 7)
				break;
		}
		while (true);
	}
	player1 = 0;
	player2 = 0;
	for (int startRows = 1; startRows <= 3; startRows++) //Diagonals 7 & 8
	{
		int row = startRows;
		int column = -1;
		player1 = 0;
		player2 = 0;
		do 
		{
			if (boardTiles [row] [column] == 1)
			{
				player1++;
				player2 = 0;
				if (player1 >= 4)
				{
					winner = 1;
					return true;
				}
			}
			if (boardTiles [row] [column] == 2)
			{
				player2++;
				player1 = 0;
				if (player1 >= 4)
				{
					winner = 2;
					return true;
				}
			}
			row += down;
			column += right;
			if (row <= -1 || column > 7)
				break;
		}
		while (true);
	}
	player1 = 0;
	player2 = 0;
	for (int startColumns = 6; startColumns >= 4; startColumns--) //Diagonals 9 to 12
	{
		int row = 0;
		int column = startColumns;
		player1 = 0;
		player2 = 0;
		do
		{
			if (boardTiles [row] [column] == 1)
			{
				player1++;
				player2 = 0;
				if (player1 >= 4)
				{
					winner = 1;
					return true;
				}
			}
			else if (boardTiles [row] [column] == 2 || boardTiles [row] [column] == 3)
			{
				player2++;
				player1 = 0;
				if (player1 >= 4)
				{
					winner = 2;
					return true;
				}
			}

			row += down;
			column += right;
			if (row <= - 1 || column >= 7) //Exit condition
				break;
		}
		while (true);
	}


	//Check for horizontal win
	int player1Count = 0;
	int player2Count = 0;
	for (int row = 5; row >= 0; row--)
	{
		player1Count = 0; //Variables must return to 0 for each new row
		player2Count = 0; 
		for (int column = 0; column < 7; column++)
		{
			if (boardTiles [row] [column] == 1)
			{
				player1Count++;
				player2Count = 0;
				if (player1Count >= 4)
				{
					winner = 1;
					return true;
				}
			}
			else if (boardTiles [row] [column] == 2 || boardTiles [row] [column] == 3)
			{
				player2Count++;
				player1Count = 0;
				if (player2Count >= 4)
				{
					winner = 2;
					return true;
				}
			}
			else
			{
				player1Count = 0;
				player2Count = 0;
			}
		}


	}
	return false;
}

void Board::outputBoard ()
{
	//cout << "1 2 3 4 5 6 7 Columns\n\n";
	/*for (int rows = 0; rows < 6; rows++)
	{
	for (int columns = 0; columns < 7; columns++)
	{
	cout << boardTiles [rows] [columns] << " ";
	}
	cout << endl;
	}*/
	cout << " 1   2   3   4   5   6   7\n";
	for(int a = 0; a <= 5; a++) //For each row
	{
		for(int b = 0; b <= 6; b++) //For each column
			cout << char(218) << char(196) << char(191) << " ";
		cout << endl;

		for(int b = 0; b <= 6; b++)
		{
			cout << char(179);
			if (boardTiles [a] [b] == 0)
				cout << " ";
			else 
				cout << boardTiles [a] [b];
			cout << char(179) << " ";
		}
		cout << endl;

		for (int b = 0; b <= 6; b++)
			cout << char(192) << char(196) << char(217) << " ";
		cout << endl;
	}

}

int Board::basic () //Chooses the drop zone by choosing the tallest column
{
	int bestMove; //Chooses which column to go into
	int columnRating [7] = {0,0,0,0,0,0,0};
	int largest = -1;
	int largeHolder;
	for (int columns = 0; columns < 7; columns++)
	{
		if (boardTiles [columnHeight [columns]] [columns] == 1) //If the opponent has piece there
		{
			columnRating [columns] += 6;
		}
		for (int sorter = 0; sorter < 7; sorter++) //Sort from highest to lowest
		{
			if (columnHeight [sorter] > largest && columnHeight [sorter] < 5)
			{
				largest = columnHeight [sorter];
				columnRating [sorter]++;
			}
		}

	}
	largest = -1;
	for (int sorter = 0; sorter < 7; sorter++) //Find the highest rated column
	{
		if (columnRating [sorter] > largest)
		{
			largest = columnRating [sorter];
			largeHolder = sorter;
		}
	}
	bestMove = largeHolder;
	srand (time(NULL));


	bestMove = rand () % 8;


	return bestMove;
}

int Board::intermediate () //Finds drop zone by looking one move ahead
{
	int bestMove;
	int columnRating [7] = {0,0,0,0,0,0,0};
	for (int columns = 0; columns < 7; columns++) //Column per column (Vertical)
	{
		for (int rows = 0; rows < 6; rows++)
		{
			if (boardTiles [rows] [columns + 1] == 1 && columns != 5) //If piece next to it is the opponents
				columnRating [columns]++;
			if (boardTiles [rows] [columns - 1] == 1 && columns != 0)
				columnRating [columns]++;
			if (boardTiles [rows + 1] [columns] == 1 && rows != 6)
				columnRating [columns]++;
			if (boardTiles [rows - 1] [columns] == 1 && rows != 0)
				columnRating [columns]++;
		}
	}
	int largest = 0;
	int largeHolder;
	for (int sorter = 0; sorter < 7; sorter++) //Find the highest rated column
	{
		if (columnRating [sorter] > largest)
		{
			largest = columnRating [sorter];
			largeHolder = sorter;
		}
	}
	bestMove = largeHolder;
	return bestMove;
}

int Board::advanced ()
{

	int advancedBestMove;
	int columnRating [7] = {0,0,0,0,0,0,0};
	int rowToCheck; //Keeps track of how tall the column is and holds this value instead of using variable columnHeight


	for (int columns = 0; columns < 7; columns++)
	{
		rowToCheck = columnHeight [columns]; //Keeps track of which row the piece would fall on
		if (boardTiles [rowToCheck + 1] [columns] == 1) //If piece to the right is the enemy
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck + 2] [columns] == 1)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck + 3] [columns] == 1)
					columnRating [columns] += 5;
			}
		}
		if (boardTiles [rowToCheck - 1] [columns] == 1) //If piece to the left is the enemy
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck - 2] [columns] == 1)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck - 3] [columns] == 1)
					columnRating [columns] += 5;
			}
		}
		if (boardTiles [rowToCheck] [columns + 1] == 1) //If piece below it is the enemy
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck] [columns + 2] == 1)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck] [columns + 3] == 1)
					columnRating [columns] += 5;
			}
		}
		if (boardTiles [rowToCheck] [columns - 1] == 1) //If piece above it is the enemy
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck] [columns - 2] == 1)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck] [columns -3] == 1)
					columnRating [columns] += 5;
			}
		}
	}
	for (int columns = 0; columns < 7; columns++)
	{
		rowToCheck = columnHeight [columns]; //Keeps track of which row the piece would fall on
		if (boardTiles [rowToCheck + 1] [columns] == 2) //If piece to the right is the itself
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck + 2] [columns] == 2)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck + 3] [columns] == 2)
					columnRating [columns] += 10;
			}
		}
		if (boardTiles [rowToCheck - 1] [columns] == 2) //If piece to the left is itself
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck - 2] [columns] == 2)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck - 3] [columns] == 2)
					columnRating [columns] += 10;
			}
		}
		if (boardTiles [rowToCheck] [columns + 1] == 2) //If piece below it is itself
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck] [columns + 2] == 2)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck] [columns + 3] == 2)
					columnRating [columns] += 10;
			}
		}
		if (boardTiles [rowToCheck] [columns - 1] == 2) //If piece above it is the enemy
		{
			columnRating [columns]++;
			if (boardTiles [rowToCheck] [columns - 2] == 2)
			{
				columnRating [columns] += 3;
				if (boardTiles [rowToCheck] [columns -3] == 2)
					columnRating [columns] += 10;
			}
		}
	}

	//Start of sorting algorithm to find best column
	int largest = 0;

	for (int possibleMove = 0; possibleMove < 7; possibleMove++)
	{
		//cout << "Column " << possibleMove << " rating " << columnRating [possibleMove] << endl;
		if (columnRating [possibleMove] > largest)
		{
			advancedBestMove = possibleMove;
			largest = columnRating [possibleMove];
		}
	}
	return advancedBestMove;
}

void Board:: turnSimulation (int player)
{
	int bestMove;


}

int Board::miniMax(int player, int layer)
{
	/*int bestColumn;
	if (layer == 0)
	return bestColumn;
	for each (node data in node ())
	{

	}*/
	int bestColumn;
	int columns [7] = {0,0,0,0,0,0,0};
	if (layer == 0)
		return bestColumn;
	else
	{
		if (player == 2)
		{
			bestColumn = -1;
			for (int columns = 0; columns < 7; columns++)
			{

			}
		}
		else //If player is 1
		{

		}
	}
}

void maxMove ()
{

}


void Board::outputWinner ()
{
	cout << "The winner is " << winner << endl;
}

void Board::readHighscore ()
{
	ifstream myFile; //Input file selection
	string highscore;
	myFile.open ("Highscores.txt");


	int count = 0;

	if (myFile.is_open ())
	{
		while (getline (myFile, arrayofNames [count]))
		{
			//cout << "Name: " << name << endl;
			//getline (myFile, arrayofScores [count]);
			myFile >> arrayofScores [count];
			//cout << "Score is " << score << endl;
			//getline (myFile, arrayofGames [count]);
			myFile >> arrayofGames [count];
			//cout << "Games played: " << gamesPlayed << endl;
			count++;
		}
		myFile.close();
	}
	else 
		std::cout << "Error opening file\n";

	cout << "Please enter your name\n";
	string userName;
	cin >> userName;
	

	


	for (int i = 0; i < 10; i++) //Search for name
	{
		if (arrayofNames [i] == userName)
		{
			cout << "Player exists\n";
			playerNumber = i;
			cout << "You have won " << arrayofScores [playerNumber] << " out of " << arrayofGames [playerNumber] << " games" << endl;
			MainPlayer.name = arrayofNames [playerNumber];
			MainPlayer.gamesPlayed = arrayofGames [playerNumber]; //stoi changes string to int
			MainPlayer.gamesWon = arrayofScores [playerNumber];
			break;
		}
		else
		{
			//cout << "An account has been made under the name " << userName << endl; //Player does not exist
			MainPlayer.name = userName;
			MainPlayer.gamesPlayed = 0;
			MainPlayer.gamesWon = 0;
		}
	}

}

void Board::setHighscore ()
{
	ofstream myFile ("Highscores.txt"); //Output selection mode

	MainPlayer.gamesPlayed++;
	if (winner == 1)
	{
		MainPlayer.gamesWon++;
	}

	arrayofGames [playerNumber] = MainPlayer.gamesPlayed;
	arrayofScores [playerNumber] = MainPlayer.gamesWon;

	if (myFile.is_open())
	{
	for (int names = 0; names < 10; names++)
		{
			myFile << arrayofNames [names] << endl;
			myFile << arrayofScores [names] << endl;
			myFile << arrayofGames [names] << endl;
		}
		//myFile << MainPlayer.name << endl;
		//myFile << MainPlayer.gamesWon << endl;
		//myFile << MainPlayer.gamesPlayed << endl;
		myFile.close();
	}
	else
		cout << "Error opening file\n";
}

void Board::debug ()
{

}