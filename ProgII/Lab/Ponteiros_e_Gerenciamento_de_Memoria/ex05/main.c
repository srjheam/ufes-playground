#include <stdio.h>

#include "tBoleto.h"

tBoleto *LeBoleto();
void ImprimirBoleto(tBoleto *);

void main(void) {
    int n;
    scanf("%d", &n);

    tBoleto **bols = construtorBoletos(n);
    int i;
    for (i = 0; i < n; i++)
        bols[i] = LeBoleto();

    tBoleto *maisCaro = bols[0];
    tBoleto *maisBarato = bols[0];
    for (i = 1; i < n; i++) {
        maisCaro = MaisCaro(maisCaro, bols[i]);
        maisBarato = MaisBarato(maisBarato, bols[i]);
    }

    float total = somaBoletos(bols, n);

    printf("Mais caro: ");
    ImprimirBoleto(maisCaro);
    printf("Mais barato: ");
    ImprimirBoleto(maisBarato);
    printf("Soma: %.2f", total);

    bols = destrutorBoletos(bols, n);
}

tBoleto *LeBoleto() {
    int cod;
    float val;
    scanf("%d %f", &cod, &val);

    return construtorBoleto(cod, val);
}
