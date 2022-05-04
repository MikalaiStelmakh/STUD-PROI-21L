#include <iostream>
#include "square.h"

int main()
{
    int number;
    std::cout << "Enter the number: ";
    std::cin >> number;
    std::cout << "The square of " << number << " is " << square(number);
}


