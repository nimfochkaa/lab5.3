#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3/5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
	TEST_CLASS(UnitTest53)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double expected1 = (sin(1.0) + 1) / (pow(cos(1.0), 2) + exp(1.0));
			Assert::AreEqual(expected1, j(1.0), 0.0001, L"Test failed for j(1.0)");

			double expected2 = (sin(-2.0) + 1) / (pow(cos(-2.0), 2) + exp(-2.0));
			Assert::AreEqual(expected2, j(-2.0), 0.0001, L"Test failed for j(-2.0)");

			
			double x = 0.5;
			double sum = 1.0; 
			double term = 1.0; 

			for (int k = 1; k <= 7; ++k)
			{
				
				double recurrenceRatio = (2 * x * x) / ((2 * k + 2) * (2 * k + 1));
				term *= recurrenceRatio;  
				sum += term;
			}

			double expected3 = sum / cos(2 * x);
			Assert::AreEqual(expected3, j(0.5), 0.0001, L"Test failed for j(0.5)");

			double expected4 = sum / cos(2 * (-0.5));
			Assert::AreEqual(expected4, j(-0.5), 0.0001, L"Test failed for j(-0.5)");
		}
	};
}
