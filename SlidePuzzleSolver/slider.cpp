//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// METHODS

// RETURN:	
//			0 = Success
//			1 = Fail
//			2 = Exit
//
int Slider::setInput(string in)
{
	// INIT
	grid.clear();

	// INPUT
	if (in.empty())
	{
		cout << "Enter a series of numbers representing your puzzle. Type 'exit' to quit.\n";
		getline(cin, INPUT);
	}
	else
	{
		cout << "Grid: " << in;
		INPUT = in;
	}


	// STREAM
	istringstream stream(INPUT);

	// DETERMINE IF INPUT IS NUMERIC
	string n;
	while (stream >> n)
	{
		if (strspn(n.c_str(), "0123456789") == n.size())
		{
			grid.push_back(atoi(n.c_str()));
		}
		else if (n != "exit")
		{
			INPUT = "ERROR: Only numbers are allowed.\n";
			return FAILURE;
		}
		else if (n == "exit")
		{
			return QUIT;
		}
	}

	// DETERMINE IF INPUT: 
	//		IS PERFECT SQUARE 
	//		RANGES FROM 1 to n^2
	//		CONTAINS DUPLICATES
	//
	double d = sqrt(grid.size());
	int i = d;
	vector<int> found;

	// PERFECT SQUARE
	if (i != d || grid.size() == 1)
	{
		INPUT = "ERROR: Series size must be a perfect square and greater than 1.\n";
		return FAILURE;
	}
	else
	{
		for (int j = 0; j < grid.size(); j++)
		{
			int n = grid.at(j);
			// IN RANGE
			if (n < 1 || n > grid.size())
			{
				INPUT = "ERROR: Series must range from 1 to n^2.\n";
				return FAILURE;
			}

			// CONTAINS DUPLICATES
			for (int k = 0; k < found.size(); k++)
			{
				if (n == found.at(k))
				{
					INPUT = "ERROR: Series contains duplicates.\n";
					return FAILURE;
				}
			}

			found.push_back(n);
		}
	}


	return SUCCESS;
}

// RETURN:
//			# of inversions
//
int Slider::inversions(vector<int> g)
{
	int size = g.size();
	int inv = 0;

	// Get number of inversions
	for (int j = 0; j < g.size(); j++)
	{
		int n = g.at(j);

		for (int k = j + 1; k < g.size(); k++)
		{
			int nn = g.at(k);
			if ((n > nn) && (n != (size)) && (nn != (size)))
			{
				inv++;
			}
		}
	}

	cout << "# of inversions: " << inv << "\n";
	return inv;
}

// RETURN:
//			0 = Success
//			1 = Failure
//
int Slider::solvability(vector<int> g, int inv)
{
	/* Notes about solvability:
	// To determine a sliding puzzles solvability we must first count its number of inversions.
	// The number of inversions is represented the number of tiles (a, b) where a>b but a appears before b.
	// If an odd width grid has an even number of inversions then it is solvable.
	// For an even width grid:
	//		If the null space is on an even row (from the top), the number of inversions must be even.
	//		If the null space is on an odd row (from the top), the number of inversions must be odd.
	*/
	int size = g.size();
	int width = sqrt(size);

	// Odd width
	if ((width % 2) != 0)
	{
		if ((inv % 2) != 0)
		{
			cout << "This grid is unsolvable! The width is odd with an odd # of inversions.\n";
			return FAILURE;
		}
	}
	// Even width
	else if ((width % 2) == 0)
	{
		for (int j = 0; j < size; j++)
		{
			int n = g.at(j);
			int row;

			// If max value (blank spot)
			if (n == size)
			{
				row = (j / width) + 1;

				// Null space on odd row
				if ((row % 2) != 0)
				{
					if ((inv % 2) == 0)
					{
						cout << "This grid is unsolvable! Null is on an odd row with an even # of inversions.\n";
						return FAILURE;
					}
				}
				// Null space on even row
				else if ((row % 2) == 0)
				{
					if ((inv % 2) != 0)
					{
						cout << "This grid is unsolvable! Null is on an even row with an odd # of inversions.\n";
						return FAILURE;
					}
				}
			}
		}
	}

	return SUCCESS;
}