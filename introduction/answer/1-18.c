/*
 * 入力行から、行の後のブランクやタブを取り除き、
 * かつ空白行は全て削除するプログラムを書け。
 */

#include <stdio.h>

int get_line(char s[]);

int main()
{
    int len;
    char line[BUFSIZ];

    while ((len = get_line(line)) > 0)
        printf("%s", line);
}

int get_line(char s[])
{
    int c, i;

    for (i = 0; i < BUFSIZ-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        switch (c) {
        case '\t': 
        case '\n': 
        case ' ': 
            --i;
            break;
        default: 
            s[i] = c;
        }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

