#ifndef TYPES_OF_SORTING_H
#pragma once

#include <iostream>
#include <time.h>
#include <chrono>

int BinarySearch(int* Array, int Size_array, int key);
void QuickSort(int* array, int low, int high);
void BubbleSort(int* Array, int Size_array);
void CountingSort(char* array, int size);
void swapElements(int& element1, int& element2);
bool isArraySorted(int* array, int Size_array);
void BogoSort(int* array, int Size_array);


#endif // !TYPES_OF_SORTING_H
