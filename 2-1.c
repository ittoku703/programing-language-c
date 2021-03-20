/* (問題がよくわからない)
 * char, short, int, long変数のsigned, unsignedの
 * 両方の型について、それらの範囲を決め、印字、
 * 計算するプログラムを書け。
 */

#include <stdio.h>

#define MIN_LENGTH      -100
#define MAX_LENGTH      100

int range(long v);

int main()
{
//---------------------------
//  型の変数を定義
//---------------------------
    signed char     c;
    signed short    sho;
    signed int      i;
    signed long     lo;
    unsigned char   u_c;
    unsigned short  u_sho;
    unsigned int    u_i;
    unsigned long   u_lo;


//---------------------------
//  範囲を決めて代入
//---------------------------
    c =     range(50);
    sho =   range(-20);
    i =     range(75);
    lo =    range(99);
    u_c =   range(50);
    u_sho = range(20);
    u_i =   range(75);
    u_lo =  range(99);

//---------------------------
//  印字する
//---------------------------

    printf("c:\t%c\n", c);
    printf("sho:\t%d\n", sho);
    printf("i:\t%d\n", i);
    printf("lo:\t%ld\n", lo);
    printf("u_c:\t%c\n", u_c);
    printf("u_sho:\t%d\n", u_sho);
    printf("u_i:\t%d\n", u_i);
    printf("u_lo:\t%lu\n", u_lo);
    
//---------------------------
// 直接計算する
//---------------------------

    return 0;
}

int range(long v)
{
    if (v >= MAX_LENGTH || v <= MIN_LENGTH) 
        return 0;
    else
        return v;
}

