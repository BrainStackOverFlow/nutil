#include "nutil.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define test_int(str, str_base, dst_base, expected_str, expected_size) { tmp_err = test_integer(str, str_base, dst_base, expected_str, expected_size); err.size_failcount += tmp_err.size_failcount; err.str_failcount += tmp_err.str_failcount;}

struct test_result
{
    int size_failcount; 
    int str_failcount;
};

struct test_result test_integer(char* str, int str_base, int dst_base, char* expected_str, size_t expected_size)
{
    static unsigned int test_counter = 0;

    struct test_result ret = {0, 0};

    size_t size = nutil_reqmem(str, str_base, dst_base);
    ret.size_failcount = expected_size == size ? 0 : 1;

    char* tmp_dst_ptr = (char*)malloc(expected_size + 1);
    memset(tmp_dst_ptr, 0, expected_size + 1);
    nutil_convert(str, tmp_dst_ptr, str_base, dst_base);
    ret.str_failcount = strcmp(expected_str, tmp_dst_ptr) ? 1 : 0;
    
    printf("test number: %u\n", test_counter);
    printf("[%c] expected size: %li\tresult size: %li\n", !ret.size_failcount ? 'V' : 'X', expected_size, size);
    printf("[%c] expected string: %s\tresult string: %s\n\n", !ret.size_failcount ? 'V' : 'X', expected_str, tmp_dst_ptr);

    free(tmp_dst_ptr);

    test_counter++;

    return ret;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    struct test_result err = {0, 0};
    struct test_result tmp_err;

    test_int("ff", 16, 10, "255", 3);
    test_int("y1z5t2", 36, 8, "17257070446", 11);
    test_int("210220001", 3, 20, "1jhi", 4);

    printf("Failed size tests: %i\nFailed string tests %i\n", err.size_failcount, err.str_failcount);
}
