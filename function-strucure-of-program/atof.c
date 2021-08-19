#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int max);
double atof(char s[]);

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

#include <ctype.h>

// 文字列sをdoubleに変換する
double atof(char s[])
{
  double val, power;
  int i, sign;

  // 空白は飛ばす
  for (i = 0; isspace(s[i]); i++)
    ;

  // +と-を判定する
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  // 整数を計算
  for (val = 0.0; isdigit(s[i]); i++) 
    val = 10.0 * val + (s[i] - '0');

  // 小数点を計算
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  // 最後に結果を返す
  return sign * val / power;
}


