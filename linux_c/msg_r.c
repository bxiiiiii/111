#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 256
#define PROJ_ID 64

int main()
{
    struct mymsg
    {
        long msgtype;
        char ctlstring[BUF_SIZE];
    }msgbuf;

    int qid;
    int msglen;
    key_t msgkey;

    msgkey = ftok(".", PROJ_ID);

    qid = msgget(msgkey, IPC_CREAT|0660);

    msglen = sizeof(struct mymsg) -4;

    if((msgrcv(qid, &msgbuf, msglen, 3, 0))==-1)
    {
        perror("msgrcv");
        exit(1);
    }

    printf("get:%s\n", msgbuf.ctlstring);
    

    return 0;
}