#include <stdio.h>

int main()
{
    int c, tmp;

    while ((c = getchar()) != EOF) {
        switch (c) {
        case '\t': 
            printf("\\t"); break;
        case '\b': 
            printf("\\b"); break;
        default: 
            putchar(c);
        }
    }
}

