#include <stdio.h>
#include <stdlib.h>

#include "tBoleto.h"

struct tBoleto {
    int cod;
    float val;
};

tBoleto *construtorBoleto(int cod, float val) {
    tBoleto *bol = malloc(sizeof *bol);

    bol->cod = cod;
    bol->val = val;

    return bol;
}

void *destrutorBoleto(tBoleto *bol) {
    free(bol);

    return NULL;
}

tBoleto *MaisCaro(tBoleto *bol1, tBoleto *bol2) {
    return bol1->val >= bol2->val ? bol1 : bol2;
}

tBoleto *MaisBarato(tBoleto *bol1, tBoleto *bol2) {
    return bol1->val <= bol2->val ? bol1 : bol2;
}

float ValorBoleto(tBoleto *bol) { return bol->val; }

tBoleto **construtorBoletos(int tam) {
    tBoleto **bols = malloc(tam * sizeof(*bols));

    return bols;
}

void *destrutorBoletos(tBoleto **bols, int tam) {
    while (tam--)
        destrutorBoleto(bols[tam]);

    free(bols);

    return NULL;
}

float somaBoletos(tBoleto **bols, int tam) {
    float soma = .0;

    while (tam--)
        soma += ValorBoleto(bols[tam]);

    return soma;
}

void ImprimirBoleto(tBoleto *bol) {
    printf("Cod: %d valor: %.2f\n", bol->cod, bol->val);
}
