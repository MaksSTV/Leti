// Eternal_despair_anti_social.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
    Stack<std::string> stack;

    std::string str1 = "123 + (12 - 13.5) / (15 - 12)";
    std::string str2 = "0.123";

    

    int left, right;
    left = 0; right = 0;
    for (int i = 0; i < str1.length(); i++) { // собственно проверка на адекватность пользователя
        if (str1[i] == '(') {
            left++;
        }
        if (str1[i] == ')') {
            right++;
        }
    }
    if (left != right) {
        throw std::runtime_error("the number on the right-parenthesis does not match the number on the lesf-parenthesis\n");
    }
    
    // пiшла вода в хату
    /*Создать пустой стек для хранения операторов
        Просматриваем выражение справа налево
        - если токен является правой скобкой, поместить его в стэк
        - если токен – операнд, добавить его в выходной список
        - если токен является левой скобкой, извлечь из стэка все символы до
        появления правой скобки и добавить их в выходной поток
        - если токен является оператором, удалить все операторы из стэка (пока не
        увидим оператор с меньшим приоритетом) и поместить их в выходной
        поток, если и только если приоритет оператора, который находится
        наверху стэка, больше или равен приоритета просматриваемого
        оператора. Затем поместить просматриваемый оператор в стэк. Иначе
        поместить просматриваемый оператор в стэк сразу
        - если после просмотра всех элементов остались операторы в стэке, то
        вывести их в выходной список
    */

    std::string temp;
    std::string temp_parenthesis;
    /*Stack<std::string> stroka;
    std::string temp;
    for (int i = str1.length() - 1; i >= 0; i--) {
        if (str1[i] == ')') {
            temp = str1[i];
            stroka.push(temp);
        }
        if()
    }*/



    // ты в муте чел....
    for (int i = 0; i < str1.length(); i++) {
        if ((str1[i] != ' ')&&(str1[i] != ')')&&(str1[i] != '(')) {
            temp += str1[i];
        }
        if (str1[i] == ')') {
            stack.push(temp);
            temp = "\0";
            temp_parenthesis = '(';
            stack.push(temp_parenthesis);
        }

        if  (str1[i] == '(') {
            temp_parenthesis = ')';
            stack.push(temp_parenthesis);
        }
        
        if (str1[i] == ' ') {
            stack.push(temp);
            temp = "\0";
        }
    }
    stack.push(temp); // 1000-7


    while (!stack.isEmpty()) {
        std::cout<<stack.peek();
        stack.pop();
    }


    system("pause");
    return 0;
}