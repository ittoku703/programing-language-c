/*
 * atofを拡張して、科学記法を扱えるようにせよ。
 */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE     100

double atof(char s[]);
int get_line(char line[], int max);
int atoi(char s[]);

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* sをdoubleに変換する */
double atof(char s[])
{
    double val, power, epower;
    int i, sign, e;

    // 空白を除く
    for (i = 0; isspace(s[i]); i++)
        ;

    // -と+を取得
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++;

    // 整数を取得
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0');

    // 小数点を取得
    if (s[i] == '.') 
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + s[i] - '0';
        power *= 0.1;
    }

    // 科学記法を取得
    if (s[i] == 'e' || s[i] == 'E') 
        i++;
    epower = (s[i] == '-') ? 0.1 : 10.0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (e = 0; isdigit(s[i]); i++)
        e = 10 * e + s[i] - '0';
    while (e--)
        power *= epower;

    return sign * val * power;
}

/* sに行を入れ、長さを返す */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n') 
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int atoi(char s[])
{
    double atof(char []);

    return (int) atof(s);
}

