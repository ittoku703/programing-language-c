/*
 * 改行文字やタブなどのエスケープ文字を\n, \tに
 * 変換し、sをtにコピーするような関数escape(s,t)を書け。
 * switchを使う。逆にエスケープを実際の文字に変換する
 * 関数も書く。
 */

#include <stdio.h>

void escape(char s[]); 

int main()
{
    char s[BUFSIZ];

    escape(s);

    printf("%s\n", s);

    return 0;
}

void escape(char s[])
{   
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '\n': 
            s[i++] = '\\';
            s[i++] = 'n';
            break;
        case '\t': 
            s[i++] = '\\';
            s[i++] = 't';
            break;
        default: 
            s[i++] = c;
        }
    }
}

