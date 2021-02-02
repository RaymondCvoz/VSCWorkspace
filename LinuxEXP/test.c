#include <stdio.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include <time.h>
#include <dirent.h>
=======
char s[1000];
int tmp1, tmp2, tmp3;
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87

int a[10];
int main()
{
<<<<<<< HEAD
    time_t t;
    time(&t);
    struct tm *a = gmtime(&t);
    printf("%d\n", a->tm_sec);
    printf("%s\n", ctime(&t));
=======
    freopen("test.txt", "r", stdin);
    freopen("tmp.txt", "w", stdout);
    int line = 0;
    scanf("%[^\n]", s);
    getchar();
    printf("%s\n", s);
    int block = 0;
    while (scanf("%s", s) != EOF)
    {
        block++;
        if (block == 5)
        {
            tmp1 = atoi(s);
            printf("%d    ", tmp1);
        }
        else if (block == 6)
        {
            tmp2 = atoi(s);
            block = 0;
            tmp3 = tmp1 * 0.3 + tmp2 * 0.7;
            printf("%d    %d    \n", tmp2, tmp3);
            tmp1 = tmp2 = tmp3 = 0;
        }
        else
        {
            printf("%s", s);
            printf("    ");
        }
    }
    fclose(stdin);
    fclose(stdout);

    freopen("tmp.txt", "r", stdin);
    freopen("test.txt", "w", stdout);

    while (scanf("%[^\n]", s) != EOF)
    {
        getchar();
        printf("%s\n", s);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
>>>>>>> 4091f1733ed66edc82e105c7a09a81d279d9bd87
}