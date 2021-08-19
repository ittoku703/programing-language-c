#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
int bitcount(unsigned x);

int main()
{
    unsigned int x = 0b100001; 
    unsigned int y = 0b000001; 
    int p = 6;
    int n = 6;

    printf("Test: %d\n", x);
    printf("getbits: %d\n", getbits(x, p, n)); 
    printf("setbits: %d\n", setbits(x, p, n, y));
    printf("invert : %d\n", invert(x, p, n));
    printf("rightrot: %d\n", rightrot(x, 4));
    printf("bitcount: %d\n", bitcount(0b110101));

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

/* xのpからnビットを反転 */
unsigned invert(unsigned x, int p, int n)
{
    return (x >> (p-n)) ^ ~(~0 << n);
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

/* xのビットを数える（1の数）*/
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        b += getbits(x, 1, 1);
    return b;
}

