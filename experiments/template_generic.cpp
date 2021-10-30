#include <iostream>

template<typename T, class S>
T demoFun(T arg1, S arg2)
{
	std::cout << "template function A" << std::endl;
	arg1 *= arg1;
	arg2 /= arg2;
	return (T)(arg1+arg2);
}

template<typename T>
int demoFun(int arg1, T arg2)
{
	std::cout << "template function B" << std::endl;
	arg1 += arg1;
	arg2 += arg2;
	return (int)(arg1*arg2);
}

template<>
int demoFun(int arg1, float arg2)
{
	std::cout << "template function C" << std::endl;
	arg1 += 2*arg1;
	arg2 += 3*arg2;
	return (int)(arg1*arg2);
}

int main()
{
	std::cout << demoFun((long)1, (int)2.7896) << std::endl; //A
	std::cout << demoFun((int)1, (double)2.7896) << std::endl; //B
	std::cout << demoFun((int)1, (float)2.7896) << std::endl; //C

	return 0;
}