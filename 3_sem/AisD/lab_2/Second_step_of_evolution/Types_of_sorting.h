#ifndef TYPES_OF_SORTING_H
#pragma once

#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
int BinarySearch(int* Array, int Size_array, int key) {
    bool flag = false;
    int high = Size_array - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while ((flag == false) && (high >= low)) {
        if (key == Array[middle]) {
            flag = true;
            return key;
        }
        else
            if (key < Array[middle])
                high = middle - 1;
            else
                low = middle + 1;

        middle = (high + low) / 2;
    }

    if (flag == false) {
        return -1;
    }
}// O(log_2 N)

void QuickSort(int* array, int low, int high) {
    int left = low;
    int right = high;
    int middle = array[(left + right) / 2];
    int temp;

    while (left <= right)
    {
        while (array[left] < middle)
            left++;
        while (array[right] > middle)
            right--;
        if (left <= right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    if (right > low)
        QuickSort(array, low, right);
    if (left < high)
        QuickSort(array, left, high);
}
void BubbleSort(int* Array, int Size_array) {
    int tmp;
    for (int i = 0; i < Size_array; i++) {
        for (int j = 0; j < Size_array - 1; j++) {
            if (Array[j] > Array[j + 1]) {
                tmp = Array[j]; // создали дополнительную переменную
                Array[j] = Array[j + 1]; // меняем местами
                Array[j + 1] = tmp; // значения элементов
            }
        }
    }
}
void CountingSort(char* array, int size) {
    int high_number = 0;
    int temp;
    for (int index = 0; index < size; index++) {
        if (array[index] > high_number) {
            high_number = array[index];
        }
    }// O(N)

    auto* count_array = new int[high_number + 1];
    for (int index = 0; index <= high_number; index++)
    {
        count_array[index] = 0;
    }// O(N)
    for (int index = 0; index < size; index++)
    {
        temp = array[index];
        count_array[temp]++;
    }// O(N)
    int index = 0;
    for (int jndex = 0; jndex <= high_number; jndex++) {
        while (count_array[jndex] != 0) {
            array[index] = jndex;
            count_array[jndex]--;
            index++;
        }
    }// O(nlog(n))
    delete[] count_array;
}

void swapElements(int& element1, int& element2)
{
    int tempVar = element1;
    element1 = element2;
    element2 = tempVar;
}
bool isArraySorted(int* array, int Size_array)
{
    for (int i = 0; i < Size_array - 1; i++) {

        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}
void BogoSort(int* array, int Size_array) {
    int j = Size_array;
    while (!isArraySorted(array, Size_array)) {
        while (Size_array > 1) {
            int r = rand() % Size_array;
            Size_array -= 1;
            swapElements(array[r], array[Size_array]);
        }
        Size_array = j;
    }
}

void CountingSort_called() {
    int size = 10;
    auto* array_char = new char[size];
    for (int index = 0; index < size; index++) {
        array_char[index] = 106 - index; 
        std::cout << array_char[index] << " ";
    }// j i h g f e d c b a
    std::cout << std::endl;
    CountingSort(array_char, size); // a b c d e f g h i j
    for (int index = 0; index < size; index++) {
        std::cout << array_char[index] << " ";
    }
    std::cout << std::endl;
    delete[] array_char;
}
void BogoSort_called() {

    auto* bogo = new int[10];

    for (int index = 0; index < 10; index++) {
        bogo[index] = rand() % 100;

    }
    bogo[5] = 40;
    std::cout << std::endl;
    BogoSort(bogo, 10);
    for (int index = 0; index < 10; index++) {
        std::cout << bogo[index] << ' ';
    }
    std::cout << std::endl;

    if (BinarySearch(bogo, 10, 40) == -1) {
        std::cout << "Not Found!!!\n";
    }
    else {
        std::cout << "Found\n";
    }

    delete[] bogo;
}

void Comparison(int size) {
    double Average_1, Average_2;
    Average_1 = Average_2 = 0;

    for (int index = 0; index < 10; index++) {

        auto* quick = new int[size];
        auto* bubble = new int[size];

        for (int jndex = 0; jndex < size; jndex++) {
            quick[jndex] = rand() % 100;
            bubble[jndex] = quick[jndex];
        }

        auto now_1 = std::chrono::high_resolution_clock::now();
        QuickSort(quick, 0, size - 1);
        auto elapsed_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now_1);

        Average_1 += elapsed_1.count();

        auto now_2 = std::chrono::high_resolution_clock::now();
        BubbleSort(bubble, size);
        auto elapsed_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now_2);

        Average_2 += elapsed_2.count();


        delete[] quick;
        delete[] bubble;

    }
    std::cout << std::setw(12) << resetiosflags(std::ios::scientific) << resetiosflags(std::ios::showpos) << resetiosflags(std::ios::showpoint) << Average_1 / 10 << "ns.  |" << std::setw(15) << resetiosflags(std::ios::scientific) << resetiosflags(std::ios::showpos) << resetiosflags(std::ios::showpoint) << Average_2 / 10 << "ns.|\n";
}
void Comparison_of_sortings() {

    std::cout << "-----------------------------------------------\n";
    std::cout << "| Size   |    QuickSort    |    BubbleSort    |\n";
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  10    |"; Comparison(10);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  100   |"; Comparison(100);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  1000  |"; Comparison(1000);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  10000 |"; Comparison(10000);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "| 100000 |"; Comparison(100000);
    std::cout << "-----------------------------------------------\n";

}


#endif // !TYPES_OF_SORTING_H
