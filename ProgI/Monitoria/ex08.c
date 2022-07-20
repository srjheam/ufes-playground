/*
 * Exercício 8 - Monitoria Prog I
 * Autor: Jheam Storch Ross
 */

#include <stdio.h>

#define TAM_VET 15

typedef struct {
    int qtdVal;
    int valores[TAM_VET];
} tVetor;

tVetor leVet();
tVetor filtraVet(tVetor vet);
void imprimeVet(tVetor vet);

void main(void) {
    tVetor vet = leVet();
    
    printf("%s", "V = [");
    imprimeVet(filtraVet(vet));
    printf("%s", "]");
}

tVetor leVet() {
    tVetor vet = { TAM_VET };

    int i;
    for (i = 0; i < TAM_VET; i++)
        scanf("%d", &vet.valores[i]);

    return vet;
}

tVetor filtraVet(tVetor vet) {
    tVetor novoVet = { 0 };

    int i;
    for (i = 0; i < vet.qtdVal; i++) {
        if (vet.valores[i] != 0) {
            int currI = novoVet.qtdVal;

            novoVet.valores[currI] = vet.valores[i];
            novoVet.qtdVal++;
        }
    }

    return novoVet;
}

void imprimeVet(tVetor vet) {
    int i;
    for (i = 0; i < vet.qtdVal; i++) {
        printf("%d", vet.valores[i]);

        if (i != vet.qtdVal - 1) {
            printf("%s", ", ");
        }
    }
    printf("%c", '\0');
}
