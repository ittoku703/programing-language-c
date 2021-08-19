/*
 * 入力のn文字目まである非ブランク文字の後で
 * 折りたたむプログラムを書け。
 */

#include <stdio.h>

#define IN      1
#define OUT     0
#define MAX_LINE    10

/* タブを適当なスペースに置き換え */
int main()
{
    int c, wc;

    for (wc = 0; (c = getchar()) != EOF; wc++) {
        if (wc >= MAX_LINE) {
            putchar('\n');
            wc = 0;
        }
        putchar(c);
    }
    
    return 0;
}

