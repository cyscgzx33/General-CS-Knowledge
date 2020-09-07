#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
typedef struct foo foo;


struct foo {
    int a;
    int b;
    int c;
    struct addrinfo* lptr;
};


foo* foo_create() {
    foo* foo_t = (foo*)malloc(sizeof(foo));
    memset(foo_t, 0, sizeof(foo));

    printf("sizeof(foo) = %ld\n", sizeof(foo));

    return foo_t;
}

int main() {

    foo* foo_t = foo_create();

    return 0;
}