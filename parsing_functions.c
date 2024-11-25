#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STLEN 1000
void parsing_string(FILE *fp)
{
  char buffer[1000] = {0};
  fgets(buffer, STLEN, fp);
  printf("\nСтрока из файла:\n");
  printf("%s\n", buffer);
}
