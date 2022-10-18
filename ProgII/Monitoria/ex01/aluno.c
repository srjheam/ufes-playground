#include <stdio.h>
#include <string.h>

#include "aluno.h"

tAluno constructAluno(char nome[TAM_NOME], int matricula, float n1, float n2, float n3) {
    tAluno aluno = { matricula, n1, n2, n3 };
    strcpy(aluno.nome, nome);

    return aluno;
}

int aprovado(tAluno aluno) {
    return (aluno.n1 + aluno.n2 + aluno.n3 ) / 3. >= 7;
}

void ordenaAlunos(tAluno alunos[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (comparaAluno(alunos[i], alunos[i - 1]) == -1) {
            tAluno tmp = alunos[i];
            alunos[i] = alunos[i - 1];
            alunos[i - 1] = tmp;

            i = 0;
        }
    }
}

int comparaAluno(tAluno a1, tAluno a2) {
    return a1.matricula < a2.matricula ? -1 : 1;
}

void imprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}
