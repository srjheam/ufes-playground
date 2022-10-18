#include <stdio.h>

void main(void) {
    int inteiro = 0;
    float real = .0;
    char caractere = 'a';

    int *pint = &inteiro;
    float *preal = &real;
    char *pchar = &caractere;

    printf("\nAntes:\n");
    printf("Inteiro @(%p): %d\n", pint, *pint);
    printf("Real @(%p): %.2f\n", preal, *preal);
    printf("Caractere @(%p): %c\n", pchar, *pchar);
    
    *pint += 42;
    *preal = .1 + .2;
    *pchar = 'z';

    printf("\nDepois:\n");
    printf("Inteiro @(%p): %d\n", pint, *pint);
    printf("Real @(%p): %.2f\n", preal, *preal);
    printf("Caractere @(%p): %c\n", pchar, *pchar);
}
