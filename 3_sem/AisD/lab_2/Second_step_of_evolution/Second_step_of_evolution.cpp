#include <iostream>
#include <time.h>
#include <chrono>
#include "Types_of_sorting.h"

int main() {
    // For bogosort:
    // (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Dear, don`t touch the value of the array value, if 
    // make more 10 (◕‿◕✿)
    // Then you and your computer are died ╰(▔∀▔)╯.
    srand(time(NULL));

    //Comparison_of_sortings();
    CountingSort_called();
    BogoSort_called();

    system("pause");
    return 0;
}