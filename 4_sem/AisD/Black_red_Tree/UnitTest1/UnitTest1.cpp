#include "pch.h"
#include "CppUnitTest.h"
#include "../Black_red_Tree/Black_red_Tree.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(testBalanceInsertDeleteGetKeys)
		{
			Tree<int, int> tree(7,10);
			tree.insert(8,8);
			tree.insert(9,12);
			tree.insert(10,11);
			tree.insert(11,6);
			tree.insert(12,3);

			Assert::AreEqual(tree.findElem(12)->color, true);
			Assert::AreEqual(tree.findElem(11)->color, false);
			Assert::AreEqual(tree.findElem(10)->color, true);
			Assert::AreEqual(tree.findElem(9)->color, false);
			Assert::AreEqual(tree.findElem(8)->color, false);
			Assert::AreEqual(tree.findElem(7)->color, false);

			auto keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 12);
			Assert::AreEqual(keys.at(1), 11);
			Assert::AreEqual(keys.at(2), 9);
			Assert::AreEqual(keys.at(3), 10);
			Assert::AreEqual(keys.at(4), 7);
			Assert::AreEqual(keys.at(5), 8);

			tree.insert(3, 6);
			tree.insert(25, 3);

			Assert::AreEqual(tree.findElem(12)->color, false);
			Assert::AreEqual(tree.findElem(11)->color, true);
			Assert::AreEqual(tree.findElem(10)->color, true);
			Assert::AreEqual(tree.findElem(9)->color, false);
			Assert::AreEqual(tree.findElem(8)->color, false);
			Assert::AreEqual(tree.findElem(7)->color, false);
			Assert::AreEqual(tree.findElem(3)->color, true);
			Assert::AreEqual(tree.findElem(25)->color, true);

			tree.remove(3);
			tree.remove(25);

			keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 11);
			Assert::AreEqual(keys.at(1), 12);
			Assert::AreEqual(keys.at(2), 9);
			Assert::AreEqual(keys.at(3), 10);
			Assert::AreEqual(keys.at(4), 7);
			Assert::AreEqual(keys.at(5), 8);

		}

		TEST_METHOD(testBalanceDeleted)
		{
			Tree<int, int> tree(7, 10);
			tree.insert(8, 8);
			tree.insert(9, 12);
			tree.insert(10, 11);
			tree.insert(11, 6);
			tree.insert(12, 3);

			Assert::AreEqual(tree.findElem(12)->color, true);
			Assert::AreEqual(tree.findElem(11)->color, false);
			Assert::AreEqual(tree.findElem(10)->color, true);
			Assert::AreEqual(tree.findElem(9)->color, false);
			Assert::AreEqual(tree.findElem(8)->color, false);
			Assert::AreEqual(tree.findElem(7)->color, false);

			tree.remove(10);

			auto keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 12);
			Assert::AreEqual(keys.at(1), 9);
			Assert::AreEqual(keys.at(2), 11);
			Assert::AreEqual(keys.at(3), 7);
			Assert::AreEqual(keys.at(4), 8);

			tree.remove(11);

			keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 9);
			Assert::AreEqual(keys.at(1), 12);
			Assert::AreEqual(keys.at(2), 7);
			Assert::AreEqual(keys.at(3), 8);

			tree.remove(12);

			keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 9);
			Assert::AreEqual(keys.at(1), 7);
			Assert::AreEqual(keys.at(2), 8);

			tree.remove(7);

			keys = tree.getKeys();

			Assert::AreEqual(keys.at(0), 9);
			Assert::AreEqual(keys.at(1), 8);

		}

		TEST_METHOD(testFindNode)
		{
			Tree<int, int> tree(7, 10);
			tree.insert(8, 8);
			tree.insert(9, 12);
			tree.insert(10, 11);
			tree.insert(11, 6);
			tree.insert(12, 3);


			Assert::IsTrue(tree.contains(8));
			Assert::IsTrue(tree.contains(9));
			Assert::IsTrue(tree.contains(10));
			

		}

		TEST_METHOD(testTreeContainsAndRemove) {
			Tree<int, int> tree(7, 10);

			Assert::IsFalse(tree.contains(777));
			Assert::IsTrue(tree.contains(7));
			
			bool b = true;

			try
			{
				tree.remove(777);
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);


		}

		TEST_METHOD(testClear)
		{
			Tree<int, int> tree(7, 10);
			tree.insert(8, 8);
			tree.insert(9, 12);
			tree.insert(10, 11);
			tree.insert(11, 6);
			tree.insert(12, 3);

			tree.clear();
			tree.insert(10, 11);
			Assert::IsTrue(tree.contains(10));


		}

		TEST_METHOD(testGetVal)
		{
			Tree<int, int> tree(7, 10);
			tree.insert(8, 8);
			tree.insert(9, 12);
			tree.insert(10, 11);
			tree.insert(11, 6);
			tree.insert(12, 3);

			auto keys = tree.getValues();

			Assert::AreEqual(keys.at(0), 3);
			Assert::AreEqual(keys.at(1), 6);
			Assert::AreEqual(keys.at(2), 12);
			Assert::AreEqual(keys.at(3), 11);
			Assert::AreEqual(keys.at(4), 10);
			Assert::AreEqual(keys.at(5), 8);


		}
	};
}
