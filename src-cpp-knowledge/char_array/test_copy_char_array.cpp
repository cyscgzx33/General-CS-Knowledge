#include <iostream>
#include <cstring>
#include <string>

void myStrcpy(char *s, char *t)
{
    while(*s++ = *t++) {}
}

int main(int argc, char** argv)
{
  std::string str = "hello world!";
  int n = str.length();
  char* t;
  printf("checkpoint 1 \n");
  // memset(t, '\0', sizeof(char) * (n + 1)); // OF COURSE FAILED! no memory allocation, how to memset???????
  printf("checkpoint 2 \n");
  t = (char*)malloc(n+1);
  strcpy(t, str.c_str());
  printf("t = %s\n", t);
  // size_t i = std::strlen(t);
  
  char* s;
  s = (char*)malloc(n+1);
  char* c = s;
  // memset(s, '\0', sizeof(char) * i); // OF COURSE FAILED! no memory allocation, how to memset???????

  int i = 0;
  while(*s++ = *t++) 
  { 
    printf("iteration: %d, ", i++);
    printf("t = %s\n", t); 
  }
  // myStrcpy(s, t);
  
  printf("s = %s\n", c);
  return 0;
}
