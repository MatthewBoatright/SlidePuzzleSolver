//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// CONSTRUCTOR
Slider::Slider()
{
	INPUT = "";

	cout << "Enter a series of numbers representing your puzzle. Type 'exit' to quit.\n";

	getline(cin, INPUT);

	istringstream stream(INPUT);

	int n;

	while (stream >> n)
	{
		cout << n << '\n';
	}
}

//============================================================
// METHODS
string Slider::getInput()
{
	return INPUT;
}