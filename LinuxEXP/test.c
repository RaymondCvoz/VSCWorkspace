#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000];
int tmp1, tmp2, tmp3;

int main()
{
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
}