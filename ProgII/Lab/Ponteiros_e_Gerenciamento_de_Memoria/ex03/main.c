#include <stdio.h>
#include <stdlib.h>

// Defina e implemente TrocaInterios
int TrocaInterios(int *a, int *b);

int main() {
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) == 2) {
        if (TrocaInterios(&n1, &n2)) {
            printf("TROCADO: %d %d\n", n1, n2);
        } else {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }
    return 0;
}

int TrocaInterios(int *a, int *b) {
    if (*a <= *b)
        return 0;

    int tmp = *b;
    *b = *a;
    *a = tmp;

    return 1;
}
