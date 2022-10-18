#include <stdio.h>

#include "conta.h"

#define TAM_S 1024

#define DEFAULT_CONTA "12345"
#define DEFAULT_AGENCIA "1234"

#define OP_SAIR 0
#define OP_SAQUE 1
#define OP_DEPOSITO 2

Conta *leConta();

void main(void) {
    Conta *conta = leConta();

    imprimeConta(conta);

    while (1) {
        int currOp;
        scanf("%d", &currOp);

        if (currOp == OP_SAIR)
            break;

        double val;
        scanf("%lf", &val);

        switch (currOp) {
        case OP_SAQUE:
            saca(conta, val);
            printf("\nSaque realizado no valor de %.2lf\n", val);
            break;

        case OP_DEPOSITO:
            deposita(conta, val);
            printf("\nDeposito realizado no valor de %.2lf\n", val);
            break;
        }
    }

    printf("\nSaldo: %.2lf\n", adquireSaldo(conta));

    conta = destrutorConta(conta);
}

Conta *leConta() {
    char nome[TAM_S], cpf[TAM_S];
    scanf("%s %s", nome, cpf);

    Conta *conta =
        construtorConta(nome, cpf, DEFAULT_AGENCIA, DEFAULT_CONTA, .0);

    return conta;
}
