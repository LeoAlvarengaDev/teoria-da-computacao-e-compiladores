#include <stdio.h>

#define MAX_CIDADES 4

int grafo[MAX_CIDADES][MAX_CIDADES] = {0}; // Inicializa a matriz com todas as distâncias como 0

// Procedimento para inserir a distância entre duas cidades na matriz
void inserirDistancia(int cidade1, int cidade2, int distancia) {
    if (cidade1 >= 0 && cidade1 < MAX_CIDADES && cidade2 >= 0 && cidade2 < MAX_CIDADES) {
        grafo[cidade1][cidade2] = distancia;
        grafo[cidade2][cidade1] = distancia; // O grafo é não-direcionado, portanto, atualizamos ambas as direções
    }
}

// Procedimento para contar quantas estradas ligam as cidades
int contarEstradas(int cidade) {
    int contador = 0;
    for (int i = 0; i < MAX_CIDADES; i++) {
        if (grafo[cidade][i] > 0) {
            contador++;
        }
    }
    return contador;
}

// Procedimento para imprimir a matriz de distâncias
void imprimirGrafo() {
    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para obter a distância entre duas cidades
int obterDistancia(int cidade1, int cidade2) {
    if (cidade1 >= 0 && cidade1 < MAX_CIDADES && cidade2 >= 0 && cidade2 < MAX_CIDADES) {
        if (grafo[cidade1][cidade2] > 0) {
            return grafo[cidade1][cidade2];
        }
    }
    return 0; // Retorna 0 se não houver estrada ligando as cidades
}

int main() {
    // Inserir distâncias entre cidades
    inserirDistancia(0, 1, 10); // Cidade 0 para Cidade 1: 10 km
    inserirDistancia(1, 2, 15); // Cidade 1 para Cidade 2: 15 km
    inserirDistancia(2, 3, 20); // Cidade 2 para Cidade 3: 20 km

    // Contar estradas ligando cidades
    int cidade = 1; // Cidade 1
    int qtdEstradas = contarEstradas(cidade);
    printf("Cidade %d tem %d estradas ligando outras cidades.\n", cidade, qtdEstradas);

    // Imprimir a matriz de distâncias
    printf("Matriz de Distâncias:\n");
    imprimirGrafo();

    // Obter distância entre cidades
    int cidadeA = 0; // Cidade 0
    int cidadeB = 2; // Cidade 2
    int distancia = obterDistancia(cidadeA, cidadeB);
    if (distancia > 0) {
        printf("A distância entre Cidade %d e Cidade %d é %d km.\n", cidadeA, cidadeB, distancia);
    } else {
        printf("Não há estrada ligando Cidade %d e Cidade %d.\n", cidadeA, cidadeB);
    }

    return 0;
}

