#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CIDADES 3

// Definindo os nomes das cidades
char cidades[MAX_CIDADES][30] = {
    "Rio de Janeiro",
    "São Paulo",
    "Belo Horizonte"
};

// Estrutura para representar uma aresta com rótulo (distância)
typedef struct {
    int destino; // O índice da cidade de destino
    int distancia;    // A distância entre as cidades
} Aresta;

// Matriz de adjacência para representar o grafo
int grafo[MAX_CIDADES][MAX_CIDADES] = {0};

// Função para inserir uma aresta (arco) no grafo
void adicionarAresta(int origem, int destino, int distancia) {
    grafo[origem][destino] = distancia;
}

// Função recursiva para calcular o comprimento do caminho entre duas cidades
int encontrarComprimentoCaminho(int origem, int destino, int comprimentoCaminho) {
    if (origem == destino) {
        return comprimentoCaminho;
    }

    int comprimentoMinimo = -1; // Inicializa com um valor que indica que não há caminho
    for (int i = 0; i < MAX_CIDADES; i++) {
        if (grafo[origem][i] > 0) {
            int comprimento = encontrarComprimentoCaminho(i, destino, comprimentoCaminho + grafo[origem][i]);
            if (comprimento > 0 && (comprimentoMinimo == -1 || comprimento < comprimentoMinimo)) {
                comprimentoMinimo = comprimento;
            }
        }
    }

    return comprimentoMinimo;
}

// Função para verificar se há ciclos no grafo (utiliza DFS)
bool temCiclo(int no, bool visitado[], bool pilha[]) {
    if (!visitado[no]) {
        visitado[no] = true;
        pilha[no] = true;

        for (int i = 0; i < MAX_CIDADES; i++) {
            if (grafo[no][i] > 0) {
                if (!visitado[i] && temCiclo(i, visitado, pilha)) {
                    return true;
                } else if (pilha[i]) {
                    return true;
                }
            }
        }
    }

    pilha[no] = false;
    return false;
}

// Função para calcular o grau de entrada de cada nó
void grauEntrada() {
    int grausEntrada[MAX_CIDADES] = {0};

    for (int i = 0; i < MAX_CIDADES; i++) {
        for (int j = 0; j < MAX_CIDADES; j++) {
            if (grafo[j][i] > 0) {
                grausEntrada[i]++;
            }
        }
    }

    printf("Grau de entrada de cada cidade:\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        printf("%s: %d\n", cidades[i], grausEntrada[i]);
    }
}

// Função para calcular o grau de saída de cada nó
void grauSaida() {
    printf("Grau de saída de cada cidade:\n");
    for (int i = 0; i < MAX_CIDADES; i++) {
        int grauSaida = 0;
        for (int j = 0; j < MAX_CIDADES; j++) {
            if (grafo[i][j] > 0) {
                grauSaida++;
            }
        }
        printf("%s: %d\n", cidades[i], grauSaida);
    }
}

int main() {
    // Inserir arestas (arcos) no grafo
    adicionarAresta(0, 1, 450); // Rio de Janeiro para São Paulo: 450 km
    adicionarAresta(1, 2, 600); // São Paulo para Belo Horizonte: 600 km
    adicionarAresta(2, 0, 500); // Belo Horizonte para Rio de Janeiro: 500 km

    // Calcular e apresentar o comprimento do caminho entre duas cidades
    int origem, destino;
    printf("Digite o índice da cidade de origem (0 - Rio de Janeiro, 1 - São Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &origem);
    printf("Digite o índice da cidade de destino (0 - Rio de Janeiro, 1 - São Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &destino);

    int comprimentoCaminho = encontrarComprimentoCaminho(origem, destino, 0);
    if (comprimentoCaminho > 0) {
        printf("O comprimento do caminho entre %s e %s é %d km.\n", cidades[origem], cidades[destino], comprimentoCaminho);
    } else {
        printf("Não há um caminho direto entre %s e %s.\n", cidades[origem], cidades[destino]);
    }

    // Verificar se há ciclos no grafo
    bool visitado[MAX_CIDADES] = {false};
    bool pilha[MAX_CIDADES] = {false};
    bool temCiclos = false;

    for (int i = 0; i < MAX_CIDADES; i++) {
        if (!visitado[i] && temCiclo(i, visitado, pilha)) {
            temCiclos = true;
            break;
        }
    }

    if (temCiclos) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    // Calcular o grau de entrada de cada nó
    grauEntrada();

    // Calcular o grau de saída de cada nó
    grauSaida();

    return 0;
}
