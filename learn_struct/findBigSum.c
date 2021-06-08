#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX2(a, b)      ((a) - (b) > 0) ? (a) : (b)

#define MAX3(a, b, c)   MAX2(MAX2(MAX2(a, b), c), 0)

int OnlineCalculate(int*, int);
int FindBigMiddle(int *iArray, int n)
{
    int i = 0, MaxSumLeft = 0, MaxSumRight = 0, sum = 0;
    for (i = (n - 1) / 2; i >= 0; i--) {
        sum += iArray[i];
        if (sum > MaxSumLeft) {
            MaxSumLeft = sum;
        }
    }
    sum = 0;
    for (i = (n - 1) / 2 + 1; i < n; i++) {
        sum += iArray[i];
        if (sum > MaxSumRight) {
            MaxSumRight = sum;
        }
    }
    return MAX3(MaxSumRight, MaxSumLeft, MaxSumLeft + MaxSumRight);
}

int FindBigSum(int *iArray, int n)
{
    if (n == 1) {
        return iArray[0]; 
    }
    else if (n == 2) {
        return MAX3(iArray[0], iArray[1], iArray[0] + iArray[1]);
    }
    else {
        return MAX3(FindBigSum(iArray, n / 2), FindBigSum(&iArray[n / 2], n - n / 2), FindBigMiddle(iArray, n));
    }
}

int main(void)
{
    int iArrayNum = 0, iArray[512] = { 0 }, MaxSum = 0 , i = 0, sum = 0, MaxSumOnline = 0;
    scanf("%d", &iArrayNum);

    for (i = 0; i < iArrayNum; i++) {
        srand((unsigned int)time(0) + i);
        iArray[i] =rand() % 100 - 50;
        printf("%d\t", iArray[i]);
    }
    printf("\n");

    MaxSum = FindBigSum(iArray, iArrayNum);
    MaxSumOnline = OnlineCalculate(iArray, iArrayNum);
    printf("%d\t%d\n", MaxSum, MaxSumOnline);
}

int OnlineCalculate(int *iArray, int iArrayNum)
{
    int MaxSum = 0, CurSum = 0, i = 0;
    for (i = 0; i < iArrayNum; i++) {
        CurSum += iArray[i];
        if (CurSum > MaxSum) {
                MaxSum = CurSum;
        }
        if (CurSum < 0) {
            CurSum = 0;
        }
    }
    return MaxSum;
}