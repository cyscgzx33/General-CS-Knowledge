#include <iostream>
#include <string>

using namespace std;
int main()
{
    string wired = "sada\aqweqe\"asdfasdaqwersad  \6   sad2";
    string wired2 = "\\\\";

    printf("wired.size() = %d", wired.size());
    printf(", wired2.size() = %d\n", wired2.size());

    return 0;
}