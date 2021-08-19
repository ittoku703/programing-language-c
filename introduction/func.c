#include <stdio.h>

int factorial(int m, int n);

int main()
{
    for (int i = 0; i < 10; ++i) 
        printf("%d %d %d \n", i, factorial(2,i), factorial(-3,i));
    return 0;
}

/* factorial: baseをn乗する： n >= 0 */
int factorial(int base, int n)
{
    int p ;

    for (p = 1; n > 0; --n)
        p *= base;
    return p;
}

