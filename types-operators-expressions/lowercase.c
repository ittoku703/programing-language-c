#include <stdio.h>

void lower(char s[]);

int main()
{
    char upper[] = "aBCdeFG"; 

    lower(upper);

    printf("%s\n", upper);

    return 0;
}

void lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        s[i] += (s[i] >= 'A' && s[i] <= 'Z') ? 'a' - 'A' : 0; 
}
