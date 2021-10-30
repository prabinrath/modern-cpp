#include <iostream>
#include <cmath>

int main()
{
	size_t size = (1024 * 100) / sizeof(double);
	double track = 0;
	while(true)
	{
		double* data = (double*) alloca(size);
		track += (double) (size * sizeof(double)) / pow(1024, 2); //MB
		std::cerr << "Allocated: " << track << "MB" << std::endl;
	}
}