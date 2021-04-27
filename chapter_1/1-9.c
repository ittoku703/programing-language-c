/*
 * 二つ以上の空白を一つの空白に置き換えながら、入力を出力に模写する
 * プログラムを書け。
 */

#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            state = OUT;
        else if (state == OUT) {
            putchar(' ');
            state = IN;
        }

        if (state == IN)
            putchar(c);
    }
    return 0;
}

