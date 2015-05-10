//============================================================
// INCLUDE GUARD
#ifndef SLIDEPUZZLESOLVER_H
#define SLIDEPUZZLESOLVER_H

//============================================================
// INCLUDED DEPENDENCIES
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <stdbool.h>
#include <stdlib.h>

//============================================================
// SLIDER CLASS
using namespace std;

class Slider
{
private:
	string INPUT;
	vector<int> grid;
public:
	Slider();
	string getInput();
};

#endif