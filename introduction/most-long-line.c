#include <stdio.h>

#define MAXLINE     1000

int max;                // 最大長
char line[MAXLINE];      // 現在の入力ぎょう
char longest[MAXLINE];   // 格納されている最大行

int get_line(void);
void copy(void);

int main()
{
    int len;        // 現在の行の長さ
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)    // 行があった
        printf("%s", longest);
    return 0;
}

/* sに行をいれ、長さを返す */
int get_line(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1
            && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* fromをtoにコピー */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}

