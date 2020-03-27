# Useful C/C++ Build/Compilation Knowledge

## Difference between `gcc` and `g++`
* [My understanding] 
    * (1) gcc will compile: \*.c/\*.cpp files as C and C++ respectively; 
    * (2) g++ will compile: \*.c/\*.cpp files but they will all be treated as C++ files; 
    * (3) also if you use g++ to link the object files it automatically links in the std C++ libraries (gcc does not do this); 
    * (4) gcc compiling C files has fewer predefined macros; 
    * (5) gcc compiling \*.cpp and g++ compiling \*.c/\*.cpp files has a few extra macros.
* [Reference] https://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc.


# Useful C/C++ Programming Knowledge

## C++ `typename` keyword
* [My understanding] Before a ***qualified dependent*** type, we need `typename`
    * For example:
    ```C++
    template <class T>
    void foo() {
        typename T::iterator* iter;
        ...
    }
    ```
*  [Reference] http://pages.cs.wisc.edu/~driscoll/typename.html

## Rvalue Reference w/ `&&` Operator
* [My understanding] Compared to `C++03` reference (now called an lvalue reference in `C++11`), the rvalue reference can bind to an rvalue like a temporay without having to be `const`. 
    * `&&` is normally only used to declare a parameter of a function, and it only takes an r-value expression, 
    * Another *cheating* way of understanding is, an rvalue is a value doesn't have a memory address. For example:
    ```C++
    void foo(int&& a)
    {
        //Some magical code...
    }
    int main()
    {
        int b;
        foo(b);       //Error. An rValue reference cannot be pointed to a lValue.
        foo(5);       //Compiles with no error.
        foo(b+3);     //Compiles with no error.
        int&& c = b;  //Error. An rValue reference cannot be pointed to a lValue.
        int&& d = 5;  //Compiles with no error.
    }
    ```
    * For another example, such syntax is now legal:
    ```C++
    T&& r = T();
    ```
* [Reference] https://www.tutorialspoint.com/What-is-double-address-operator-and-and-in-Cplusplus, https://stackoverflow.com/questions/5481539/what-does-t-double-ampersand-mean-in-c11

## Generic Pointer `void*` in C/C++
* [My understanding] A void pointer is a pointer that has no associated data type with it. A void pointer can hold address of any type and can be typcasted to any type.
    * One can type cast `void*` to other types, such as `double*`
    ```C++
    void* num_ptr;
    double* double_ptr = (double*)num_ptr;
    // or all-in-one definition
    double n = *(double*)num_ptr;
    ```
    * A conplicated example, `void* (*routine)(void*)`, it declares `routine`, which is a pointer to a function taking a single parameter of type `void*` and returning the type `void*`, the detailed version of explanation:
    (for practical execution of the idea, please check [src/generic_function_pointer](https://github.com/cyscgzx33/general-cs-knowledge/blob/master/src-cpp-knowledge/generic_fucntion_pointer.c))
    ```C++
            routine             -- routine
           *routine             -- is a pointer
          (*routine)(      )    -- to a function
          (*routine)(void *)    -- taking a single parameter of type void *
         *(*routine)(void *)    -- returning a pointer
    void *(*routine)(void *)    -- to void    
    ```
* [Reference] https://stackoverflow.com/questions/12700384/convert-void-to-double/12700631#12700631, https://stackoverflow.com/questions/21411113/what-does-void-routinevoid-mean-in-c


## STD I/O in C/C++
* [Reference] [Reading and Wring Through CSV Files](https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/), [I/O STL Library](https://www.learncpp.com/cpp-tutorial/181-input-and-output-io-streams/)

## Classic String Copy: `while (*s++ = *t++);`
* [My understanding] The s and t variables are pointers (almost certainly characters), s being the destination. The following steps illustrate what's happening:
    * Firstly, dereference operation (`*`) starts from right-hand-side, `*t` followed by `*s`
    * Secondly, assign operation (`=`) does it job from right-hand-side to left-hand-side, i.e., `*s = *t`
    * Thirdly, suffix/postfix increment(`++`) executes from left-hand-side to right-hand-side, `s++` followed by `t++`
    * Fourthly, the assignment return the value as the right-hand-side value (in this case it is `*t`), and `while(*t)` will continue the loop until `*t` is `\0` (which is `NUL` or `NULL` in [*ASCII* code](https://www.ascii-code.com/))
    * Finally, when the loop ends, according to the behavior of suffix/postfix increment(`++`), current position of pointer `s` and `t` are one more step behind the string end position `0`.
    ```
    H   e   l   l   o   ,   w   o   r   l   d   !   \0
    ^^                                              ^^          ^^
    st                                              st          st
    [Loop starts]  ----------------------->     [Loop ends]   [one more step after loop ends]
    ```
    * Ultimately, it is equivalent to (Credits to ***Patrick Schluter*** :thumsup:, listed in the reference StackOverflow page) 
    ```C++
    char tmp = 0;
    do {
        tmp = *t;
        *s = tmp;
        s++;
        t++;
    } while(tmp);
    ```
* [Example src code] check [src code](../src-cpp-knowledge/char_array/test_copy_char_array.cpp)
* [Reference] [StackOverflow Explanation](https://stackoverflow.com/questions/810129/how-does-whiles-t-copy-a-string), [C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence), [ASCII Code](https://www.ascii-code.com/)