
#include <stdio.h>
#include "include/method.h"
 
int main()
{
    int a = 40;
    int b = 4;
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));
    printf("a * b = %d\n", multi(a, b));
    printf("a / b = %f\n", div(a, b));
    return 0;
}