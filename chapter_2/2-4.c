/* 
 * 文字列s2中の任意の文字に等しい文字をs1から除去する
 * squeeze(s1, s2)を書け。
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char str[BUFSIZ] = "abcdefg";
    char target[BUFSIZ] = "abcde";

    squeeze(str, target);

    printf("%s\n", str);
    return 0;
}

/* s1からs2の文字を消す */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int flag = 0;

    // s1を文字に変換 for i
    for (i = j = 0; s1[i] != '\0'; i++) {
        // s2を文字に変換 for j
        for (k = 0; s2[k] != '\0'; k++)
            // s1[i]がs2と一致したらフラグ
            if (s1[i] == s2[k]) flag = 1;
        // フラグが立たなければ代入
        if (!flag)
            s1[j++] = s1[i];
        flag = 0;
    }
    s1[j] = '\0';
}


