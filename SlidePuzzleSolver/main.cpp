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

				//DEBUG
				Slider slider2;
				vector<int> p, c1, c2, c21, c22, c3;
				Node r(p, 8), leaf1(c1, 2), leaf2(c2, 8), leaf21(c21, 2), leaf22(c22, 1), leaf3(c3, 6);
				r.addChild(leaf1); r.addChild(leaf2); r.addChild(leaf3);
				leaf2.addChild(leaf21); leaf2.addChild(leaf22);

				// Act
				int output = slider2.smallestInverions(r);
				cout << "OUTPUT: " << output << "\n";
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