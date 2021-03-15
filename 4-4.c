/*
 * popすることなくスタックの一番上を印刷し、複製、交換する
 * コマンドを追加せよ
 */

#include <stdio.h>
#include <stdlib.h>     // atof

#define MAXOP       100     // 非演算子、演算子の最大サイズ
#define NUMBER      0       // 数字があったという記号

int getop(char []);
void push(double);
double pop(void);
double pop_dup(void);

/* 逆ポーランド電卓プログラム */
int main()
{
    int type;       // 入力の値のタイプ
    int sign;       // マイナスかプラスか
    double op2;     // 数字のバッファ
    char s[MAXOP];  // 入力された値を格納

    /* 返された値の文字を評価 */
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: 
            push(atof(s));
            break;
        case '+': 
            push(pop() + pop());
            break;
        case '-': 
            op2 = pop();
            push(pop() - op2);
            break;
        case '*': 
            push(pop() * pop());
            break;
        case '/': 
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else 
                printf("error: zero divisor\n");
            break;
        case '%': 
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else 
                printf("error: zero divisor\n");
            break;
        case '=': 
            op2 = pop_dup();
            printf("=%.8g", op2);
            break;
        case '\n': 
            printf("\t%.8g\n", pop());
            break;
        default: 
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL      100     // valスタックの最大の長さ

int sp = 0;
double val[MAXVAL];

/* fを値スタックにプッシュする */
void push(double f)
{
    if (sp < MAXVAL) 
        val[sp++] = f;
    else 
        printf("error: stack full, can\'t push %g\n", f);
}

/* スタックから一番上の値をポップして返す */
double pop(void)
{
    if (sp > 0) 
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double pop_dup(void)
{
    float tmp;

    if (sp >= 2) {
        tmp = val[sp-2]; val[sp-2] = val[sp-1]; val[sp-1] = tmp;
        /* printf("%f, %f\n", val[sp-1], val[sp-2]); */
        return val[sp-2];
    }
    else if (sp > 0) {
        return val[sp-1];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* 
 * getchar()を2回目は、二文字目を取ってくる
 * int hoge = getchar() -> input: hogehoge
 * hoge = getchar() -> o
 */
#include <ctype.h>

int getch(void);
void ungetch(int);

/* 次の演算子あるいは数値の非演算子をとってくる */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ;

    s[1] = '\0';
    if (c == '-') {
        if (!isdigit(c = getch())) {
            ungetch(c);
            return '-';
        }
        ungetch(c);
    }
    else if (!isdigit(c) && c != '.') 
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE     100

char    buf[BUFSIZE];       // ungetch用バッファ
int     bufp = 0;           // buf中の次の空き位置

/* 一文字取ってくる */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* 文字を入力に戻す */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


