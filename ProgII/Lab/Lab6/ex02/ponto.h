#ifndef _PONTO_H_
#define _PONTO_H_

#define DESTE_TIPO_ float
#define DESTE_FORMATO_ "f"

#include <stdio.h>

typedef struct ponto tPonto;

tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y);
void ImprimirPonto(tPonto *p);
void LiberarPonto(tPonto *p);
void salvarPonto(tPonto *p, FILE *f);
tPonto *carregarPonto(FILE *f);

#endif // _PONTO_H_
