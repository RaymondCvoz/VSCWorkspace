#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define KEY_MSG 0x101 //使用共有的IPC key
#define MSGSIZE 64

typedef struct //定义消息结构体：消息类型和消息数据
{
	long mtype;
	char mtext[MSGSIZE];
} msgbuf;

#define LEN sizeof(msgbuf) - sizeof(long)

int main()
{
	int msgid;
	msgbuf buf1, buf2;
	msgid = msgget(KEY_MSG, IPC_CREAT | 0666);
	while (1)
	{
		msgrcv(msgid, &buf1, LEN, 1L, 0);
		//接受客户端1的消息
		printf("Receive client1 message: %s\n", buf1.mtext); //打印收到的消息
		if (buf1.mtext[0] == 'x' || buf1.mtext[0] == 'X')
		//若是退出标志，则给2个客户端都发退出信息
		{
			strcpy(buf1.mtext, "x");
			buf1.mtype = 3L;
			msgsnd(msgid, &buf1, LEN, 0);
			buf1.mtype = 4L;
			msgsnd(msgid, &buf1, LEN, 0);
			break;
		}
		buf1.mtype = 4L;
		msgsnd(msgid, &buf1, LEN, 0);						 //将客户端1的消息转发给客户端2
		msgrcv(msgid, &buf2, LEN, 2L, 0);					 //接受客户端2的消息
		printf("Receive client2 message: %s\n", buf2.mtext); //打印收到的消息
		if (buf2.mtext[0] == 'x' || buf2.mtext[0] == 'X')
		//若是退出标志，则给2个客户端发退出信息
		{
			strcpy(buf2.mtext, "x");
			buf2.mtype = 3L;
			msgsnd(msgid, &buf2, LEN, 0);
			buf2.mtype = 4L;
			msgsnd(msgid, &buf2, LEN, 0);
			break;
		}
		buf2.mtype = 3L;
		msgsnd(msgid, &buf2, LEN, 0); //将客户端2的消息转发给客户端1
	}
	sleep(1);					   //若退出，则先等待，以确保客户端程序退出
	msgctl(msgid, IPC_RMID, NULL); //删除消息队列，释放空间
	exit(0);
}
