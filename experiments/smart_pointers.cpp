#include <memory>
#include <iostream>

int main()
{
	auto p = std::unique_ptr<double>(new double(10.54));
	// auto b = p; //error as copy constructor is deleted explicitly for unique_ptr
	auto b = std::move(p);

	std::cout << (p == nullptr) << std::endl; 
	// prints 1, means move sets the p to null to prevent a dangling pointer

	std::cout << *b << std::endl;

	auto a = std::shared_ptr<double>(new double(10.54));
	std::cout << a.use_count() << std::endl;
	auto c = a;
	std::cout << a.use_count() << std::endl;
}