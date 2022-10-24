#include "ponto.h"

#include <stdlib.h>

struct ponto {
    DESTE_TIPO_ x;
    DESTE_TIPO_ y;
};

tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y) {
    tPonto *p = malloc(sizeof *p);

    p->x = x;
    p->y = y;

    return p;
}

void ImprimirPonto(tPonto *p) {
    printf("{%.2" DESTE_FORMATO_ ", %.2" DESTE_FORMATO_ "}", p->x, p->y);
}

void LiberarPonto(tPonto *p) { free(p); }

void salvarPonto(tPonto *p, FILE *f) {
    fwrite(p, sizeof *p, 1, f);

}

tPonto *carregarPonto(FILE *f) {
    tPonto *p = malloc(sizeof *p);

    if (fread(p, sizeof *p, 1, f) == 0) {
        free(p);
        return NULL;
    }

    return p;
}
