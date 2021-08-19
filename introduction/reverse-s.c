#include <stdio.h>

#define MATCH_SIZ      5 

int get_line(char s[]);
char * reverse(char s[]);

int main()
{
    int len;
    int match;
    char line[BUFSIZ];

    match = MATCH_SIZ;
    while ((len = get_line(line)) > 0)
        if (len == match+1) 
            printf("match: %s", reverse(line));
}

int get_line(char s[])
{
    int c, i;

    for (i = 0; i < BUFSIZ-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        switch (c) {
        case '\t': 
        case '\n': 
        case ' ': 
            --i;
            break;
        default: 
            s[i] = c;
        }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

char * reverse(char s[])
{
    char tmp;
    int i, j, len;

    for (i = len= 0; s[i] != '\0'; ++i)
        ++len;
    for (i = 0, j = len-2; i < len/2; ++i, --j) {
        printf("%c, %c\n", s[i], s[j]);
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    s[len-1] = '\n';
    return s;
}

