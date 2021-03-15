/*
 * getchar() != EOFという式の値が0か1であることを確認せよ。
 */

#include <stdio.h>

int main()
{
    printf("%d\n", (getchar() != EOF));

    return 0;
}

