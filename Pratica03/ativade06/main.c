#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CITIES 3

// Definindo os nomes das cidades
char cities[MAX_CITIES][30] = {
    "Rio de Janeiro",
    "Sao Paulo",
    "Belo Horizonte"
};

// Estrutura para representar uma aresta com rótulo (distância)
typedef struct {
    int destination; // O índice da cidade de destino
    int distance;    // A distância entre as cidades
} Edge;

// Matriz de adjacência para representar o grafo
int graph[MAX_CITIES][MAX_CITIES] = {0};

// Função para inserir uma aresta (arco) no grafo
void addEdge(int source, int destination, int distance) {
    graph[source][destination] = distance;
}

// Função recursiva para calcular o comprimento do caminho entre duas cidades
int findPathLength(int source, int destination, int pathLength) {
    if (source == destination) {
        return pathLength;
    }

    int minLength = -1; // Inicializa com um valor que indica que não há caminho
    for (int i = 0; i < MAX_CITIES; i++) {
        if (graph[source][i] > 0) {
            int length = findPathLength(i, destination, pathLength + graph[source][i]);
            if (length > 0 && (minLength == -1 || length < minLength)) {
                minLength = length;
            }
        }
    }

    return minLength;
}

// Função para verificar se há ciclos no grafo (utiliza DFS)
bool hasCycle(int node, bool visited[], bool stack[]) {
    if (!visited[node]) {
        visited[node] = true;
        stack[node] = true;

        for (int i = 0; i < MAX_CITIES; i++) {
            if (graph[node][i] > 0) {
                if (!visited[i] && hasCycle(i, visited, stack)) {
                    return true;
                } else if (stack[i]) {
                    return true;
                }
            }
        }
    }

    stack[node] = false;
    return false;
}

// Função para calcular o grau de entrada de cada nó
void inDegree() {
    int inDegrees[MAX_CITIES] = {0};

    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            if (graph[j][i] > 0) {
                inDegrees[i]++;
            }
        }
    }

    printf("Grau de entrada de cada cidade:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        printf("%s: %d\n", cities[i], inDegrees[i]);
    }
}

// Função para calcular o grau de saída de cada nó
void outDegree() {
    printf("Grau de saída de cada cidade:\n");
    for (int i = 0; i < MAX_CITIES; i++) {
        int outDegree = 0;
        for (int j = 0; j < MAX_CITIES; j++) {
            if (graph[i][j] > 0) {
                outDegree++;
            }
        }
        printf("%s: %d\n", cities[i], outDegree);
    }
}

int main() {
    // Inserir arestas (arcos) no grafo
    addEdge(0, 1, 450); // Rio de Janeiro para São Paulo: 450 km
    addEdge(1, 2, 600); // São Paulo para Belo Horizonte: 600 km
    addEdge(2, 0, 500); // Belo Horizonte para Rio de Janeiro: 500 km

    // Calcular e apresentar o comprimento do caminho entre duas cidades
    int source, destination;
    printf("Digite o índice da cidade de origem (0 - Rio de Janeiro, 1 - São Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &source);
    printf("Digite o índice da cidade de destino (0 - Rio de Janeiro, 1 - São Paulo, 2 - Belo Horizonte): ");
    scanf("%d", &destination);

    int pathLength = findPathLength(source, destination, 0);
    if (pathLength > 0) {
        printf("O comprimento do caminho entre %s e %s é %d km.\n", cities[source], cities[destination], pathLength);
    } else {
        printf("Não há um caminho direto entre %s e %s.\n", cities[source], cities[destination]);
    }

    // Verificar se há ciclos no grafo
    bool visited[MAX_CITIES] = {false};
    bool stack[MAX_CITIES] = {false};
    bool hasCycles = false;

    for (int i = 0; i < MAX_CITIES; i++) {
        if (!visited[i] && hasCycle(i, visited, stack)) {
            hasCycles = true;
            break;
        }
    }

    if (hasCycles) {
        printf("O grafo possui ciclos.\n");
    } else {
        printf("O grafo não possui ciclos.\n");
    }

    // Calcular o grau de entrada de cada nó
        inDegree();

    // Calcular o grau de saída de cada nó
    outDegree();

    return 0;
}
