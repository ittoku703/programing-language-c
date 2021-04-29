/*
 * 押し戻す文字を一文字だけにするように、getchとungetchを描き直せ。
 */
#include <stdio.h>

int   getch(void);
void  ungetch(int);

int   buf;

int main()
{
  ungetch('A');
  ungetch('B');
  printf("%c\n", getch());
  ungetch('C');
  printf("%c\n", getch());

  return 0;
}

int getch(void)
{
  int c;

  c = (buf) ? buf : getchar();
  buf = 0;
  return c;
}

void ungetch(int c)
{
  if (buf)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}


