#include "pch.h"
#include "CppUnitTest.h"
#include "..\Second_step_of_evolution\Types_of_sorting.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_QuickSort)
		{
			auto* array = new int[10];
			for (auto index = 0; index < 10; index++) {
				array[index] = 10 - index;
				// 10 9 8 7 6 5 4 3 2 1
			}

			QuickSort(array, 0, 9);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
			Assert::AreEqual(array[3], 4);
			Assert::AreEqual(array[4], 5);
			Assert::AreEqual(array[5], 6);
			Assert::AreEqual(array[6], 7);
			Assert::AreEqual(array[7], 8);
			Assert::AreEqual(array[8], 9);
			Assert::AreEqual(array[9], 10);

			delete[] array;
		}

		TEST_METHOD(Test_BubbleSort)
		{
			auto* array = new int[10];
			for (auto index = 0; index < 10; index++) {
				array[index] = 10 - index;
				// 10 9 8 7 6 5 4 3 2 1
			}

			BubbleSort(array, 10);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
			Assert::AreEqual(array[3], 4);
			Assert::AreEqual(array[4], 5);
			Assert::AreEqual(array[5], 6);
			Assert::AreEqual(array[6], 7);
			Assert::AreEqual(array[7], 8);
			Assert::AreEqual(array[8], 9);
			Assert::AreEqual(array[9], 10);

			delete[] array;
		}

		TEST_METHOD(Test_BogoSort)
		{
			auto* array = new int[10];
			for (auto index = 0; index < 10; index++) {
				array[index] = 10 - index;
				// 10 9 8 7 6 5 4 3 2 1
			}

			BogoSort(array, 10);

			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 3);
			Assert::AreEqual(array[3], 4);
			Assert::AreEqual(array[4], 5);
			Assert::AreEqual(array[5], 6);
			Assert::AreEqual(array[6], 7);
			Assert::AreEqual(array[7], 8);
			Assert::AreEqual(array[8], 9);
			Assert::AreEqual(array[9], 10);

			delete[] array;
		}

		TEST_METHOD(Test_CountingSort)
		{
			auto* array = new char[10];
			for (auto index = 0; index < 10; index++) {
				array[index] = 106 - index;
				// // j i h g f e d c b a
			}

			CountingSort(array, 10); // a b c d e f g h i j

			Assert::AreEqual(array[0], 'a');
			Assert::AreEqual(array[1], 'b');
			Assert::AreEqual(array[2], 'c');
			Assert::AreEqual(array[3], 'd');
			Assert::AreEqual(array[4], 'e');
			Assert::AreEqual(array[5], 'f');
			Assert::AreEqual(array[6], 'g');
			Assert::AreEqual(array[7], 'h');
			Assert::AreEqual(array[8], 'i');
			Assert::AreEqual(array[9], 'j');

			delete[] array;
		}

		TEST_METHOD(Test_BinarySearch)
		{
			auto* array = new int[10];
			for (auto index = 0; index < 10; index++) {
				array[index] = index+1;
				// 1 2 3 4 5 6 7 8 9 10
			}

			Assert::AreEqual(BinarySearch(array, 10, 999),-1);
			Assert::AreEqual(BinarySearch(array, 10, 1), 1);
			Assert::AreEqual(BinarySearch(array, 10, 2), 2);
			Assert::AreEqual(BinarySearch(array, 10, 3), 3);

			delete[] array;
		}
	};

