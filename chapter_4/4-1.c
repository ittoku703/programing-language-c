/*
 * sにおけるtの最も右側の出現位置を返す関数strrindex(s,t)を書け。
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE     1000

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* パターンにマッチする全ての行を探す。 */
int main()
{
  char line[MAXLINE];
  int idx, found = 0;

  while ((get_line(line, MAXLINE)) > 0)
    if ((idx = strrindex(line, pattern)) >= 0) {
      printf("%d: %s", idx, line);
      found++;
    }
  printf("found: %d\n", found);
  return found;
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

/* sのtのインデックスを返す、なければ-1 */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}

/* sのtのインデックスを返す、なければ-1 */
int strrindex(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s)-1; s[i] >= 0; i--) {
    for (j = i, k = strlen(t)-1; t[k] >= 0 && s[j] == t[k]; j--, k--)
      ;
    if (k <= 0)
      return ++i;
  }
  return -1;
}

