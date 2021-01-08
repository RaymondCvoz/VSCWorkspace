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
		msgrcv(msgid, &buf2, LEN, 4L, 0); //等待客户端1发消息
		if (buf2.mtext[0] == 'x' || buf2.mtext[0] == 'X')
		{
			printf("client2 will quit!\n");
			break;
		}
		else
			printf("Receive from client1, message: %s\n", buf2.mtext);

		sleep(1); //等待一秒，以确保客户端1已经收到了回执
		printf("input the msg to client1:");
		gets(buf1.mtext);
		buf1.mtype = 2L;
		msgsnd(msgid, &buf1, LEN, 0); //给客户端1发送回执消息
	}
}