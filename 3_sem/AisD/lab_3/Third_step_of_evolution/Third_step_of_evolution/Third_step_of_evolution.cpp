// Third_step_of_evolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Heap {
	private:
		class Elem {
			private:
				Elem *next_left, *next_right, *parent;
				int data;
			public:

		};

	public:

	
};

class Stack {
	private:

		class Elem_stack {
			private:
				Elem_stack* next;
				int data;
			public:
				Elem_stack(int data = 0, Elem_stack* next = NULL) : data(data), next(next){}
				~Elem_stack() = default;

				void setNext(Elem_stack* newnext) {
					this->next = newnext;
				}

				Elem_stack* getNext() {
					return this->next;
				}

				int getElemdata() {
					return this->data;
				}
		};

		Elem_stack* head, * last;

	public:

		Stack() { // create blank list
			this->head = NULL;
			this->last = this->head;
		}

		Stack(int data) { // create list with one element
			Elem_stack* elem = new Elem_stack(data);
			this->head = elem;
			this->last = elem;
		}

		void push(int item) {
			if (head == NULL) {
				Elem_stack* elem = new Elem_stack(item);
				this->head = elem;
				this->last = elem;
			}
			else {
				Elem_stack* temp = new Elem_stack(item);
				Elem_stack* cur = head; // 1
				this->head = temp; // 2
				this->head->setNext(cur); // 3
			}
		}

		void pop() {
			Elem_stack* cur = head;
			head = head->getNext();
			//std::cout << cur->getElemdata() << "\n";
			delete cur;
		}

		int peek() {
			return head->getElemdata();
		}

		bool isEmpty() {
			if (head == NULL) {
				return true;
			}
			else {
				return false;
			}
		}
			
		size_t size() {
			Elem_stack* cur = head;
			int count = 0;
			while (cur != NULL) {
				count++;
				cur = cur->getNext();
			}
			return count;
		}

		void print() { // FIX ME!! Need remake, after doing methods peek and size
			Elem_stack* cur = head;
			while (cur != NULL) {
				std::cout << cur->getElemdata() << "\n";
				cur = cur->getNext();
			}
			std::cout << std::endl;
		}

};

class Queue {
private:

	class Elem_queue {
	private:
		Elem_queue* next;
		int data;
	public:
		Elem_queue(int data = 0, Elem_queue* next = NULL) : data(data), next(next) {}
		~Elem_queue() = default;

		void setNext(Elem_queue* newnext) {
			this->next = newnext;
		}

		Elem_queue* getNext() {
			return this->next;
		}

		int getElemdata() {
			return this->data;
		}
	};

	Elem_queue* head, * last;

public:

	Queue() { // create blank list
		this->head = NULL;
		this->last = this->head;
	}

	Queue(int data) { // create list with one element
		Elem_queue* elem = new Elem_queue(data);
		this->head = elem;
		this->last = elem;
	}

	void enqueue(int item) { // new last elem
		if (head == NULL) {
			Elem_queue* elem = new Elem_queue(item);
			this->head = elem;
			this->last = elem;
		}
		else {
			Elem_queue* temp = new Elem_queue(item);
			Elem_queue* cur = last; // 1
			this->last = temp; // 2
			cur->setNext(last); // 3
		}
	}

	void dequeue() { // delete head elem
		Elem_queue* cur = head;
		head = head->getNext();
		delete cur;
	}


	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	size_t size() {
		Elem_queue* cur = head;
		int count = 0;
		while (cur != NULL) {
			count++;
			cur = cur->getNext();
		}
		return count;
	}

	void print() { // FIX ME!! Need remake, after doing methods peek and size
		Elem_queue* cur = head;
		while (cur != NULL) {
			std::cout << cur->getElemdata() << "\n";
			cur = cur->getNext();
		}
		std::cout << std::endl;
	}
};

int main()
{
	Stack stack(12);
	stack.push(13);
	stack.push(14);
	stack.push(15);
	stack.push(16);

	std::cout << "Stack size: " << stack.size()<<"\n";

	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	std::cout << stack.peek()<<"\n";

	std::cout << "Stack size: " << stack.size() << "\n";

	Queue queue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);

	std::cout << "Queue size: " << queue.size() << "\n";

	queue.print();

	queue.dequeue();
	queue.dequeue();

	std::cout << "Queue size: " << queue.size() << "\n";

	queue.print();

	system("pause");
	return 0;
}
