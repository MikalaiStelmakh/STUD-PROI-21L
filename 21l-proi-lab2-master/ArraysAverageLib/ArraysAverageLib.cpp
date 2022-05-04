#include <array>
#include "ArraysAverage.h"


double average(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
	double sum = 0, number, counter = 0;
	for (size_t row = 0; row < rows; ++row)
	{
		for (size_t column = 0; column < columns; ++column)
		{
			number = array[row][column];
			if (checkNumber(number) == true and number != 0)
			{
				sum += number;
				counter++;
			}
		}
	}
	if (counter == 0)
		return 0;
	else
		return sum / counter;
}

int oddSum(int number)
{
	int sum = 0, n;
	while (number > 0)
	{
		n = number % 10;
		sum += n;
		number = number / 100;
	}
	return sum;
}

int evenSum(int number)
{
	int sum = 0, n;
	number = number / 10;
	while (number > 0)
	{	
		n = number % 10;
		sum += n;
		number = number / 100;
	}
	return sum;
}

bool checkNumber(int number)
{
	if (oddSum(number) == evenSum(number))
		return true;
	else
		return false;
}
