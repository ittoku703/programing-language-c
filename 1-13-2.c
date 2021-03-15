/*
 * 入力した単語の長さをヒストグラムにしてプリントするプログラムをかけ。
 */

#include <stdio.h>

#define IN  1
#define OUT 0
#define LENGTH  30

int main()
{
    int c, wc, state;
    int hg[LENGTH];

    // initialize
    wc, state = 0;
    for (int i = 0; i < LENGTH; i++) 
        hg[i] = 0;

    // count word in hg[LENGTH]
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (wc > LENGTH) wc = LENGTH;
            if (wc == 0) continue;
            ++hg[wc-1];
            wc = 0;
        }
        else if (state == OUT) {
            state = IN;
            ++wc;
        }
        else
            ++wc;
    }

    // histgraph output!!!
    int word_count = 0;
    for (int i = 0; i < LENGTH; i++) 
        word_count += hg[i];
    printf("Word Count: %d\n", word_count);

    // create histgraph!!!
    printf("==> Histgram <==\n");
    for (int i = LENGTH; i > 0; --i) {
        printf("%2d | ", i);
        
        for (int count = 0; count < LENGTH; ++count)
            if (hg[count] >= i)
                printf(" * ");
            else
                printf("   ");
        printf("\n");
    }

    // bottom output!!!
    printf("   ");
    for (int i = 0; i < LENGTH; ++i)
        printf("---");
    printf("---\n     ");
    for (int i = 0; i < LENGTH; ++i) 
        printf("%2d ", i+1);
    printf("\n");
}

