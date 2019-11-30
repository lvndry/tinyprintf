/*
 * =====================================================================================
 *
 *       Filename:  tinyprintf.test.c
 *
 *    Description:  Tinyprintf test file
 *
 *        Version:  1.0
 *        Created:  09/16/2019 08:37:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Landry Monga (), lvndry@protonmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>

#include "tinyprintf.h"

int main(void)
{
    int tiny_res = tinyprintf("Hello World");
    assert(tiny_res == 11);
    tiny_res = tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    assert(tiny_res == 17);
    tiny_res = tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    assert(tiny_res == 17);
    tiny_res = tinyprintf("%%s", "in your head");
    assert(tiny_res == 2);
    tiny_res = tinyprintf("Good morning human! %t Tinyprintf is cool!", 12);
    assert(tiny_res == 40);
    tiny_res = tinyprintf("%c %c is %s...%d too.", '4', '2', "the answer",'*');
    assert(tiny_res == 27);

    return 0;
}
