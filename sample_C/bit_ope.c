#include <stdio.h>

typedef union {
    struct {
    unsigned char a : 1;
    unsigned char b : 4;
    unsigned char : 2;
    unsigned char c : 1;
    };
    unsigned char all;
    
}BITOPE;

int main()
{
    BITOPE bitOpe;
    bitOpe.all = 0xDA;

    printf("a: %hhu, b: %hhu, c: %hhu. size: %lu\n", bitOpe.a, bitOpe.b, bitOpe.c, sizeof(bitOpe));
}