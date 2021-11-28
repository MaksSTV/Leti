#include "pch.h"
#include "CppUnitTest.h"
#include "../Third_step_of_evolution/Heap.h"
#include "../Third_step_of_evolution/Iterator.h"
#include "../Third_step_of_evolution/Queue.h"
#include "../Third_step_of_evolution/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(test_stack)
		{
			Stack<int> stack;

			for (int index = 0; index < 5; index++) {
				stack.push(index);
			}
			
			for (int jndex = 4; jndex >= 0; jndex--) {
				Assert::AreEqual(jndex, stack.peek());
				stack.pop();
			}

			Assert::IsTrue(stack.isEmpty());
			stack.push(12);
			Assert::IsFalse(stack.isEmpty());
			stack.pop();

			bool b = true;
			try
			{
				stack.peek();
			}
			catch (std::out_of_range)
			{
				b = false;
			}
			Assert::IsFalse(b);

			b = true;
			try
			{
				stack.pop();
			}
			catch (std::out_of_range)
			{
				b = false;
			}
			Assert::IsFalse(b);
		}

		TEST_METHOD(test_queue) {
			Queue<int> queue;

			for (int index = 0; index < 5; index++) {
				queue.enqueue(index);
			}

			for (int jndex = 4; jndex >= 0; jndex--) {
				Assert::AreEqual(4-jndex, queue.front());
				queue.dequeue();
			}
			
			Assert::IsTrue(queue.isEmpty());
			queue.enqueue(12);
			Assert::IsFalse(queue.isEmpty());
			queue.dequeue();

			bool b = true;
			try
			{
				queue.front();
			}
			catch (std::out_of_range)
			{
				b = false;
			}
			Assert::IsFalse(b);

			b = true;
			try
			{
				queue.dequeue();
			}
			catch (std::out_of_range)
			{
				b = false;
			}
			Assert::IsFalse(b);
		}

		TEST_METHOD(test_heap_contains_and_remove) {
			Heap heap(12);

			Assert::IsFalse(heap.contains(777));
			Assert::IsTrue(heap.contains(12));

			bool b = true;

			try
			{
				heap.remove(777);
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);
			

		}

		TEST_METHOD(test_heap) {
			Heap heap(12);

			heap.insert(2);  //				12
			heap.insert(4);	 //			   /  \ 
			heap.insert(6);  //			  6    4 <- last_parent
			heap.insert(5);  //			 / \
							 //         2   5

			int last_parent = 0;
			Iterator* dft_1;
			dft_1 = heap.create_dft_iterator();
			if (dft_1->has_next()) {
				while (dft_1->has_next()) {
					last_parent = dft_1->next();
					if (last_parent == 4) { break; }
				}
			}
			Assert::AreEqual(4, last_parent);
			delete dft_1;
			heap.remove(2);  //				    12
			heap.remove(5);  //			       /  \ 
						     //last_parent -> 6    4 

			Iterator* dft_2;
			dft_2 = heap.create_dft_iterator();
			if (dft_2->has_next()) {
				while (dft_2->has_next()) {
					last_parent = dft_2->next();
					if (last_parent == 6) { break; }
				}
			}
			Assert::AreEqual(6, last_parent);
		
			delete dft_2;

			Heap heap_2;
			heap_2.insert(12);
			heap_2.insert(13);
			heap_2.insert(14);

			Iterator* dft_3;
			int count_node = 0;
			dft_3 = heap_2.create_dft_iterator();
			if (dft_3->has_next()) {
				while (dft_3->has_next()) {
					dft_3->next();
					count_node++;
				}
			}
			Assert::AreEqual(3, count_node);

			delete dft_3;
		}

		TEST_METHOD(test_dft) {
			Heap flesh_heap(1);
			Iterator* dft;
			int Array[9];

			flesh_heap.insert(2);
			flesh_heap.insert(30);
			flesh_heap.insert(4);
			flesh_heap.insert(5);
			flesh_heap.insert(100);
			flesh_heap.insert(40);
			flesh_heap.insert(6);
			flesh_heap.insert(7);
			
			int i = 0;
			dft = flesh_heap.create_dft_iterator();
			if (dft->has_next()) {
				while (dft->has_next()) {
					Array[i++] = dft->next();
				}
			}
			i = 0;

			Assert::AreEqual(100, Array[i++]);
			Assert::AreEqual(7, Array[i++]);
			Assert::AreEqual(6, Array[i++]);
			Assert::AreEqual(1, Array[i++]);
			Assert::AreEqual(5, Array[i++]);
			Assert::AreEqual(4, Array[i++]);
			Assert::AreEqual(40, Array[i++]);
			Assert::AreEqual(2, Array[i++]);
			Assert::AreEqual(30, Array[i++]);
			delete dft;

		}

		TEST_METHOD(test_bft) {
			Heap flesh_heap(1);
			Iterator* bft;
			int Array[9];

			flesh_heap.insert(2);
			flesh_heap.insert(30);
			flesh_heap.insert(4);
			flesh_heap.insert(5);
			flesh_heap.insert(100);
			flesh_heap.insert(40);
			flesh_heap.insert(6);
			flesh_heap.insert(7);

			int i = 0;
			bft = flesh_heap.create_bft_iterator();
			if (bft->has_next()) {
				while (bft->has_next()) {
					Array[i++] = bft->next();
				}
			}
			i = 0;

			Assert::AreEqual(100, Array[i++]);
			Assert::AreEqual(7, Array[i++]);
			Assert::AreEqual(40, Array[i++]);
			Assert::AreEqual(6, Array[i++]);
			Assert::AreEqual(4, Array[i++]);
			Assert::AreEqual(2, Array[i++]);
			Assert::AreEqual(30, Array[i++]);
			Assert::AreEqual(1, Array[i++]);
			Assert::AreEqual(5, Array[i++]);
			delete bft;

		}
	};
}
