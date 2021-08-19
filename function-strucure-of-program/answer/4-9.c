/*
 * getchとungetchをEOFを扱えるプログラムに書きなおせ。
 */
#include <stdio.h>

int   getch(void);
void  ungetch(int);

int   buf[BUFSIZ];
int   bufp;

int main()
{
  int c;

  ungetch(EOF);
  ungetch('A');
  ungetch('B');
  ungetch('C');
  ungetch('D');
  while ((c = getch()) != EOF)
    putchar(c);
  printf("\n");

  return 0;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZ)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}


