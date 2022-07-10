/* Exercício 4 - Monitoria Prog I
   Autor: Jheam Storch Ross */

#include <stdio.h>

long factorial(int n) {
    if (!n) {
        return 1;
    }
    
    return n * factorial(n - 1);
}

void main(void) {
    int n = 0;

    scanf("%d%*c", &n);

    int i;
    for (i = 0; i < n; i++) {
        int fac;
        scanf("%d%*c", &fac);
        printf("%d %ld\n", fac, factorial(fac));
    }
}
