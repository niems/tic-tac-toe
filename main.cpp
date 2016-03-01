#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void menu(); //
void displayBoard( const vector<string> &board_positions ); //displays the tic tac toe board
void boardInitialize( vector<string> &board_positions, vector<string> &symbols ); //initializes the board with values for the user to play at

void newGame( vector<string> &board_positions, vector<string> &symbols ); //starts a new game against the computer
bool boardMoveCheck( vector<string> &board_positions, int pos ); //returns true if the position can be played

enum PLAYER{ COMPUTER, USER };

string float_to_string(float f)
{
	std::stringstream stream;

	stream << f;
	return stream.str();
}



int main()
{
	vector<string> symbols; //symbols used on the board( 'X' and 'O' )
	vector<string> board_positions; //

	newGame( board_positions, symbols );

	system("pause");
	return 0;
}

void displayBoard( const vector<string> &board_positions )
{
	int pos = 0;

	for(int i = 0; i < 3; i++) //number of rows
	{
		cout << board_positions[ pos++ ] << " | " << board_positions[ pos++ ] << " | " << board_positions[ pos++ ] << endl;

		if( i < 2 )
		{
			for(int j = 0; j < 9; j++)
			{
				cout << "-";
			}

			cout << endl;
		}
	}

	cout << endl << endl;
}

void boardInitialize( vector<string> &board_positions, vector<string> &symbols )
{
	symbols.push_back("O"); //computer
	symbols.push_back("X"); //user

	for(int i = 0; i < 9; i++)
	{
			board_positions.push_back( float_to_string(i) );
	}
}

void newGame( vector<string> &board_positions, vector<string> &symbols )
{
	string winner = "no winner"; //user plays until there is a winner
	PLAYER player = PLAYER::USER; //determines who goes first
	int position = 1; //position played on the board

	boardInitialize( board_positions, symbols ); //assigns default values to the board

	do
	{
		displayBoard( board_positions ); //displays the board for the user

		cout << "Enter where to play (0 - 8): ";
		cin >> position;

		cout << endl << endl;

		if( boardMoveCheck( board_positions, position ) ) //if the position can be played at
		{
			board_positions[position] = symbols[player]; //assigns the player's symbol to the chosen board position 

			//check if the current player won
		}

		else
			cout << "INVALID POSITION" << endl << endl;
		

	}while( winner == "no winner" );
}

//returns true if the position can be played
bool boardMoveCheck( vector<string> &board_positions, int pos )
{
	if( pos < 0 || pos >= board_positions.size() )
		return false; //out of range

	else if( board_positions[pos] == "O" || board_positions[pos] == "X" )
		return false; //this position cannot be played at

	return true; //this position can be played at
}