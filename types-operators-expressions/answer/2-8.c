/*
 * 整数xの値を右にnビット回転する関数rightrot(x, n)を書け。
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned int x = 0b100001; 

    printf("rightrot: %d\n", rightrot(x, 4));

    return 0;
}

/* xを右にnビット回転 */
unsigned rightrot(unsigned x, int n)
{
    int i;
    int nx;

    // 桁をiに格納
    for (i = 0, nx = x; nx > 0; i++)
        nx /= 2;

    // 下n桁を取得、n個分左シフト
    int shiftbit = ((x & ~(~0 << n)) << (i - n));
    // xをn個分右にシフト
    x = x >> n;

    return x + shiftbit;
}

