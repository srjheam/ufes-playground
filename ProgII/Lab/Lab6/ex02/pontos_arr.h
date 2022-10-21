#ifndef _PONTOS_ARR_H_
#define _PONTOS_ARR_H_

#include <stdio.h>

#include "ponto.h"

typedef struct pontos_arr tPontos_arr;

tPontos_arr *inicializarTPontos();
void LiberarTPontos(tPontos_arr *tp);
void adicionarPonto(tPonto *p, tPontos_arr *tp);
void salvarPontos(tPontos_arr *p, FILE *f);
tPontos_arr *carregarPontos(FILE *f);
void imprimirPontos(tPontos_arr *tp);

#endif
