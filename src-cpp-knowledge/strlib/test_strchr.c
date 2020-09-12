#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char* s = "GETFILE GET /root/a.jpg\r\n\r\nGETFILE GET /root/b.jpg\r\n\r\n";
    char* start = s;
    int total_len = strlen(s);

    while (s - start < total_len) {
        char* end = strstr(s, "\r\n\r\n");
        if (end == NULL) break;
        int len = end - s;
        char* header = strstr(s, "GETFILE GET ");
        if (header == NULL) break;
        char* path = malloc(len-12+1);
        sprintf(path, "%s", s+12);
        path[len-12] = '\0';
        printf("path: %s\n", path);
        s += len+4;
    }

    return 0;
}