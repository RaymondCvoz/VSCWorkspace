#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main()
{
    if (fork() == 0)
    {
        printf("\n");
        execl("/bin/ls", "ls", (char *)0);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_SUCCESS);
}