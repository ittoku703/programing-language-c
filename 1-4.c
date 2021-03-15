/* 
 * 温度を摂氏から華氏に換算するプログラムを書け。
 */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("%s\t%s\n", "celsius", "fahr");
    while (celsius <= upper) {
        fahr = (5.0/9.0) * (celsius-32.0);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

