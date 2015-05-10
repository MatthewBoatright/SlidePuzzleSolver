#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InputTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(setInput_ExpectedString_Return0)
		{
			Assert::AreEqual(1, 1);
		}

	};
}