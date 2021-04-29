/*
 * getlineを使って入力全体を読み込む方法で、電卓プログラムを書き換えよ。
 * https://github.com/fsaadatmand/The-C-Programming-Language/blob/master/chapter04/4-10.c
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
#define MAXLINE   100

int get_line(char [], int);

int getop(char s[])
{
  static int i, len;
  static char line[MAXLINE];
  int j;

  if (i == len) {
    len = get_line(line, MAXLINE);
    if (!len) 
      return EOF;
    i = 0;
  }

  j = 0;
  // white space and tab skip.
  while (isblank(line[i]))
    ++i;

  // minus and plus flag
  if ((line[i] == '-' || line[i] == '+') && isdigit(line[i+1]))
    s[j++] = line[i++];

  // math_function flag
  if (isalpha(line[i])) {
    while (isalpha(line[i]))
      s[j++] = line[i++];
    s[j] = '\0';
    return (strlen(s) == 1) ? s[0] : NAME;
  }

  // not number
  if (!isdigit(line[i]) && line[i] != '.')
    return line[i++];

  // number
  if (isdigit(line[i]))
    while (isdigit(line[i]))
      s[j++] = line[i++];

  // float
  if (line[i] == '.')
    while (isdigit(line[i]))
      s[j++] = line[i++];

  s[j] = '\0';

  return NUMBER;
}

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

