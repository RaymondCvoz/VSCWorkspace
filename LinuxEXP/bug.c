#include <stdio.h>
#include <stdlib.h>

static char buff[256];
static char *string;
int main()
{
    gets(string);
    printf("%s\n", string);
}