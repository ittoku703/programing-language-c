/*
 * 符号なし整数nをb進数文字表現に変換し、sに格納する関数itob(n,s,b)を書け。
 * 特にitob(n,s,16)はnをs中の16真数に変換する。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_LENGTH      5

void itob(unsigned n, char s[], int b);
void reverse(char s[]);

int main()
{
    char buf[BUFSIZ];

    for (int i = 0; buf[i] != '\0'; i++)
        buf[i] = '\0';
    itob(2, buf, 10);
    printf("itob: %s\n", buf);

    return 0;
}

/* 符号なし整数を2進数に変換 */
void itob(unsigned n, char s[], int b)
{
    int i, j;

    i = 0;
    // n(10進数)を2進数にしてsに格納
    if (b == 10) {
        do {
            s[i++] = n & 1 ? '1' : '0';
        } while ((n = n >> 1));
        reverse(s);
    }
    // n(10進数)を16進数にしてsに格納
    else if (b == 16) {
        char ox[] = "0123456789abcdef";

        while (n > 0) {
            j = n % 16;
            n /= 16;
            s[i++] = ox[j];
        }
        reverse(s);
    }
    else 
        printf("argument error: bに10か16を入れてください。");
    s[i] = '\0';
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c;
}

