#include <stdio.h>
#include <stdlib.h>

void LeDadosParaVetor(int *vet, int tam);
void OrdeneCrescente(int *vet, int tam);
void ImprimeDadosDoVetor(int *vet, int tam);

int main(int argc, char *argv[]) {
    int casos;

    scanf("%d", &casos);
    while (casos) {
        int tam;
        scanf("%d", &tam);

        int vet[tam];
        LeDadosParaVetor(vet, tam);

        OrdeneCrescente(vet, tam);

        ImprimeDadosDoVetor(vet, tam);

        casos--;
    }
    return 0;
}

void LeDadosParaVetor(int *vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        scanf("%d", vet + i);
}

void OrdeneCrescente(int *vet, int tam) {
    int i;
    for (i = 1; i < tam; i++) {
        if (vet[i - 1] > vet[i]) {
            int tmp = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = tmp;

            i = 0;
        }
    }
}

void ImprimeDadosDoVetor(int *vet, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("%c", '\n');
}
