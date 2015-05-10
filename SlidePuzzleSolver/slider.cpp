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