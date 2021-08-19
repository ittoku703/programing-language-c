#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_LENGTH      5

int atoi(char s[]);
void shellsort(int v[], int n);
void reverse(char s[]);
void expand(char s1[], char s2[]);
void itoa(int n, char s[]);
void itob(unsigned n, char s[], int b, int width);
int trim(char s[]);

int main()
{
    char s[] = "3209- 78329+ 748";
    int num[] = { 10, 31, 90, 8, 75 };
    char chara[] = "-0-9A-Z a-b-z";
    char buf[BUFSIZ];

//  ----------------------
//  atoi
//  ----------------------
    printf("atoi: %d\n", atoi(s));

//  ----------------------
//  shellsort
//  ----------------------
    shellsort(num, NUM_LENGTH);
    printf("shellsort: ");
    for (int i = 0; i < NUM_LENGTH; i++)
        printf("%d, ", num[i]);
    printf("\n");
    
//------------------------
//  reverse 
//------------------------
    reverse(s);
    printf("reverse: %s\n", s);

//------------------------
//  expand
//------------------------
    expand(chara, buf);
    printf("expand: %s\n", buf);

//------------------------
//  itoa
//------------------------
    for (int i = 0; buf[i] != '\0'; i++)
        buf[i] = '\0';
    itoa(-12345, buf);
    printf("itoa: %s\n", buf);


//------------------------
//  itob
//------------------------
    for (int i = 0; buf[i] != '\0'; i++)
        buf[i] = '\0';
    itob(2, buf, 10, 5);
    printf("itob: %s\n", buf);
   
//------------------------
// trim
//------------------------

    char trim_s[] = "A B C D E";
    int trim_n = trim(trim_s);
    printf("trim: %d %s\n", trim_n, trim_s);
    return 0;
}

/* sを整数に変換する */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)     // 空白を飛ばす
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')     // 符号を飛ばす
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* v[]を上昇順にソート */
void shellsort(int v[], int n)
{
    int gap, i, j, tmp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                tmp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = tmp;
            }
}

/* 文字列sを逆順にする */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) 
        c = s[i], s[i] = s[j], s[j] = c; 
}

/* 文字列s1内のa-zのような省略記法を、abc...xyzにしてs2に格納する。 */
void expand(char s1[], char s2[])
{
    int i, j, c;

    // example: a-z 0-9 B-D a-b-c -a-z a-z0-9 
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            if (s1[i-1] >= '0' && s1[i-1] <= '9' && 
                s1[i+1] >= '0' && s1[i+1] <= '9') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else if (s1[i-1] >= 'A' && s1[i-1] <= 'Z' && 
                 s1[i+1] >= 'A' && s1[i+1] <= 'Z') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else if (s1[i-1] >= 'a' && s1[i-1] <= 'z' &&
                 s1[i+1] >= 'a' && s1[i+1] <= 'z') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else {
                s2[j++] = s1[i];
            }
        }
        else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

/* nをs中の文字に変換 */
void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s);
}

/* 符号なし整数を2進数に変換 */
void itob(unsigned n, char s[], int b, int width)
{
    int i, j;

    i = 0;
    // n(10進数)を2進数にしてsに格納
    if (b == 10) {
        do {
            s[i++] = n & 1 ? '1' : '0';
        } while ((n = n >> 1));
        if (i <= width)
            for (width -= i; width > 0; width--) 
                s[i++] = '0';
        reverse(s);
    }
    // n(10進数)を16進数にしてsに格納
    else if (b == 16) {
        char ox[] = "0123456789abcdef";

        while (n > 0) {
            j = n % 16;
            n /= 16;
            s[i++] = ox[j];
        }
        if (i <= width)
            for (width -= i; width > 0; width--) 
                s[i++] = '0';
       reverse(s);
    }
    else 
        printf("argument error: bに10か16を入れてください。");
    s[i] = '\0';
}

/* 空白、タブ、改行文字を取り除く */
int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; n--) 
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') 
            break;
        
    s[n+1] = '\0';
    return n;
}

