#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    //dp = opendir(argv[1]);
    dp = opendir("/home/ilia/OTUS_HW_12/logs");
    printf("Hello world!\n");
    return 0;
}
