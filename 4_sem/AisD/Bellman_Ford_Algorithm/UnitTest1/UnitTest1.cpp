#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Bellman_Ford_Algorithm.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestAlgorithm)
		{
			List<Edge> edge; 
			edge.push_back(Edge{ "Saint Petersburg", "Vladivostok", 20, 0, 3 });
			edge.push_back(Edge{ "Khabarovsk", "Vladivostok", 8, 2, 3 });
			edge.push_back(Edge{ "Vladivostok", "Khabarovsk", 13, 3, 2 });
			edge.push_back(Edge{ "Saint Petersburg", "Khabarovsk", 14, 0, 2 });
			edge.push_back(Edge{ "Khabarovsk", "Moscow", 35, 2, 1 });
			edge.push_back(Edge{ "Moscow", "Khabarovsk", 40, 1, 2 });
			edge.push_back(Edge{ "Moscow", "Saint Petersburg", 20, 1, 0 });
			edge.push_back(Edge{ "Saint Petersburg", "Moscow", 10, 0, 1 });

			List<std::string> vertices;
			vertices.push_back("Saint Petersburg");
			vertices.push_back("Moscow");
			vertices.push_back("Khabarovsk");
			vertices.push_back("Vladivostok");

			int requiredPath = INT_MAX - 10000;

			requiredPath = algorithm(&edge, &vertices, "Moscow", "Khabarovsk");
			Assert::AreEqual(requiredPath, 34);
			requiredPath = algorithm(&edge, &vertices, "Moscow", "Saint Petersburg");
			Assert::AreEqual(requiredPath, 20);
			requiredPath = algorithm(&edge, &vertices, "Moscow", "Vladivostok");
			Assert::AreEqual(requiredPath, 40);
			requiredPath = algorithm(&edge, &vertices, "Moscow", "Moscow");
			Assert::AreEqual(requiredPath, INT_MAX - 10000);

			requiredPath = algorithm(&edge, &vertices, "Saint Petersburg", "Khabarovsk");
			Assert::AreEqual(requiredPath, 14);
			requiredPath = algorithm(&edge, &vertices, "Saint Petersburg", "Saint Petersburg");
			Assert::AreEqual(requiredPath, INT_MAX - 10000);
			requiredPath = algorithm(&edge, &vertices, "Saint Petersburg", "Moscow");
			Assert::AreEqual(requiredPath, 10);
			requiredPath = algorithm(&edge, &vertices, "Saint Petersburg", "Vladivostok");
			Assert::AreEqual(requiredPath, 20);

			requiredPath = algorithm(&edge, &vertices, "Khabarovsk", "Khabarovsk");
			Assert::AreEqual(requiredPath, INT_MAX - 10000);
			requiredPath = algorithm(&edge, &vertices, "Khabarovsk", "Saint Petersburg");
			Assert::AreEqual(requiredPath, 55);
			requiredPath = algorithm(&edge, &vertices, "Khabarovsk", "Moscow");
			Assert::AreEqual(requiredPath, 35);
			requiredPath = algorithm(&edge, &vertices, "Khabarovsk", "Vladivostok");
			Assert::AreEqual(requiredPath, 8);

			requiredPath = algorithm(&edge, &vertices, "Vladivostok", "Khabarovsk");
			Assert::AreEqual(requiredPath, 13);
			requiredPath = algorithm(&edge, &vertices, "Vladivostok", "Saint Petersburg");
			Assert::AreEqual(requiredPath, 68);
			requiredPath = algorithm(&edge, &vertices, "Vladivostok", "Moscow");
			Assert::AreEqual(requiredPath, 48);
			requiredPath = algorithm(&edge, &vertices, "Vladivostok", "Vladivostok");
			Assert::AreEqual(requiredPath, INT_MAX - 10000);
		}
	};
}
