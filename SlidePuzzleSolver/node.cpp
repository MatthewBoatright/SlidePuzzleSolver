//============================================================
// DEPENDENCIES
#include "slider.h"
#define TOP_LEFT 0
#define TOP_RIGHT (width - 1)
#define BOTTOM_LEFT (width * width - width)
#define BOTTOM_RIGHT (size - 1)

//============================================================
// METHODS
vector<char> Node::possibleMoves()
{
	/* To find the next possible moves we must:
	//		Exclude the last move taken to reach this node.
	//		Determine if null is at a corner. (Only two possible moves).
	//		Determine if null is against a wall. (Only three possible moves).
	*/
	vector<char> moves;
	int loc = -1;
	int size = grid.size();
	int width = sqrt(size);

	for (int j = 0; j < grid.size(); j++)
	{
		if (grid.at(j) == size)
		{
			loc = j;
		}
	}

	// CORNERS
	if (loc == TOP_LEFT)
	{
		moves = { 'D', 'R' };
	}
	else if (loc == TOP_RIGHT)
	{
		moves = { 'D', 'L' };
	}
	else if (loc == BOTTOM_LEFT)
	{
		moves = { 'R', 'U' };
	}
	else if (loc == BOTTOM_RIGHT)
	{
		moves = { 'L', 'U' };
	}
	// TOP SIDE
	else if (TOP_LEFT < loc && loc < TOP_RIGHT)
	{
		moves = { 'D', 'L', 'R' };
	}
	// BOTTOM SIDE
	else if (BOTTOM_LEFT < loc && loc < BOTTOM_RIGHT)
	{
		moves = { 'L', 'R', 'U' };
	}
	// LEFT SIDE
	else if (loc % width == 0)
	{
		moves = { 'D', 'R', 'U' };
	}
	// RIGHT SIDE
	else if (loc % width == (width - 1))
	{
		moves = { 'D', 'L', 'U' };
	}
	else
	{
		moves = { 'D', 'L', 'R', 'U' };
	}

	////DEBUG
	//cout << last_move << " MOVES: ";
	//for (int x = 0; x < grid.size(); x++)
	//{
	//	cout << grid.at(x);
	//}
	//cout << "\n";

	// Remove last_move
	char lm = ' ';
	if (last_move == 'D')
		lm = 'U';
	if (last_move == 'L')
		lm = 'R';
	if (last_move == 'R')
		lm = 'L';
	if (last_move == 'U')
		lm = 'D';
	for (int j = 0; j < moves.size(); j++)
	{
		if (moves.at(j) == lm)
		{
			moves.erase(moves.begin()+j);
		}
	}

	return moves;
}