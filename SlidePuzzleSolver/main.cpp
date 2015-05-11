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
			signal = slider.solvability(slider.getGrid(), slider.inversions(slider.getGrid()));

			if (signal == SUCCESS)
			{
				cout << "Solving...\n";
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