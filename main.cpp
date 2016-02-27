#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct boardPosition
{
	string position_val; 
};

void menu(); //
void displayBoard(boardPosition pos); //displays the tic tac toe board



int main()
{
	boardPosition pos1;
	pos1.position_val = "0";

	displayBoard( pos1 );

	system("pause");
	return 0;
}

void displayBoard(boardPosition pos)
{

	cout << endl << endl;

	for(int i = 0; i < 60; i++)

		
		cout << "-";

	cout << endl; //new row

	for(int k = 0; k < 30; k++) //number of rows for board
	{
		for(int j = 0; j < 60; j++) //number of colums for board
		{
			if(j == 0 || j == 59)
				cout << "|";

			else if(j % 20 == 0)
				cout << "|";

			else
				cout << " ";
		}

		cout << endl; //new row
	}

	cout << endl << endl;
}