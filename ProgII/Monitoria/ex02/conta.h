#ifndef _CONTA_H_
#define _CONTA_H_

typedef struct Conta Conta;

Conta *construtorConta(char *, char *, char *, char *, double);

void *destrutorConta(Conta *);

double adquireSaldo(Conta *);

int deposita(Conta *, double);

int saca(Conta *, double);

void imprimeConta(Conta *);

#endif
