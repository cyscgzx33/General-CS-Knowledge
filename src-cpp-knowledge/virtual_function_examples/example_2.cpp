class A
{
public:
    virtual const char* getName() const { return "A"; } // note: function is const
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    A &rBase = c;
    std::cout << rBase.getName() << '\n';
 
    return 0;
}

/**
 * [Output]
 * A
 * 
 * [Explain]
 * A. This one is a little trickier. rBase is an A reference to a C object, 
 * so rBase.getName() would normally call A::getName(). But A::getName() is virtual, 
 * so it calls the most derived version of the function between A and C. And that is A::getName(). 
 * Because B::getName() and c::getName() are not const, they are not considered overrides! 
 * Consequently, this program prints A.
 */