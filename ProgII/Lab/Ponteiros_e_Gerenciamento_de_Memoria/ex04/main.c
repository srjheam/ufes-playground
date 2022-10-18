#include <stdio.h>
#include <stdlib.h>

void fillArr(int *arr, int n, int v);

int main() {
    const int tam_arr = 5;
    int array[tam_arr];
    fillArr(array, tam_arr, 42);

    int i;
    for (i = 0; i < tam_arr; i++)
        printf("%d ", *(array + i));

    printf("%c", '\n');
}

void fillArr(int *arr, int n, int v) {
    int i;
    for (i = 0; i < n; i++)
        *(arr + i) = v;
}
