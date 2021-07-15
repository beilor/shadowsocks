#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true = 1
} bool;

bool isPalindrome(int x)
{
    int numberArray[10] = { 0 }, i = 0, index = 0;

    if (x < 0) {
        return false;
    }
    while (x != 0) {
        numberArray[i] = x % 10;
        x = x / 10;
        i++;
    }

    for (index = 0; index < i / 2; index++) {
        if (numberArray[index] != numberArray[i - index  -1]) {
            return false;
        }
    }

    return true;
}

bool isPalindrome2(int x)
{
    int reverX = 0;

    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    while (x > reverX) {
        reverX = reverX * 10 + x % 10;
        x = x / 10;
    }

    return x == reverX || x == reverX / 10;
}

void intToStr(int iNum, char *str)
{
    int numberArray[11] = { 0 }, i = 0, index = 0, count = 0, sign;

    if (iNum == 0x80000000) {
        memcpy(str, "-2147483648", 11);    // -2147483648 * -1 will overflow, so process here.
        return;
    }

    if (iNum < 0) {
        sign = -1;
        iNum = -iNum;
    }

    while (iNum != 0) {
        numberArray[i] = iNum % 10;
        iNum = iNum / 10;
        i++;
    }


    if (sign < 0) {
        str[index++] = '-';
    }

    while (i > 0) {
        str[index] = numberArray[i - 1] + '0';
        index++;
        i--;
    }
}


int main(int argc, char *argv[])
{
    int iInput;
    bool result;
    char str[12];
    memset(str, 0, sizeof(str));
    printf("input a number: ");
    scanf("%d", &iInput);

    printf("*****%d*****\n", iInput);
    result = isPalindrome2(iInput);
    // intToStr(iInput, str);
    // printf("result is %s\n", str);
    printf("result is %s\n", result ? "true" : "false");
    return 0;
}