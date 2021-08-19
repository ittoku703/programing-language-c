#include <stdio.h>

#define IN  1
#define OUT 0

/* 単語をカウントするプログラム */
int main()
{
    int c, wc, state;

    wc = state = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++wc;
        }
    }
    printf("word: %d\n", wc);
}

