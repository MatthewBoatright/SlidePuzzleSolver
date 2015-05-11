//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// MAIN
int main()
{
	int signal;
	Slider slider;

	do
	{
		signal = slider.setInput();

		if (signal == SUCCESS)
		{
			cout << "Beginning calculations...\n";
			vector<int> g = slider.getGrid();
			int i = slider.inversions(g);

			signal = slider.solvability(g, i);

			if (signal == SUCCESS)
			{
				cout << "Solving...\n";
				Node root(g, i);
			}
		}
		else if (signal == FAILURE)
		{
			cout << slider.getInput();
		}
		else if (signal == QUIT)
		{
			cout << "Quiting...\n";
		}
		else
		{
			cout << "Unknown return: " << signal << "\n";
		}

		cout << "\n";
	} 
	while (signal != QUIT);

	return 0;
}