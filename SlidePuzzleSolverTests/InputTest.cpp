#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SlidePuzzleSolver/slider.h"
#include "../SlidePuzzleSolver/slider.cpp"
#include "../SlidePuzzleSolver/node.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SlidePuzzleSolverTests
{
	TEST_CLASS(InputTest)
	{
	public:
		
		Slider slider;

		TEST_METHOD(Input_ExpectedSize4_ReturnSuccess)
		{
			// Arrange
			int expected = SUCCESS;

			// Act
			int output = slider.setInput("1 2 3 4");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_ExpectedSize25_ReturnSuccess)
		{
			// Arrange
			int expected = SUCCESS;

			// Act
			int output = slider.setInput("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_Exit_ReturnQuit)
		{
			// Arrange
			int expected = QUIT;

			// Act
			int output = slider.setInput("exit");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_UnexpectedContainsAlpha_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 a 4");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_UnexpectedNonSquareSeries_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 3");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_UnexpectedIncorrectRange_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 3 5");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_UnexpectedDuplicates_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output1 = slider.setInput("1 2 3 3");
			int output2 = slider.setInput("1 2 3 4 5 6 7 7");
			int output3 = slider.setInput("12 1 10 2 7 11 4 14 5 16 8 15 8 13 6 3");
			int output4 = slider.setInput("9 9 9 9 9 9 9 9 9");

			// Assert
			Assert::AreEqual(expected, output1);
			Assert::AreEqual(expected, output2);
			Assert::AreEqual(expected, output3);
			Assert::AreEqual(expected, output4);
		}

	};

	TEST_CLASS(InversionsTest)
	{
	public:

		Slider slider;

		TEST_METHOD(Inversions_2x2_Return1)
		{
			// Arrange
			int expected = 1;
			// Grid:
			// 2 1
			// 3 4
			//
			vector<int> grid(4);
			grid = { 2, 1,
				3, 4 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Inversions_2x2_Return2)
		{
			// Arrange
			int expected = 2;
			// Grid:
			// 2 3
			// 1 4
			//
			vector<int> grid(4);
			grid = { 2, 3,
				1, 4 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Inversions_2x2_Return3)
		{
			// Arrange
			int expected = 3;
			// Grid:
			// 4 3
			// 2 1
			//
			vector<int> grid(4);
			grid = { 4, 3,
				2, 1 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Inversions_3x3_Return11)
		{
			// Arrange
			int expected = 11;
			// Grid:
			//	7	1	2
			//	5	4	9
			//	8	3	6
			//
			vector<int> grid(4);
			grid = { 7, 1, 2,
				5, 4, 9,
				8, 3, 6 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Inversions_4x4_Return49)
		{
			// Arrange
			int expected = 49;
			// Grid:
			//	12	1	10	2
			//	7	11	4	14
			//	5	16	9	15
			//	8	13	6	3
			//
			vector<int> grid(16);
			grid = { 12, 1, 10, 2,
				7, 11, 4, 14,
				5, 16, 9, 15,
				8, 13, 6, 3 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

	};

	TEST_CLASS(SolvabilityTest)
	{
	public:

		Slider slider;

		TEST_METHOD(Solvability_OddWidthEvenInv_ReturnSuccess)
		{
			// Arrange
			int expected = SUCCESS;
			vector<int> grid(9);
			grid = { 1, 2, 3,
				4, 5, 6,
				7, 8, 9 };

			// Act
			int output = slider.solvability(grid, 2);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Solvability_OddWidthOddInv_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;
			vector<int> grid(9);
			grid = { 1, 2, 3,
				4, 5, 6,
				7, 8, 9 };

			// Act
			int output = slider.solvability(grid, 1);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Solvability_EvenWidthNullOnOddInvOdd_ReturnSuccess)
		{
			// Arrange
			int expected = SUCCESS;
			vector<int> grid(4);
			grid = { 4, 1,
				1, 1 };

			// Act
			int output = slider.solvability(grid, 1);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Solvability_EvenWidthNullOnOddInvEven_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;
			vector<int> grid(4);
			grid = { 4, 1,
				1, 1 };

			// Act
			int output = slider.solvability(grid, 2);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Solvability_EvenWidthNullOnEvenInvOdd_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;
			vector<int> grid(4);
			grid = { 1, 1,
				4, 1 };

			// Act
			int output = slider.solvability(grid, 1);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Solvability_EvenWidthNullOnEvenInvEven_ReturnSuccess)
		{
			// Arrange
			int expected = SUCCESS;
			vector<int> grid(4);
			grid = { 1, 1,
				4, 1 };

			// Act
			int output = slider.solvability(grid, 2);

			// Assert
			Assert::AreEqual(expected, output);
		}

	};

	TEST_CLASS(PossibleMovesTest)
	{
	public:

		TEST_METHOD(PossibleMoves_CornerTL_ReturnDR)
		{
			// Arrange
			string expected = "DR";
			vector<int> g;
			g = { 4, 1,
				1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_CornerTR_ReturnDL)
		{
			// Arrange
			string expected = "DL";
			vector<int> g;
			g = { 1, 4,
				1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_CornerBL_ReturnRU)
		{
			// Arrange
			string expected = "RU";
			vector<int> g;
			g = { 1, 1,
				4, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_CornerBR_ReturnLU)
		{
			// Arrange
			string expected = "LU";
			vector<int> g;
			g = { 1, 1,
				1, 4 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_WallLeft_ReturnDRU)
		{
			// Arrange
			string expected = "DRU";
			vector<int> g;
			g = { 1, 1, 1,
				9, 1, 1,
				1, 1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_WallRight_ReturnDLU)
		{
			// Arrange
			string expected = "DLU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 1, 9,
				1, 1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_WallTop_ReturnDLR)
		{
			// Arrange
			string expected = "DLR";
			vector<int> g;
			g = { 1, 9, 1,
				1, 1, 1,
				1, 1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_WallBottom_ReturnLRU)
		{
			// Arrange
			string expected = "LRU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 1, 1,
				1, 9, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_Center_ReturnDLRU)
		{
			// Arrange
			string expected = "DLRU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 9, 1,
				1, 1, 1 };
			Node node(g, 0, 0);

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_LastMoveD_ReturnDLR)
		{
			// Arrange
			string expected = "DLR";
			vector<int> g;
			g = { 1, 1, 1,
				1, 9, 1,
				1, 1, 1 };
			Node node(g, 0, 0);
			node.setLastMove('D');

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_LastMoveL_ReturnDLU)
		{
			// Arrange
			string expected = "DLU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 9, 1,
				1, 1, 1 };
			Node node(g, 0, 0);
			node.setLastMove('L');

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_LastMoveR_ReturnDRU)
		{
			// Arrange
			string expected = "DRU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 9, 1,
				1, 1, 1 };
			Node node(g, 0, 0);
			node.setLastMove('R');

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(PossibleMoves_LastMoveU_ReturnLRU)
		{
			// Arrange
			string expected = "LRU";
			vector<int> g;
			g = { 1, 1, 1,
				1, 9, 1,
				1, 1, 1 };
			Node node(g, 0, 0);
			node.setLastMove('U');

			// Act
			vector<char> out = node.possibleMoves();
			string output(out.begin(), out.end());

			// Assert
			Assert::AreEqual(expected, output);
		}
		
	};

	TEST_CLASS(SmallestDistanceTest)
	{
	public:

		TEST_METHOD(SmallestDistance_TwoTier_Return1)
		{
			// Arrange
			int expected = 1;
			Slider slider;
			vector<int> p, c1, c2, c3;
			Node root(p, 8, 0), leaf1(c1, 1, 1), leaf2(c2, 8, 1), leaf3(c3, 6, 1);
			root.addChild(&leaf1); root.addChild(&leaf2); root.addChild(&leaf3);

			// Act
			int output = slider.smallestDistance(&root);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(SmallestDistance_ThreeTier_Return1)
		{
			/*				R
			//			   /|\
			//			 c1 c2 c3
			//				/\
			//			  c21 c22
			*/
			// Arrange
			int expected = 1;
			Slider slider;
			vector<int> p, c1, c2, c21, c22, c3;
			Node root(p, 8, 0), leaf1(c1, 2, 1), leaf2(c2, 8, 1), leaf21(c21, 2, 2), leaf22(c22, 1, 2), leaf3(c3, 6, 1);
			root.addChild(&leaf1); root.addChild(&leaf2); root.addChild(&leaf3);
			leaf2.addChild(&leaf21); leaf2.addChild(&leaf22);

			// Act
			int output = slider.smallestDistance(&root);

			// Assert
			Assert::AreEqual(expected, output);
		}
	};

	TEST_CLASS(ManhattanDistanceTest)
	{
	public:

		Slider slider;

		TEST_METHOD(Distance_3x3_Return40)
		{
			// Arrange
			int expected = 40;
			vector<int> grid = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

			// Act
			int output = slider.getManhattanDistance(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Distance_3x3_Return0)
		{
			// Arrange
			int expected = 0;
			vector<int> grid = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			// Act
			int output = slider.getManhattanDistance(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}
	};

}