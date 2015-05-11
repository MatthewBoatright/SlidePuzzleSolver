//============================================================
// INCLUDE GUARD
#ifndef SLIDER_H
#define SLIDER_H

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
// DEFINES
#define SUCCESS 0
#define FAILURE 1
#define QUIT 2

//============================================================
// SLIDER CLASS
using namespace std;

class Slider
{
private:
	string INPUT;
	vector<int> grid;
public:
	int setInput(string in="");
	int inversions(vector<int> g);
	int solvability(vector<int> g, int inv);
	string getInput() { return INPUT; };
	vector<int> getGrid() { return grid; };
};

#endif