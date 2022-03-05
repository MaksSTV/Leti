#include "pch.h"
#include "CppUnitTest.h"
#include "../Black_red_Tree/Black_red_Tree.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Rotate)
		{
			Tree bucha(10);
			bucha.insert(8);
			bucha.insert(12);
			bucha.insert(11);
			bucha.insert(6);
			bucha.insert(3);

			

		}
	};
}
