#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

//char buf[] = "welcome";

void *handler(void *p) //void *p = buf;
{
<<<<<<< HEAD
    getchar();
=======
    //getchar();
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87
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
<<<<<<< HEAD
    f(&s);
    printf("%s\n", s);
=======
    //f(&s);
    //printf("%s\n", s);
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87

#if 1
    pthread_t thread;
    char buf[] = "welcome";
    void *result;

<<<<<<< HEAD
    int x;
    x = pthread_create(&thread, NULL, handler, (void *)buf);
    printf("%d\n", x);
=======
    if (pthread_create(&thread, NULL, handler, (void *)buf))
        exit(-1);
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87

    pthread_join(thread, &result); //exit(0); waitpid(pid, &status, 0);

    printf("***\n");
    printf("result:%s\n", (char *)result);

<<<<<<< HEAD
    while (1)
        ;
=======
    // while (1)
    //     ;
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87
#endif

    exit(0);
}
