/**
*
* Solution to course project # 03
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Georgi Stoychev
* @idnumber 7MI0600157
* @compiler VC
*
* file with utility functions, needed to assist the others
*
*/

#include <iostream>

const int MAX_SIZE = 50;
const double MIN = 1e-5;

size_t CustomStrLen(const char* str) {
    size_t index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}

bool IsAValidName(const char* name, size_t size) {
    size = CustomStrLen(name);

    for (int i = 0; i < size; i++) {
        if ((name[i] < '0' || name[i] > '9') && (name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z') && (name[i] != '_')) {
            return false;
        }
    }
    return true;
}

void GetSymbol(char* symbol) {
    bool isTheSymbolCorrect;

    do {
        std::cin >> symbol;
        isTheSymbolCorrect = true;

        if (!IsAValidName(symbol, CustomStrLen(symbol))) {
            isTheSymbolCorrect = false;
            std::cout << "That is not a valid symbol! Please try again: ";
        }

    } while (!isTheSymbolCorrect);
}

void clearConsole() {
    std::cout << "\033[;H";
    std::cout << "\033[J";
}

void Swap(double& a, double& b) {

    double temp = a;
    a = b;
    b = temp;
}

double CustomFabs(double num) {
    return num - 0 > MIN ? num : -num;
}