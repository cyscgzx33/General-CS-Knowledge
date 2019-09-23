#include <iostream>

class Base {
  public:
  	virtual const char* getName() const; // we NEED to implement the non-pure virtual function here 
                                         // otherwise the compiler just throw out an error:
  	                                     // /tmp/ccwdKRBN.o:(.rodata._ZTI7Derived[_ZTI7Derived]+0x10): undefined reference to `typeinfo for Base'
                                         // collect2: error: ld returned 1 exit status

};

class Derived : public Base {
  public:
  	virtual const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d;
	Base& bRef = d;
	std::cout << bRef.getName() << std::endl;

	/* Even if we only conduct the following (calling Derived object only but not touching Base object), it does NOT compile */
	Derived d2;
	std::cout << d2.getName() << std::endl;
	return 0;
}