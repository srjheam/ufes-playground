/* Exercício 2 - Monitoria Prog I
   Autor: Jheam Storch Ross */

#include <stdio.h>

void main(void) {
    int line = 0, column = 0;
    printf("%s", "Movimentos de uma Torre no xadrez!\n");

    printf("%s", "Digite a linha em que a Torre se encontra:\n");
    scanf("%d", &line);
    printf("%s", "Digite a coluna em que a Torre se encontra:\n");
    scanf("%d", &column);

    printf("%s", "Movimentos possíveis:\n");

    printf("%s", "     1  2  3  4  5  6  7  8\n");
    int i;
    for (i = 1; i <= 8; i++)
    {
        printf("%d%s", i, " |  ");
        int j;
        for (j = 1; j <= 8; j++)
        {
            if (i == line || j == column) {
                printf("%c", 'x');
            }
            else {
                printf("%c", '-');
            }
            printf("%s", "  ");
        }
        printf("%s", "\n");
    }
}
