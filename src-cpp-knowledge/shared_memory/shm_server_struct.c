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
  char buf[200];
} shm_data_t;

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    shm_data_t* addr;

    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5678;
    // key = ftok("shmfile",65); // no need to "deliberately assign a file"

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    addr = (shm_data_t*)shm;

    /*
     * Now put some things into the memory for the
     * other process to read.
     */
    s = addr->buf;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;

    *s = NULL;

    /*
     * Finally, we wait until the other process 
     * changes the first character of our memory
     * to '*', indicating that it has read what 
     * we put there.
     */
    while (*shm != '*')
        sleep(1);

    exit(0);
}