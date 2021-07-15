#include <stdio.h>

int reverse(int x){
    int result = 0, tmp = 0;

    while ( x != 0) {
        result = 10 * result + x % 10;
        if (result / 10 != tmp) {
            return 0;
        }
        tmp = result;
        x = x / 10;
    }

    return result;
}


int main(int argc, char *argv[])
{
    int iInput, iOutput;
    printf("input a number: ");
    scanf("%d", &iInput);

    printf("*****%d*****\n", iInput);
    iOutput = reverse(iInput);
    printf("*****%d*****\n", iOutput);
}