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

## C++ 'typename' keyword
* [My understanding] Before a ***qualified dependent*** type, we need `typename`
    * For example:
    ```
    template <class T>
    void foo() {
        typename T::iterator* iter;
        ...
    }
    ```
*  [Reference] http://pages.cs.wisc.edu/~driscoll/typename.html