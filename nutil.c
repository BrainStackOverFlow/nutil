/*
    Copyright (c) 2020 BrainStackOverFlow

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "nutil.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <gmp.h>

static int is_base(char c, int base)
{
    if ((2 <= base) && (base <= 10))
    {
        return (c >= '0') && (c < ('0' + base));
    }
    else if (base <= 36)
    {
        return ((c >= '0') && (c < ('0' + base))) || ((tolower(c) >= 'a') && (tolower(c) < ('a' + (base - 10))));
    }
    return 0;
}

static int digit_to_int(char c, int base)
{
    if(!is_base(c, base)) /* error */
    {
        return -1;
    }
    else if ((c >= '0') && (c < ('0' + base)))
    {
        return c - '0';
    }
    else if ((tolower(c) >= 'a') && (tolower(c) < ('a' + (base - 10))))
    {
        return tolower(c) - 'a' + 10;
    }

    return -1; /* should never reach here */
}

static char int_to_digit(int num, int base)
{
    if (num >= base)
    {
        return EOF;
    }

    if (num < 10)
    {
        return num + '0';
    }
    else if ((10 <= num) && (num <=36))
    {
        return num + 'a' - 10;
    }
    
    return EOF; /* should never reach here */
}

static int reverse_str(char* str, int length)
{ 
    for (int i = 0; i < length / 2; i++) 
    {
        char tmp = str[length - i - 1];
        str[length - i - 1] = str[i];
        str[i] = tmp;
    }
    return 0;
} 

size_t nutil_reqmem(const char* src, int src_base, int dst_base)
{
    return (size_t)ceill((long double)strlen(src) * logl((long double)src_base) / logl((long double)dst_base));
}

size_t nutil_convert(const char* src, char* dst, int src_base, int dst_base)
{
    mpz_t src_number;
    mpz_init(src_number);

    mpz_t digit;
    mpz_init(digit);

    size_t src_length = strlen(src) - 1;
    size_t index = 0;
    
    while(src[index] != '\0')
    {
        mpz_ui_pow_ui(digit, src_base, src_length - index);
        int tmp = digit_to_int(src[index], src_base);

        if (tmp == -1) /* error */
        {
            return 0;
        }
        
        mpz_mul_ui(digit, digit, tmp);
        mpz_add(src_number, src_number, digit);  

        index++;
    }

    index = 0;

    while(mpz_sgn(src_number))
    {
        mpz_mod_ui(digit, src_number, dst_base);
        mpz_div_ui(src_number, src_number, dst_base);

        dst[index] = int_to_digit(mpz_get_ui(digit), dst_base);

        if (dst[index] == EOF) /* error */
        {
            return 0;
        }
        
        index++; 
    }

    reverse_str(dst, index);

    mpz_clear(digit);
    mpz_clear(src_number);

    return index;
}
