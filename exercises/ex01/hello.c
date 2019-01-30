#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%d", y);
    return 0;
}

/*

1. Adding int x = 5 adds the following in the Assembly code.

subq	$16, %rsp
movl	$5, -4(%rbp)

It looks like it is allocating 16 bits then allocating the value 5 to it.

2. After adding optimization, the above lines appear to disappear from the
assembly code.

3. Making it print x adds a lot of movl calls.
Optimize appears to reduce the space allocated for x from 16 to 8 bits.

4. The optimized version has significantly fewer movl calls, and from reading the
output I suspect that in the process of optimation the compiler got rid of the x
variable and just made y equal to 1 + 5.
*/
