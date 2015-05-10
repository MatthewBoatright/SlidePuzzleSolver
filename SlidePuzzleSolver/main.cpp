//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// MAIN
int main()
{
	string exit;
	do
	{
		Slider slider;
		exit = slider.getInput();
	} 
	while (exit != "exit");

	

	return 0;
}