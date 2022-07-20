/*
 * Exercício 9 - Monitoria Prog I
 * Autor: Jheam Storch Ross
 */

#include <stdio.h>

#define TAM_QUESTOES 10

void leQuestoes(char questoes[TAM_QUESTOES]);

typedef struct {
    char respostas[TAM_QUESTOES];
} tAluno;

tAluno leAluno();
int adquireAcertos(tAluno aluno, char gabarito[TAM_QUESTOES]);

void main(void) {
    int n;
    scanf("%d%*c", &n);

    tAluno alunos[n];

    int i;
    for (i = 0; i < n; i++) {
        alunos[i] = leAluno();
    }
    scanf("%*c");

    char gabarito[TAM_QUESTOES];
    leQuestoes(gabarito);

    for (i = 0; i < n; i++) {
        printf("Aluno %d: %d acertos\n", i + 1, adquireAcertos(alunos[i], gabarito));
    }
}

void leQuestoes(char questoes[TAM_QUESTOES]) {
    int i;
    for (i = 0; i < TAM_QUESTOES; i++) {
        scanf("%c%*c", &questoes[i]);
    }
}

tAluno leAluno() {
    tAluno aluno;
    leQuestoes(aluno.respostas);

    return aluno;
}

int adquireAcertos(tAluno aluno, char gabarito[TAM_QUESTOES]) {
    int acertos = 0;

    int i;
    for (i = 0; i < TAM_QUESTOES; i++) {
        if (aluno.respostas[i] == gabarito[i]) {
            acertos++;
        }
    }
    
    return acertos;
}
