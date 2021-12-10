// Eternal_despair_anti_social.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string str1 = "123.0";
    std::string str2 = "0.123";

    auto m1 = std::stod(str1);
    auto m2 = std::stod(str2);

    std::cout << m1 + m2;

    system("pause");
    return 0;
}