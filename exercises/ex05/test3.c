#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rand.h"

main (int argc, char *argv[])
{
    int i;
    double x;

    srandom (time (NULL)); // Randomize the seed

    for (i=0; i<10000; i++) {
        x = my_random_double();
        printf ("%lf\n", x);
    }
}
