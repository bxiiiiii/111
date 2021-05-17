#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

#define BUFSIZE 256
#define PROJ_ID 64

int main()
{
    struct mymsg
    {
        long msgtype;
        char ctlstring[BUFSIZE];
    }msgbuf;

    int qid;
    int msglen;
    key_t msgkey;

    if((msgkey = ftok(".", PROJ_ID)) ==-1 )
    {
        perror("ftok");
        exit(1);
    }

    qid = msgget(msgkey, IPC_CREAT|0660);
    if(qid == -1)
    {
        perror("msgkey");
        exit(1);
    }

    msgbuf.msgtype = 3;
    strcpy(msgbuf.ctlstring, "Hello,message queue");
    msglen = sizeof(struct mymsg) - sizeof(long);

    if((msgsnd(qid, (void *)&msgbuf, msglen, 0)) ==-1 )
    {
        perror("msgsnd");
        exit(1);
    }

    return 0;
}