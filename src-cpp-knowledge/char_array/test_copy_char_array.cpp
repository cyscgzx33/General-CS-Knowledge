#include <iostream>
#include <cstring>
#include <string>

void myStrcpy(char* s, char* t)
{
  while(*s++ = *t++);
  // explanation:
  // Firstly, dereference operation (`*`) starts from right-hand-side, `*t` followed by `*s`
  // Secondly, assign operation (`=`) does it job from right-hand-side to left-hand-side, i.e., `*s = *t`
  // Thirdly, suffix/postfix increment(`++`) executes from left-hand-side to right-hand-side, `s++` followed by `t++`
  // Fourthly, the assignment return the value as the right-hand-side value (in this case it is `*t`), and `while(*t)`
  //           will continue the loop until `*t` is `\0` (which is `NUL` or `NULL` in [*ASCII* code](https://www.ascii-code.com/))
  // Finally, when the loop ends, according to the behavior of suffix/postfix increment(`++`), current position of pointer `s` and `t` 
  //          are one more step behind the string end position `0`.
}

void myStrcpy2(char*s, char* t)
{
  // Todo: finish this experiment
  while(*++s = *++t);
  // explanation:
  // 
}

int main(int argc, char** argv)
{
  // Example 1: copy from std::string to char array using strcpy()
  //            step 1) define char* and allocate memory
  //            step 2) execute strcpy(), note std::string should be converted to c_str()

  std::string str = "hello world!";
  int n = str.length();
  char* t;
  t = (char*)malloc(n+1);
  strcpy(t, str.c_str());
  printf("----------------  Example 1:  ----------------\n");
  printf("The copied t is: %s\n", t);

  // ------------------------------ End of Example 1 ----------------------------------------------
  

  // Example 2: copy from char array to char array using while (*s++ = *t++)
  //            step 1) define char* s and allocate memory
  //            step 2) execute while (*s++ = *t++)
  char* s = new char; // Note: we can also allocate memory for s as a char array, 
                      // such as, s = (char*)malloc(n+1); (exactly same as in Example 1)
                      // but if we define it w/o allocation, such as, char* s;
                      // it will show Segmentation fault (core dumpted)
  char* c = s;        // A pointer points to the initial position of *s, will be used to print *s
  char* p = t;        // A pointer points to the initial position of *t, will be used in the variation
  int i = 0;          // A helper variable to record how many iteration we've executed

  printf("\n----------------  Example 2:  ----------------\n");
  while (*s++ = *t++)
  {
    printf("iteration: %d, ", i++);
    printf("t = %s\n", t); 
  }
  printf("The copied s is: %s\n", c); // Here we have to use c, as it stays at head of copied array
                                      // Output: The copied s is: hello world!
  printf("The copied s is: %s\n", s); // If we print s to check, it stays at end of copied array
                                      // Output: The copied s is: 

  // ------------------------------ End of Example 2 ----------------------------------------------


  // Example 3: use a function to process while (*s++ = *t++)
  char* v = new char;
  myStrcpy(v, p); // Note: now it's obviously pass-by-value, the values of v and p are NOT changed
                  // The good point to use a function is, no need to create a temporary pointer

  printf("\n----------------  Example 3:  ----------------\n");
  printf("The copied v is: %s\n", v); // Output: The copied v is: hello world!

  // ------------------------------ End of Example 3 ----------------------------------------------

  return 0;
}
