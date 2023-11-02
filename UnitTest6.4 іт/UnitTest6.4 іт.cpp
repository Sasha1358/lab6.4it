#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64іт
{
	TEST_CLASS(UnitTest64іт)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			int arr[] = { -3, -5, 0, -1, -9, -7 };
			int size = 6;
			int result = SumAbsAfterFirstZero(arr, size);
			(result == 17); // Очікувана сума модулів після першого нуля
		}
	};
}
