#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {
    char* s = "GETFILE OK 107528";
    char scheme[10], status[20];
    size_t filelen;
    printf("hello-1\n");
    sscanf(s, "%s %s %ld", scheme, status, &filelen);
    printf("hello!\n");
    printf("scheme: %s, status: %s, filelen: %ld\n", scheme, status, filelen);

    return 0;
}


