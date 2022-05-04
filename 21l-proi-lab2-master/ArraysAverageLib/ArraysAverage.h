#pragma once
#include <array>

const size_t maxRows = 20;
const size_t maxColumns = 20;

double average(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
int oddSum(int number);
int evenSum(int number);
bool checkNumber(int number);