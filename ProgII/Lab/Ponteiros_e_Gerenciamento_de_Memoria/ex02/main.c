#include <stdio.h>

void main(void) {
    int inteiro1 = 0;
    int inteiro2 = 0;

    printf("Maior enderereço dos inteiros: %p\n",
           &inteiro1 > &inteiro2 ? &inteiro1 : &inteiro2);
    // sempre será o endereço do inteiro2 pois ele foi alocado em cima de
    // inteiro1, na stack
}
