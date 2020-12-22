#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE	1024

void signal_handler(int s);

int main(int argc, char **argv)
{
	int fd;

	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	signal(SIGPIPE, signal_handler);

	//int open(const char *path, int oflag, ...);
	if ((fd = open(argv[1], O_WRONLY)) < 0)
	{
		fprintf(stderr, "open fifo %s for writting failed: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	fprintf(stdout, "open fifo %s for writting successed.\n", argv[0]);

	char buffer[BUFFER_SIZE];
	ssize_t n;

	//char *fgets(char *s, int size, FILE * stream);
	while (fgets(buffer, BUFFER_SIZE, stdin))
	{
again:
		//ssize_t write(int fd, const void *buf, size_t count);
		if ((n = write(fd, buffer, strlen(buffer))) < 0)
		{
			if (errno == EINTR)
			{
				goto again;
			}
			else
			{
				fprintf(stderr, "write() failed on fifo: %s\n", strerror(errno));
				break;
			}
		}  // end if
	}  // end while

	return 0;
}

void signal_handler(int signo)
{
	fprintf(stdout, "Caught signal %d\n", signo);
}

