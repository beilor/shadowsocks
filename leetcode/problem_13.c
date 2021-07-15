#include <stdio.h>
#include <string.h>

int romanToInt(char * s)
{
    int iIndex = 0, iNum = 0;

    while (s[iIndex] != 0) {
        switch(s[iIndex]) {
            case 'I':
            iNum += 1;
            break;

            case 'V':
            if (iIndex >= 1 && s[iIndex - 1] == 'I') {
                iNum += 3;
            }
            else {
                iNum += 5;
            }
            break;

            case 'X':
            if (iIndex >= 1 && s[iIndex - 1] == 'I') {
                iNum += 8;
            }
            else {
                iNum += 10;
            }
            break;

            case 'L':
            if (iIndex >= 1 && s[iIndex - 1] == 'X') {
                iNum += 30;
            }
            else {
                iNum += 50;
            }
            break;

            case 'C':
            if (iIndex >= 1 && s[iIndex - 1] == 'X') {
                iNum += 80;
            }
            else {
                iNum += 100;
            }
            break;

            case 'D':
            if (iIndex >= 1 && s[iIndex - 1] == 'C') {
                iNum += 300;
            }
            else {
                iNum += 500;
            }
            break;

            case 'M':
            if (iIndex >= 1 && s[iIndex - 1] == 'C') {
                iNum += 800;
            }
            else {
                iNum += 1000;
            }
            break;

            default:
            printf("error character %d!\n", s[iIndex]);
            break;
            // return 0;
        }
        iIndex++;
    }

    return iNum;
}

int romanToInt2(char *s)
{
    int symbolValue[26], iIndex = 0, iInt = 0, iTmp = 0;
    symbolValue['I' - 'A'] = 1;
    symbolValue['V' - 'A'] = 5;
    symbolValue['X' - 'A'] = 10;
    symbolValue['L' - 'A'] = 50;
    symbolValue['C' - 'A'] = 100;
    symbolValue['D' - 'A'] = 500;
    symbolValue['M' - 'A'] = 1000;

    while (s[iIndex] != 0) {
        iTmp = symbolValue[s[iIndex] - 'A'];
        if (s[iIndex + 1] != 0 && iTmp < symbolValue[s[iIndex + 1] - 'A']) {
            iInt -= iTmp;
        }
        else {
            iInt += iTmp;
        }
        iIndex++;
    }

    return iInt;
}

int main(int argc, char *argv[])
{
    char str[16];
    int result;
    memset(str, 0, sizeof(str));
    printf("input a roman number: ");
    scanf("%s", str);

    result = romanToInt2(str);
    printf("str is %s, int is %d\n", str, result);
}