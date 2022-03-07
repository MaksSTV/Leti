#ifndef DFT_ITERATOR
#pragma once

#include "Stack.h"
#include "Iterator.h"
#include "Elem.h"

template<class T_key, class T_value>
class dft_iterator : public Iterator<T_key>{
public:

	dft_iterator(Elem<T_key, T_value>* root);

	~dft_iterator();

	bool has_next() override;

	T_key next() override;

	Elem<T_key, T_value>* getCur() {
		return this->cur;//да
	}

private:

	Stack<Elem<T_key, T_value>*>* stack;

	Elem<T_key, T_value>* cur;
};



template<class T_key, class T_value>
inline dft_iterator<T_key, T_value>::dft_iterator(Elem<T_key, T_value>* root)
{
	cur = root;
	stack = new Stack<Elem<T_key, T_value>*>();
}

template<class T_key, class T_value>
inline dft_iterator<T_key, T_value>::~dft_iterator()
{
	delete stack;
}

template<class T_key, class T_value>
inline bool dft_iterator<T_key, T_value>::has_next()
{
	return cur != nullptr;
}

template<class T_key, class T_value>
inline T_key dft_iterator<T_key, T_value>::next()
{
	if (!has_next()) {
		throw std::out_of_range("No more elements");
	}

	T_key temp = *(cur->data);

	if (cur->next_right != nullptr) {
		stack->push(cur->next_right);
	}

	if (cur->next_left != nullptr) {
		cur = cur->next_left;
	}
	else {
		try {
			cur = stack->peek();
			stack->pop();
		}
		catch (std::out_of_range) {
			cur = nullptr;
		}
	}

	return temp;
}


#endif // !DFT_ITERATOR


