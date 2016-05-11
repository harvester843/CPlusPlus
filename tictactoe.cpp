/*
Benjamin Lipscomb
25 March 2016

Input: The user creates an array of 9 characters. The user inputs characters X or O which alternate
between turns. Once all characters in the array have been filled, the game ends.

Output: When the user inputs a character between 1-9 it will display either an X or O on the corresponding 
(numerical) character. Once all spaces on the board have been filled, the program will display Game Over text.

Purpose: Fills an array of characters based on what the user enters. Once the array has been completely filled,
the program terminates. Numerical values can be entered into an array and be assigned and displayed as characters.

*/

#include <iostream>
using namespace std;

void showBoard(char board[]);

int main( ){
	char board[9];
	int numMoves = 0;
	char whoseTurn = 'X';
	int move;

	//For loop that fills the board array with
	//characters 1-9
	for (int i = 0; i < 9; i++)
	{
		board[i]='1'+ i;
	}//end for loop

	//user can input moves until all 9 characters have filled the board
	while (numMoves < 9)
	{
		showBoard(board);
		cout << "Enter move: " << endl;
		cin >> move;

		//only values 1 - 9 are allowed, otherwise
		//user will be prompted to try again
		if ((move < 1) || (move > 9))
			cout << "Invalid Move, try again" << endl;
		else
		{
			move--;

			//user cannot make the same move twice, otherwise,
			//it will display this space is taken
			if ((board[move]=='X') || (board[move]=='O'))
			{
				cout << "That space is taken." << endl;
			}//end if statement
			else
			{
				board[move] = whoseTurn;
				//switches the turns
				if (whoseTurn =='X')
				{
					whoseTurn = 'O';
				}//end if statement
				else
				{
					whoseTurn= 'X';
				}//end else statement
				numMoves++;
			}//end else statement
		}//end else statement
	}//end while loop

	//displays the board
	showBoard(board);
	cout << endl << "Game Over!" << endl;
	system("pause");
	return 0;

}//end main method

// Function that displays the board on the screen,
// and outputs each character in the array
void showBoard(char board[])
{
	cout << endl; //blank line
	for (int i = 0; i < 9; i++)
	{
		cout <<board[i] << " ";
		if ((i+1) % 3 == 0) 
		{
			cout << endl; //blank line
		}//end if statement
	}//end for loop
	cout << endl; //blank line
}//end function showBoard


