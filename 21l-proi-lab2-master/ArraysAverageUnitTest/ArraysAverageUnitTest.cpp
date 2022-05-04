#include "CppUnitTest.h"
#include "../ArraysAverageLib/ArraysAverage.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArraysAverageUnitTest
{
	TEST_CLASS(ArraysAverageUnitTest)
	{
	public:
		
		TEST_METHOD(TestSumOfDigits)
		{
			int number = 111;
			int even = evenSum(number);
			int odd = oddSum(number);
			Assert::AreEqual(even, 1);
			Assert::AreEqual(odd, 2);
		}
		TEST_METHOD(TestSumOfDigitsOfZero)
		{
			int number = 0;
			int even = evenSum(number);
			int odd = oddSum(number);
			Assert::AreEqual(even, 0);
			Assert::AreEqual(odd, 0);
		}
		TEST_METHOD(TestCheckNumber)
		{
			int number = 11;
			bool isNumber = checkNumber(number);
			Assert::AreEqual(true, isNumber);
		}

		TEST_METHOD(TestFindAverage)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {11,52,1}, {4,1111,6} } };
			double result = average(t, 3, 3);
			Assert::AreEqual(561.0, result);
		}
		TEST_METHOD(TestFindAverageEmptyArray)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {} } };
			double result = average(t, 0, 0);
			Assert::AreEqual(0.0, result);
		}

		TEST_METHOD(TestFindAverageNoRightNumbers)
		{
			std::array<std::array<int, maxColumns>, maxRows> t = { { {32,52,43}, {123,5,6}, {5,3,1} } };
			double result = average(t, 3, 3);
			Assert::AreEqual(0.0, result);
		}
	};
}
