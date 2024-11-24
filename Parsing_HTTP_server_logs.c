#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

void *thread_body(void *arg);
void parsing_string(FILE *fp);

int main(int argc, char *argv[])
{

    DIR *dp = NULL;
    FILE *fp = NULL;
    struct dirent *dirp = NULL;
    long int location = 0;
    //dp = opendir(argv[1]);
    char name_directory[100] = {0};
    char name_file[400] = {0};
    int read_symbol = 0;
    int number_files = 0;
    int number_threads = 8;
    pthread_t thread[number_threads];
    int result[number_threads];

    strcpy(name_directory, "/home/ilia/OTUS_HW_12/logs");
    //dp = opendir("/home/ilia/OTUS_HW_12/logs");
    dp = opendir(name_directory);
    if(dp == NULL)
    {
       printf("Не удалось открыть каталог %s\n", "/home/ilia/OTUS_HW_12/logs");
       exit(1);
    }
    location = telldir(dp);
    while((dirp = readdir(dp)) != NULL)
    {
       if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0)
            number_files++;
       printf("%s\n", dirp->d_name);
    }
    printf("В каталоге %s %d файлов.\n", name_directory, number_files);
    printf("И снова вывод!\n");
    FILE *file_pointers[number_files];  // Количество файловых дескрипторов, совпадает с количеством имен файлов
    // Открываем файлы в каталоге.
    seekdir(dp, location);
    for(int i = 0; (dirp = readdir(dp)) != NULL && i < number_files;)
    {
       if(strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0)
       {
          sprintf(name_file, "%s/%s", name_directory, dirp->d_name);
          if((file_pointers[i] = fopen(name_file, "rb")) == NULL)
          {
             printf("Не удалось открыть файл %s\n", name_file);
             //exit(EXIT_FAILURE);
          }
          printf("%s\n", dirp->d_name);
          for(int j = 0; j < 400; j++)
          {
             read_symbol = getc(file_pointers[i]);
             putc(read_symbol, stdout);
          }
          i++;
       }

    }
    // Создаем потоки из разчета 1 поток на 1 файл
    for(int i = 0; i < number_files; i++)
    {
       result[i] = pthread_create(&thread[i], NULL, thread_body, file_pointers[i]);
       if(result[i])
       {
          printf("The threads could not be created\n");
          exit(1);
       }
       result[i] = pthread_join(thread[i], NULL);
       if(result[i])
       {
          printf("The threads could not be joined\n");
          exit(2);
       }
    }

    seekdir(dp, location);
    // Чтение файлов каталога.
    if((dirp = readdir(dp)) == NULL)
    {
       printf("Не удалось прочитать каталог!\n");
    }
    sprintf(name_file, "%s/%s", name_directory, dirp->d_name);
    if((fp = fopen(name_file, "rb")) == NULL)
    {
       printf("Не удалось открыть файл %s\n", name_file);
       //exit(EXIT_FAILURE);
    }
    if((fp = fopen(dirp->d_name, "rb")) == NULL)
    {
       printf("Не удалось открыть файл %s\n", dirp->d_name);
       //exit(EXIT_FAILURE);
    }

    if((fp = fopen(name_file, "rb")) == NULL)
    {
       printf("Не удалось открыть файл %s\n", name_file);
       //exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 500; i++)
    {
       read_symbol = getc(fp);
       putc(read_symbol, stdout);
    }
    for(int i = 0; i < number_files; i++)
        fclose(file_pointers[i]);
    printf("\nHello world!\n");
    return 0;
}
