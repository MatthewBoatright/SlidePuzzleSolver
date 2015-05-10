//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// CONSTRUCTOR
Slider::Slider()
{
	bool reject;

	do
	{
		// INIT
		INPUT = "";
		grid.clear();
		reject = false;

		// INPUT
		cout << "Enter a series of numbers representing your puzzle. Type 'exit' to quit.\n";
		getline(cin, INPUT);

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
				reject = true;
				cout << "ERROR: Only numbers are allowed.\n";
				break;
			}
		}

		// DETERMINE IF INPUT IS PERFECT SQUARE AND RANGES FROM 1 to n^2
		if (!reject)
		{
			double d = sqrt(grid.size());
			int i = d;

			if (i != d || grid.size() == 1)
			{
				cout << "ERROR: Series size must be a perfect square and greater than 1.\n";
				reject = true;
			}
			else
			{
				for (int j = 0; j < grid.size(); j++)
				{
					if (grid.at(j) < 1 || grid.at(j) > grid.size())
					{
						cout << "ERROR: Series must range from 1 to n^2.\n";
						reject = true;
					}
				}
			}
		}
	} 
	while (reject);

	cout << "SUCCESS.\n";
}

//============================================================
// METHODS
string Slider::getInput()
{
	return INPUT;
}