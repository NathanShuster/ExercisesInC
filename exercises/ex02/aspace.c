/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    int var3 = 8;
    void *p = malloc(128);
    void *q = malloc(128);
    char *s = "Hello, World";

    void *t1 = malloc(16);
    void *t2 = malloc(16);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of var3 is %p\n", &var3);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("q points to %p\n", q);
    printf ("t1 points to %p\n", t1);
    printf ("t2 points to %p\n", t2);

    return 0;
}

//The heap does grow up (toward larger addresses)
//The stack grows down (toward smaller addresses)
//The space between two memory allocations of 16 is 32
