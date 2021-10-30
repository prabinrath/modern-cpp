#include <iostream>

// Explicit casting of classes for CRTP : Curiously Recurring Template Pattern

template<typename T>
class Base
{
	public:
		Base(T& temp) { std::cout << "Derived object static cast to Base\n"; }
		Base(float a, float b) { std::cout << "Base object created\n"; }
		Base() { static_cast<T*>(this)->classMsg(); }
		float a;
		float b;
};

class Derived: public Base<Derived>
{
	public:
		void classMsg() { std::cout << "Derived message fun call\n"; }
		Derived(float temp): c{temp}, Base<Derived>{temp,temp+5} { std::cout << "Derived object created\n"; }
		Derived(Base<Derived>& temp) { std::cout << "Base object static cast to Derived\n"; }
		float c;
};

int main()
{
	Base<Derived> *b = new Base<Derived>{10.54, 8.23};
	Derived *d = new Derived{6.67};

	// *b = static_cast<Base<Derived>&>(*d); 
	// *d = static_cast<Derived&>(*b); 
	*b = static_cast<Base<Derived>>(*d); 
	*d = static_cast<Derived>(*b); 
}
