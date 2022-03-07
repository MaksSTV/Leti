// Black_red_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template <class T_key, class T_value>
class Tree {
	private:
		class Elem {
		public:
			Elem* next_left, * next_right, * parent;
			T_key* data;
			T_value* val;
			bool color;// 1 - red, 0 - black

			
			Elem(T_key* data = nullptr, T_value* val = nullptr, Elem* next_left = nullptr, Elem* next_right = nullptr, Elem* parent = nullptr, bool color = true) :
				next_left(next_left), next_right(next_right), parent(parent), color(color){
				
				if ((data == nullptr) && (val != nullptr)) {
					throw std::invalid_argument("Sorry, but you mom?");
				}
				if ((data != nullptr) && (val == nullptr)) {
					throw std::invalid_argument("Sorry, but you daddy?");
				}
				
				if ((data != nullptr)&&(val != nullptr)) {
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

		Elem* root;

		//int* digit = new int(*data);
		//this->data = digit;
		
	public:
		Tree() { // create blank list
			this->root = nullptr;
		}

		Tree(T_key data, T_value val) { // create list with one element
			Elem* elem = new Elem(&data, &val);
			this->root = elem;
			this->root->color = false; // root only black

			Elem* right_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);
			Elem* left_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);

			root->next_left = left_nil;
			left_nil->parent = root;

			root->next_right = right_nil;
			right_nil->parent = root;
		}

		int getLeftPointer() {
			Elem* tmp = root;
			tmp = tmp->next_left->next_left;
			rightRotate(tmp);
			return *tmp->data;
		}

		int getRightPointer() {
			Elem* tmp = root;
			tmp = tmp->next_left->next_right;
			leftRotate(tmp);
			return *tmp->data;
		}

		

		void insert(T_key key, T_value val) {// root = 8
			if (root == nullptr) {
				Elem* elem = new Elem(&key, &val);
				this->root = elem;
				this->root->color = false;

				Elem* right_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);
				Elem* left_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);

				root->next_left = left_nil;
				left_nil->parent = root;

				root->next_right = right_nil;
				right_nil->parent = root;
			}
			else {
				Elem* temp = new Elem(&key, &val);//8
				Elem* cur = root;//10
			
				while (true) {
					if (*temp->data > *cur->data) {
						if (cur->next_right->data == nullptr) {
							cur->next_right = temp;
							temp->parent = cur;
							break;
						}
						else {
							cur = cur->next_right;
						}
					}
					else {
						if (cur->next_left->data == nullptr) {
							cur->next_left = temp;
							temp->parent = cur;
							break;
						}
						else {
							cur = cur->next_left;
						}
					}
				}

				Elem* right_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);
				Elem* left_nil = new Elem(nullptr, nullptr, nullptr, nullptr, nullptr, false);

				temp->next_left = left_nil;
				left_nil->parent = temp;

				temp->next_right = right_nil;
				right_nil->parent = temp;


			}
		}

		void leftRotate(Elem* y){
			// now 'y' is son of 'x'
			// and 'z' is grandPa of 'x'
			Elem* x = y->parent;
			Elem* z = x->parent;
			if (x->parent == nullptr) {
				z = nullptr;
			}
			else {
				z = x->parent;
			}

			if (y->next_left->data != nullptr) {
				x->next_right = y->next_left;
			}

			if (z == nullptr) {
				y = root;
			}
			else if (z->next_left == x) {
				z->next_left = y;
				y->parent = z;
			}
			else {
				z->next_right = y;		
				y->parent = z;
			}

			x->next_right = y->next_left;
			y->next_left = x;		// y->next_left = x->next_right;
			x->parent = y;			// x->next_right = y;
		}							// y->parent = x;

		void rightRotate(Elem* x){
			// now 'x' is son of 'y'
			// and 'z' is grandPa of 'y'
			Elem* y = x->parent;
			Elem* z;
			if (y->parent == nullptr) {
				z = nullptr;
			}
			else {
				z = y->parent;
			}

			if (x->next_right->data != nullptr) {
				y->next_left = x->next_right;
			}

			if (z == nullptr) {
				x = root;		
			}
			else if (z->next_right == y) {
				z->next_right = x;
				x->parent = z;
			}	
			else {
				z->next_left = x;
				x->parent = z;
			}

			y->next_left = x->next_right;
			x->next_right = y;
			y->parent = x;

		}

		void leftRightRotate(Elem* y){
		leftRotate(y);
		rightRotate(y);
	}

		void rightLeftRotate(Elem* y){
		rightRotate(y);
		leftRotate(y);
	}
};

int main()
{

	// не рабочая хуета
	Tree<int, std::string> bucha(10, "Pudge");

	bucha.insert(8, "Ancent_Apparation");
	bucha.insert(12, "Mirana");
	bucha.insert(11, "Troll_Warlord");
	bucha.insert(6, "Spirit_Braker");
	bucha.insert(3, "Zeus");

	int *a = new int(bucha.getLeftPointer());
	
	std::cout << *a << std::endl;

	int* b = new int(bucha.getRightPointer());

	std::cout << *b << std::endl;

	system("pause");
	return 0;
}
