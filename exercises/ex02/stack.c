/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

//If the function was correct, it would output the adresses of two local variables
//and then print out 42 size number of times.
//However, we get a segmentation fault. This is due to the fact that:
//A pointer must point to a variable allocated on the heap.
//Making a pointer point to a variable on the stack (a local variable) will cause a segmentation fault
//Commenting out the print statements in foo() and bar() stop the function from outputting addresses.
//When compiling the function, we get a warning that the function returns the address of a local variable,
//which as explained above, is a non-starter in pointer world.
