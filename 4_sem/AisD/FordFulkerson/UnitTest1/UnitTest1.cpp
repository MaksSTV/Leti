#include "pch.h"
#include "CppUnitTest.h"

#include "..//FordFulkerson/Algorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			List<Vertex> test;
			test.push_back(Vertex{ "S", "O", 3, 0, 1 });
			test.push_back(Vertex{ "S", "P", 3, 0, 2 });
			test.push_back(Vertex{ "O", "Q", 3, 1, 3 });
			test.push_back(Vertex{ "O", "P", 2, 1, 2 });
			test.push_back(Vertex{ "P", "R", 2, 2, 4 });
			test.push_back(Vertex{ "Q", "R", 4, 3, 4 });
			test.push_back(Vertex{ "Q", "T", 2, 3, 5 });
			test.push_back(Vertex{ "R", "T", 3, 4, 5 });

			List<std::string> vertices;
			vertices.push_back("S");
			vertices.push_back("O");
			vertices.push_back("P");
			vertices.push_back("Q");
			vertices.push_back("R");
			vertices.push_back("T");

			Assert::AreEqual(findMaxFlow(test, vertices), 5);
		}

		TEST_METHOD(TestMethod2)
		{
			List<Vertex> test;
			test.push_back(Vertex{ "S", "B", 7, 0, 1 });
			test.push_back(Vertex{ "S", "C", 4, 0, 2 });
			test.push_back(Vertex{ "B", "C", 4, 1, 2 });
			test.push_back(Vertex{ "B", "E", 2, 1, 3 });
			test.push_back(Vertex{ "C", "E", 8, 2, 3 });
			test.push_back(Vertex{ "C", "D", 4, 2, 4 });
			test.push_back(Vertex{ "E", "D", 4, 3, 4 });
			test.push_back(Vertex{ "E", "T", 5, 3, 5 });
			test.push_back(Vertex{ "D", "T", 12, 4, 5 });

			List<std::string> vertices;
			vertices.push_back("S");//1
			vertices.push_back("B");//2
			vertices.push_back("C");//3
			vertices.push_back("E");//4
			vertices.push_back("D");//5
			vertices.push_back("T");//6

			Assert::AreEqual(findMaxFlow(test, vertices), 10);
		}
	};
}
