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

	// DETERMINE IF INPUT IS PERFECT SQUARE AND RANGES FROM 1 to n^2
	double d = sqrt(grid.size());
	int i = d;

	if (i != d || grid.size() == 1)
	{
		INPUT = "ERROR: Series size must be a perfect square and greater than 1.\n";
		return FAILURE;
	}
	else
	{
		for (int j = 0; j < grid.size(); j++)
		{
			if (grid.at(j) < 1 || grid.at(j) > grid.size())
			{
				INPUT = "ERROR: Series must range from 1 to n^2.\n";
				return FAILURE;
			}
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
			if ((n > nn) && (n != (size-1)) && (nn != (size-1)))
			{
				inv++;
			}
		}
	}

	return inv;
}

// RETURN:
//			0 = Success
//			1 = Failure
//
int Slider::solvability(vector<int> g)
{
	int size = g.size();
	int width = sqrt(size);
	int inv = inversions(g);

	// If odd
	if ((width % 2) != 0)
	{
		if ((inv % 2) != 0)
		{
			cout << "This grid is unsolvable!\n";
			return FAILURE;
		}
	}
	else if ((width % 2) == 0)
	{

	}

	return 0;
}