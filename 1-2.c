/* 
 * xが上にあげなかったある文字であるとして、printfの引数に\xを含めると
 * どうなるかを調べる実験を行え
 */

#include <stdio.h>

int main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
    printf("\x55\n");

    return 0;
}

// answer: \xはasciiの文字コードで表現される

