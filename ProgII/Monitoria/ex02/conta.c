#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conta.h"
#include "usuario.h"

struct Conta {
    Usuario *usr;
    char *nAgencia;
    char *nConta;
    double saldo;
};

Conta *construtorConta(char *nome, char *cpf, char *nAgencia, char *nConta,
                       double saldo) {
    Conta *conta = malloc(sizeof *conta);

    conta->usr = construtorUsuario(nome, cpf);

    conta->nAgencia = malloc(sizeof conta->nAgencia);
    strcpy(conta->nAgencia, nAgencia);

    conta->nConta = malloc(sizeof conta->nConta);
    strcpy(conta->nConta, nConta);

    conta->saldo = saldo;

    return conta;
}

void *destrutorConta(Conta *conta) {
    destrutorUsuario(conta->usr);
    free(conta->nAgencia);
    free(conta->nConta);
    free(conta);

    return NULL;
}

double adquireSaldo(Conta *conta) { return conta->saldo; }

int deposita(Conta *conta, double val) {
    conta->saldo += val;

    return 1;
}

int saca(Conta *conta, double val) {
    if (conta->saldo < val)
        return 0;

    conta->saldo -= val;

    return 1;
}

void imprimeConta(Conta *conta) {
    char *usrNome = adquireNome(conta->usr);
    printf("Usuário: %s\n", usrNome);

    free(usrNome);
    usrNome = NULL;

    printf("Conta: %s\n", conta->nConta);
    printf("Agência: %s\n", conta->nAgencia);
}