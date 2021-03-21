/*
 * 文字列s1中のa-zのような省略記法を、それと等価なabc...xyzのようにし
 * s2中に展開する関数expand(s1,s2)を書け。a-b-cやa-z0-9やa-zのような場合も
 * 処理できるようにせよ。
 */

#include <stdio.h>

#define NUM_LENGTH      5

void expand(char s1[], char s2[]);

int main()
{
    char s[] = "-0-9A-Z a-b-z";
    char buf[BUFSIZ];

    expand(s, buf);

    printf("expand: %s\n", buf);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, c;

    // example: a-z 0-9 B-D a-b-c -a-z a-z0-9 
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            if (s1[i-1] >= '0' && s1[i-1] <= '9' && 
                s1[i+1] >= '0' && s1[i+1] <= '9') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else if (s1[i-1] >= 'A' && s1[i-1] <= 'Z' && 
                 s1[i+1] >= 'A' && s1[i+1] <= 'Z') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else if (s1[i-1] >= 'a' && s1[i-1] <= 'z' &&
                 s1[i+1] >= 'a' && s1[i+1] <= 'z') {
                for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                    s2[j++] = c;
                ++i;
            }
            else {
                s2[j++] = s1[i];
            }
        }
        else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

