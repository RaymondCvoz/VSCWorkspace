#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define KEY_MSG 0x101
#define MSGSIZE 64

typedef struct
{
	long mtype;
	char mtext[MSGSIZE];
} msgbuf;

#define LEN sizeof(msgbuf) - sizeof(long)

int main()
{
	int msgid;
	msgbuf buf1, buf2;
	msgid = msgget(KEY_MSG, 0666);
	while (1)
	{
		printf("input the msg to client2:");
		gets(buf1.mtext);
		buf1.mtype = 1L;
		msgsnd(msgid, &buf1, LEN, 0); //客户端1获取消息并发往服务器

		msgrcv(msgid, &buf2, LEN, 3L, 0); //准备从客户端2获取消息
		if (buf2.mtext[0] == 'x' || buf2.mtext[0] == 'X')
		{
			printf("client1 will quit!\n");
			break;
		}
		printf("Receive from client2, message: %s\n", buf2.mtext);
	}
	return 0;
}
