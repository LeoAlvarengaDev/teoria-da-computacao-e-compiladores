#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    printf("Informe o valor de i: ");
    scanf("%d", &i);


    generate_MQ(i);

    return 0;
}
// Função recursiva para verificar se [n, m] está em MQ
int is_in_MQ(int n, int m) {
    if (n == 0 && m == 1) {
        return 1; // Caso base: [0, 1] pertence a MQ
    } else if (n < m) {
        return is_in_MQ(n, m - 1); // Passo recursivo: [n, m] pertence a MQ se [n, m-1] pertence a MQ
    }
    return 0; // Caso contrário, [n, m] não está em MQ
}

// Função para gerar e imprimir MQ até um valor dado de i
void generate_MQ(int i) {
    for (int j = 0; j <= i; j++) {
        printf("I %d | j %d | ", i, j);
        for (int m = j + 1; m <= i + 1; m++) {
            if (is_in_MQ(j, m)) {
                printf("[%d,%d] ", j, m);
            }
        }
        printf("\n");
    }
}

