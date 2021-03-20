#include <stdio.h>

#define MAXLINE     1000    // 行の上限
#define DETAB       4       // 置き換えるホワイトスペースの数

/* タブを適当なスペースに置き換え */
int main()
{
    int i, c;

    while ( (c = getchar()) != EOF) 
        if (c == '\t') 
           for (i = 0; i < DETAB; ++i) 
               putchar(' ');
        else
            putchar(c);

    return 0;
}

