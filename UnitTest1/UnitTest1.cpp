#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTest
{
    TEST_CLASS(ArrayTest)
    {
    public:

        TEST_METHOD(TestCountPositiveEven)
        {
            int array[SIZE] = { 2, -5, 8, 12, -3, 10, 0, -1, 16, -7, 3, -11, 14, -9, 6, 4, -15, 18, -6, -2, 20, -8, 30, -10, -20 };
            int expectedCount = 11; // Ручний підрахунок додатних парних елементів
            Assert::AreEqual(expectedCount, count(array, SIZE));
        }

        TEST_METHOD(TestSumPositiveEven)
        {
            int array[SIZE] = { 2, -5, 8, 12, -3, 10, 0, -1, 16, -7, 3, -11, 14, -9, 6, 4, -15, 18, -6, -2, 20, -8, 30, -10, -20 };
            int expectedSum = 140; // Ручний підрахунок суми додатних парних елементів
            Assert::AreEqual(expectedSum, sum(array, SIZE));
        }

        TEST_METHOD(TestReplaceZero)
        {
            int array[SIZE] = { 2, -5, 8, 12, -3, 10, 0, -1, 16, -7, 3, -11, 14, -9, 6, 4, -15, 18, -6, -2, 20, -8, 30, -10, -20 };
            int expectedArray[SIZE] = { 0, -5, 0, 0, -3, 0, 0, -1, 0, -7, 3, -11, 0, -9, 0, 0, -15, 0, -6, -2, 0, -8, 0, -10, -20 };
            replaceZero(array, SIZE);

            for (int i = 0; i < SIZE; i++) {
                Assert::AreEqual(expectedArray[i], array[i]);
            }
        }
    };
}
