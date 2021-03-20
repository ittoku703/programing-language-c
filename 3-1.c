/*
 * ループの中で1回しかテストしないようなプログラムを書き
 * 実行時間の差を測定せよ。
 */

#include <stdio.h>

#define NUM_LENGTH      1000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int num[NUM_LENGTH];

    for (int i = 0; i < NUM_LENGTH; i++)
        num[i] = i;

    printf("binsearch: %d\n", binsearch2(999, num, NUM_LENGTH));

    return 0;
}

/* v[n]からxを探す */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

/* v[n]からxを探す */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    for (int i = low; i <= high; i++)
        if (x == v[i])
            return i;
    return -1;
}

