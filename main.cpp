#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void menu(); //
void displayBoard( const vector<string> &board_positions ); //displays the tic tac toe board
void boardInitialize( vector<string> &board_positions );

string float_to_string(float f)
{
	std::stringstream stream;

	stream << f;

	return stream.str();
}

int main()
{
	vector<string> board_positions;

	boardInitialize( board_positions );
	displayBoard( board_positions );

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

void boardInitialize( vector<string> &board_positions )
{
	for(int i = 0; i < 9; i++)
	{
			board_positions.push_back( float_to_string(i) );
	}
}