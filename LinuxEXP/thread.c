#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

//char buf[] = "welcome";

void *handler(void *p) //void *p = buf;
{
    //getchar();
    printf("%s\n", (char *)p);

    //return p;
    pthread_exit(p);
}

void f(char **p) //char **p = &s;
{
    char *q = "dadf";
    *p = q;
}

int main(int argc, char *argv[])
{
    char *s = NULL;
    //f(&s);
    //printf("%s\n", s);

#if 1
    pthread_t thread;
    char buf[] = "welcome";
    void *result;

    if (pthread_create(&thread, NULL, handler, (void *)buf))
        exit(-1);

    pthread_join(thread, &result); //exit(0); waitpid(pid, &status, 0);

    printf("***\n");
    printf("result:%s\n", (char *)result);

    // while (1)
    //     ;
#endif

    exit(0);
}
