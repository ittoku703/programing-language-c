#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char str[BUFSIZ] = "abcdefg";
    char target[BUFSIZ] = "t";

    printf("%d\n", any(str, target));
    return 0;
}

/* s1からs2の文字を消す */
int any(char s1[], char s2[])
{
    int i, j, k;
    int flag = 0;

    // s1を文字に変換 for i
    for (i = 0; s1[i] != '\0'; i++) 
        // s2を文字に変換 for j
        for (j = 0; s2[j] != '\0'; j++)
            // s1[i]がs2と一致したらiを返す
            if (s1[i] == s2[j]) return i;
    
    return -1;
}


