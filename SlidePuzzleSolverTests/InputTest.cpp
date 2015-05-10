#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SlidePuzzleSolver/slider.h"
#include "../SlidePuzzleSolver/slider.cpp"

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
					5, 16, 8, 15,
					8, 13, 6, 3 };

			// Act
			int output = slider.inversions(grid);

			// Assert
			Assert::AreEqual(expected, output);
		}

	};
}