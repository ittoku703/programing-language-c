/*
 * 空白、タブ、改行を数えるプログラムを書け。
 */

#include <stdio.h>

int main()
{
    int c, nw, nt, nl;

    nw = nt = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nw;
        if (c == '\t')
            ++nt;
        if (c == '\n') 
            ++nl;
    }
    printf("%d %d %d\n", nw, nt, nl);

    return 0;
}

