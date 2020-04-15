#include <iostream>

#define E 0
#define X 1
#define O -1
using namespace std;


class TTT{

	short board[3][3];// each item should always have the value 0,1, or -1
	int turn; // always start with X

public:
	TTT(); // initialize board

	void ClearBoard(); // reinitialize board

	short CheckBoard()const; // decide if game is over, return winner number
							 // X, O, Cat, or noone (game isn't over)

	bool MakeMove(short player, int r, int c);
							 // true if move is available
							 // false if move is unavailable

	void PrintBoard()const;  // print board in TTT format
					
};