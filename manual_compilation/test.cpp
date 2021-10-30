#include <iostream>
#include "division.h"
#include "division.h"
#include "multiply.h"

int sumation(int a,int b);

int sumation(int a,int b)
{
	return a+b;
}

int main()
{
	size_t ind = 0;
	for(ind = 0;ind<10;ind++)
	{
		std::cout << ind << " " << sumation(ind+10,ind+2) << std::endl;
		std::cout << ind << " " << multiply(ind+10,ind+2) << std::endl;
		std::cout << ind << " " << division(ind+10) << std::endl;
	}
	return 0;
}
