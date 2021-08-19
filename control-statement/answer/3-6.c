/*
 * 三つの引数を受け付けるitoaプログラムをかけ。第三引数は
 * 最小フィールド幅を指定するものである。
 */

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int wid);
void reverse(char s[]);

int main()
{
    char buf[BUFSIZ];

    itoa(-12345, buf, 10);

    printf("itoa: %s\n", buf);

    return 0;
}

/* nをs中の文字に変換 */
void itoa(int n, char s[], int wid)
{
    int i, sign;

    if ((sign = n) < 0)     // 符号を記録
        n = -n;             // nを生にする
    i = 0;
    do {                    // 数字を逆順に生成する
        s[i++] = n % 10 + '0';      // 次の桁をとってきて
    } while ((n /= 10) > 0);        // 削除する
    if (sign < 0)
        s[i++] = '-';
    while (i <= wid) 
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

/* 文字列sを逆順にする */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c; 
}
