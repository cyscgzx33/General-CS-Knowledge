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

void set_lptr(foo** foo_p) {
    (*foo_p)->lptr = (struct addrinfo*)malloc(sizeof(struct addrinfo));
    printf("allocated size = %ld\n", sizeof(struct addrinfo));

}

int main() {

    foo* foo_t = foo_create();

    set_lptr(&foo_t);

    return 0;
}