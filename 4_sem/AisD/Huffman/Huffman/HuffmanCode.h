#ifndef HUFFMANCODE_H

#pragma once
#include <iostream>
#include "Tree.h"
#include "HuffmanTree.h"


class HuffCode{

	private:

		Red_Black_Tree<char, int, std::string> map;
		HuffmanTree huffTree;
		std::string stringEncode;
		std::string stringParse;

		void Frequency(std::string string, Red_Black_Tree<char, int, std::string>& map){
			if (getLength(string) == 0){
				throw std::invalid_argument("An empty string cannot be encoded");
			}
			else{
				for (int index = 0; string[index] != '\0'; index++){
					if (map.getSize() == 0){
						map.insert(string[index], 1);
					}
					else{
						if (map.find(string[index])){
							map.getElem(string[index])->value++;
						}
						else{
							map.insert(string[index], 1);
						}
					}
				}
			}
		}

		void buildHuffTree(Red_Black_Tree<char, int, std::string>& map, HuffmanTree& tree){

			HuffmanTree::List listVertices;
			Red_Black_Tree<char, int, std::string>::List<char> List_keys = map.get_keys();
			Red_Black_Tree<char, int, std::string>::List<int> List_values = map.get_values();
			while (List_keys.get_head() != nullptr && List_values.get_head() != nullptr){
				listVertices.pushBack(tree.createNewElement(List_keys.get_head()->data, List_values.get_head()->data));
				List_keys.pop_front();
				List_values.pop_front();
			}
			HuffmanTree::List processedVertices;
			processedVertices.copyList(listVertices);

			modificationHuffTree(listVertices);

			getBinaryCode(processedVertices);
		}

		void modificationHuffTree(HuffmanTree::List& listVertices){
			listVertices.sortListElements();
			while (listVertices.getSizeList() != 1){
				listVertices.pushBack(listVertices.CombiningElements(huffTree));
				listVertices.popFront();
				listVertices.popFront();
				if (listVertices.getSizeList() > 2){
					listVertices.sortListElements();
				}
			}
			huffTree.setRootNode(listVertices.getHead()->data);
		}

		void getBinaryCode(HuffmanTree::List& node){
			while (node.getHead() != nullptr){
				map.getElem(node.getHead()->data->symbol)->code = huffTree.getCode(node.getHead()->data);
				node.popFront();
			}
		}

		double getLength(std::string string){
			double index = 0;
			for (index; string[index] != '\0'; index++);
			return index;
		}

	public:

		HuffCode(std::string string){
			stringParse = string;
			stringEncode = "";
			Frequency(string, map);
			buildHuffTree(map, huffTree);
		}

		~HuffCode(){
			stringParse = "";
			stringEncode = "";
			map.clear();
			huffTree.clear();
		}

		HuffmanTree* getHuffmanTree(){
			return &huffTree;
		}

		Red_Black_Tree<char, int, std::string>* getMap(){
			return &map;
		}

		void getTableFrequenciesAndCodes(){
			std::cout << "Table symbols - frequencies - codes:\n";
			if (stringEncode != ""){
				map.print();
			}
		}

		std::string codingSourceString(){
			std::cout << "Encoded string:\n";
			for (int index = 0; stringParse[index] != '\0'; index++) {
				stringEncode += map.getElem(stringParse[index])->code;
			}
			return stringEncode;
		}

		std::string decodingEncodedString(){
			std::cout << "Decoding.\n";
			std::string decodedString = "";
			if (stringEncode == ""){
				return decodedString;
			}
			else{
				decodedString = huffTree.decoding(stringEncode);
				return decodedString;
			}
		}

		double volumeSourseString(){
			std::cout << "Source string size in bits: ";
			return getLength(stringParse) * 8;
		}

		double volumeEncodeString(){
			std::cout << "Encode string size in bits: ";
			return getLength(stringEncode);
		}

		double compressionRatio(){
			std::cout << "Compression ratio: ";
			return (getLength(stringParse) * 8 / getLength(stringEncode));
		}
};

#endif // !HUFFMANCODE_H