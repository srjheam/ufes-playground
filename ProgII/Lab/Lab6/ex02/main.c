#include "pontos_arr.h"

tPonto *lePonto();

void main(void) {
    tPontos_arr *tp_stdin = inicializarTPontos();

    const int qtd = 6;
    printf("Entre com %d pontos:\n", qtd);
    int i;
    for (i = 0; i < qtd; i++)
        adicionarPonto(lePonto(), tp_stdin);

    printf("Pontos lidos da entrada padrão:\n");
    imprimirPontos(tp_stdin);

    FILE *f = fopen("pontos.bin", "wb");
    salvarPontos(tp_stdin, f);
    fclose(f);
    LiberarTPontos(tp_stdin);

    printf("Pontos salvos em arquivo binário.\n");
    printf("Carregando pontos a partir do arquivo...\n");

    f = fopen("pontos.bin", "rb");
    tPontos_arr *tp_bin = carregarPontos(f);    
    fclose(f);

    printf("Pontos lidos do arquivo binário:\n");
    imprimirPontos(tp_bin);
    LiberarTPontos(tp_bin);
}

tPonto *lePonto() {
    DESTE_TIPO_ x, y;
    scanf("%" DESTE_FORMATO_ " %" DESTE_FORMATO_, &x, &y);

    tPonto *p = CriarPonto(x, y);

    return p;
}
