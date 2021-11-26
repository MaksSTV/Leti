#ifndef ITERATOR_H
#pragma once

class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};

#endif // !ITERATOR_H