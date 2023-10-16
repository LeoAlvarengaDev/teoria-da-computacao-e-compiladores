#include <stdio.h>
#include <stdlib.h>

void relacaoNaturaisInteiro(int limite);
void relacaoNaturaisInteiroRecursivo(int limite);

int main()
{
    int limite;
    printf("\nInforme o limite:\n");
    scanf("%d",&limite);

    relacaoNaturaisInteiro(limite);

    return 0;
}

void relacaoNaturaisInteiro(int limite){
     int par,impar;
     for(int i = 0; i <= limite;i++){

        if(i == 0 || i == 1){
            par = i;
            printf("[%d,%d],",i,par);
        }else if(i%2 == 0){
            par = (i/2)*-1;
            printf("[%d,%d],",i,par);
        }else{
            impar = (i/2)+1;
            printf("[%d,%d],",i,impar);
        }
    }
    printf("\n");

    relacaoNaturaisInteiroRecursivo(limite);
}

void relacaoNaturaisInteiroRecursivo(int limite){
    int par,impar;

    if (limite == 0) {
        par = limite;
        printf("[%d,%d],", limite, par);
    } else if (limite == 1) {
        impar = limite;
        printf("[%d,%d],", limite, impar);
    } else if (limite % 2 == 0) {
        par = (limite / 2) * -1;
        printf("[%d,%d],", limite, par);
    } else {
        impar = (limite / 2) + 1;
        printf("[%d,%d],", limite, impar);
    }

    if (limite > 0) {
        relacaoNaturaisInteiroRecursivo(limite - 1);
    }
}

