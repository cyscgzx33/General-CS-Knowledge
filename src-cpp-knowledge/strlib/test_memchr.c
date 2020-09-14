#include <stdio.h>
#include <string.h>

int findEnding(char s[]) {
    int len = strlen(s);
    char* pch = s;
    int pos = -1;
    while ((pch+1) != NULL && (pch = (char*)memchr(pch+1, '\r', len)) != NULL) {
        printf("pch pos: %ld\n", pch - s);
        if ((pch+1) != NULL && *(pch+1) == '\n' &&
            (pch+2) != NULL && *(pch+2) == '\r' &&
            (pch+3) != NULL && *(pch+3) == '\n') {
            pos = pch - s;
            break;
        }
        len -= (pch - s + 1);
        printf("len = %d\n", len);
    }

    printf("pos = %d\n", pos);

    return pos;
}


int main() {
    char s1[] = "hello \r\n hello1 \r\n\r hello2 \r\n\r\n hello3.";
    char s2[] = "hellohello\r\n\r\n";
    
    findEnding(s1);
    findEnding(s2);

    return 0;
}
