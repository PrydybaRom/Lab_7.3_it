#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73it
{
	TEST_CLASS(UnitTest73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k, n;
			int** matrix = create(k=2, n=3);

			int nonZeroColumns = countColumns(matrix, k, n);
			deleteM(matrix, k);

			Assert::AreEqual(nonZeroColumns, 2);
		}
	};
}
