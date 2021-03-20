/*
 * ブランクの列を同じスペーシングで揃えるタブを
 * スペースで置き換えるプログラムをかけ。
 */

#include <stdio.h>

#define IN      1
#define OUT     0

/* タブを適当なスペースに置き換え */
int main()
{
    int c, state;

    state = IN;
    while ((c = getchar()) != EOF) 
        if (c == ' ') 
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\t');
            putchar(c);
        }
        else 
            putchar(c);
    return 0;
}

