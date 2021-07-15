#include <stdio.h>

int main(void)
{
    FILE *fd = fopen("test.txt", "rw");
    char str[100];
    int num1, num2;

    fgets(str, 100, fd);

    fgets(&num1, 4, fd);
    fgets(&num2, 4, fd);

    printf("%s %d %d\n", str, num1, num2);
    printf("%lu\n", sizeof(int));

}