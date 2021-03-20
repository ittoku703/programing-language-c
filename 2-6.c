/*
 * 位置pから始まるnビットをyの右端のnビットにセットし、
 * 他のビットはそのままにしたxを返す関数setbits(x, p, n, y)
 * を書け。
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned int x = 0b100001; 
    unsigned int y = 0b000001; 
    int p = 6;
    int n = 6;

    printf("getbits: %d\n", getbits(x, p, n)); 
    printf("setbits: %d\n", setbits(x, p, n, y));

    return 0;
}

/* xのpから（右へ）nビット取得する */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p-n)) & ~(~0 << n);
}

/* xのpからnビットをyの右にセット */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (y << n) + getbits(x, p, n);
}

