#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

void getattr(int msqid, struct msqid_ds attr)
{
    msgctl(msqid, IPC_STAT, &attr);

    printf("*****start****\n");
    printf("current number of bytes on queue = %ld\n", attr.__msg_cbytes);
    printf("number of messages in queue = %ld\n", attr.msg_qnum);
    printf("max number of bytes on queue = %ld\n",attr.msg_qbytes);
    printf("------------------\n");
}

int main()
{
    struct mybuf{
        long type;
        char str[512];
    }buf;
    int qid, len;
    key_t key;
    struct msqid_ds attr;

    key = ftok(".", 32);
    qid = msgget(key, IPC_CREAT|0660);

    buf.type = 1;
    fgets(buf.str, 512, stdin);
    buf.str[strlen(buf.str)-1] = '\0';
    len = sizeof(buf) - sizeof(long);

    getattr(qid, attr);

    msgsnd(qid, (void *)&buf, len, IPC_NOWAIT);

    msgctl(qid, IPC_RMID, NULL);
    getattr(qid,attr);

    return 0;

}