#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#include "Called_sorting.h"
#include "Types_of_sorting.h"

void CountingSort_called() {
    int size = 10;
    auto* array_char = new char[size];
    for (int index = 0; index < size; index++) {
        array_char[index] = 106 - index; std::cout << array_char[index] << " ";
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

    std::cout << std::endl;
    BogoSort(bogo, 10);
    for (int index = 0; index < 10; index++) {
        std::cout << bogo[index] << ' ';
    }
    std::cout << std::endl;

    if (BinarySearch(bogo, 10, 40) == -1) {
        std::cout << "Nenaxod\n";
    }
    else {
        std::cout << "Naxod\n";
    }

    delete[] bogo;
}

void Comparison(size_t size) {
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
        QuickSort(quick, 0, size-1);
        auto elapsed_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now_1);

        Average_1 += elapsed_1.count();

        auto now_2 = std::chrono::high_resolution_clock::now();
        BubbleSort(bubble, size);
        auto elapsed_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now_2);

        Average_2 += elapsed_2.count();


        delete[] quick;
        delete[] bubble;

    }
    std::cout << std::setw(12) << resetiosflags(std::ios::scientific) << resetiosflags(std::ios::showpos) << resetiosflags(std::ios::showpoint)<<Average_1 / 10 << "ns.  |" << std::setw(15) << resetiosflags(std::ios::scientific) << resetiosflags(std::ios::showpos) << resetiosflags(std::ios::showpoint)<< Average_2 / 10 << "ns.|\n";
}
void Comparison_of_sortings() {
    
    std::cout << "-----------------------------------------------\n";
    std::cout << "| Size   |    QuickSort    |    BubbleSort    |\n";
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  10    |" ; Comparison(10);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  100   |" ; Comparison(100);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  1000  |" ; Comparison(1000);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "|  10000 |" ; Comparison(10000);
    std::cout << "|--------|-----------------|------------------|\n";
    std::cout << "| 100000 |"; Comparison(100000);
    std::cout << "-----------------------------------------------\n";
 
}

 