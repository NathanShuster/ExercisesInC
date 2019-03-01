/* Example code for Software Systems at Olin College.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/
/*
To run
gcc test_util.c util.c && ./a.out
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
//#include "trout.h"
#include "minunit.h"

int tests_run = 0;


/*
case  1: return("host unreachable");
    case  2: return("protocol unreachable");
    case  3: return("port unreachable");
*/

static char *test1() {
  icmpcode_v4
    char* res = icmpcode_v4(1);
    char* message = "test1 failed: should be 'host unreachable'";
    mu_assert(message, res == "host unreachable");
    return NULL;
}

static char *test2() {
    char* res = icmpcode_v4(2);
    char *message = "test2 failed: should be 'protocol unreachable'";
    mu_assert(message, res == "protocol unreachable");
    return NULL;
}

static char *test3() {
    char* res = icmpcode_v4(3);
    char *message = "test3 failed: should be 'port unreachable'";
    mu_assert(message, res == "port unreachable");
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
