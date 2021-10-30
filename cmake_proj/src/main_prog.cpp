#include <iostream>
#include "division.h"
#include "multiply.h"
#include <string>
#include <vector>

int sumation(int a,int b);

int sumation(int a,int b)
{
	return a+b;
}

class Fun
{
	public:
		int& access() {return x;}
	private:
		int x;	
};

int main()
{
	// size_t ind = 0;
	// for(ind = 0;ind<2;ind++)
	// {
	// 	std::cout << ind << " " << sumation(ind+10,ind+2) << std::endl;
	// 	std::cout << ind << " " << multiply(ind+10,ind+2) << std::endl;
	// 	std::cout << ind << " " << division(ind+10) << std::endl;
	// }

	// std::string a = "Hello";
	// std::vector<std::string> v;
	// //std::string&& b = std::move(a);
	// std::cout<<a<<std::endl;
	// v.push_back(std::move(a));
	// std::cout<<a<<" : "<<v[0]<<std::endl;
	Fun obj;
	obj.access() = 5;
	std::cout<<obj.access()<<std::endl;
	return 0;
}
