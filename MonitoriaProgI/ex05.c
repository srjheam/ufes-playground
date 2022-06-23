/*
 * Exercício 5 - Monitoria Prog I
 * Autor: Jheam Storch Ross
 */

#include <stdio.h>
#define PENDENTE 0
#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1

int EscovarDentes() {
    printf("Escovando os dentes!\n");
    return 1;
}

int ArrumarCama() {
    printf("Arrumando a cama!\n");
    return 1;
}

int PrepararCafe() {
    printf("Preparando o cafe!\n");
    return 1;
}

void main(void) {
    int option;
    int dentes = PENDENTE, cama = PENDENTE, cafe = PENDENTE;
    do {
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            if (dentes == ESCOVADO && cama == ARRUMADA && cafe == PREPARADO) {
                printf("Saindo de casa!\n");
            }
            else {
                printf("### Ainda ha tarefas pendentes! ###\n");
            }
            break;
            
        case 1:
            if (dentes == ESCOVADO) {
                printf("Isso já foi feito\n");
                break;
            }

            dentes = EscovarDentes();
            break;
        case 2:
            if (cama == ARRUMADA) {
                printf("Isso já foi feito\n");
                break;
            }

            cama = ArrumarCama();
            break;
        case 3:
            if (cafe == PREPARADO) {
                printf("Isso já foi feito\n");
                break;
            }

            cafe = PrepararCafe();
            break;
        }
    } while (!(option == 0 && dentes == ESCOVADO && cama == ARRUMADA && cafe == PREPARADO));
}
