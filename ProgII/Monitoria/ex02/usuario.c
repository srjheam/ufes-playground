#include <stdlib.h>
#include <string.h>

#include "usuario.h"

#define TAM_CPF sizeof(char) * 12

struct Usuario {
    char *nome;
    char *cpf;
};

Usuario *construtorUsuario(char *nome, char *cpf) {
    Usuario *usr = malloc(sizeof *usr);

    usr->nome = malloc(sizeof(char) * (strlen(nome) + 1));
    usr->cpf = malloc(TAM_CPF);

    strcpy(usr->nome, nome);
    strncpy(usr->cpf, cpf, TAM_CPF);

    return usr;
}

void *destrutorUsuario(Usuario *usr) {
    free(usr->nome);
    free(usr->cpf);
    free(usr);

    return NULL;
}

char *adquireNome(Usuario *usr) {
    char *str = malloc(sizeof *str * (strlen(usr->nome) + 1));

    strcpy(str, usr->nome);

    return str;
}
