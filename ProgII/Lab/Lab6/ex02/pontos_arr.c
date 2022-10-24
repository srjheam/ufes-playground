#include <stdlib.h>

#include "pontos_arr.h"

struct pontos_arr {
    unsigned int n;
    tPonto **ps;
    unsigned int length;
};

tPontos_arr *inicializarTPontos() {
    tPontos_arr *tp = malloc(sizeof *tp);

    const unsigned int size = 10;
    tp->n = size;
    tp->ps = malloc(size * sizeof(void *));
    tp->length = 0;

    return tp;
}

void LiberarTPontos(tPontos_arr *tp) {
    int i;
    for (i = 0; i < tp->length; i++) {
        LiberarPonto(tp->ps[i]);
    }

    free(tp->ps);
    free(tp);
}

void adicionarPonto(tPonto *p, tPontos_arr *tp) {
    if (tp->length == tp->n) {
        tp->n *= 2;
        tp->ps = realloc(tp->ps, tp->n * sizeof(void *));
    }

    // p element may still be acessed from "main" 
    tp->ps[tp->length++] = p;
}

void salvarPontos(tPontos_arr *p, FILE *f) {
    int i;
    for (i = 0; i < p->length; i++)
        salvarPonto(p->ps[i], f);
}

tPontos_arr *carregarPontos(FILE *f) {
    tPontos_arr *tp = inicializarTPontos();

    tPonto *p;
    while (p = carregarPonto(f))
        adicionarPonto(p, tp);
    
    return tp;
}

void imprimirPontos(tPontos_arr *tp) {
    int i;
    for (i = 0; i < tp->length; i++) {
        ImprimirPonto(tp->ps[i]);
        printf("%c", '\n');
    }
}