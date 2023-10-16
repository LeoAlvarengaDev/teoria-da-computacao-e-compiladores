#include <stdio.h>

// Função para calcular a potência de um conjunto
void calcularPotencia(int vet[], int x) {
    printf("P(A):");

    for (int i = 0; i < (1 << x); i++) { // Loop para gerar os subconjuntos
        printf("{");
        int primeiro = 1;
        for (int j = 0; j < x; j++) {
            if ((i & (1 << j)) != 0) {
                if (!primeiro) {
                    printf(",");
                }
                printf("%d", vet[j]);
                primeiro = 0;
            }
        }
        printf("}");
        if (i != (1 << x) - 1) {
            printf(",");
        }
    }

    printf("\n");
}

int main() {
    int x;
    scanf("%d", &x);
    int vet[x];

    for (int i = 0; i < x; i++) {
        scanf("%d", &vet[i]);
    }

    calcularPotencia(vet, x);

    return 0;
}

