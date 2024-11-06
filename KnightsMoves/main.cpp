#include <iostream>	// Include input output stream library
#include <cstdlib>	// Needed for rand() and srand()
#include <ctime>	// Needed for time()
#include <vector>	// Include the vector library
using namespace std;

// Declaring a structure named "cell" that represents each square in the chessboard
struct cell {
	int row;
	char column;
};

const int N = 8;	// number of rows and column in the chessboard

cell chessboard[N][N];

vector<cell> possibleMoves;

// Initializes the fields of each element in the chessboard array
void initialize()
{
	for (int row = 0; row < N; row++) {
		char letterColumn = 'a';
		for (int col = 0; col < N; col++, letterColumn++) {
			chessboard[row][col].row = row + 1;
			chessboard[row][col].column = letterColumn;
		}
	}
}

/* Checks if the row and column passed in as argument are greater than or equal to 0 and less than or 
equal to N - 1 and returns true if they are*/ 
bool isValidCell(int row, int column)
{
	return (row >= 0 && row <= N-1) && (column >= 0 && column <= N - 1);
}

/* Finds all the possible moves the knight can do while at position (row, column) */
void findPossibleMoves(int row, int column)
{
	if (isValidCell(row + 1, column - 2)) {
		possibleMoves.push_back(chessboard[row + 1][column - 2]);	// Adds cell to the back of the vector if true
	}

	if (isValidCell(row - 1, column - 2)) {
		possibleMoves.push_back(chessboard[row - 1][column - 2]);
	}

	if (isValidCell(row + 1, column + 2)) {
		possibleMoves.push_back(chessboard[row + 1][column + 2]);
	}

	if (isValidCell(row - 1, column + 2)) {
		possibleMoves.push_back(chessboard[row - 1][column + 2]);
	}

	if (isValidCell(row - 2, column + 1)) {
		possibleMoves.push_back(chessboard[row - 2][column + 1]);
	}

	if (isValidCell(row - 2, column - 1)) {
		possibleMoves.push_back(chessboard[row - 2][column - 1]);
	}

	if (isValidCell(row + 2, column + 1)) {
		possibleMoves.push_back(chessboard[row + 2][column + 1]);
	}

	if (isValidCell(row + 2, column - 1)) {
		possibleMoves.push_back(chessboard[row + 2][column - 1]);
	}
}

// Outputs all the possible moves of the knight
void outputPossibleMoves()
{
	for (int i = 0; i < possibleMoves.size(); i++)
	{
		cout << possibleMoves.at(i).column << possibleMoves.at(i).row;

		if (i < possibleMoves.size() - 1)
			cout << ';';
	}
}

int main() 
{
	// Get a different random number each time the program runs
	srand(static_cast<unsigned int>(time(0)));

	// Generate a random number between 0 and 7 for both the row and the column in the chessboard array representing the starting point of the knight
	int startingRow = rand() % N;
	int startingCol = rand() % N;

	initialize();

	cout << "Starting position: " << chessboard[startingRow][startingCol].column << chessboard[startingRow][startingCol].row << endl << endl;

	findPossibleMoves(startingRow, startingCol);

	cout << "The knight can move to: ";
	outputPossibleMoves();
	cout << endl;

	return 0;
}