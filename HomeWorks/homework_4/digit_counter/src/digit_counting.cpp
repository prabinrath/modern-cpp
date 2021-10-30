#include "digit_counting.h"
#include <stdexcept>

bool ReturnTrue()
{
	return true;
}

double Warp(double number, double factor)
{
	double number_ = number;
	number_ += factor;
	number_ -= factor;
	return number_;
}

int CountSameSignificantDigits(double a, double b)
{
	throw std::logic_error("Requirements not clear enough for implementation");
}