// Eternal_despair_anti_social.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "Stack.h"
#include "Functions.h"


int main()
{
    Stack<std::string> stack;
    std::string temp;
    std::string temp_parenthesis;
    Stack<std::string> prefix;
    Stack<std::string> buffer; // (cos(45) + sin(45))
    std::string str1 = "(-e + -5) + (-e + sin(180))"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512
    std::string str2 = "(sqrt(4.5) - cbrt(45)) * (ctg(45) + tg(45)) - (5.5 - 88) - (cos(45) + sin(45)) - (ln(45) + log(45)) + (pi + e)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


    parenthesis_check(str1);
    convert_string_to_stack(str1, stack);
    convert_infix_to_prefix(stack, prefix, buffer);
    std::cout << "Starting expression: " << str1 << std::endl;
    std::cout << "Expression in prefix form: ";
    Stack<std::string> calculation;
    while (!prefix.isEmpty()) {
        std::cout << prefix.peek();
        calculation.push(prefix.peek());
        prefix.pop();
    }
    std::cout << std::endl;
    std::cout << calculation_in_prefix_form(calculation);
    
    
    system("pause");
    return 0;
}