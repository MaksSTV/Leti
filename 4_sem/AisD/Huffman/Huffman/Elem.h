#pragma once

template <class T_key, class T_value>
class Elem {
public:
	Elem* next_left, * next_right, * parent;
	T_key* data;
	T_value* val;
	bool color;// 1 - red, 0 - black


	Elem(T_key* data = nullptr, T_value* val = nullptr, Elem* next_left = nullptr, Elem* next_right = nullptr, Elem* parent = nullptr, bool color = true) :
		next_left(next_left), next_right(next_right), parent(parent), color(color) {

		if ((data == nullptr) && (val != nullptr)) {
			throw std::invalid_argument("Sorry, but you mom?");
		}
		if ((data != nullptr) && (val == nullptr)) {
			throw std::invalid_argument("Sorry, but you daddy?");
		}

		if ((data != nullptr) && (val != nullptr)) {
			T_key* digit = new T_key(*data);
			this->data = digit;

			T_value* parametr = new T_value(*val);
			this->val = parametr;
		}
		else {
			this->val = nullptr;
			this->data = nullptr;
		}
	}

	~Elem() = default;
};