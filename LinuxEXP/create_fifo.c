#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	//int mkfifo(const char *path, mode_t mode);
	if (mkfifo(argv[1], 0644) < 0)
	{
		fprintf(stderr, "mkfifo() failed: %s\n", strerror(errno));
		exit(1);
	}

	return 0;
}
