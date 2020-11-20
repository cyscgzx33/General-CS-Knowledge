#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

/* message queue data type */
// Reference: Beej's Guide to IPC, Chapter 7.3
typedef struct msgbuf_boss_t {
	long mtype;
	struct msgbuf_boss_info {
		char file_name[100];
		int is_found; // 0: FILE_NOT_FOUND; 1: FILE_OK
		size_t file_len;
        int nseg;
        int nsegsize;
        int target;
	} info;
} msgbuf_boss_t;

int main(void)
{
    msgbuf_boss_t buf;
    int mqid;
    key_t key;

    if ((key = ftok("sender.c", 120)) == -1) {
		perror("ftok");
		exit(1);
	}

	if ((mqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
		perror("msgget");
		exit(1);
	}

    
}