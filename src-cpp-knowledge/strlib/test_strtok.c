#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* getStatus(char* s) {
    char* p = strtok(s, " ");
    printf("p = %s\n", p);
    if (strcmp(p, "GETFILE") != 0)
        return "INVALID";
    printf("hello1\n");
    p = strtok(NULL, " ");
    if (strcmp(p, "ERROR") == 0) return "ERROR";
    else if (strcmp(p, "FILE_NOT_FOUND") == 0) return "FILE_NOT_FOUND";
    else if (strcmp(p, "INVALID") == 0) return "INVALID";
    else if (strcmp(p, "OK") == 0) {
        p = strtok(NULL, " ");
        size_t len;
        int res = sscanf(p, "%zu", &len);
        if (res == 1) {
            printf("len = %ld, ", len);
            char* converted_p;
            sprintf(converted_p, "%zu", len);
            if (strcmp(converted_p, p) == 0) return "OK";
            else return "INVALID";
        }
        else return "INVALID";
    }
    else {
        printf("p = %s\n", p);
        return "INVALID";
    }
}

int main() {
    // char s1[] = "GETFILE OK 781";
    // char s2[] = "GETFILE ERROR";
    // char s3[] = "GETFILE FILE_NOT_FOUND";
    // char s4[] = "\\u0004\\u001fZ_y\\u0010\\u0004\\u001dF:_\\b)\\u0006.";
    // char s5[] = "GETFILE OK 8&1";
    // char s6[] = "GETFILE HAHA";
    char s7[] = "";
    // printf("getStatus(s1): %s\n", getStatus(s1));
    // printf("getStatus(s2): %s\n", getStatus(s2));
    // printf("getStatus(s3): %s\n", getStatus(s3));
    // printf("getStatus(s4): %s\n", getStatus(s4));
    // printf("getStatus(s5): %s\n", getStatus(s5));
    // printf("getStatus(s6): %s\n", getStatus(s6));
    printf("getStatus(s7): %s\n", getStatus(s7));

    return 0;
}