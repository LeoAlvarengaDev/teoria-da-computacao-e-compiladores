#include <stdio.h>
#include <stdlib.h>

typedef struct veiculo {
    char *numeroChassi;
    char *marca;
    char *modelo;
    double preco;
} tveiculo;

tveiculo* alocarVeiculos(int n);
tveiculo* realocarVeiculos(tveiculo *array,int n);
void preencher(tveiculo *array, int n);
int* alocarVetor(int n);
void leStr (char *str, int n) ;
void imprimeStr (char *str);

int main()
{
    int n,j,novo;
    char lixo;
    printf("Informe quatos carros devem ser inseridos: ");
    scanf("%d", &n);
    scanf("%c", &lixo);

    tveiculo *array = alocarVeiculos(n);

    preencher(array,n);
    for(int i = 0; i < n ; i++){

        printf("\nNumero do Chassi:");
        imprimeStr(array[i].numeroChassi);
        printf("\nMarca:");
        imprimeStr(array[i].marca);
        printf("\nModelo:");
        imprimeStr(array[i].modelo);
        printf("\nPreco : %.2f",array[i].preco);
    }

    printf("\nInforme quatos novos carros devem ser inseridos: ");
    scanf("%d", &j);
    scanf("%c", &lixo);

    array = realocarVeiculos(array,j);

    preencher(array,j);
    for(int i = 0; i < j ; i++){

        printf("\nNumero do Chassi:");
        imprimeStr(array[i].numeroChassi);
        printf("\nMarca:");
        imprimeStr(array[i].marca);
        printf("\nModelo:");
        imprimeStr(array[i].modelo);
        printf("\nPreco : %.2f",array[i].preco);
    }



    free(array);
    return 0;
}

tveiculo* alocarVeiculos(int n){

    // Alocação dinâmica de memória usando calloc
    tveiculo *array = (tveiculo *) malloc(n*sizeof(tveiculo));

    if (array == NULL) {
    printf("Falha na alocação de memória.\n");
    return 1;
    }

    return array;
}

int* alocarVetor(int n){
    // Alocação dinâmica de memória usando calloc
    int *array = (int *) calloc(n, sizeof(int));

    if (array == NULL) {
    printf("Falha na alocação de memória.\n");
    return 1;
    }

    return array;
}

void preencher(tveiculo *array, int n){
    char lixo;
    for(int i = 0; i < n ; i++){

        tveiculo v;

        v.numeroChassi = alocarVetor(100);
        v.marca = alocarVetor(100);
        v.modelo  = alocarVetor(100);

        printf("\nDados do %d Carro", i+1);

        printf("\nInforme o numero do Chassi:");
        leStr(v.numeroChassi,100);

        printf("\nInforme a Marca:");
        leStr(v.marca,100);

        printf("\nInforme o Modelo:");
        leStr(v.modelo,100);

        printf("\nInforme o preco:");
        scanf("%lf", &(v.preco));

        scanf("%c", &lixo);

        array[i] = v;

        free(v.numeroChassi);
        free(v.marca);
        free(v.modelo);
    }
}

void leStr (char *str, int n) {
    int i = 0;
    scanf ("%c", &str[0]);
    for (i = 1; (str[i - 1] != '\n') && (i < n - 1); i++)
        scanf ("%c", &str[i]);
    str[i - 1] = '\0';
}

void imprimeStr (char *str) {
    int i;
    for (i = 0; (str[i] != '\0') && (i < 255); i++)
        printf ("%c", str[i]);
}

tveiculo* realocarVeiculos(tveiculo *array,int n){

    // Alocação dinâmica de memória usando calloc
    array = (tveiculo *) realloc(array, n * sizeof(tveiculo));

    if (array == NULL) {
    printf("Falha na alocação de memória.\n");
    return 1;
    }

    return array;
}
