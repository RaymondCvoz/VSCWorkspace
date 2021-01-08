#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

int a[10];
int main()
{
    time_t t;
    time(&t);
    struct tm *a = gmtime(&t);
    printf("%d\n", a->tm_sec);
    printf("%s\n", ctime(&t));
}