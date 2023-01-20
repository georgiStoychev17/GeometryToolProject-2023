#pragma once
#include <iostream>

const int MAX_SIZE = 50;
const double MIN = 1e-5;

size_t CustomStrLen(const char*);

bool IsAValidName(const char*, size_t);

void GetSymbol(char*);

void clearConsole();

void Swap(double&, double&);

double CustomFabs(double);
