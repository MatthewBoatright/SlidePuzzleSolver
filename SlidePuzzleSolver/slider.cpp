//============================================================
// DEPENDENCIES
#include "slider.h"

//============================================================
// METHODS

// RETURN:	
//			0 = Success
//			1 = Fail
//			2 = Exit
//
int Slider::setInput(string in)
{
	// INIT
	grid.clear();

	// INPUT
	if (in.empty())
	{
		cout << "Enter a series of numbers representing your puzzle. Type 'exit' to quit.\n";
		getline(cin, INPUT);
	}
	else
	{
		cout << "Grid: " << in;
		INPUT = in;
	}


	// STREAM
	istringstream stream(INPUT);

	// DETERMINE IF INPUT IS NUMERIC
	string n;
	while (stream >> n)
	{
		if (strspn(n.c_str(), "0123456789") == n.size())
		{
			grid.push_back(atoi(n.c_str()));
		}
		else if (n != "exit")
		{
			INPUT = "ERROR: Only numbers are allowed.\n";
			return FAILURE;
		}
		else if (n == "exit")
		{
			return QUIT;
		}
	}

	// DETERMINE IF INPUT: 
	//		IS PERFECT SQUARE 
	//		RANGES FROM 1 to n^2
	//		CONTAINS DUPLICATES
	//
	double d = sqrt(grid.size());
	int i = d;
	vector<int> found;

	// PERFECT SQUARE
	if (i != d || grid.size() == 1)
	{
		INPUT = "ERROR: Series size must be a perfect square and greater than 1.\n";
		return FAILURE;
	}
	else
	{
		for (int j = 0; j < grid.size(); j++)
		{
			int n = grid.at(j);
			// IN RANGE
			if (n < 1 || n > grid.size())
			{
				INPUT = "ERROR: Series must range from 1 to n^2.\n";
				return FAILURE;
			}

			// CONTAINS DUPLICATES
			for (int k = 0; k < found.size(); k++)
			{
				if (n == found.at(k))
				{
					INPUT = "ERROR: Series contains duplicates.\n";
					return FAILURE;
				}
			}

			found.push_back(n);
		}
	}


	return SUCCESS;
}

// RETURN:
//			# of inversions
//
int Slider::inversions(vector<int> g)
{
	int size = g.size();
	int inv = 0;

	// Get number of inversions
	for (int j = 0; j < g.size(); j++)
	{
		int n = g.at(j);

		for (int k = j + 1; k < g.size(); k++)
		{
			int nn = g.at(k);
			if ((n > nn) && (n != (size)) && (nn != (size)))
			{
				inv++;
			}
		}
	}

	//cout << "# of inversions: " << inv << "\n";
	return inv;
}

// RETURN:
//			0 = Success
//			1 = Failure
//
int Slider::solvability(vector<int> g, int inv)
{
	/* Notes about solvability:
	// To determine a sliding puzzles solvability we must first count its number of inversions.
	// The number of inversions is represented the number of tiles (a, b) where a>b but a appears before b.
	// If an odd width grid has an even number of inversions then it is solvable.
	// For an even width grid:
	//		If the null space is on an even row (from the top), the number of inversions must be even.
	//		If the null space is on an odd row (from the top), the number of inversions must be odd.
	*/
	int size = g.size();
	int width = sqrt(size);

	// Odd width
	if ((width % 2) != 0)
	{
		if ((inv % 2) != 0)
		{
			cout << "This grid is unsolvable! The width is odd with an odd # of inversions.\n";
			return FAILURE;
		}
	}
	// Even width
	else if ((width % 2) == 0)
	{
		for (int j = 0; j < size; j++)
		{
			int n = g.at(j);
			int row;

			// If max value (blank spot)
			if (n == size)
			{
				row = (j / width) + 1;

				// Null space on odd row
				if ((row % 2) != 0)
				{
					if ((inv % 2) == 0)
					{
						cout << "This grid is unsolvable! Null is on an odd row with an even # of inversions.\n";
						return FAILURE;
					}
				}
				// Null space on even row
				else if ((row % 2) == 0)
				{
					if ((inv % 2) != 0)
					{
						cout << "This grid is unsolvable! Null is on an even row with an odd # of inversions.\n";
						return FAILURE;
					}
				}
			}
		}
	}

	return SUCCESS;
}

int Slider::getManhattanDistance(vector<int> g)
{
	int distance = 0;

	for (int j = 0; j < g.size(); j++)
	{
		distance += abs((j + 1) - g.at(j));
	}

	return distance;
}

vector<char> Slider::solve(Node *n)
{
	vector<char> solution;
	int h = smallestDistance(n);

	////DEBUG
	//cout << "Starting distance: " << h << "\n";

	while (h != 0)
	{
		expandNodes(n, h);
		h = smallestDistance(n);
		//char c;
		//cin >> c;
	}

	solution = getSolutions(n, solution);

	cout << "PATH: ";
	for (int x = 0; x < solution.size(); x++)
	{
		cout << solution.at(x);
	}
	cout << "\n";

	return solution;
}

// RETURN:
//			H = inversion hueristic
//
int Slider::smallestDistance(Node* n)
{
	/* This is a recursive function that finds the smallest number of inversions through DFS and returns it.
	// The root is the first node passed to this function. It will check the current nodes number of children.
	// If there are no children then the node is a leaf and we can look at its number of inversions.
	// If it's smaller than the current H then we will return it. Else we ignore it.
	*/
	int H = 99999;
	vector<Node*> c = n->getChildren();

	// If there are children, keep going down.
	if (c.size() > 0)
	{

		for (int j = 0; j < c.size(); j++)
		{
			int dist = smallestDistance(c.at(j));

			if (dist < H)
			{
				H = dist;
			}
		}
	}
	// If no children, this is a leaf. Grab the number of inversions.
	else
	{
		H = n->getDist();
	}

	return H;
}

void Slider::expandNodes(Node *n, int i)
{
	/* This is a recursive function that will traverse the game tree and expand
	// any leaf nodes that have the smallest number of inversions.
	*/
	vector<Node*> c = n->getChildren();
	vector<int> g = n->getGrid();
	int size = g.size();
	int width = sqrt(size);
	int d = n->getDist();

	////DEBUG
	//cout << c.size() << " CURR NODE: ";
	//for (int x = 0; x < g.size(); x++)
	//{
	//	cout << g.at(x);
	//}
	//cout << "\n";

	// DFS to leaf nodes.
	if (c.size() > 0)
	{
		for (int j = 0; j < c.size(); j++)
		{
			expandNodes(c.at(j), i);
		}
	}
	/*	When at a leaf:
	//		Determine the possible moves for this node.
	//		Get null space location.
	//		Based on possible moves, rearrange grid.
	//			D = Switch null space with space at loc + width
	//			L = Switch null space with space at loc - 1
	//			R = Switch null space with space at loc + 1
	//			U = Switch null space with space at loc - width
	//		Create a number of additional nodes based on the number of possible moves.
	*/
	else if (d == i)
	{
		////DEBUG
		//cout << d << " EXPANDING: ";
		//for (int x = 0; x < g.size(); x++)
		//{
		//	cout << g.at(x);
		//}
		//cout << "\n";

		vector<char> moves = n->possibleMoves();
		vector<int> temp;
		int loc;

		for (int k = 0; k < size; k++)
		{
			if (g.at(k) == size)
			{
				loc = k;
			}
		}

		for (int k = 0; k < moves.size(); k++)
		{
			temp = g;
			if (moves.at(k) == 'D')
			{
				iter_swap(temp.begin() + loc, temp.begin() + (loc + width));
			}
			else if (moves.at(k) == 'L')
			{
				iter_swap(temp.begin() + loc, temp.begin() + (loc - 1));
			}
			else if (moves.at(k) == 'R')
			{
				iter_swap(temp.begin() + loc, temp.begin() + (loc + 1));
			}
			else if (moves.at(k) == 'U')
			{
				iter_swap(temp.begin() + loc, temp.begin() + (loc - width));
			}

			////DEBUG
			//cout << "- OUTPUT: ";
			//for (int x = 0; x < temp.size(); x++)
			//{
			//	cout << temp.at(x);
			//}
			//cout << "\n";

			Node* next = new Node(temp, getManhattanDistance(temp), n->getPath());
			next->setLastMove(moves.at(k));
			n->addChild(next);
		}
	}
}

vector<char> Slider::getSolutions(Node* n, vector<char> solution)
{
	vector<Node*> c = n->getChildren();

	if (c.size() > 0)
	{
		for (int j = 0; j < c.size(); j++)
		{
			solution = getSolutions(c.at(j), solution);
		}
	}
	else if (n->getDist() == 0)
	{
		return n->getPath();
	}

	return solution;
}