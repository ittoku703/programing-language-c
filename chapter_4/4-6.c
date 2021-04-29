/*
 * 変数を取り扱うコマンドを追加せよ。
 * （一文字の名前を持つ26個の変数を与えるのは容易）
 * 最近印刷された値に対する変数を加えよ。
 * 0~9 x =
 */
#include <stdio.h>
#include <stdlib.h>   // atof()
#include <ctype.h>

#define MAXOP     100   // num, operator max size
#define NUMBER    '0'   // num flag
#define NAME      '1'   // Math function flag
#define BUFSIZE   100
#define MAXVAR    26

int variable;
double mem[MAXVAR];

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_toptwo(void);
int math_function(char s[]);

void store_variable(void);
void fetch_variable(int);

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
      case NAME: 
        if (!math_function(s))
          printf("error: unknown command %s\n", s);
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
      case '%': 
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        else 
          printf("error: zero divisor\n");
        break;
      case '?': 
        print_top();
        break;
      case 'd': 
        duplicate_top();
        break;
      case 's': 
        swap_toptwo();
        break;
      case '=': 
        store_variable();
        break;
      case '\n': 
        printf("\t%.8g\n", pop());
        break;
      default: 
        if (islower(type))
          fetch_variable(type);
        else
          printf("error: unknown command %s\n", s);
        break;
    }
    variable = type;
  }
  return 0;
}

/*
 * pop is output val[sp] value.
 * push is input val[sp] value.
 */
#include <math.h>     // sin, exp, pow
#include <string.h>   // for strcmp

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

void print_top(void)
{
  double top = pop();

  printf("\t%.8g\n", top);
  push(top);
}

void duplicate_top(void)
{
  double top = pop();

  push(top);
  push(top);
}

void swap_toptwo(void)
{
  double top1, top2;

  top1 = pop(), top2 = pop();
  push(top1), push(top2);
}

int math_function(char s[])
{
  if (!strcmp(s, "sin"))
    push(sin(pop()));
  else if (!strcmp(s, "cos"))
    push(cos(pop()));
  else if (!strcmp(s, "exp"))
    push(exp(pop()));
  else if (!strcmp(s, "sqrt"))
    push(sqrt(pop()));
  else if (!strcmp(s, "pow")) {
    double op2 = pop();
    push(pow(pop(), op2));
  }
  else 
    return 0;
  return 1;
}

void store_variable(void)
{
  if (variable >= 'a' && variable <= 'z') {
    pop();
    push(mem[variable - 'a'] = pop());
  }
  else 
    printf("error: no variable name\n");
}

void fetch_variable(int var)
{
  push(mem[var - 'a']);
}

/*
 * getop は数字、演算子、文字をgetcharメソッドで取得し、sに格納、判定をする
 * getch は標準入力から文字を取ってくるか、
 */
int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c;

  // space, tab skip!!
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  i = 0;
  if (c == '-')
    if (!isdigit(s[++i] = c = getch())) {
      ungetch(c);
      c = s[0];
    }

  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    ungetch(c);
    return (strlen(s) == 1) ? s[0] : NAME;
  }

  // c is charactor
  if (!isdigit(c) && c != '.')
    return c;

  // reading Integer
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  // reading Float
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}


char buf[BUFSIZE];
int bufp = 0;

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

