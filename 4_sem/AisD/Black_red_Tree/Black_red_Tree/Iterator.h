#ifndef ITERATOR_H
#pragma once


template <class T_key>
class Iterator {
public:
	virtual T_key next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};

#endif // !ITERATOR_H