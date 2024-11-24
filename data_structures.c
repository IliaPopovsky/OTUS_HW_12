#include <stdio.h>
#include <stdlib.h>
#include "hash_functions.h"

void create_hashtable(long last)
{
   HTnode *pointer_htnode = NULL;
   if((pointer_htnode = (HTnode *)calloc(size, sizeof(HTnode))) == NULL)
   {
        fprintf(stdout, "There is not enough memory space to construct this hash table array, provided that the entire source text file is analyzed.\n"
                        "Consider analyzing the original text file in parts.\n");
        exit(1);
   }
   else
   {
        fprintf(stdout, "There is enough memory space to construct this hash table array, provided that the entire source text file is analyzed.\n");

   }
}
