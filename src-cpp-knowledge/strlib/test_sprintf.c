#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    char s1[100];
    char s2[100] = "hello\r\n\r\n";

    s1[0] = '\0';

    sprintf(s1, "%s%s", s1, s2);
    printf("s1: %s\n", s1);
    int s1len = strlen(s1);

    printf("s1len: %d\n", s1len);

    char* ending = strstr(s1, "\r\n\r\n");

    int diff = ending - s1;

    printf("diff: %d\n", diff);

    return 0;
}