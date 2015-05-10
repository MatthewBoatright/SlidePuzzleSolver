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

//============================================================
// SLIDER CLASS
using namespace std;

class Slider
{
private:
	string INPUT;
public:
	Slider();
	string getInput();
};

#endif