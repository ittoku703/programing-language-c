#include <stdio.h>

void escape(char s[]); 

int main()
{
    char s[BUFSIZ];

    escape(s);

    printf("%s\n", s);

    return 0;
}

void escape(char s[])
{   
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '\n': 
            s[i++] = '\\';
            s[i++] = 'n';
            break;
        case '\t': 
            s[i++] = '\\';
            s[i++] = 't';
            break;
        default: 
            s[i++] = c;
        }
    }
}

