#include <iostream> 
using namespace std; 

class base { 
public: 
	virtual void print() 
	{ 
		cout << "print base class" << endl; 
	} 

	// virtual void pure() = 0;

	void show() 
	{ 
		cout << "show base class" << endl; 
	} 
}; 

class derived : public base { 
public: 
	void print() override //override keyword is optional but using it is defencive programming
	{ 
		cout << "print derived class" << endl; 
	} 

	// void pure() override
	// {
	// 	cout << "Pure virtual funtion overridden" << endl;
	// }

	void show() 
	{ 
		cout << "show derived class" << endl; 
	} 
}; 

int main() 
{ 
	base* bptr;
	bptr = new base; 
  	bptr->print();
   	delete bptr;
    derived d;
	bptr = &d; 

	// virtual function, binded at runtime 
	bptr->print(); 

	// Non-virtual function, binded at compile time 
	bptr->show(); 
} 