#ifndef HUFFMANTREE_H

#include "Tree.h"
#pragma once

class HuffmanTree {

	private:

		class ElementHuffmanTree{
			public:

				char symbol;
				size_t frequency;
				ElementHuffmanTree* next_left;
				ElementHuffmanTree* next_right;
				ElementHuffmanTree* parent;

				ElementHuffmanTree(char symbol = '\0', size_t frequencyOccurrence = 0, ElementHuffmanTree* parent_node = nullptr, ElementHuffmanTree* left_node = nullptr, ElementHuffmanTree* right_node = nullptr) 
					: symbol(symbol), frequency(frequencyOccurrence), parent(parent_node), next_left(left_node), next_right(right_node) {}

				~ElementHuffmanTree(){
					symbol = '\0';
					frequency = 0;
					parent = nullptr;
					next_left = nullptr;
					next_right = nullptr;
				}
		};

		size_t sizeTree;
		ElementHuffmanTree* rootNode;

		void reverseRemoval(ElementHuffmanTree* node){
			if (node == nullptr) return;
			reverseRemoval(node->next_left);
			reverseRemoval(node->next_right);
			delete node;
			sizeTree--;
		}

	public:

		HuffmanTree(){
			sizeTree = 0;
			rootNode = nullptr;
		}

		~HuffmanTree(){
			clear();
			sizeTree = 0;
			rootNode = nullptr;
		}

		void setRootNode(ElementHuffmanTree* root){
			rootNode = root;
		}

		size_t getSizeTree(){
			return sizeTree;
		}

		void clear(){
			if (getSizeTree() != 0){
				reverseRemoval(rootNode);
				sizeTree = 0;
				rootNode = nullptr;
			}
		}

		ElementHuffmanTree* getRootNode(){
			return rootNode;
		}

		ElementHuffmanTree* createNewElement(char symbol, size_t frequency){
			sizeTree++;
			return new ElementHuffmanTree(symbol, frequency);
		}

		std::string decoding(std::string& encodedString){
			std::string decodedString = "";
			ElementHuffmanTree* currentElement = rootNode;
			for (int index = 0; encodedString[index] != '\0'; index++){
				if (getSizeTree() != 1){
					if (encodedString[index] == '0'){
						currentElement = currentElement->next_right;
					}
					else{
						currentElement = currentElement->next_left;
					}
				}
				if (currentElement->symbol != '\0'){
					decodedString += currentElement->symbol;
					currentElement = rootNode;
				}
			}
			return decodedString;
		}

		std::string getCode(ElementHuffmanTree* currentSymbol){
			std::string codeSymbol = "";
			ElementHuffmanTree* previousNode = currentSymbol;
			while (currentSymbol->parent != nullptr){
				previousNode = currentSymbol;
				currentSymbol = currentSymbol->parent;
				if (currentSymbol->next_left == previousNode) {
					codeSymbol = "1" + codeSymbol;
				}
				else codeSymbol = "0" + codeSymbol;
			}
			if (currentSymbol->parent == nullptr && currentSymbol->next_left == nullptr && currentSymbol->next_right == nullptr){
				codeSymbol = "0";
			}
			return codeSymbol;
		}

		class List {
			class Node{
				public:

					ElementHuffmanTree* data;
					Node* next;

					Node(HuffmanTree::ElementHuffmanTree* data = nullptr, Node* next = nullptr) {
						this->data = data;
						this->next = next;
					}
					~Node()
					{
						data = nullptr;
						next = nullptr;
					}
			};

				size_t sizeList;
				Node* head;
				Node* last;

			public:

				List(size_t size = 0, Node* head = nullptr, Node* last = nullptr){
					this->sizeList = size;
					this->head = head;
					this->last = last;
				}
				~List(){
					clearList();
					sizeList = 0;
					head = nullptr;
					last = nullptr;
				}

				Node* getHead(){
					return head;
				}

				size_t getSizeList(){
					return sizeList;
				}

				void clearList(){
					if (getSizeList() != 0){
						Node* current_item = head;
						while (current_item != nullptr){
							current_item = current_item->next;
							delete head;
							head = current_item;
						}
						head = nullptr;
						last = nullptr;
						sizeList = 0;
					}
				}

				void pushBack(ElementHuffmanTree* element_value){
					if (head == nullptr){
						Node* new_list_item = new Node(element_value, nullptr);
						head = new_list_item;
						last = new_list_item;
						sizeList++;
					}
					else{
						Node* new_list_item = new Node(element_value, nullptr);
						last->next = new_list_item;
						last = new_list_item;
						sizeList++;
					}
				}

				ElementHuffmanTree* popFront(){
					if (getSizeList() > 0){
						if (getSizeList() == 1){
							clearList();
						}
						else{
							Node* list_item = head;
							head = head->next;
							sizeList--;
							return list_item->data;
						}
					}
					else throw std::invalid_argument("The list is empty, there are no available elements to delete");
				}

				ElementHuffmanTree* CombiningElements(HuffmanTree& Tree){
					Node* firstElement = head;
					Node* secondElement = head->next;
					auto totalFrequency = firstElement->data->frequency + secondElement->data->frequency;
					ElementHuffmanTree* newNode = Tree.createNewElement('\0', totalFrequency);
					firstElement->data->parent = newNode;
					newNode->next_left = firstElement->data;
					secondElement->data->parent = newNode;
					newNode->next_right = secondElement->data;
					return newNode;
				}

				void sortListElements(){
					if (head != nullptr){
						for (int i = 0; i < getSizeList(); i++){
							for (Node* nurrentElement = head; nurrentElement->next != nullptr; nurrentElement = nurrentElement->next) {
								if (nurrentElement->data->frequency > nurrentElement->next->data->frequency){
									HuffmanTree::ElementHuffmanTree* temporaryElement = nurrentElement->data;
									nurrentElement->data = nurrentElement->next->data;
									nurrentElement->next->data = temporaryElement;
								}
							}
						}
					}
					else throw std::invalid_argument("Sorting the list is not possible because it is empty");
				}

				void copyList(const List& copiedList){
					Node* currentElement = copiedList.head;
					while (currentElement != nullptr){
						pushBack(currentElement->data);
						currentElement = currentElement->next;
					}
				}

				friend std::ostream& operator<<(std::ostream& stream, const List& List){
					if (List.head != nullptr){
						List::Node* current = List.head;
						while (current != nullptr){
							stream << current->data->symbol << " ";
							current = current->next;
						}
						stream << '\n';
						return stream;
					}
					else return stream << "\n\n";
				}
		};
};

#endif // !HUFFMANTREE_H