#include <iostream>
#include <cmath>
#include <algorithm>
using std ::cout;
using std ::endl;
int main()
{
    double *data = nullptr;
    size_t size = pow(1024, 3) / sizeof(double); // Produce 1GB
    for(int i=0;i<1;i++)
    {
        // Allocate memory for the data.
        data = new double[size];
        std ::fill(data, data + size, 1.23);
        cout << "Iteration "<< i<<" Done!" << endl;
    }

    int unused;
    std ::cin >> unused; // Wait for user.

    return 0;
}