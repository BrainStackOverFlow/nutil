#include "nutil.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc < 3) 
    { 
        printf("ERROR: not enough arguments\n\tArgument 1: the number to convert into decimal. for example \'ffff\'\n\tArgument 2: the base of the number. for example: \'16\'\n\texample use: \'example ffff 16\'\n");
        return 0;
    }

    /* i am assuming correct input order */

    int src_base = strtol(argv[2], NULL, 10);

    size_t size = nutil_reqmem(argv[1], src_base, 10);

    char* dst_buffer = (char*)malloc(size + 1);
    memset(dst_buffer, 0, size + 1);

    nutil_convert(argv[1], dst_buffer, src_base, 10);

    printf("%s\n", dst_buffer);

    free(dst_buffer);

    return 0;
}