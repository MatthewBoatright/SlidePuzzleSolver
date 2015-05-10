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

		// DETERMINE IF ACCEPTABLE
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
				cout << "Please only enter numbers.\n";
				break;
			}
		}
	} 
	while (reject);

	for (int j = 0; j < grid.size(); j++)
	{
		cout << grid.at(j) << '\n';
	}

}

//============================================================
// METHODS
string Slider::getInput()
{
	return INPUT;
}