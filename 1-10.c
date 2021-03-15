/*
 * タブを\t, バックスペースを\b, バックスラッシュを\\に置き換えながら、入力を出力に
 * 模写するプログラムを書け。
 */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\') 
            printf("\\");
        else
            putchar(c);
    }
    return 0;
}

