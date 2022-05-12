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

		void nountingFrequencyOccurrence(std::string string, Red_Black_Tree<char, int, std::string>& Map){
			if (getStringLength(string) == 0){
				throw std::domain_error("An empty string cannot be encoded");
			}
			else{
				for (int index = 0; string[index] != '\0'; index++){
					if (Map.get_size_tree() == 0){
						Map.insert(string[index], 1);
					}
					else{
						if (Map.find(string[index])){
							Map.Get_map_element(string[index])->value++;
						}
						else{
							Map.insert(string[index], 1);
						}
					}
				}
			}
		}

		void createTreeHuffman(Red_Black_Tree<char, int, std::string>& Map, HuffmanTree& Tree){

			HuffmanTree::List listVertices;
			Red_Black_Tree<char, int, std::string>::List<char> List_keys = Map.get_keys();
			Red_Black_Tree<char, int, std::string>::List<int> List_values = Map.get_values();
			while (List_keys.get_head() != nullptr && List_values.get_head() != nullptr){
				listVertices.pushBack(Tree.createNewElement(List_keys.get_head()->data, List_values.get_head()->data));
				List_keys.pop_front();
				List_values.pop_front();
			}
			HuffmanTree::List processedVertices;
			processedVertices.copyList(listVertices);

			formingTreeHuffman(listVertices);

			getCodeSymbols(processedVertices);
		}

		void formingTreeHuffman(HuffmanTree::List& listVertices){
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

		void getCodeSymbols(HuffmanTree::List& processedVertices){
			while (processedVertices.getHead() != nullptr){
				map.Get_map_element(processedVertices.getHead()->data->symbol)->code = huffTree.getCode(processedVertices.getHead()->data);
				processedVertices.popFront();
			}
		}

		double getStringLength(std::string string){
			double index = 0;
			for (index; string[index] != '\0'; index++);
			return index;
		}

	public:

		HuffCode(std::string string){
			stringParse = string;
			stringEncode = "";
			nountingFrequencyOccurrence(string, map);
			createTreeHuffman(map, huffTree);
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
				stringEncode += map.Get_map_element(stringParse[index])->code;
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

		double memoryCapacitySourceString(){
			std::cout << "Source string size in bits: ";
			return getStringLength(stringParse) * 8;
		}

		double memoryCapacityEncodedString(){
			std::cout << "Encode string size in bits: ";
			return getStringLength(stringEncode);
		}

		double compressionRatio(){
			std::cout << "Compression ratio: ";
			return (getStringLength(stringParse) * 8 / getStringLength(stringEncode));
		}
};

#endif // !HUFFMANCODE_H