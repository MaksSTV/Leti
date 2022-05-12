#ifndef TREE_H
#define TREE_H 
#pragma once

#include <iostream>

#include "Stack.h"
#include "Iterator.h"
#include "DFT_iterator.h"
#include "Elem.h"
#include "LinkedList.h"
#include "Color.h"

template<typename T1, typename T2, typename T3>
class Red_Black_Tree
{
	private:

		class ElemRBT{

			public:

				int color;
				T1 key;
				T2 value;
				T3 code;
				ElemRBT* next_left, * next_right, * parent;


				ElemRBT(int color = red, T1 key = 0, T2 value = 0, ElemRBT* parent_node = nullptr, T3 code = "", ElemRBT* next_left = nullptr, ElemRBT* right_node = nullptr) 
					: color(color), key(key), value(value), code(code), parent(parent_node), next_left(next_left), next_right(right_node) {}

				~ElemRBT(){
					color = 0;
					key = 0;
					value = 0;
					code = "";
					parent = nullptr;
					next_left = nullptr;
					next_right = nullptr;
				}

		};

		size_t size_tree;
		ElemRBT* root, *nil;

	public:

		Red_Black_Tree(){
			size_tree = 0;
			root = nullptr;
			nil = new ElemRBT(black);
		}

		~Red_Black_Tree(){
			clear();
			size_tree = 0;
			root = nullptr;
			nil = nullptr;
		}

		ElemRBT* get_root_node(){
			if (getSize() != 0){
				return root;
			}
			else throw std::invalid_argument("Red-black tree (associative array) is empty");
		};

		size_t getSize(){
			return size_tree;
		}

		ElemRBT* get_nil_node(){
			if (getSize() != 0){
				return nil;
			}
			else throw std::invalid_argument("Red-black tree (associative array) is empty");
		}

		void insert(T1 key, T2 value){
			if (getSize() != 0){
				bool New_element_added(false);
				ElemRBT* current_element = root;
				while (!New_element_added){
					if (key > current_element->key && (current_element->next_right == nullptr || current_element->next_right == nil)){
						current_element->next_right = new ElemRBT(red, key, value, current_element);
						current_element->next_right->next_left = nil;
						current_element->next_right->next_right = nil;
						Restoring_properties_insert(current_element->next_right);
						New_element_added = true;
						size_tree++;
					}
					else if (key < current_element->key && (current_element->next_left == nullptr || current_element->next_left == nil)){
						current_element->next_left = new ElemRBT(red, key, value, current_element);
						current_element->next_left->next_left = nil;
						current_element->next_left->next_right = nil;
						Restoring_properties_insert(current_element->next_left);
						New_element_added = true;
						size_tree++;
					}
					else if (key > current_element->key){
						current_element = current_element->next_right;
					}
					else if (key < current_element->key){
						current_element = current_element->next_left;
					}
					else if (key == current_element->key){
						throw std::invalid_argument("An associative array cannot contain elements with the same keys");
					}
				}
			}
			else{
				root = new ElemRBT(black, key, value);
				if (nil == nullptr) nil = new ElemRBT(black);
				root->next_left = nil;
				root->next_right = nil;
				root->parent = nil;
				nil->next_left = root;
				nil->next_right = root;
				size_tree++;
			}
		}

		void Left_turn(ElemRBT* element_x){
			ElemRBT* element_y = element_x->next_right;

			if (element_y->next_left != nullptr){
				element_x->next_right = element_y->next_left;
				if (element_y->next_left != nil) element_y->next_left->parent = element_x;
				element_y->next_left = nullptr;
				element_y->parent = nullptr;
			}

			if (element_x->parent == nil){
				root = element_y;
				element_y->parent = nil;
				nil->next_left = element_y;
				nil->next_right = element_y;
			}

			else if (element_x->parent->next_left == element_x){
				element_x->parent->next_left = element_y;
				element_y->parent = element_x->parent;
			}
			else{
				element_x->parent->next_right = element_y;
				element_y->parent = element_x->parent;
			}
			element_x->parent = element_y;
			element_y->next_left = element_x;
		}


		void Right_turn(ElemRBT* element_y){
			ElemRBT* element_x = element_y->next_left;
			if (element_x->next_right != nullptr){
				element_y->next_left = element_x->next_right;
				if (element_x->next_right != nil) element_x->next_right->parent = element_y;
				element_x->next_right = nullptr;
				element_x->parent = nullptr;
			}
			if (element_y->parent == nil){
				root = element_x;
				element_x->parent = nil;
				nil->next_left = element_x;
				nil->next_right = element_x;
			}
			else if (element_y->parent->next_right == element_y){
				element_y->parent->next_right = element_x;
				element_x->parent = element_y->parent;
			}
			else
			{
				element_y->parent->next_left = element_x;
				element_x->parent = element_y->parent;
			}
			element_y->parent = element_x;
			element_x->next_right = element_y;
		}

		void Restoring_properties_insert(ElemRBT* new_node){
			while (new_node->parent->color == red && new_node != root){
				if (new_node->parent->parent->next_left == new_node->parent){
					if (new_node->parent->parent->next_right->color == red){
						new_node->parent->parent->next_right->color = black;
						new_node->parent->color = black;
						new_node->parent->parent->color = red;
						new_node = new_node->parent->parent;
					}
					else if (new_node->parent->next_right == new_node){
						new_node = new_node->parent;
						Left_turn(new_node);
					}
					else{
						new_node->parent->color = black;
						new_node->parent->parent->color = red;
						Right_turn(new_node->parent->parent);
					}
				}
				else if (new_node->parent->parent->next_right == new_node->parent){
					if (new_node->parent->parent->next_left->color == red){
						new_node->parent->parent->next_left->color = black;
						new_node->parent->color = black;
						new_node->parent->parent->color = red;
						new_node = new_node->parent->parent;
					}
					else if (new_node->parent->next_left == new_node){
						new_node = new_node->parent;
						Right_turn(new_node);
					}
					else{
						new_node->parent->color = black;
						new_node->parent->parent->color = red;
						Left_turn(new_node->parent->parent);
					}
				}
			}
			root->color = black;
		}

		bool find(T1 key){
			if (getSize() != 0){
				bool Element_found(false);
				ElemRBT* current_element = root;
				while (!Element_found){
					if (key == current_element->key){
						return true;
					}
					else if (key > current_element->key){
						current_element = current_element->next_right;
					}
					else if (key < current_element->key){
						current_element = current_element->next_left;
					}
					if (current_element == nil){
						return false;
					}
				}
			}
			else throw std::invalid_argument("The element cannot be found because the associative array is empty");
		}

		ElemRBT* getElem(T1 key){
			if (getSize() != 0 && find(key)){
				bool Element_found(false);
				ElemRBT* current_element = root;
				while (!Element_found){
					if (key == current_element->key){
						return current_element;
					}
					else if (key > current_element->key){
						current_element = current_element->next_right;
					}
					else if (key < current_element->key){
						current_element = current_element->next_left;
					}
				}
			}
			else throw std::invalid_argument("The element could not be found");
		}

		void remove(T1 key){
			if (find(key)){
				bool Element_removed(false);
				ElemRBT* delete_node = root;
				while (!Element_removed){
					if (key == delete_node->key){
						int original_color = delete_node->color;
						if (delete_node->next_left == nil && delete_node->next_right == nil && delete_node == root){
							nil->next_left = nullptr;
							nil->next_right = nullptr;
							delete delete_node;
							Element_removed = true;
							size_tree = 0;
						}
						else{
							if (delete_node->next_left == nil){
								ElemRBT* element_x = delete_node->next_right;
								if (delete_node == root){
									root = element_x;
									nil->next_left = element_x;
									nil->next_right = element_x;
								}
								if (delete_node->parent->next_left == delete_node)
									delete_node->parent->next_left = element_x;
								else delete_node->parent->next_right = element_x;
								element_x->parent = delete_node->parent;
								delete delete_node;
								Element_removed = true;
								size_tree--;
								if (original_color == black) Restoring_properties_remove(element_x);
							}
							else if (delete_node->next_right == nil){
								ElemRBT* element_x = delete_node->next_left;
								if (delete_node == root){
									root = element_x;
									nil->next_left = element_x;
									nil->next_right = element_x;
								}
								if (delete_node->parent->next_left == delete_node)
									delete_node->parent->next_left = element_x;
								else delete_node->parent->next_right = element_x;
								element_x->parent = delete_node->parent;
								delete delete_node;
								Element_removed = true;
								size_tree--;
								if (original_color == black) Restoring_properties_remove(element_x);
							}
							else{
								ElemRBT* element_y = delete_node->next_right;
								while (element_y->next_left != nil) element_y = element_y->next_left;
								if (delete_node == root){
									root = element_y;
									nil->next_left = element_y;
									nil->next_right = element_y;
								}
								original_color = element_y->color;
								ElemRBT* element_x = element_y->next_right;
								if (element_y->parent == delete_node){
									element_x->parent = element_y;
								}
								else{
									element_y->parent->next_left = element_x;
									element_x->parent = element_y->parent;
									element_y->next_right = delete_node->next_right;
									delete_node->next_right->parent = element_y;
								}
								if (delete_node->parent != nil){
									if (delete_node->parent->next_left == delete_node)
										delete_node->parent->next_left = element_y;
									else delete_node->parent->next_right = element_y;
								}
								element_y->parent = delete_node->parent;
								element_y->next_left = delete_node->next_left;
								delete_node->next_left->parent = element_y;
								element_y->color = delete_node->color;
								delete delete_node;
								Element_removed = true;
								size_tree--;
								if (original_color == black) Restoring_properties_remove(element_x);
							}
						}
					}
					else if (key > delete_node->key){
						delete_node = delete_node->next_right;
					}
					else if (key < delete_node->key){
						delete_node = delete_node->next_left;
					}
				}
			}
			else throw std::invalid_argument("An element with such a key is missing in the array");
		}

		void Restoring_properties_remove(ElemRBT* element_x){
			ElemRBT* brother_node;
			while (element_x != root && element_x->color == black){

				if (element_x->parent->next_left == element_x){
					brother_node = element_x->parent->next_right;

					if (brother_node->color == red){
						brother_node->color = black;
						element_x->parent->color = red;
						Left_turn(element_x->parent);
						brother_node = element_x->parent->next_right;
					}
					if (brother_node->next_left->color == black && brother_node->next_right->color == black){
						brother_node->color = red;
						element_x = element_x->parent;
						if (nil->parent != nullptr) nil->parent = nullptr;
					}
					else{
						if (brother_node->next_right->color == black){
							brother_node->next_left->color = black;
							brother_node->color = red;
							Right_turn(brother_node);
							brother_node = element_x->parent->next_right;
						}
						brother_node->color = element_x->parent->color;
						element_x->parent->color = black;
						brother_node->next_right->color = black;
						Left_turn(element_x->parent);
						nil->parent = nullptr;
						element_x = root;
					}
				}
				else if (element_x->parent->next_right == element_x){
					brother_node = element_x->parent->next_left;
					if (brother_node->color == red){
						brother_node->color = black;
						element_x->parent->color = red;
						Right_turn(element_x->parent);
						brother_node = element_x->parent->next_left;
					}
					if (brother_node->next_left->color == black && brother_node->next_right->color == black){
						brother_node->color = red;
						element_x = element_x->parent;
						if (nil->parent != nullptr) nil->parent = nullptr;
					}
					else{
						if (brother_node->next_left->color == black){
							brother_node->next_right->color = black;
							brother_node->color = red;
							Left_turn(brother_node);
							brother_node = element_x->parent->next_left;
						}
						brother_node->color = element_x->parent->color;
						element_x->parent->color = black;
						brother_node->next_left->color = black;
						Right_turn(element_x->parent);
						nil->parent = nullptr;
						element_x = root;
					}
				}
			}
			element_x->color = black;
		}

		void clear(){
			if (getSize() != 0){
				while (getSize() != 0){
					remove(root->key);
				}
				delete nil;
				nil = nullptr;
				root = nullptr;
				size_tree = 0;
			}
		}

		class Queue{
			class Queue_element{
				public:
					ElemRBT* data;
					Queue_element* next;

					Queue_element(ElemRBT* data = nullptr, Queue_element* next = nullptr){
						this->data = data;
						this->next = next;
					}
					~Queue_element(){
						data = nullptr;
						next = nullptr;
					}
			};

			Queue_element* head; // Pointer to the beginning of the queue
			Queue_element* tail; // Pointer to the end of the queue
			size_t size_queue; // Queue size

		public:

			// Queue Class Constructor
			Queue()
			{
				head = nullptr;
				tail = nullptr;
				size_queue = 0;
			}
			// Queue class destructor
			~Queue()
			{
				clear_queue();
			};

			// Checking the queue for emptiness
			bool queue_is_empty()
			{
				return size_queue == 0;
			}

			// Getting the queue size
			int get_size_queue()
			{
				return size_queue;
			}

			// Getting a pointer to the head element of the queue
			Queue_element* get_head()
			{
				return head;
			}

			// Getting a pointer to the tail element of the queue
			Queue_element* get_tail()
			{
				return tail;
			}

			// Adding an element to the queue
			void enqueue(ElemRBT* data)
			{
				Queue_element* current = new Queue_element(data);
				if (queue_is_empty())
				{
					head = current;
					tail = current;
					size_queue++;
				}
				else
				{
					tail->next = current;
					tail = current;
					size_queue++;
				}
			};

			// Removing an element from the queue
			ElemRBT* dequeue()
			{
				if (!queue_is_empty())
				{
					ElemRBT* element;
					Queue_element* delete_element;
					if (size_queue == 1)
					{
						element = head->data;
						delete head;
						head = nullptr;
						tail = nullptr;
						size_queue = 0;
						return element;
					}
					else
					{
						element = head->data;
						delete_element = head;
						head = head->next;
						delete delete_element;
						size_queue--;
						return element;
					}
				}
				else return nullptr;
			}

			// Clearing the queue
			void clear_queue()
			{
				if (!queue_is_empty())
				{
					while (!queue_is_empty())
					{
						dequeue();
					}
					head = nullptr;
					tail = nullptr;
					size_queue = 0;
				}
			}
		};

		class Breadth_first_traverse_iterator{
			private:

				ElemRBT* nil_node;
				ElemRBT* current;
				Queue queue;

			public:
				Breadth_first_traverse_iterator(ElemRBT* root_node, ElemRBT* nil){
					current = root_node;
					queue.enqueue(current);
					nil_node = nil;
				}
				~Breadth_first_traverse_iterator(){
					current = nullptr;
					queue.clear_queue();
				}

				ElemRBT* next(){
					if (has_next()){
						current = queue.dequeue();
						if (current->next_left != nil_node){
							queue.enqueue(current->next_left);
						}
						if (current->next_right != nil_node){
							queue.enqueue(current->next_right);
						}
						return current;
					}
					else throw std::invalid_argument("There are no tree elements to process");
				}

				bool has_next(){
					return !queue.queue_is_empty();
				}

		};

		template<typename T>
		class List{
			private:

				class Node{
					public:

						T data;
						Node* next;

						Node(T data = 0, Node* next = nullptr) {
							this->data = data;
							this->next = next;
						}
						~Node(){
							data = 0;
							next = nullptr;
						}
				};

				size_t size_list;
				Node* head;
				Node* last;

			public:

				List(size_t size = 0, Node* head = nullptr, Node* last = nullptr){
					this->size_list = size;
					this->head = head;
					this->last = last;
				}

				~List(){
					clear_list();
					size_list = 0;
					head = nullptr;
					last = nullptr;
				};

				bool isEmpty(){
					return (size_list == 0);
				}

				size_t get_size_list(){
					return size_list;
				}

				Node* get_head(){
					return head;
				}

				void push_back(T element_value){
					if (head == nullptr){
						Node* new_list_item = new Node(element_value, nullptr);
						head = new_list_item;
						last = new_list_item;
						size_list++;
					}
					else{
						Node* new_list_item = new Node(element_value, nullptr);
						last->next = new_list_item;
						last = new_list_item;
						size_list++;
					}
				}

				void pop_front(){
					if (get_size_list() > 0){
						if (get_size_list() == 1){
							clear_list();
						}
						else{
							Node* list_item = head;
							head = head->next;
							delete list_item;
							size_list--;
						}
					}
					else throw std::invalid_argument("The list is empty, there are no available items to delete");
				}

				void clear_list(){
					if (!isEmpty()){
						Node* current_item = head;
						while (current_item != nullptr){
							current_item = current_item->next;
							delete head;
							head = current_item;
						}
						head = nullptr;
						last = nullptr;
						size_list = 0;
					}
				}

				friend std::ostream& operator<<(std::ostream& stream, const List<T>& List){
					if (List.head != nullptr){
						List::Node* current = List.head;
						while (current != nullptr){
							stream << current->data << " ";
							current = current->next;
						}
						stream << '\n';
						return stream;
					}
					else return stream << "The list is empty\n\n";
				}
		};

		List<T1> get_keys(){
			if (getSize() != 0){
				List<T1>* List_keys = new List<T1>;
				Breadth_first_traverse_iterator* bft_iterator = new Breadth_first_traverse_iterator(root, nil);
				while (bft_iterator->has_next()) List_keys->push_back(bft_iterator->next()->key);
				return *List_keys;
			}
			else throw std::invalid_argument("Red-black tree (associative array) is empty");
		}

		List<T2> get_values(){
			if (getSize() != 0){
				List<T2>* List_value = new List<T2>;
				Breadth_first_traverse_iterator* bft_iterator = new Breadth_first_traverse_iterator(root, nil);
				while (bft_iterator->has_next()) List_value->push_back(bft_iterator->next()->value);
				return *List_value;
			}
			else throw std::invalid_argument("Red-black tree (associative array) is empty");
		}

		void print(){
			if (getSize() != 0){
				Breadth_first_traverse_iterator* bft_iterator = new Breadth_first_traverse_iterator(root, nil);
				ElemRBT* Node;
				while (bft_iterator->has_next()){
					Node = bft_iterator->next();
					std::cout << Node->key << "\t" << Node->value << "\t" << Node->code << "\n";
				}
			}
			else throw std::invalid_argument("Redòblack tree is empty");
		}
};
#endif // !TREE_H