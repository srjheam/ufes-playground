/*
 * Exercício 6 - Monitoria Prog I
 * Autor: Jheam Storch Ross
 */

#include <stdio.h>
#include <string.h>

int getDV10Valido(int cpf[]) {
    int soma = cpf[0] * 10 + cpf[1] * 9 + cpf[2] * 8 + cpf[3] * 7 + cpf[4] * 6 + cpf[5] * 5 + cpf[6] * 4 + cpf[7] * 3 + cpf[8] * 2;
    int resto = soma % 11;

    if (resto < 2) {
        return 0;
    }
    else {
        return 11 - resto;
    }
}

int getDV11Valido(int cpf[]) {
    int soma = cpf[0] * 11 + cpf[1] * 10 + cpf[2] * 9 + cpf[3] * 8 + cpf[4] * 7 + cpf[5] * 6 + cpf[6] * 5 + cpf[7] * 4 + cpf[8] * 3 + getDV10Valido(cpf) * 2;
    int resto = soma % 11;

    if (resto < 2) {
        return 0;
    }
    else {
        return 11 - resto;
    }
}

int EhValidoCPF(int cpf[]) {
    return cpf[9] == getDV10Valido(cpf) && cpf[10] == getDV11Valido(cpf);
}

int EhMaiorIdade(int anoNasc) {
    return 2022 - anoNasc >= 18;
}

int EhAprovado(int pntAdvert) {
    int r = pntAdvert <= 3;
    return r;
}

int EhVerdadeiro(int cpf[], int anoNasc, int pntAdvert) {
    int result = 1;

    if (!EhValidoCPF(cpf)) {
        printf("CPF INVALIDO!\n");
        result = 0;
    }
    if (!EhMaiorIdade(anoNasc)) {
        printf("EH MENOR DE IDADE!\n");
        result = 0;
    }
    if (!EhAprovado(pntAdvert)) {
        printf("FOI REPROVADO!\n");
        result = 0;
    }

    return result;
}

int EhDigito(int d) {
    return d >= '0' && d <= '9';
}

void main(void) {
    int n;
    do {
        system("cls||clear");
        printf("Digite o numero de usuarios a serem validados: ");
        scanf("%d%*c", &n);
        printf("\n");
    } while (n <= 0);

    int i;
    for (i = 1; i <= n; i++) {
        int cpf[11], anoNasc, pntAdvert;

        char curr;
        int j;
        for (j = 0; j <= 11; j++) {
            scanf("%c", &curr);
            if (!EhDigito(curr) || j == 11) {
                break;
            }
            
            cpf[j] = curr - '0';
        }
        
        if (!isspace(curr) || j != 11) {
            /* Invalidates CPF */
            cpf[0] = __INT_MAX__;
            if (j > 11) {
                scanf("%*[^\n]");
            }
        }

        scanf("%d %d%*c", &anoNasc, &pntAdvert);


        int valido = EhVerdadeiro(cpf, anoNasc, pntAdvert);

        printf("%d eh ", i);
        if (!valido) {
            printf("in");
        }
        printf("valido!\n");
    }
}
