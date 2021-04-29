/*
 * 文字列全体を入力に戻すルーチンungets(s)を書け。
 */

#include <stdio.h>
#include <stdlib.h>   // atof()
#include <string.h>   // strlen(s)

#define BUFSIZE 100
#define MAXLEN  10000

int getch(void);
void ungetch(int);
void ungets(char []);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
  int c, i;
  char s[MAXLEN];

  printf("Enter string to test ungets function:\n");
  for (i = 0; (s[i] = getch()) != '\n'; i++)
    ;
  s[i++] = '\n', s[i] = '\0';
  ungets(s);

  while ((c = getch())!= EOF)
    putchar(c);
  return 0;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else 
    buf[bufp++] = c;
}

void ungets(char s[])
{
  for (int i = strlen(s) - 1; i >= 0; --i)
    ungetch(s[i]);
}

