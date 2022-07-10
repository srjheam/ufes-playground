/* Exercício 3 - Monitoria Prog I
   Autor: Jheam Storch Ross */

#include <stdio.h>

void main(void) {
    int n = 0;

    scanf("%d%*c", &n);

    int i;
    for (i = 0; i < n; i++) {
        char costumer;
        float expenses = .0;
        scanf("%c %f%*c", &costumer, &expenses);
        printf("Cliente %c ganhou um bonus de %.3f$!\n", costumer, expenses * (expenses < 500 ? .1 : .15));
    }
}
