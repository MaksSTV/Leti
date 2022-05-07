// Huffman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "Tree.h"
#include "Pair.h"

// I
// создаем список в котором в каждой ноде есть пара символ+частота встречаемости
// если такой символ есть, то ++, если нет, то pushback()
// сортируем этот список (например пузырьком)
// 
//
// II
// TODO...

int main()
{
    std::string test = "it is test string";

    List<ElemListHuffman> parseList;

    int size = test.size();
    int sizeList = 0;

    for (int i = 0; i < size; i++) {
        ElemListHuffman node;

        if (size == 0) {
            node.symbol = test[0];
            node.frequency++;
            parseList.push_back(node);
            sizeList++;
            continue;
        }
            bool check = 0;
            for (int j = 0; j < sizeList; j++) {
                if (parseList.at(j).symbol == test[i]) {
                    parseList.at(j).frequency++;
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                node.symbol = test[i];
                node.frequency++;
                parseList.push_back(node);
                sizeList++;
                continue;
            }
        
    }
    //std::cout << sizeList;
    auto lenght = parseList.get_size();
    for (int i = 0; i < lenght; i++) {
        std::cout << parseList.at(i).symbol << "\t" << parseList.at(i).frequency << "\n";
    }

    system("pause");
    return 0;
}
