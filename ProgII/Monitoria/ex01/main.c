#include <stdio.h>

#include "aluno.h"

tAluno leAluno();

void main(void) {
    int n;
    scanf("%d", &n);

    tAluno alunos[n];

    int i;
    for (i = 0; i < n; i++)
        alunos[i] = leAluno();

    ordenaAlunos(alunos, n);

    printf("%s", "Alunos Aprovados:\n");
    for (i = 0; i < n; i++)
        if (aprovado(alunos[i]))
            imprimeAluno(alunos[i]);
}

tAluno leAluno() {
    char nome[TAM_NOME];
    int matricula;
    float n1, n2, n3;
    scanf("%s %d %f %f %f", nome, &matricula, &n1, &n2, &n3);

    tAluno aluno = constructAluno(nome, matricula, n1, n2, n3);
    return aluno;
}
