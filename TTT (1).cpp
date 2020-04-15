#include "TTT.h"
/*
Name: TTT()
Description: Constructor initializes the matrix
Incoming: 2-D array board and turn
Outgoing: n/a
Return: n/a
*/
TTT::TTT(){
	//hard coded values into the matrix
	int temp[3][3] = {2,3,4,5,6,7,8,9,10};
	
	for (int r=0; r<3; r++)
		for(int c=0; c<3; c++)
			board[r][c] = temp[r][c];
	
}
/*
Name: ClearBoard
Description: resets matrix
Incoming: 2-D array board and turn
Outgoing: information
Return: n/a
*/
void TTT::ClearBoard(){
	//resets the board back to the beginning in case of a new game wanted
	
	int temp[3][3] = {2,3,4,5,6,7,8,9,10};
	for (int r=0; r<3; r++)
		for(int c=0; c<3; c++)
			board[r][c]= temp[r][c];
	 
}
/*
Name: CheckBoard
Description: Checks if there has been a winner
Incoming:  2-D array board and turn
Outgoing: n/a
Return: int X,O, or 0 depending on the winner
*/
short TTT::CheckBoard()const{
	
	int check=0;

	while (check==0){
	//searches each possible chance for a win and returns the value of the winner if found. if not found 
	//it return the value of the cat
		if (board[0][0]== X && board[0][1] == X && board[0][2] == X){
			check=1;
		}else if (board[1][0]== X && board[1][1] == X && board[1][2] == X){
			check = 1;
		}else if (board[2][0]== X && board[2][1] == X && board[2][2] == X){
			check = 1;
		}else if (board[0][0]== X && board[1][0] == X && board[2][0] == X){
			check = 1;
		}else if (board[0][1]== X && board[1][1] == X && board[1][2] == X){
			check = 1;
		}else if (board[0][2]== X && board[1][2] == X && board[2][2] == X){
			check = 1;
		}else if (board[0][0]== X && board[1][1] == X && board[2][2] == X){
			check = 1;
		}else if (board[0][2]== X && board[1][1] == X && board[2][0] == X){
			check = 1;
		}else if (board[0][0]== O && board[0][1] == O && board[0][2] == O){
			check=-1;
		}else if (board[1][0]== O && board[1][1] == O && board[1][2] == O){
			check = -1;
		}else if (board[2][0]== O && board[2][1] == O && board[2][2] == O){
			check = -1;
		}else if (board[0][0]== O && board[1][0] == O && board[2][0] == O){
			check = -1;
		}else if (board[0][1]== O && board[1][1] == O && board[1][2] == O){
			check = -1;
		}else if (board[0][2]== O && board[1][2] == O && board[2][2] == O){
				check = -1;
		}else if (board[0][0]== O && board[1][1] == O && board[2][2] == O){
			check = -1;
		}else if (board[0][2]== O && board[1][1] == O && board[2][0] == O){
			check = -1;
		}
	return check;
	}
}/*
Name: MakeMove
Description: Checks to make sure players move is acceptable 
Incoming:  player, a row and a column for the move in board[][]
Outgoing: n/a
Return: true or false depending on if mood if availiable 
*/
bool TTT::MakeMove(short  player, int r, int c){

	bool pass =false;
	
	//used to toggle the player 
	if (turn == 1){		
		player =-1;
		turn *= -1;
	}
	else if (turn == -1){
		player = 1;
		turn = turn *-1;
	}
	
	//checks if the move the player selected is available or if its already taken
	//by another player if it is not  the function returns true. else it returns false 
	if (board[r][c]!=X && board[r][c] != O){
		board[r][c] =player;
		pass = true;
	}
	else 
		cout << "That spot is already taken" << endl;
	return pass;




}
/*
Name: PrintBoard
Description:output contents of the board[][] matrix
Incoming:  2-D array board and turn
Outgoing: 2-D Array
Return: n/a
*/
void TTT::PrintBoard()const{
	//used to print the matrix of the board the user will be using
		for (int r=0; r<3; r++){
			for(int c=0; c<3; c++)
				cout << board[r][c] << "|";
		cout << endl;
		}
}
