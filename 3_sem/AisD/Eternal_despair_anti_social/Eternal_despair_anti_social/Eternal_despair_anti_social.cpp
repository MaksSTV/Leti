// Eternal_despair_anti_social.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"


int priority(std::string c)
{
    if (c == "^")
    {
        return 3;
    }
    else if (c == "*" || c == "/")
    {
        return 2;
    }
    else if (c == "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isOperator(std::string c)
{
    if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool math_func(std::string c) {
    if ((c[0] == 's') && (c[1] == 'i') && (c[2] == 'n') && (c[3] == '(')) {
        return true;
    }
    else if ((c[0] == 'c') && (c[1] == 'o') && (c[2] == 's') && (c[3] == '(')) {
        return true;
    }
    else if ((c[0] == 't') && (c[1] == 'g') && (c[2] == '(')) {
        return true;
    }
    else if ((c[0] == 'c') && (c[1] == 't') && (c[2] == 'g') && (c[3] == '(')) {
        return true;
    }
    else if ((c[0] == 'l') && (c[1] == 'n') && (c[2] == '(')) {
        return true;
    }
    else if ((c[0] == 'l') && (c[1] == 'o') && (c[2] == 'g') && (c[3] == '(')) {
        return true;
    }
    else if ((c[0] == 's') && (c[1] == 'q') && (c[2] == 'r') && (c[3] == 't') && (c[4] == '(')) {
        return true;
    }
    else if ((c[0] == 'c') && (c[1] == 'b') && (c[2] == 'r') && (c[3] == 't') && (c[4] == '(')) {
        return true;
    }
    else if ((c[0] == 'p') && (c[1] == 'i') && (c[2] == '\0')) {
        return true;
    }
    else if ((c[0] == 'e') && (c[1] == '\0')) {
        return true;
    }
    else {
        return false;
    }
}

void parenthesis_check(std::string c) {
    int left, right;
    left = 0; right = 0;
    for (int i = 0; i < c.length(); i++) { // собственно проверка на адекватность пользователя
        if (c[i] == '(') {
            left++;
        }
        if (c[i] == ')') {
            right++;
        }
    }
    if (left != right) {
        throw std::runtime_error("the number on the right-parenthesis does not match the number on the lesf-parenthesis\n");
    }
}

void convert_string_to_stack(std::string str1, Stack<std::string> *stack) {
    std::string temp;
    std::string temp_parenthesis;
    // ты в муте чел....
    for (int i = 0; i < str1.length(); i++) {
        if ((str1[i] == 's') && (str1[i + 1] == 'i') && (str1[i + 2] == 'n')) {
            //sin
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение sin(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'c') && (str1[i + 1] == 'o') && (str1[i + 2] == 's')) {
            //cos
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение cos(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 't') && (str1[i + 1] == 'g')) {
            //tg
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение tg(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'c') && (str1[i + 1] == 't') && (str1[i + 2] == 'g')) {
            //ctg
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение ctg(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'l') && (str1[i + 1] == 'n')) {
            //ln
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение ln(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'l') && (str1[i + 1] == 'o') && (str1[i + 2] == 'g')) {
            //log
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение log(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 's') && (str1[i + 1] == 'q') && (str1[i + 2] == 'r') && (str1[i + 3] == 't')) {
            //sqrt
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение sqrt(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'c') && (str1[i + 1] == 'b') && (str1[i + 2] == 'r') && (str1[i + 3] == 't')) {
            //cbrt
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // записали полность выражение cbrt(45)
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'p') && (str1[i + 1] == 'i')) {
            //PI
            while (str1[i] != ' ') {
                temp += str1[i];
                i++;
            }
            // записали полность выражение pi
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if ((str1[i] == 'e')) {
            //Exponenta
            while (str1[i] != ' ') {
                temp += str1[i];
                i++;
            }
            // записали полность выражение e
            stack->push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }

        if ((str1[i] != ' ') && (str1[i] != ')') && (str1[i] != '(')) {
            temp += str1[i];
        }
        if (str1[i] == ')') {
            stack->push(temp);
            temp = "\0";
            temp_parenthesis = '(';
            stack->push(temp_parenthesis);
        }

        if (str1[i] == '(') {
            temp_parenthesis = ')';
            stack->push(temp_parenthesis);
        }

        if (str1[i] == ' ') {
            stack->push(temp);
            temp = "\0";
        }
    }
    stack->push(temp); // 1000-7
}

void convert_infix_to_prefix(Stack<std::string>* stack, Stack<std::string>* prefix, Stack<std::string>* buffer) {
    // у меня нет проблем, кроме моей бошки
    std::string temp;
    while (!stack->isEmpty()) {
        if ((!stack->isEmpty()) && (stack->peek() == "")) {
            stack->pop();
        }
        if ((!stack->isEmpty()) && (stack->peek() == "(")) {
            buffer->push("(");
            stack->pop();
        }
        if ((!stack->isEmpty()) && (stack->peek() == "")) {
            stack->pop();
        }
        if (!stack->isEmpty()) {
            temp = stack->peek();
        }

        if ((temp[0] >= 48) && (temp[0] <= 57) || math_func(temp)) {
            prefix->push(stack->peek());
            stack->pop();
        }
        else {
            throw std::out_of_range("Error! Incorrect expression!\n");
        }
        if ((!stack->isEmpty()) && (stack->peek() == "")) {
            stack->pop();
        }
        if ((!stack->isEmpty()) && (stack->peek() == ")")) {
            while (buffer->peek() != "(") {
                prefix->push(buffer->peek());
                buffer->pop();
            }
            if (buffer->peek() == "(") {
                buffer->pop();
            }
            stack->pop();
        }
        if ((!stack->isEmpty()) && (stack->peek() == "")) {
            stack->pop();
        }
        if ((!stack->isEmpty()) && (isOperator(stack->peek()))) {
            while ((!buffer->isEmpty()) && (priority(buffer->peek()) >= priority(stack->peek()))) {
                prefix->push(buffer->peek());
                buffer->pop();
            }

            buffer->push(stack->peek());
            stack->pop();
        }
        std::cout << "5\n";
        // клонит спать если только под утро
    }
    while (!buffer->isEmpty()) {
        prefix->push(buffer->peek());
        buffer->pop();
    }
}

int main()
{
    Stack<std::string> stack;
    std::string temp;
    std::string temp_parenthesis;
    Stack<std::string> prefix;
    Stack<std::string> buffer; // (cos(45) + sin(45))
    std::string str2 = "(11 + 12) + 10 * cos(45) + (12 + 15)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512
    std::string str1 = "(cos(45) + sin(45)) / (11 + 12) + 10 * cos(45) + (12 + 15)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


    parenthesis_check(str1);
    convert_string_to_stack(str1, &stack);
    convert_infix_to_prefix(&stack, &prefix, &buffer);
    std::cout << "0\n";
    
    

    
    std::cout << "1\n";
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
    // у меня нет проблем, кроме моей бошки
   
    std::cout << "Bochka bass kolbasit solo\n";
    

    while (!prefix.isEmpty()) {
        std::cout << prefix.peek();
        prefix.pop();
    }
    


    system("pause");
    return 0;
}