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

    The purpose of this library: Convert arbitary long numbers from base n to base m.
                                 Numbers are represented by char strings in the ascii format,
                                 the library doesn't handle number prefixes like '0xnnnn' or '0nnnn'
                                 this library supports numbers in base36 (0-9, a-z)
                                 outputted alphabetical characters are lowercase
    
    Requirements: libc (c standard lib)
                  gmp (GNU Multiple Precision Arithmetic Library)
*/

#ifndef __NUTIL_H__
#define __NUTIL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * @brief returns the amount of memory required for the number in <src> (which is in base <src_base>) at base of <dst_base>. excludes the nul char
 * 
 * @param src nul terminated string
 * @param src_base integer between 2 - 36
 * @param dst_base integer between 2 - 36
 * @return size_t
 */
extern size_t nutil_reqmem(const char* src, int src_base, int dst_base);

/**
 * @brief converts the number in <src> which is in base <src_base> into base <dst_base>. doesn't add nul at the end
 * 
 * @param src nul terminated string
 * @param dst buffer that the funcion writes into
 * @param src_base integer between 2 - 36
 * @param dst_base integer between 2 - 36
 * @return size_t how many characters were written. return value 0 is considerd an error
 */
extern size_t nutil_convert(const char* src, char* dst, int src_base, int dst_base);

#ifdef __cplusplus
}
#endif

#endif /* __NUTIL_H__ */
