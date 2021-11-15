#include <iostream>
#include <time.h>
#include <chrono>
#include "Types_of_sorting.h"

int BinarySearch(int* Array, int Size_array, int key) {
    char flag = 'N';
    int high = Size_array - 1;
    int low = 0;
    int middle = (high + low) / 2;
    while ((flag == 'N') and (high >= low)) {
        if (key == Array[middle])
            flag = 'Y';
        else
            if (key < Array[middle])
                high = middle - 1;
            else
                low = middle + 1;

        middle = (high + low) / 2;
    }

    return (flag == 'Y') ? middle : -1;
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
        for (int j = 0; j < Size_array-1; j++) {
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
    }

    auto* count_array = new int[high_number + 1];
    for (int index = 0; index <= high_number; index++)
    {
        count_array[index] = 0;
    }
    for (int index = 0; index < size; index++)
    {
        temp = array[index];
        count_array[temp]++;
    }
    int index = 0;
    for (int jndex = 0; jndex <= high_number; jndex++) {
        while (count_array[jndex] != 0) {
            array[index] = jndex;
            count_array[jndex]--;
            index++;
        }
    }
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