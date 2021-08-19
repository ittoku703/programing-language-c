#include <stdio.h>

#define COLLAPSE_LINE       10  // 行の最大文字数

/* 入力がCOLLAPSE＿LINE以上であれば、改行する */
int main()
{
    int i, c;

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (i > COLLAPSE_LINE) {
            i = 0;
            putchar('\n');
        }
        if (c == '\n')
            i = 0;
        putchar(c);
    }
    return 0;
}
