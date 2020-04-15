/*
Programmed By: Jalyn Cosby
Description: A simple tic tac toe game using a 2-D matrix and minor calculations
*/

#include "TTT.h"
#include <fstream>

//function declarations:
void outfile(TTT&);
void descript();
int input();

int main(){
	char option='y';
	int boom=1;

	int opon=X;
	int i=0;;
	
	descript();
	cout << endl;

while (option =='y'|| option =='Y'){		//used to determine is the players would like a rematch 
	//initializes the board:
	TTT();
	TTT game1;
	int decis=0;
	game1.PrintBoard();
	
	while (game1.CheckBoard() == 0){				//loops until somebody has won

	
		cout << endl;
			
		switch (input()){				//in control of managing inputs from user:
			case 2: 
				game1.MakeMove(opon,0,0);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
			break;
			case 3: 
				game1.MakeMove(opon,0,1);
				game1.PrintBoard();
				cout << endl;			
				game1.CheckBoard();
				break;
			case 4:
				game1.MakeMove(opon,0,2);	
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			case 5:
				game1.MakeMove(opon,1,0);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			case 6:
				game1.MakeMove(opon,1,1);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
			break;
			case 7:	
				game1.MakeMove(opon,1,2);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			case 8:
				game1.MakeMove(opon,2,0);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			case 9:
				game1.MakeMove(opon,2,1);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			case 10:
				game1.MakeMove(opon,2,2);
				game1.PrintBoard();
				cout << endl;
				game1.CheckBoard();
				break;
			default:
				cout << "You entered a choice that was not availiable" << endl;
				break;


			boom++;
		}
	}
		cout << "Would You Like to play Again (y/n)? ";
		cin >> option;
		boom =0;
		if (option =='n' || option == 'N'){				//if user enters no the output file is promted and the board is cleared.
			outfile(game1);
			game1.ClearBoard();
		}
	
	}

	return 0;
}
/*
Name: outfile
Description: in control of the output file and it information
Incoming: information for the game being played 
Outgoing:	wins and loss totals 
Return: n/a
*/
void outfile(TTT& game1){
	
	string filename;
	int x_wins=0,o_wins=0,cat_wins=0;
	int x_loss=0,o_loss=0,cat_loss=0;

	ofstream finalfile;
	//opens output file and checks if file is found or not
	finalfile.open("results.txt");
	if(finalfile.fail()){
		cout << "ERROR: File " << filename << "not found" <<endl;
		exit(1);
	}
	//keeps up with the winners and lossers of each game
	if (game1.CheckBoard() ==1){
		x_wins++;
		o_loss++;
		cat_loss ++;
	} else	if (game1.CheckBoard() ==-1){
		o_wins++;
		x_loss++;
		cat_loss++;
	}
	else{
		cat_wins++;
		x_loss++;
		o_loss++;
	}
	
	finalfile << "Players:" << "\t" << "Wins" << "\t" << "Losses" << endl;
	finalfile << "X: " << "\t" << "\t"<< "\t" << x_wins << "\t" << "\t"<< x_loss << endl;
	finalfile << "O: " << "\t" << "\t"<< "\t" << o_wins << "\t"<< "\t" << o_loss << endl;
	finalfile << "Cat:" << "\t" << "\t" << cat_wins << "\t"<< "\t" << cat_loss << endl;
	cout << "File with totals has been sent!" << endl;
	finalfile.close();
}
/*
Name: descript
Description: gives the user information/instructions before the game starts
Incoming: n/a
Outgoing: information
Return: n/a
*/
void descript(){
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "** Description:                                                                     **" << endl;
	cout << "** There are two players (1=X,-1=O). The first one with 3 in a row wins.            **" << endl;
	cout << "** A rematch after each game is allowed. Once you have decided to quit              **" << endl;
	cout << "** the total results will be sent to a file named results.txt                       **" << endl;
	cout << "** GOOD LUCK!!!!!!!!!!!!                                                            **" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "**************************************************************************************" << endl;
}
/*
Name: input
Description: prompts user for choice spot.
Incoming: n/a
Outgoing: information
Return: int of the spot wanted 
*/
int input(){
	int choice;
		cout << "Enter a choice: ";
		cin >> choice; 	
	return choice;
}


	
