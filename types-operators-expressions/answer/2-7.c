/*
 * xのビット位置pからnビットを反転(1を0, 0を1)し、他のビットは
 * そのままにしたxを返す関数invert(x, p, n)を書け。
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned int x = 0b111110; 
    int p = 6;
    int n = 6;

    printf("invert : %d\n", invert(x, p, n));

    return 0;
}

/* xのpからnビットを反転 */
unsigned invert(unsigned x, int p, int n)
{
    return (x >> (p-n)) ^ ~(~0 << n);
}

