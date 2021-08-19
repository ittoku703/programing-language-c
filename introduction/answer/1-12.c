/*
 * 入力した単語を一行に一つづつ印字するプログラムを書け。
 */

#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            putchar('\n');
            state = IN;
        }

        if (state == IN)
            putchar(c);
    }
    return 0;
}

