#include <stdio.h>
#include <stdlib.h>

//7) Receba o valor do sal�rio m�nimo e o valor do sal�rio de um funcion�rio. O algoritmo
//deve calcular e apresentar a quantidade de sal�rios m�nimos que esse funcion�rio
//recebe.

int main()
{
    double salmin,salfun;
    int qtnsal;
    printf("\nInforme quanto � o salario minimo: ");
    scanf("%lf",&salmin);

    printf("\nInforme seu salario:");
    scanf("%lf",&salfun);


    qtnsal = (int)salfun/salmin;

    printf("\nVoce ganha %d salarios minimos",qtnsal);

    return 0;
}
