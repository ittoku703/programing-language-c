#include <stdio.h>

int icheck(int c);
int lower(int c);
int htoi(char s[]);

int main()
{
    char x[] = "0x293";

    printf("%d %d\n", 0xfff, htoi(x));
    return 0;
}

/* 十六進数を十進数に */
int htoi(char s[])
{
    int i, n;

    if (s[0] == '0' && s[1] == 'x')
        i = 2;
    else 
        i = 0;

    n = 0; 
    while (s[i] != '\0') {
        if (icheck(s[i]) == 0) return 0;
        s[i] = lower(s[i]);
        n = 16 * n + (s[i] - '0');
        ++i;
    }

    return n;
}

/* 文字列のチェック*/
int icheck(int c)
{
    return  (c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'F') || 
            (c >= 'a' && c <= 'f');
}
/* 大文字を小文字に */
int lower(int c)
{
    if (c >= 'A' && c <= 'F')
        c += 'a' - 'A';

    if (c >= 'a' && c <= 'f')
        return c - 39;
    else 
        return c;
}

