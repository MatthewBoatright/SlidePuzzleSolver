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

class Node
{
private:
	int inv;
	char last_move;
	vector<int> grid;
	vector<Node*> children;
public:
	Node(vector<int> g, int i) { grid = g; inv = i; };
	int getInv() { return inv; };
	char getLastMove() { return last_move; };
	void setLastMove(char lm) { last_move = lm; };
	vector<int> getGrid() { return grid; };
	vector<Node*> getChildren() { return children; };
	void addChild(Node* c) { children.push_back(c); };
	vector<char> possibleMoves();
};

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
	vector<char> solve(Node r);
	int smallestInverions(Node r);
	void expandSmallest(int i);
};

#endif