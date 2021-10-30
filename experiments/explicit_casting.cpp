#include <iostream>


class Other
{
	public:
		// Other(float temp): d{temp} {}
		float d;
		// virtual ~Other() = default;
};

class Base
{
	public:
		// Base(Other& temp){}
		// Base(float a, float b){}
		float a;
		float b;
		// virtual ~Base() = default;
};

class Derived: public Base
{
	public:
		Derived(float temp): c{temp}, Base{temp,temp+5}{}
		// Derived(Base& temp){}
		float c;
};

int main()
{
	Base *b = new Base{10.54, 8.23};
	Derived *d = new Derived{6.67};
	Other *o = new Other{8.23};

	*b = static_cast<Base>(*d); //Allowed by default
	// *d = static_cast<Derived>(*b); //Allowed with additional syntax
	//Allowed only if constructor is present to handle Base as arg in Derived class (line 26)
	// *b = static_cast<Base>(*o); //Allowed with additional syntax
	//Allowed only if constructor is present to handle Other as arg in Base class (line 15)

	Base *b_temp = reinterpret_cast<Base*>(d); //Allowed
	Derived *d_temp = reinterpret_cast<Derived*>(b); //Allowed
	Base *b_temp1 = reinterpret_cast<Base*>(o); //Allowed

	long *num1 = new long(786);
	double *num2 = reinterpret_cast<double*>(num1); //Allowed
	std::cout << *num1 << " " << *num2 << std::endl;

	// float *num3 = reinterpret_cast<float*>(b); //Allowed
	int *num3 = reinterpret_cast<int*>(b); //Allowed
	std::cout << *num3 << std::endl;

	Base *b_temp2 = dynamic_cast<Base*>(d); //Allowed by default
	// Derived *d_temp2 = dynamic_cast<Derived*>(b); //Allowed with additional syntax
	//Allowed only if Base is polymorphic (line 19)
	// Base *b_temp3 = dynamic_cast<Base*>(o); //Allowed with additional syntax
	//Allowed only if Other is polymorphic (line 9)
	//Polymorphic means the class should have atleast one virtual function. 
	//If no candidate available then make destructor virtual
}

/*
All or nothing principle - If you define any one of the following special functions :
[Destructor, Copy constructor, Move constructor, Assignment, Move assignment]
then you have to define all of them :)
*/