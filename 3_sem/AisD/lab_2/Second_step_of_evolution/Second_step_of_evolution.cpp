#include <iostream>
#include <time.h>
#include <stdlib.h> 

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

void QuickSort(int* array, int low, int high)
{
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


int main() {
    srand(time(NULL));
    int LuckyPanch = 0;
    for (int i = 0; i < 10000; i++) {
        int* array = new int[10];
        for (int index = 0; index < 10; index++) {
            array[index] = rand() % 1000;
        }
        for (int index = 0; index < 10; index++) {
            std::cout << array[index] << " ";
        }
        std::cout << std::endl;
        QuickSort(array, 0, 9);
        for (int index = 0; index < 10; index++) {
            std::cout << array[index] << " ";
        }
        std::cout << std::endl;
        // андрей уже отсортировал, приступаем к двоичной сортировке
        if (BinarySearch(array, 10, 15) == -1) {
            std::cout << "Ti popusk!!!\n";
        }
        else { std::cout << "Good job!!!\n";  LuckyPanch++; }
        delete[] array;
        std::cout << std::endl;
    }

    std::cout << LuckyPanch;
    system("pause");
    return 0;
}