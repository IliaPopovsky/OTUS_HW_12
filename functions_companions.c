#include <stdio.h>
#include <stdlib.h>
void parsing_string(FILE *fp);

void *thread_body(void *arg)
{
    long last = 0;                                  // размер файла
    fseek((FILE *)arg, 0L, SEEK_SET);               // перейти в начало файла
    fseek((FILE *)arg, 0L, SEEK_END);               // перейти в конец файла
    last = ftell((FILE *)arg);
    printf("Размер файла %ld байт\n", last);
    fseek((FILE *)arg, 0L, SEEK_SET);               // перейти в начало файла
    parsing_string((FILE *)arg);
}
