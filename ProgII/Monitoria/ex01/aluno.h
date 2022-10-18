#ifndef _ALUNO_H_
#define _ALUNO_H_

#define TAM_NOME 1024

typedef struct {
    int matricula;
    float n1;
    float n2;
    float n3;
    char nome[TAM_NOME];
} tAluno;

tAluno constructAluno(char[TAM_NOME], int, float, float, float);

int aprovado(tAluno);

void ordenaAlunos(tAluno[], int);

int comparaAluno(tAluno, tAluno);

void imprimeAluno(tAluno);

#endif