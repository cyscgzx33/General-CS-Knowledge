/*
 * shm-client - client program to demonstrate shared memory.
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 2000

/* shm data struct */
// Reference: lecture notes in P3L3-14
typedef struct {
  int m;
} shm_data_t;

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    shm_data_t* addr;

    /*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;
    // key = ftok("shmfile",65); // no need to "deliberately assign a file"
    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    addr = (shm_data_t*)shm;

    /*
     * Now read what the server put in the memory.
     */
    for (s = (char*)addr + sizeof(int); *s != NULL; s++)
        putchar(*s);
    putchar('\n');

    /*
     * Finally, change the first character of the 
     * segment to '*', indicating we have read 
     * the segment.
     */
    *shm = '*';

    exit(0);
}