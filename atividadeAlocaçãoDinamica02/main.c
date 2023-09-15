#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char *nome;
    char *senha;
    double salario;
} tpessoa;

tpessoa* alocarPessoa(int n);
void preencher(tpessoa *array,int n);
int* alocarVetor(int n);
void leStr (char *str, int n) ;
void imprimeStr (char *str);

int main()
{
    int n;
    char lixo;
    printf("Informe quatas pessoas devem ser cadastradas: ");
    scanf("%d", &n);
    scanf("%c", &lixo);

    tpessoa *array = alocarPessoa(n);

    preencher(array,n);
    for(int i = 0; i < n ; i++){
        printf("\nDados  da pessoa %d:",i+1);
        printf("\nNome:");
        imprimeStr(array[i].nome);
        printf("\nSenha:");
        imprimeStr(array[i].senha);
        printf("\nSalario : %.2f",array[i].salario);
    }


    free(array);
    return 0;
}

tpessoa* alocarPessoa(int n){

    // Alocação dinâmica de memória usando calloc
    tpessoa *array = (tpessoa *) calloc(n,sizeof(tpessoa));

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

void preencher(tpessoa *array, int n){
    char lixo;
    for(int i = 0; i < n ; i++){

        tpessoa p;

        p.nome = alocarVetor(100);
        p.senha= alocarVetor(100);

        printf("\nDados da %d Pessoa:", i+1);

        printf("\nInforme o nome:");
        leStr(p.nome,100);

        printf("\nInforme a senha:");
        leStr(p.senha,100);

        printf("\nInforme o salario:");
        scanf("%lf", &(p.salario));

        scanf("%c", &lixo);

        array[i] = p;

        free(p.nome);
        free(p.senha);
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
