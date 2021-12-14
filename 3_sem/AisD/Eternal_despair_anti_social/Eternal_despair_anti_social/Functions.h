#ifndef FUNCTIONS_H
#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Stack.h"

bool Approximate(double a, double b, double epsilon) {
    if (fabs(a) < fabs(b)) {
        return fabs(a - b) <= fabs(b) * epsilon;
    }
    else {
        return fabs(a - b) <= fabs(a) * epsilon;
    }
}

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
    if (c == "+\0" || c == "-\0" || c == "*\0" || c == "/\0" || c == "^\0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool math_func(std::string c) {
    if (((c[0] == 's') && (c[1] == 'i') && (c[2] == 'n') && (c[3] == '(')) || ((c[0] == '-') && (c[1] == 's') && (c[2] == 'i') && (c[3] == 'n') && (c[4] == '('))) {
        return true;
    }
    else if (((c[0] == 'c') && (c[1] == 'o') && (c[2] == 's') && (c[3] == '(')) || ((c[0] == '-') && (c[1] == 'c') && (c[2] == 'o') && (c[3] == 's') && (c[4] == '('))) {
        return true;
    }
    else if (((c[0] == 't') && (c[1] == 'g') && (c[2] == '(')) || ((c[0] == '-') && (c[1] == 't') && (c[2] == 'g') && (c[3] == '('))) {
        return true;
    }
    else if (((c[0] == 'c') && (c[1] == 't') && (c[2] == 'g') && (c[3] == '(')) || ((c[0] == '-') && (c[1] == 'c') && (c[2] == 't') && (c[3] == 'g') && (c[4] == '('))) {
        return true;
    }
    else if (((c[0] == 'l') && (c[1] == 'n') && (c[2] == '(')) || ((c[0] == '-') && (c[1] == 'l') && (c[2] == 'n') && (c[3] == '('))) {
        return true;
    }
    else if (((c[0] == 'l') && (c[1] == 'o') && (c[2] == 'g') && (c[3] == '(')) || ((c[0] == '-') && (c[1] == 'l') && (c[2] == 'o') && (c[3] == 'g') && (c[4] == '('))) {
        return true;
    }
    else if (((c[0] == 's') && (c[1] == 'q') && (c[2] == 'r') && (c[3] == 't') && (c[4] == '(')) || ((c[0] == '-') && (c[1] == 's') && (c[2] == 'q') && (c[3] == 'r') && (c[4] == 't') && (c[5] == '('))) {
        return true;
    }
    else if (((c[0] == 'c') && (c[1] == 'b') && (c[2] == 'r') && (c[3] == 't') && (c[4] == '(')) || ((c[0] == '-') && (c[1] == 'c') && (c[2] == 'b') && (c[3] == 'r') && (c[4] == 't') && (c[5] == '('))) {
        return true;
    }
    else if (((c[0] == 'p') && (c[1] == 'i') && (c[2] == '\0')) || ((c[0] == '-') && (c[1] == 'p') && (c[2] == 'i') && (c[3] == '\0'))) {
        return true;
    }
    else if (((c[0] == 'e') && (c[1] == '\0')) || ((c[0] == '-') && (c[1] == 'e') && (c[2] == '\0'))) {
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

void convert_string_to_stack(std::string str1, Stack<std::string>& stack) {
    std::string temp;
    std::string temp_parenthesis;
    
    for (int i = 0; i < str1.length(); i++) {
        if (((str1[i] == 's') && (str1[i + 1] == 'i') && (str1[i + 2] == 'n')) || ((str1[i] == '-') && (str1[i + 1] == 's') && (str1[i + 2] == 'i') && (str1[i + 3] == 'n'))) {
            //sin
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++;//  sin(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'c') && (str1[i + 1] == 'o') && (str1[i + 2] == 's')) || ((str1[i] == '-') && (str1[i + 1] == 'c') && (str1[i + 2] == 'o') && (str1[i + 3] == 's'))) {
            //cos
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; //  cos(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 't') && (str1[i + 1] == 'g')) || ((str1[i] == '-') && (str1[i + 1] == 't') && (str1[i + 2] == 'g'))) {
            //tg
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // tg(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'c') && (str1[i + 1] == 't') && (str1[i + 2] == 'g')) || ((str1[i] == '-') && (str1[i + 1] == 'c') && (str1[i + 2] == 't') && (str1[i + 3] == 'g'))) {
            //ctg
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // ctg(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'l') && (str1[i + 1] == 'n')) || ((str1[i] == '-') && (str1[i + 1] == 'l') && (str1[i + 2] == 'n'))) {
            //ln
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // ln(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'l') && (str1[i + 1] == 'o') && (str1[i + 2] == 'g')) || ((str1[i] == '-') && (str1[i + 1] == 'l') && (str1[i + 2] == 'o') && (str1[i + 3] == 'g'))) {
            //log
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // log(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 's') && (str1[i + 1] == 'q') && (str1[i + 2] == 'r') && (str1[i + 3] == 't')) || ((str1[i] == '-') && (str1[i + 1] == 's') && (str1[i + 2] == 'q') && (str1[i + 3] == 'r') && (str1[i + 4] == 't'))) {
            //sqrt
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; // sqrt(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'c') && (str1[i + 1] == 'b') && (str1[i + 2] == 'r') && (str1[i + 3] == 't')) || ((str1[i] == '-') && (str1[i + 1] == 'c') && (str1[i + 2] == 'b') && (str1[i + 3] == 'r') && (str1[i + 4] == 't'))) {
            //cbrt
            while (str1[i] != ')') {
                temp += str1[i];
                i++;
            }
            temp += str1[i];
            i++; //  cbrt(45)
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'p') && (str1[i + 1] == 'i')) || ((str1[i] == '-') && (str1[i + 1] == 'p') && (str1[i + 2] == 'i'))) {
            //PI
            while ((str1[i] != ' ') && (str1[i] != ')')) {
                temp += str1[i];
                i++;
            }
            //  pi
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }
        if (((str1[i] == 'e')) || ((str1[i] == '-') && (str1[i + 1] == 'e'))) {
            //Exponenta
            while ((str1[i] != ' ') && (str1[i] != ')')) {
                temp += str1[i];
                i++;
            }
            //  e
            stack.push(temp);
            temp = "\0";
            if (i >= str1.length()) {
                throw std::out_of_range("Techies SS!!!\n");
            }
        }

        if ((str1[i] != ' ') && (str1[i] != ')') && (str1[i] != '(')) {
            temp += str1[i];
        }
        if (str1[i] == ')') {
            stack.push(temp);
            temp = "\0";
            temp_parenthesis = '(';
            stack.push(temp_parenthesis);
        }

        if (str1[i] == '(') {
            temp_parenthesis = ')';
            stack.push(temp_parenthesis);
        }

        if (str1[i] == ' ') {
            stack.push(temp);
            temp = "\0";
        }
    }
    stack.push(temp); // 1000-7
}

void convert_infix_to_prefix(Stack<std::string>& stack, Stack<std::string>& prefix, Stack<std::string>& buffer) {
    
    std::string temp;
    while (!stack.isEmpty()) {
        if ((!stack.isEmpty()) && (stack.peek() == "")) {
            stack.pop();
        }
        if ((!stack.isEmpty()) && (stack.peek() == "(")) {
            buffer.push("(");
            stack.pop();
        }
        if ((!stack.isEmpty()) && (stack.peek() == "")) {
            stack.pop();
        }
        if (!stack.isEmpty()) {
            temp = stack.peek();
        }

        if ((temp[0] >= 48) && (temp[0] <= 57) || math_func(temp)) {
            prefix.push(stack.peek());
            stack.pop();
        }
        else if ((temp[0] == '-') && (temp[1] >= 48) && (temp[1] <= 57)) {
            prefix.push(stack.peek());
            stack.pop();
        }
        else {
            throw std::out_of_range("Error! Incorrect expression!\n");
        }
        if ((!stack.isEmpty()) && (stack.peek() == "")) {
            stack.pop();
        }
        if ((!stack.isEmpty()) && (stack.peek() == ")")) {
            while (buffer.peek() != "(") {
                prefix.push(buffer.peek());
                buffer.pop();
            }
            if (buffer.peek() == "(") {
                buffer.pop();
            }
            stack.pop();
        }
        if ((!stack.isEmpty()) && (stack.peek() == "")) {
            stack.pop();
        }
        if ((!stack.isEmpty()) && (isOperator(stack.peek()))) {
            while ((!buffer.isEmpty()) && (priority(buffer.peek()) >= priority(stack.peek()))) {
                prefix.push(buffer.peek());
                buffer.pop();
            }

            buffer.push(stack.peek());
            stack.pop();
        }
        std::cout << "5\n";
       
    }
    while (!buffer.isEmpty()) {
        prefix.push(buffer.peek());
        buffer.pop();
    }
}

double calculation_in_prefix_form(Stack<std::string>& calculation) {
    Stack<std::string> temp;
    std::string operator_1;
    std::string operator_2;
    double x = 0;
    double y = 0;
    while (!calculation.isEmpty()) {
        if (!isOperator(calculation.peek())) {// operator
            temp.push(calculation.peek());
            calculation.pop();
        }
        if (isOperator(calculation.peek())) {// operand
            operator_2 = temp.peek();
            temp.pop();
            operator_1 = temp.peek();
            temp.pop();

            if (((operator_1[0] == 's') && (operator_1[1] == 'i') && (operator_1[2] == 'n') && (operator_1[3] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 's') && (operator_1[2] == 'i') && (operator_1[3] == 'n') && (operator_1[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_1[0] == 's') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 's') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if ((int)round(x) % 180 == 0) {
                        if (Approximate(x, (int)round(x), 0.00001)) {
                            x = 0;
                            approx = 0;
                        }
                    }

                    if (approx) {
                        if (uno) {
                            x = -1 * sin(x * 3.14 / 180);
                        }
                        else {
                            x = sin(x * 3.14 / 180);
                        }
                    }

                }

            }
            else if (((operator_1[0] == 'c') && (operator_1[1] == 'o') && (operator_1[2] == 's') && (operator_1[3] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 'c') && (operator_1[2] == 'o') && (operator_1[3] == 's') && (operator_1[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_1[0] == 'c') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 'c') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if (((int)round(x) % 90 == 0) && ((int)round(x) % 180 != 0)) {
                        if (Approximate(x, (int)round(x), 0.00001)) {
                            x = 0;
                            approx = 0;
                        }
                    }

                    if (approx) {
                        if (uno) {
                            x = -1 * cos(x * 3.14 / 180);
                        }
                        else {
                            x = cos(x * 3.14 / 180);
                        }
                    }

                }
            }
            else if (((operator_1[0] == 't') && (operator_1[1] == 'g') && (operator_1[2] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 't') && (operator_1[2] == 'g') && (operator_1[3] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_1[0] == 't') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 't') {
                        i = 3;
                        uno = 0;
                    }
                    else {
                        i = 4;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if ((int)round(x) % 180 == 0) {
                        if (Approximate(x, (int)round(x), 0.00001)) {
                            x = 0;
                            approx = 0;
                        }
                    }
                    else if (((int)round(x) % 90 == 0) && ((int)round(x) % 180 != 0)) {
                        if (Approximate(x, (int)round(x), 0.00001)) {
                            throw std::invalid_argument("Does not exist");
                        }
                    }

                    if (approx) {
                        if (uno) {
                            x = -1 * tan(x * 3.14 / 180);
                        }
                        else {
                            x = tan(x * 3.14 / 180);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 'c') && (operator_1[1] == 't') && (operator_1[2] == 'g') && (operator_1[3] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 'c') && (operator_1[2] == 't') && (operator_1[3] == 'g') && (operator_1[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_1[0] == 'c') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 'c') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if (((int)round(x) % 90 == 0) && ((int)round(x) % 180 != 0)) {
                        if (Approximate(x, round(x), 0.00001)) {
                            x = 0;
                            approx = 0;
                        }
                    }
                    else if ((int)round(x) % 180 == 0) {
                        if (Approximate(x, round(x), 0.00001)) {
                            throw std::invalid_argument("Does not exist");
                        }
                    }

                    if (approx) {
                        if (uno) {
                            x = -1 * 1 / tan(x * 3.14 / 180);
                        }
                        else {
                            x = 1 / tan(x * 3.14 / 180);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 'l') && (operator_1[1] == 'n') && (operator_1[2] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 'l') && (operator_1[2] == 'n') && (operator_1[3] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_1[0] == 'l') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 'l') {
                        i = 3;
                        uno = 0;
                    }
                    else {
                        i = 4;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46) && (operator_1[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);
                    if (x <= 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            x = -1 * log(x);
                        }
                        else {
                            x = log(x);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 'l') && (operator_1[1] == 'o') && (operator_1[2] == 'g') && (operator_1[3] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 'l') && (operator_1[2] == 'o') && (operator_1[3] == 'g') && (operator_1[4] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_1[0] == 'l') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 'l') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46) && (operator_1[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if (x <= 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            x = -1 * log10(x);
                        }
                        else {
                            x = log10(x);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 's') && (operator_1[1] == 'q') && (operator_1[2] == 'r') && (operator_1[3] == 't') && (operator_1[4] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 's') && (operator_1[2] == 'q') && (operator_1[3] == 'r') && (operator_1[4] == 't') && (operator_1[5] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_1[0] == 's') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 's') {
                        i = 5;
                        uno = 0;
                    }
                    else {
                        i = 6;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if (x < 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            x = -1 * sqrt(x);
                        }
                        else {
                            x = sqrt(x);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 'c') && (operator_1[1] == 'b') && (operator_1[2] == 'r') && (operator_1[3] == 't') && (operator_1[4] == '(')) || ((operator_1[0] == '-') && (operator_1[1] == 'c') && (operator_1[2] == 'b') && (operator_1[3] == 'r') && (operator_1[4] == 't') && (operator_1[5] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_1[0] == 'c') || (operator_1[0] == '-')) {
                    if (operator_1[0] == 'c') {
                        i = 5;
                        uno = 0;
                    }
                    else {
                        i = 6;
                    }
                    if ((operator_1[i] == ')') || (operator_1[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_1[i] != ')') {
                        if (((operator_1[i] < 48) || (operator_1[i] > 57)) && (operator_1[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_1[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    x = std::stod(math);

                    if (x < 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            x = -1 * cbrt(x);
                        }
                        else {
                            x = cbrt(x);
                        }
                    }
                }
            }
            else if (((operator_1[0] == 'p') && (operator_1[1] == 'i') && (operator_1[2] == '\0')) || ((operator_1[0] == '-') && (operator_1[1] == 'p') && (operator_1[2] == 'i') && (operator_1[3] == '\0'))) {
                if (operator_1[0] == 'p') {
                    x = 3.14;
                }
                else {
                    x = -3.14;
                }
            }
            else if (((operator_1[0] == 'e') && (operator_1[1] == '\0')) || ((operator_1[0] == '-') && (operator_1[1] == 'e') && (operator_1[2] == '\0'))) {
                if (operator_1[0] == 'e') {
                    x = 2.718;
                }
                else {
                    x = -2.718;
                }
            }
            else {
                x = std::stod(operator_1);
            }

            if (((operator_2[0] == 's') && (operator_2[1] == 'i') && (operator_2[2] == 'n') && (operator_2[3] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 's') && (operator_2[2] == 'i') && (operator_2[3] == 'n') && (operator_2[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_2[0] == 's') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 's') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if ((int)round(y) % 180 == 0) {
                        if (Approximate(y, (int)round(y), 0.00001)) {
                            y = 0;
                            approx = 0;
                        }
                    }

                    if (approx) {
                        if (uno) {
                            y = -1 * sin(y * 3.14 / 180);
                        }
                        else {
                            y = sin(y * 3.14 / 180);
                        }
                    }

                }

            }
            else if (((operator_2[0] == 'c') && (operator_2[1] == 'o') && (operator_2[2] == 's') && (operator_2[3] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 'c') && (operator_2[2] == 'o') && (operator_2[3] == 's') && (operator_2[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_2[0] == 'c') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 'c') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if (((int)round(y) % 90 == 0) && ((int)round(y) % 180 != 0)) {
                        if (Approximate(y, (int)round(y), 0.00001)) {
                            y = 0;
                            approx = 0;
                        }
                    }

                    if (approx) {
                        if (uno) {
                            y = -1 * cos(y * 3.14 / 180);
                        }
                        else {
                            y = cos(y * 3.14 / 180);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 't') && (operator_2[1] == 'g') && (operator_2[2] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 't') && (operator_2[2] == 'g') && (operator_2[3] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_2[0] == 't') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 't') {
                        i = 3;
                        uno = 0;
                    }
                    else {
                        i = 4;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if ((int)round(y) % 180 == 0) {
                        if (Approximate(y, (int)round(y), 0.00001)) {
                            y = 0;
                            approx = 0;
                        }
                    }
                    else if (((int)round(y) % 90 == 0) && ((int)round(y) % 180 != 0)) {
                        if (Approximate(y, (int)round(y), 0.00001)) {
                            throw std::invalid_argument("Does not exist");
                        }
                    }

                    if (approx) {
                        if (uno) {
                            y = -1 * tan(y * 3.14 / 180);
                        }
                        else {
                            y = tan(y * 3.14 / 180);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 'c') && (operator_2[1] == 't') && (operator_2[2] == 'g') && (operator_2[3] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 'c') && (operator_2[2] == 't') && (operator_2[3] == 'g') && (operator_2[4] == '('))) {
                int i = 0;
                bool uno = 1;
                bool approx = 1;
                std::string math;
                if ((operator_2[0] == 'c') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 'c') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);
                    if (((int)round(y) % 90 == 0) && ((int)round(y) % 180 != 0)) {
                        if (Approximate(y, round(y), 0.00001)) {
                            y = 0;
                            approx = 0;
                        }
                    }
                    else if ((int)round(y) % 180 == 0) {
                        if (Approximate(y, round(y), 0.00001)) {
                            throw std::invalid_argument("Does not exist");
                        }
                    }

                    if (approx) {
                        if (uno) {
                            y = -1 * 1 / tan(y * 3.14 / 180);
                        }
                        else {
                            y = 1 / tan(y * 3.14 / 180);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 'l') && (operator_2[1] == 'n') && (operator_2[2] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 'l') && (operator_2[2] == 'n') && (operator_2[3] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_2[0] == 'l') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 'l') {
                        i = 3;
                        uno = 0;
                    }
                    else {
                        i = 4;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);
                    if (y <= 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            y = -1 * log(y);
                        }
                        else {
                            y = log(y);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 'l') && (operator_2[1] == 'o') && (operator_2[2] == 'g') && (operator_2[3] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 'l') && (operator_2[2] == 'o') && (operator_2[3] == 'g') && (operator_2[4] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_2[0] == 'l') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 'l') {
                        i = 4;
                        uno = 0;
                    }
                    else {
                        i = 5;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if (y <= 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            y = -1 * log10(y);
                        }
                        else {
                            y = log10(y);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 's') && (operator_2[1] == 'q') && (operator_2[2] == 'r') && (operator_2[3] == 't') && (operator_2[4] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 's') && (operator_2[2] == 'q') && (operator_2[3] == 'r') && (operator_2[4] == 't') && (operator_2[5] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_2[0] == 's') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 's') {
                        i = 5;
                        uno = 0;
                    }
                    else {
                        i = 6;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if (y < 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            y = -1 * sqrt(y);
                        }
                        else {
                            y = sqrt(y);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 'c') && (operator_2[1] == 'b') && (operator_2[2] == 'r') && (operator_2[3] == 't') && (operator_2[4] == '(')) || ((operator_2[0] == '-') && (operator_2[1] == 'c') && (operator_2[2] == 'b') && (operator_2[3] == 'r') && (operator_2[4] == 't') && (operator_2[5] == '('))) {
                int i = 0;
                bool uno = 1;
                std::string math;
                if ((operator_2[0] == 'c') || (operator_2[0] == '-')) {
                    if (operator_2[0] == 'c') {
                        i = 5;
                        uno = 0;
                    }
                    else {
                        i = 6;
                    }
                    if ((operator_2[i] == ')') || (operator_2[i] == '.')) {
                        throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                    }
                    while (operator_2[i] != ')') {
                        if (((operator_2[i] < 48) || (operator_2[i] > 57)) && (operator_2[i] != 46) && (operator_2[i] != 45)) {
                            throw std::invalid_argument("Error!!! Incorrect expression!!!\n");
                        }
                        else {
                            math += operator_2[i]; // было sin(45)
                            i++;                   // стало 45
                        }
                    }
                    y = std::stod(math);

                    if (y < 0) {
                        throw std::underflow_error("Error!!! Incorrect expression!!!\n");
                    }
                    else {
                        if (uno) {
                            y = -1 * cbrt(y);
                        }
                        else {
                            y = cbrt(y);
                        }
                    }
                }
            }
            else if (((operator_2[0] == 'p') && (operator_2[1] == 'i') && (operator_2[2] == '\0')) || ((operator_2[0] == '-') && (operator_2[1] == 'p') && (operator_2[2] == 'i') && (operator_2[3] == '\0'))) {
                if (operator_2[0] == 'p') {
                    y = 3.14;
                }
                else {
                    y = -3.14;
                }
            }
            else if (((operator_2[0] == 'e') && (operator_2[1] == '\0')) || ((operator_2[0] == '-') && (operator_2[1] == 'e') && (operator_2[2] == '\0'))) {
                if (operator_2[0] == 'e') {
                    y = 2.718;
                }
                else {
                    y = -2.718;
                }
            }
            else {
                y = std::stod(operator_2);
            }

            if (calculation.peek() == "+") {
                x = y + x;
                temp.push(std::to_string(x));
            }
            if (calculation.peek() == "-") {

                x = y - x;
                temp.push(std::to_string(x));
            }
            if (calculation.peek() == "*") {
                x = y * x;
                temp.push(std::to_string(x));
            }
            if (calculation.peek() == "/") {
                x = y / x;
                temp.push(std::to_string(x));
            }
            if (calculation.peek() == "^") {
                x = pow(y, x);
                temp.push(std::to_string(x));
            }
            calculation.pop();
        }
    }
    return x;

}
#endif // !FUNCTIONS_H