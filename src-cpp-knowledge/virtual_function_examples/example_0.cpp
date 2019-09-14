#include <iostream>

class A
{
  public:
  	virtual const char* getName() { return "A"; }
};

class B : public A
{
  public:
    virtual const char* getName() { return "B"; }	
};

class C : public B
{
  public:
  	// Note no getName() function in C	
};

class D : public C
{
  public:
  	virtual const char* getName() { return "D"; }
};

class E : public D
{
  public:
    // Note no getName() function in E
};

int main()
{
	E e;
	A& rBase = e;
	std::cout << rBase.getName() << '\n';

	return 0;
}

/**
 * [Output]
 * D

 * [Explain]
 * D. rBase is an A reference pointing to a E object. 
 * Normally rBase.getName() would call A::getName(), 
 * but A::getName() is virtual so it instead calls 
 * the most recently derived matching function 
 * between A and E. 
 * That is D::getName(), which prints D.
 */