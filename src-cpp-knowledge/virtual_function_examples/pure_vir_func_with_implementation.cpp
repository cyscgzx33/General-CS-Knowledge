#include <iostream>

class Base {
  public:
  	virtual const char* getName() const = 0; // Usually, we should NOT implement the pure virtual function
                                             // But we CAN implement it as a non-inline funcion 
                                             // But Base can still NOT be able to instantiate
};

const char* Base::getName() const
{
  return "Base"; // some default implementation
}

class Derived : public Base {
  public:
  	virtual const char* getName() const { return "Derived"; }
};

int main()
{

  Base b; // Compile error

	Derived d;
	Base& bRef = d;
	std::cout << "Result of calling \"bRef.Base::getName()\" : " << bRef.Base::getName() << std::endl;
  std::cout << "Result of calling \"bRef.getName()\" : " << bRef.getName() << std::endl;
	return 0;
}