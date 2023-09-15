#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int* alocacao(int *array,int n);
void preeecher(int *array,int n);
void imprimir(int *array, int n);

int main() {
    int *array, n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = alocacao(array,n);

    preeecher(array,n);

    imprimir(array,n);

    // Liberar a mem�ria alocada com malloc
    free(array);

    return 0;
}

int* alocacao(int *array,int n){
    array = (int *)malloc(n* sizeof(int));

    if (array == NULL) {
        printf("Falha na aloca��o de mem�ria.\n");
        return 1;
    }else{
        return array;
    }
}

void preeecher(int *array, int n){
    srand (time (NULL)); //Inicia a gera��o de inteiros aleat�rios com uma nova semente.

    for (int i = 0; i < n; i++) {
        array[i] = rand()%1000;
    }
}

void imprimir(int *array, int n){

    printf("Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

