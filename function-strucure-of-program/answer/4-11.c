/*
 * ungetchを必要としないgetopを作成せよ
 */
#include <stdio.h>
#include <stdlib.h>   // atof()

#define MAXOP     100   // num, operator max size
#define NUMBER    '0'   // num flag

int getop(char []);

void push(double);
double pop(void);

int main()
{
  int type;         // num, operand, chatacter?
  double op2;       // operand '-', '/'
  char s[MAXOP];    // number

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER: 
        push(atof(s));
        break;
      case '+': 
        push(pop() + pop());
        break;
      case '*': 
        push(pop() * pop());
        break;
      case '-': 
        op2 = pop();
        push(pop() - op2);
        break;
      case '/': 
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else 
          printf("error: zero divisor\n");
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

/*
 * pop is output val[sp] value.
 * push is input val[sp] value.
 */

#define MAXVAL    100   // val stack max deep

int sp = 0;             // stack, pointer
double val[MAXVAL];      // value stack

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else 
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/*
 * getop は数字、演算子、文字をgetcharメソッドで取得し、sに格納、判定をする
 * getch は標準入力から文字を取ってくるか、
 */
#include <ctype.h>

int getch(void);

int getop(char s[])
{
  int i, c;
  static int prevC;

  (prevC > 0) ? (c = prevC) : (s[0] = c = getch());

  // space, tab skip!!
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  // c is charactor
  if (!isdigit(c) && c != '.') {
    prevC = c;
    return c;
  }
  
  // reading Integer
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  
  // reading Float
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  prevC = c;
  printf("%s %d\n", s, prevC);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

