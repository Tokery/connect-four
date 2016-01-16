
#include "Master.h"

class Board
{
public:
	Board();

	void insertPiece (int, int, int); //player, column, row
	bool checkColumnFree (int);
	bool checkForWin ();
	void outputBoard ();
	int basic ();
	int intermediate ();
	int advanced ();
	void outputWinner ();
	void readHighscore ();
	void setHighscore ();
	void debug ();
	void turnSimulation (int);
	int miniMax (int, int);
	struct node
	{
		int data;
		struct node* left; //Makes a pointer of type node called left
		struct node* right;
	};
	struct player
	{
		int gamesPlayed;
		string name;
		int gamesWon;
		int gamesLost;
	};
	player MainPlayer; //Makes new player called MainPlayer

private:
	int boardTiles [6][7]; //6 rows, 7 columns
	int tempBoard [6][7]; //Currently not in use
	int columnHeight [7]; //Keeps track of the number of pieces in a column
	string arrayofNames [10];
	int arrayofScores [10];
	int arrayofGames [10];
	int winner;
	int playerNumber;
};