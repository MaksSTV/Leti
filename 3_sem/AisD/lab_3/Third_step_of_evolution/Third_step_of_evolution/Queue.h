#ifndef QUEUE_H
#pragma once

template <class T>
class Queue {
private:

	class Elem_queue {
	
	public:

		Elem_queue* next;
		T data;

		Elem_queue(T data = 0, Elem_queue* next = NULL) : data(data), next(next) {}
		~Elem_queue() = default;

		void setNext(Elem_queue* newnext) {
			this->next = newnext;
		}

		Elem_queue* getNext() {
			return this->next;
		}

		T getElemdata() {
			return this->data;
		}
	};

	Elem_queue* head, * last;

public:

	Queue() { // create blank list
		this->head = NULL;
		this->last = this->head;
	}

	Queue(T data) { // create list with one element
		Elem_queue* elem = new Elem_queue(data);
		this->head = elem;
		this->last = elem;
	}

	void enqueue(T item) { // new last elem
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

	T front();
};

template<class T>
inline T Queue<T>::front()
{
	return head->getElemdata();
}

#endif // !QUEUE_H