#include <stdio.h>
#include <stdlib.h>

//7) Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
//deve calcular e apresentar a quantidade de salários mínimos que esse funcionário
//recebe.

int main()
{
    double salmin,salfun;
    int qtnsal;
    printf("\nInforme quanto é o salario minimo: ");
    scanf("%lf",&salmin);

    printf("\nInforme seu salario:");
    scanf("%lf",&salfun);


    qtnsal = (int)salfun/salmin;

    printf("\nVoce ganha %d salarios minimos",qtnsal);

    return 0;
}
