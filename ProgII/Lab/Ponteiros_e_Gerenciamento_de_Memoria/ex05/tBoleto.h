#ifndef _TBOLETO_H_
#define _TBOLETO_H_

typedef struct tBoleto tBoleto;

tBoleto *construtorBoleto(int, float);
void *destrutorBoleto(tBoleto *);
tBoleto *MaisCaro(tBoleto *, tBoleto *);
tBoleto *MaisBarato(tBoleto *, tBoleto *);
float ValorBoleto(tBoleto *);

tBoleto **construtorBoletos(int);
void *destrutorBoletos(tBoleto **, int);
float somaBoletos(tBoleto **, int);


void ImprimirBoleto(tBoleto *);

#endif
