#include<iostream>
#include <cmath>
#include <algorithm>

int main()
{
	size_t size = pow(1024, 2) / sizeof(double); // Produce 1MB
    double data[size*7];
    std ::fill(data, data + size, 1.23);
    int unused;
    std ::cin >> unused; // Wait for user.
}
