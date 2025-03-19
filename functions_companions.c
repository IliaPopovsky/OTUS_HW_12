#include <stdio.h>
#include <stdlib.h>

#define SIZE 8192
#define SIZE_BYTES_BUF 30

long parsing_string(char *str, char *url, char *referer);

void *thread_body(void *arg)
{

    int number_thread = *((int *) arg);
	int fd = 0;
	int length = 0;

    char url[SIZE] = { 0 };
	char referer[SIZE] = { 0 };
	char str[SIZE] = {0};
    long last = 0;                                  // размер файла
    fseek((FILE *)arg, 0L, SEEK_SET);               // перейти в начало файла
    fseek((FILE *)arg, 0L, SEEK_END);               // перейти в конец файла
    last = ftell((FILE *)arg);
    printf("Размер файла %ld байт\n", last);
    fseek((FILE *)arg, 0L, SEEK_SET);               // перейти в начало файла




    parsing_string(str, url, referer);
}
