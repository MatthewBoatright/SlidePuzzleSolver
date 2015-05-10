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

		TEST_METHOD(Input_ContainsAlpha_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 a 4");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_NonSquareSeries_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 3");

			// Assert
			Assert::AreEqual(expected, output);
		}

		TEST_METHOD(Input_IncorrectRange_ReturnFailure)
		{
			// Arrange
			int expected = FAILURE;

			// Act
			int output = slider.setInput("1 2 3 5");

			// Assert
			Assert::AreEqual(expected, output);
		}

	};
}