#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *dp;

    dir = opendir("./testfolder");
    if (dir == NULL)
    {
        printf("folder not found");
        return 0;
    }
    while ((dp = readdir(dir)) != NULL)
    {
        
        if (dp->d_name[0] == '.')
            continue;
        for (int i = 0; i < strlen(dp->d_name) - 3; i++)
        {
            if (dp->d_name[i] == 'd' && dp->d_name[i + 1] == 'a' && dp->d_name[i + 2] == 't' && dp->d_name[i + 3] == 'a')
            {
                printf("%s\n", dp->d_name);
            }
        }
    }
    closedir(dir);
    return 0;
}