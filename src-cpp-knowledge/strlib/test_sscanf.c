#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main() {
    // char* s = "GETFILE OK 107528";
    char* s = "\\u0004\\u001fZ_y\\u0010\\u0004\\u001dF:_\\b)\\u0006.";
    char scheme[10], status[20];
    size_t filelen;
    printf("hello-1\n");
    int res = sscanf(s, "%s %s %ld", scheme, status, &filelen);
    printf("hello!\n");
    printf("res = %d", res);
    // printf("scheme: %s, status: %s, filelen: %ld\n", scheme, status, filelen);

    return 0;
}


