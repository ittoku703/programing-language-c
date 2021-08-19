#include <stdio.h>

#define     LOWER   0       // 表の下限
#define     UPPER   300     // 上限
#define     STEP    20      // きざみ

float fahrenheit(int celsius);

int main()
{
    int celsius;

    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) { 
        printf("%3d %6.1f\n", celsius, fahrenheit(celsius));
    }
}

/* fahr = 0, 20, ..., 300に対して、華氏ー摂氏対応表を印字する */
float fahrenheit(int celsius)
{
    return(5.0/9.0)*(celsius-32);
}
