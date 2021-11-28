#ifndef QUEUE_H
#pragma once

#include <iostream>

using namespace std;
template <class T>
class Queue
{
private:
	class Elem_queue
	{
	private:
		
	public:
		Elem_queue(T data = 0, Elem_queue* next = NULL) : data(data), next(next) {}
		T data;
		Elem_queue* next;
		
	};

	Elem_queue* head, *last;

public:
	Queue();

	~Queue();

	void dequeue();

	void enqueue(T);

	bool isEmpty();

	T front();

};

template <class T> Queue<T>::Queue()
{
	head = NULL;
	last = NULL;
}

template <class T> Queue<T>::~Queue()
{
	while (!isEmpty()){
		dequeue();
	}
}

template <class T> void Queue<T>::enqueue(T data)
{
	Elem_queue* temp = new Elem_queue(data);
	if (isEmpty())
	{
		head = temp;
		last = head;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

template <class T> void Queue<T>::dequeue()
{
	if (isEmpty()) {
		throw out_of_range("No more elements");
	}
	else {
		Elem_queue* temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T> bool Queue<T>::isEmpty()
{
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> T Queue<T>::front()
{
	if (isEmpty()) {
		throw out_of_range("Empty");
	}
	else {
		return head->data;
	}
}

#endif // !QUEUE_H