#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

    DIR *dp = NULL;
    struct dirent *dirp;
    //dp = opendir(argv[1]);
    dp = opendir("/home/ilia/OTUS_HW_12/logs");
    if(dp == NULL)
    {
       printf("Не удалось открыть каталог %s\n", "/home/ilia/OTUS_HW_12/logs");
       exit(1);
    }
    while((dirp = readdir(dp)) != NULL)
    {
       printf("%s\n", dirp->d_name);
    }
    printf("\nHello world!\n");
    return 0;
}
