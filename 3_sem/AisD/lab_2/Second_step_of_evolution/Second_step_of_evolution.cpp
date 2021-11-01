#include <iostream>
#include <time.h>
#include <cstdlib> 
#include <chrono>
#include <cstring>

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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (Array[j] > Array[j + 1]) {
                tmp = Array[j]; // создали дополнительную переменную
                Array[j] = Array[j + 1]; // меняем местами
                Array[j + 1] = tmp; // значения элементов
            }
        }
    }
}
void InsertionSort(int* array, int arraySize) {
    int temp, i, j;
    for (i = 1; i < arraySize; i++)
    {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
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

















int main() {
    srand(time(NULL));
/*
    for (int i = 0; i < 1; i++) {
        double Average_1, Average_2, Average_3;
        Average_1 = Average_2 = Average_3 = 0;

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

        for (int i = 0; i < 10; i++) {

            int* array_1 = new int[1000];
            int* array_2 = new int[1000];
            int* array_3 = new int[1000];
            for (int index = 0; index < 1000; index++) {
                array_1[index] = rand() % 100;
                array_2[index] = array_1[index];
                array_3[index] = array_1[index];
            }


            for (int index = 0; index < 10; index++) {
                std::cout << array_1[index] << " ";
            }
            std::cout << std::endl;
            auto  now = std::chrono::high_resolution_clock::now();
            QuickSort(array_1, 0, 9);
            for (int index = 0; index < 10; index++) {
                std::cout << array_1[index] << " ";
            }
            std::cout << std::endl;
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
            Average_1 += elapsed.count();
            std::cout << "QuickSort: " << elapsed.count() << "ns.\n";
            std::cout << std::endl; std::cout << std::endl;







            for (int index = 0; index < 10; index++) {
                std::cout << array_2[index] << " ";
            }
            std::cout << std::endl;
            now = std::chrono::high_resolution_clock::now();
            BubbleSort(array_2, 10);
            for (int index = 0; index < 10; index++) {
                std::cout << array_2[index] << " ";
            }
            std::cout << std::endl;
            elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
            Average_2 += elapsed.count();
            std::cout << "BubbleSort: " << elapsed.count() << "ns.\n";
            std::cout << std::endl;
            std::cout << std::endl;






            for (int index = 0; index < 10; index++) {
                std::cout << array_3[index] << " ";
            }
            std::cout << std::endl;
            now = std::chrono::high_resolution_clock::now();
            InsertionSort(array_3, 10);
            for (int index = 0; index < 10; index++) {
                std::cout << array_3[index] << " ";
            }
            std::cout << std::endl;
            elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
            Average_3 += elapsed.count();
            std::cout << "InsertionSort: " << elapsed.count() << "ns.\n";
            std::cout << std::endl;
            std::cout << std::endl;


            delete[] array_1;
            delete[] array_2;
            delete[] array_3;

        }

        std::cout << Average_1 / 10 << "\t" << Average_2 / 10 << "\t" << Average_3 / 10 << "\n";
    }
    */

    // больной ублюдок, не трогай значение величины массива, если сделать больше 10
    // То тебе и твоему компьютеру конец.
    auto* array_1 = new int[10];

    for (int index = 0; index < 10; index++) {
        array_1[index] = rand() % 100;
       
    }
    /*for (int index = 0; index < 100; index++) {
        std::cout << array_1[index] << ' ';
    }*/
    std::cout << std::endl;
    BogoSort(array_1, 10);
    for (int index = 0; index < 10; index++) {
        std::cout << array_1[index]<< ' ';
    }
    std::cout << std::endl;
    
    system("pause");
    return 0;
}