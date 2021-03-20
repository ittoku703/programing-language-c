/*
 * 入力中の異なる文字の頻度をヒストグラムにプリントする
 * プログラムを書け。
 */

#include <stdio.h>

#define ASCII   127

int main()
{
    int c, ascii[ASCII];

    for (int i = 0; i < ASCII; ++i) 
        ascii[i] = 0;

    while ((c = getchar()) != EOF) {
        for (int i = 0; i < ASCII; ++i)
            if (c == i)
                ++ascii[i];
    }

    printf("==> character <==\n");
    for (int i = 0; i < ASCII; ++i) {
        if (ascii[i] == 0) continue;
        printf("%c -> ", i);
        for (int count = 0; count < ascii[i]; ++count)
            putchar('*');
        printf("\n");
    }
}

